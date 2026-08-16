/*
 * Modified to discard host-toolchain metadata from the KAR Wii apploader build
 * by KAR project contributors, 2026-08-15.
 */

OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc:common)

SECTIONS {

	.mystart 0x811fffe0 : { start.o }
	.text 0x81200000 : { *(.text) }
	.data : { *(.data) }
	.sdata : { *(.sdata) }
	.rodata : { *(.rodata)}

	. = ALIGN(32768);
	.stack : {
		_stack_top = .;
		. += 32768;
		_stack_bot = .;
	}

	__bss_start = .;
	.bss : { *(.bss) }
	.sbss : { *(.sbss) }
	__bss_end = .;

	/DISCARD/ : {
		*(.comment)
		*(.note*)
		*(.eh_frame*)
	}
}
