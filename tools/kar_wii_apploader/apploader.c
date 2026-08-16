/** Wii apploader, based on apploader.c from the cubeboot-tools package.
 * Modified to support Wii, and stripped down to support normal discs.
 *
 * Copyright (C) 2008 marcan
 * Copyright (C) 2008 bushing
 * Copyright (C) 2005-2006 The GameCube Linux Team
 * Copyright (C) 2005,2006 Albert Herranz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, version 2.
 *
 */

/*
 * Modified for the KAR merged-DOL MEM2 loader and stricter input validation
 * by KAR project contributors, 2026-08-15.
 */

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include "gcm.h"
#include "dol.h"

#define printf al_control.report
#define panic(...) { printf(__VA_ARGS__); while(1); }

#define DI_ALIGN_SHIFT	5
#define DI_ALIGN_SIZE	(1UL << DI_ALIGN_SHIFT)
#define DI_ALIGN_MASK	(~((1 << DI_ALIGN_SHIFT) - 1))

#define MEM1_START	0x80003100U
#define MEM1_END		0x81200000U
#define KAR_LOADER_START 0x93000000U
#define KAR_LOADER_END	0x933d0000U

#define di_align(addr)	(void *) \
			((((unsigned long)(addr)) + \
				 DI_ALIGN_SIZE - 1) & DI_ALIGN_MASK)

struct dolphin_debugger_info {
	uint32_t		present;
	uint32_t		exception_mask;
	uint32_t		exception_hook_address;
	uint32_t		saved_lr;
	unsigned char		__pad1[0x10];
} __attribute__ ((__packed__));

struct dolphin_lowmem {
	struct gcm_disk_info	b_disk_info;

	uint32_t		a_boot_magic;
	uint32_t		a_version;

	uint32_t		b_physical_memory_size;
	uint32_t		b_console_type;

	uint32_t		a_arena_lo;
	uint32_t		a_arena_hi;
	void			*a_fst;
	uint32_t		a_fst_max_size;

	struct dolphin_debugger_info a_debugger_info;
	unsigned char		hook_code[0x60];

	uint32_t		o_current_os_context_phys;
	uint32_t		o_previous_os_interrupt_mask;
	uint32_t		o_current_os_interrupt_mask;

	uint32_t		tv_mode;
	uint32_t		b_aram_size;

	void			*o_current_os_context;
	void			*o_default_os_thread;
	void			*o_thread_queue_head;
	void			*o_thread_queue_tail;
	void			*o_current_os_thread;

	uint32_t		a_debug_monitor_size;
	void			*a_debug_monitor;

	uint32_t		a_simulated_memory_size;

	void			*a_bi2;

	uint32_t		b_bus_clock_speed;
	uint32_t		b_cpu_clock_speed;
} __attribute__ ((__packed__));

/*
 *
 */

static void al_enter(void (*report) (char *text, ...));
static int al_load(void **address, uint32_t * length, uint32_t * offset);
static void *al_exit(void);

/*
 *
 */
struct apploader_control {
	unsigned 	step;
	unsigned long	fst_address;
	uint32_t	fst_offset;
	uint32_t	fst_size;
	unsigned long	bi2_address;
		void		(*report) (char *text, ...);
};

struct bootloader_control {
	void *entry_point;
	uint32_t offset;
	uint32_t size;
	uint32_t sects_bitmap;
	uint32_t all_sects_bitmap;
};


static struct dolphin_lowmem *lowmem =
			 (struct dolphin_lowmem *)0x80000000;

static struct apploader_control al_control = { .fst_size = ~0 };
static struct bootloader_control bl_control = { .size = ~0 };

extern unsigned char __bss_end[];

static unsigned char di_buffer[DI_SECTOR_SIZE] __attribute__ ((aligned(32)));
static unsigned char header_buffer[sizeof(struct gcm_disk_header) + sizeof(struct gcm_disk_header_info)] __attribute__ ((aligned(32)));

struct gcm_disk_header *disk_header;
struct gcm_disk_header_info *disk_header_info;

/*
 * This is our particular "main".
 * It _must_ be the first function in this file.
 */
void al_start(void **enter, void **load, void **exit)
{
	al_control.step = 0;
	*enter = al_enter;
	*load = al_load;
	*exit = al_exit;
}

static void sync_cache(void *p, uint32_t n)
{
	uint32_t start, end;

	start = (uint32_t)p & ~31;
	end = ((uint32_t)p + n + 31) & ~31;
	n = (end - start) >> 5;

	while (n--) {
		__asm__("dcbst 0,%0 ; icbi 0,%0" : : "b"(p));
		p += 32;
	}
	__asm__("sync ; isync");
}

static void sync_before_read(void *p, uint32_t n)
{
	uint32_t start, end;

	start = (uint32_t)p & ~31;
	end = ((uint32_t)p + n + 31) & ~31;
	n = (end - start) >> 5;

	while (n--) {
		__asm__("dcbf 0,%0" : : "b"(p));
		p += 32;
	}
	__asm__("sync");
}

void memset(uint8_t *buf, int byte, int len) {
	int i;
	for(i=0; i<len; i++) buf[i] = byte;
}


/*
 * Loads a bitmap mask with all non-void sections in a DOL file.
 */
static int al_load_dol_sects_bitmap(struct dol_header *h)
{
	int i, sects_bitmap;

	sects_bitmap = 0;
	for (i = 0; i < DOL_MAX_SECT; i++) {
		/* zero here means the section is not in use */
		if (dol_sect_size(h, i) == 0)
			continue;

		sects_bitmap |= (1 << i);
	}
	return sects_bitmap;
}

static int al_range_is_supported(uint32_t start, uint32_t size)
{
	uint32_t end = start + size;

	if (end < start)
		return 0;
	return (start >= MEM1_START && end <= MEM1_END) ||
	       (start >= KAR_LOADER_START && end <= KAR_LOADER_END);
}

/*
 * Checks if the DOL we are trying to boot is appropiate enough.
 */
static void al_check_dol(struct dol_header *h, uint32_t dol_length)
{
	int i, valid = 0;
	uint32_t value;

	/* now perform some sanity checks */
	for (i = 0; i < DOL_MAX_SECT; i++) {
		/* A nonempty DOL segment may not be stored in the header. */
		if (dol_sect_size(h, i) != 0
		    && dol_sect_offset(h, i) < DOL_HEADER_SIZE) {
			panic("detected segment offset within DOL header\n");
		}

		/* offsets must be aligned to 32 bytes */
		value = dol_sect_offset(h, i);
		if (value != (uint32_t) di_align(value)) {
			panic("detected unaligned section offset\n");
		}

		/* addresses must be aligned to 32 bytes */
		value = dol_sect_address(h, i);
		if (value != (uint32_t) di_align(value)) {
			panic("unaligned section address\n");
		}

		/* The IPL reads section lengths rounded up to a cache line. */
		{
			uint32_t offset = dol_sect_offset(h, i);
			uint32_t size = dol_sect_size(h, i);
			uint32_t aligned_size = (size + DI_ALIGN_SIZE - 1) &
						DI_ALIGN_MASK;

			if (aligned_size < size || offset > dol_length ||
			    aligned_size > dol_length - offset) {
				panic("segment past DOL file size\n");
			}
		}

		if (dol_sect_size(h, i) != 0) {
			uint32_t section_start = dol_sect_address(h, i);
			uint32_t section_size = dol_sect_size(h, i);

			if (!al_range_is_supported(section_start, section_size)) {
				panic("segment outside supported MEM1/MEM2 ranges\n");
			}
		}

		if (i < DOL_SECT_MAX_TEXT) {
			/* remember that entrypoint was in a code segment */
			if (h->entry_point >= dol_sect_address(h, i)
			    && h->entry_point < dol_sect_address(h, i) +
			    dol_sect_size(h, i))
				valid = 1;
		}
	}

	if (h->size_bss != 0 &&
	    !al_range_is_supported(h->address_bss, h->size_bss)) {
		panic("BSS outside supported MEM1/MEM2 ranges\n");
	}

	/* if entrypoint is not within a code segment reject this file */
	if (!valid) {
		panic("entry point out of text segment\n");
	}

	/* we've got a valid dol if we got here */
	return;
}

/*
 * Initializes the apploader related stuff.
 * Called by the IPL.
 */
static void al_enter(void (*report) (char *text, ...))
{
	al_control.step = 1;
	al_control.report = report;
	printf("al_enter(%p)\n",report);
	if (report) {
		report("KAR Wii OSS Apploader\n");
		report("By Albert Herranz, The GameCube Linux Team, marcan, and bushing\n");
	}

}

/*
 * This is the apploader main processing function.
 * Called by the IPL.
 */
static int al_load(void **address, uint32_t *length, uint32_t *offset)
{
	struct dol_header *dh;
	unsigned long lowest_start;
	uint32_t aligned_fst_size;
	uint32_t workspace_end;
	int j, k;

	int need_more = 1; /* this tells the IPL if we need more data or not */

	printf("al_load: step %d\n",al_control.step);

	switch (al_control.step) {
	case 0:
		/* should not get here if al_enter was called */
	case 1:

		/* read sector 0, containing disk header and disk header info */
		*address = header_buffer;
		*length = (uint32_t) di_align(sizeof(*disk_header) + sizeof(*disk_header_info));
		*offset = 0;
		sync_before_read(*address, *length);

		al_control.step++;
		printf("Apploader: Reading header\n");
		break;
	case 2:
		disk_header = (struct gcm_disk_header *)header_buffer;
		disk_header_info = (struct gcm_disk_header_info *)(header_buffer + sizeof(*disk_header));
		printf("GameCode: %c%c%c%c\n",disk_header->info.game_code[0], disk_header->info.game_code[1],
			   disk_header->info.game_code[2], disk_header->info.game_code[3] );
		printf("Game Name: %s\n",disk_header->game_name);

		bl_control.offset = disk_header->layout.dol_offset;
		if (disk_header->layout.fst_offset <= bl_control.offset ||
		    disk_header->layout.fst_offset - bl_control.offset >
			    (0xffffffffU >> 2)) {
			panic("invalid DOL/FST offsets\n");
		}
		bl_control.size =
			(disk_header->layout.fst_offset - bl_control.offset) << 2;

		/* request the .dol header */
		*address = di_buffer;
		*length = DOL_HEADER_SIZE;
		*offset = bl_control.offset;
		sync_before_read(*address, *length);

		bl_control.sects_bitmap = 0;
		al_control.step++;
		printf("Apploader: Reading DOL header\n");
		break;
	case 3:
		/* .dol header loaded */
		dh = (struct dol_header *)di_buffer;

		/* sanity checks here */
		al_check_dol(dh, bl_control.size);

		/* save our entry point */
		bl_control.entry_point = (void *)dh->entry_point;

		/*
		 * Clear BSS before loading sections. Retail KAR has initialized
		 * data sections inside its broad BSS span, so clearing it after
		 * section loads would destroy those initialized bytes.
		 */
		if (dh->size_bss)
			memset((void *)dh->address_bss, 0, dh->size_bss);

		/* pending and valid sections, respectively */
		bl_control.sects_bitmap = 0;
		bl_control.all_sects_bitmap = al_load_dol_sects_bitmap(dh);

		al_control.step++;
		// fall through
	case 4:
		dh = (struct dol_header *)di_buffer;

		/*
		 * Load the sections in ascending order.
		 * We need this because we are loading a bit more of data than
		 * strictly necessary on DOLs with unaligned lengths.
		 */

		/* find lowest start address for a pending section */
		lowest_start = 0xffffffff;
		for (j = -1, k = 0; k < DOL_MAX_SECT; k++) {
			/* continue if section is already done */
			if ((bl_control.sects_bitmap & (1 << k)) != 0)
				continue;
			/* do nothing for non sections */
			if (!(bl_control.all_sects_bitmap & (1 << k)))
				continue;
			/* found new candidate */
			if (dol_sect_address(dh, k) < lowest_start) {
				lowest_start = dol_sect_address(dh, k);
				j = k;
			}
		}
		/* mark section as being loaded */
		bl_control.sects_bitmap |= (1 << j);

		/* request a .dol section */
		*address = (void *)dol_sect_address(dh, j);;
		*length = (uint32_t) di_align(dol_sect_size(dh, j));
		*offset = bl_control.offset + (dol_sect_offset(dh, j)>>2);
		printf("Apploader: loading DOL section @ %p from 0x%x: 0x%x bytes\n",*address,*length,*offset<<2);

		sync_before_read(*address, *length);
		if (dol_sect_is_text(dh, j))
			sync_before_read(*address, *length);

		/* check if we are going to be done with all sections */
		if (bl_control.sects_bitmap == bl_control.all_sects_bitmap) {
			/* bye, bye */
			al_control.step++;
		}
		break;
	case 5:
		/* DOL loaded, now read FST */

		al_control.fst_offset = disk_header->layout.fst_offset;
		if (disk_header->layout.fst_size > (0xffffffffU >> 2)) {
			panic("FST size overflow\n");
		}
		al_control.fst_size = disk_header->layout.fst_size << 2;
		if (al_control.fst_size < sizeof(struct gcm_file_entry)) {
			panic("FST is too small\n");
		}
		workspace_end = (uint32_t)__bss_end;
		if (workspace_end > 0x81800000U - 0x2000U) {
			panic("invalid apploader workspace\n");
		}
		workspace_end += 0x2000U;
		if (al_control.fst_size > 0xffffffffU - (DI_ALIGN_SIZE - 1)) {
			panic("FST alignment overflow\n");
		}
		aligned_fst_size =
			(al_control.fst_size + DI_ALIGN_SIZE - 1) & DI_ALIGN_MASK;
		if (aligned_fst_size < al_control.fst_size ||
		    aligned_fst_size > 0x81800000U - workspace_end) {
			panic("FST overlaps the apploader workspace\n");
		}
		al_control.fst_address = 0x81800000U - aligned_fst_size;

		/* read fst.bin */
		*address = (void *)al_control.fst_address;
		*length = aligned_fst_size;
		*offset = al_control.fst_offset;
		sync_before_read(*address, *length);

		al_control.step++;
		printf("Apploader: Loading FST\n");
		break;
	case 6:
		/* fst.bin loaded */

		al_control.bi2_address = al_control.fst_address - 0x2000;

		/* read bi2.bin */
		*address = (void *)al_control.bi2_address;
		*length = 0x2000;
		*offset = 0x440>>2;
		sync_before_read(*address, *length);

		al_control.step++;
		printf("Apploader: Loading BI2\n");
		break;
	case 7:
		/* bi2.bin loaded */

		lowmem->a_boot_magic = 0x0d15ea5e;
		lowmem->a_version = 1;

		lowmem->a_arena_hi = al_control.fst_address;
		lowmem->a_fst = (void *)al_control.fst_address;
		lowmem->a_fst_max_size = al_control.fst_size;
		//memset(&lowmem->a_debugger_info, 0, sizeof(struct dolphin_debugger_info));
		//lowmem->a_debug_monitor_size = 0;
		lowmem->a_debug_monitor = (void *)0x81800000;
		lowmem->a_simulated_memory_size = 0x01800000;
		lowmem->a_bi2 = (void *)al_control.bi2_address;
		sync_cache(lowmem, 1);

		*length = 0;
		need_more = 0;
		printf("Apploader: Processing complete\n");
		al_control.step++;
		break;
	default:
		al_control.step++;
		break;
	}

	return need_more;
}

/*
 *
 */
static void *al_exit(void)
{
	printf("al_exit() = %p\n",bl_control.entry_point);
	return bl_control.entry_point;
}
