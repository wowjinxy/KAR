.include "macros.inc"
.file "itdata.c"

# 0x80250038..0x802514A4 | size: 0x146C
.text
.balign 4

# .text:0x0 | 0x80250038 | size: 0x60
.fn kar_itdata_get_kind_data_entry, global
/* 80250038 0024CE38  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8025003C 0024CE3C  7C 08 02 A6 */	mflr r0
/* 80250040 0024CE40  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250044 0024CE44  80 8D 07 F0 */	lwz r4, lbl_805DD8D0@sda21(r0)
/* 80250048 0024CE48  80 84 00 08 */	lwz r4, 0x8(r4)
/* 8025004C 0024CE4C  28 04 00 00 */	cmplwi r4, 0x0
/* 80250050 0024CE50  41 82 00 10 */	beq .L_80250060
/* 80250054 0024CE54  1C 03 00 18 */	mulli r0, r3, 0x18
/* 80250058 0024CE58  7C 64 02 14 */	add r3, r4, r0
/* 8025005C 0024CE5C  48 00 00 2C */	b .L_80250088
.L_80250060:
/* 80250060 0024CE60  3C 60 80 4B */	lis r3, lbl_804B61C8@ha
/* 80250064 0024CE64  38 63 61 C8 */	addi r3, r3, lbl_804B61C8@l
/* 80250068 0024CE68  4C C6 31 82 */	crclr cr1eq
/* 8025006C 0024CE6C  48 18 4C 7D */	bl OSReport
/* 80250070 0024CE70  3C 60 80 4B */	lis r3, kar_src_itdata_804b61e4@ha
/* 80250074 0024CE74  38 80 00 E3 */	li r4, 0xe3
/* 80250078 0024CE78  38 63 61 E4 */	addi r3, r3, kar_src_itdata_804b61e4@l
/* 8025007C 0024CE7C  38 AD A2 98 */	li r5, lbl_805D7378@sda21
/* 80250080 0024CE80  48 1D 84 39 */	bl __assert
/* 80250084 0024CE84  38 60 00 00 */	li r3, 0x0
.L_80250088:
/* 80250088 0024CE88  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8025008C 0024CE8C  7C 08 03 A6 */	mtlr r0
/* 80250090 0024CE90  38 21 00 10 */	addi r1, r1, 0x10
/* 80250094 0024CE94  4E 80 00 20 */	blr
.endfn kar_itdata_get_kind_data_entry

# .text:0x60 | 0x80250098 | size: 0x18
.fn kar_itdata_is_kind_data_loaded, global
/* 80250098 0024CE98  80 6D 07 F0 */	lwz r3, lbl_805DD8D0@sda21(r0)
/* 8025009C 0024CE9C  80 63 00 08 */	lwz r3, 0x8(r3)
/* 802500A0 0024CEA0  7C 03 00 D0 */	neg r0, r3
/* 802500A4 0024CEA4  7C 00 1B 78 */	or r0, r0, r3
/* 802500A8 0024CEA8  54 03 0F FE */	srwi r3, r0, 31
/* 802500AC 0024CEAC  4E 80 00 20 */	blr
.endfn kar_itdata_is_kind_data_loaded

# .text:0x78 | 0x802500B0 | size: 0x64
.fn kar_itdata_get_kind_resource, global
/* 802500B0 0024CEB0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802500B4 0024CEB4  7C 08 02 A6 */	mflr r0
/* 802500B8 0024CEB8  90 01 00 14 */	stw r0, 0x14(r1)
/* 802500BC 0024CEBC  80 8D 07 F0 */	lwz r4, lbl_805DD8D0@sda21(r0)
/* 802500C0 0024CEC0  80 84 00 08 */	lwz r4, 0x8(r4)
/* 802500C4 0024CEC4  28 04 00 00 */	cmplwi r4, 0x0
/* 802500C8 0024CEC8  41 82 00 10 */	beq .L_802500D8
/* 802500CC 0024CECC  1C 03 00 18 */	mulli r0, r3, 0x18
/* 802500D0 0024CED0  7C 64 02 14 */	add r3, r4, r0
/* 802500D4 0024CED4  48 00 00 2C */	b .L_80250100
.L_802500D8:
/* 802500D8 0024CED8  3C 60 80 4B */	lis r3, lbl_804B61C8@ha
/* 802500DC 0024CEDC  38 63 61 C8 */	addi r3, r3, lbl_804B61C8@l
/* 802500E0 0024CEE0  4C C6 31 82 */	crclr cr1eq
/* 802500E4 0024CEE4  48 18 4C 05 */	bl OSReport
/* 802500E8 0024CEE8  3C 60 80 4B */	lis r3, kar_src_itdata_804b61e4@ha
/* 802500EC 0024CEEC  38 80 00 E3 */	li r4, 0xe3
/* 802500F0 0024CEF0  38 63 61 E4 */	addi r3, r3, kar_src_itdata_804b61e4@l
/* 802500F4 0024CEF4  38 AD A2 98 */	li r5, lbl_805D7378@sda21
/* 802500F8 0024CEF8  48 1D 83 C1 */	bl __assert
/* 802500FC 0024CEFC  38 60 00 00 */	li r3, 0x0
.L_80250100:
/* 80250100 0024CF00  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250104 0024CF04  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80250108 0024CF08  7C 08 03 A6 */	mtlr r0
/* 8025010C 0024CF0C  38 21 00 10 */	addi r1, r1, 0x10
/* 80250110 0024CF10  4E 80 00 20 */	blr
.endfn kar_itdata_get_kind_resource

# .text:0xDC | 0x80250114 | size: 0x68
.fn kar_itdata_get_kind_model_joint_root, global
/* 80250114 0024CF14  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250118 0024CF18  7C 08 02 A6 */	mflr r0
/* 8025011C 0024CF1C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250120 0024CF20  80 8D 07 F0 */	lwz r4, lbl_805DD8D0@sda21(r0)
/* 80250124 0024CF24  80 84 00 08 */	lwz r4, 0x8(r4)
/* 80250128 0024CF28  28 04 00 00 */	cmplwi r4, 0x0
/* 8025012C 0024CF2C  41 82 00 10 */	beq .L_8025013C
/* 80250130 0024CF30  1C 03 00 18 */	mulli r0, r3, 0x18
/* 80250134 0024CF34  7C 64 02 14 */	add r3, r4, r0
/* 80250138 0024CF38  48 00 00 2C */	b .L_80250164
.L_8025013C:
/* 8025013C 0024CF3C  3C 60 80 4B */	lis r3, lbl_804B61C8@ha
/* 80250140 0024CF40  38 63 61 C8 */	addi r3, r3, lbl_804B61C8@l
/* 80250144 0024CF44  4C C6 31 82 */	crclr cr1eq
/* 80250148 0024CF48  48 18 4B A1 */	bl OSReport
/* 8025014C 0024CF4C  3C 60 80 4B */	lis r3, kar_src_itdata_804b61e4@ha
/* 80250150 0024CF50  38 80 00 E3 */	li r4, 0xe3
/* 80250154 0024CF54  38 63 61 E4 */	addi r3, r3, kar_src_itdata_804b61e4@l
/* 80250158 0024CF58  38 AD A2 98 */	li r5, lbl_805D7378@sda21
/* 8025015C 0024CF5C  48 1D 83 5D */	bl __assert
/* 80250160 0024CF60  38 60 00 00 */	li r3, 0x0
.L_80250164:
/* 80250164 0024CF64  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80250168 0024CF68  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8025016C 0024CF6C  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80250170 0024CF70  7C 08 03 A6 */	mtlr r0
/* 80250174 0024CF74  38 21 00 10 */	addi r1, r1, 0x10
/* 80250178 0024CF78  4E 80 00 20 */	blr
.endfn kar_itdata_get_kind_model_joint_root

# .text:0x144 | 0x8025017C | size: 0x58
.fn kar_itdata_get_param_float_44_with_pickup_override, global
/* 8025017C 0024CF7C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250180 0024CF80  7C 08 02 A6 */	mflr r0
/* 80250184 0024CF84  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250188 0024CF88  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8025018C 0024CF8C  7C 7F 1B 78 */	mr r31, r3
/* 80250190 0024CF90  38 60 00 04 */	li r3, 0x4
/* 80250194 0024CF94  48 00 3F A1 */	bl fn_80254134
/* 80250198 0024CF98  2C 03 00 00 */	cmpwi r3, 0x0
/* 8025019C 0024CF9C  41 82 00 1C */	beq .L_802501B8
/* 802501A0 0024CFA0  80 1F 00 48 */	lwz r0, 0x48(r31)
/* 802501A4 0024CFA4  54 00 07 7B */	rlwinm. r0, r0, 0, 29, 29
/* 802501A8 0024CFA8  41 82 00 10 */	beq .L_802501B8
/* 802501AC 0024CFAC  80 6D 07 EC */	lwz r3, lbl_805DD8CC@sda21(r0)
/* 802501B0 0024CFB0  C0 23 01 B0 */	lfs f1, 0x1b0(r3)
/* 802501B4 0024CFB4  48 00 00 0C */	b .L_802501C0
.L_802501B8:
/* 802501B8 0024CFB8  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 802501BC 0024CFBC  C0 23 00 44 */	lfs f1, 0x44(r3)
.L_802501C0:
/* 802501C0 0024CFC0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802501C4 0024CFC4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802501C8 0024CFC8  7C 08 03 A6 */	mtlr r0
/* 802501CC 0024CFCC  38 21 00 10 */	addi r1, r1, 0x10
/* 802501D0 0024CFD0  4E 80 00 20 */	blr
.endfn kar_itdata_get_param_float_44_with_pickup_override

# .text:0x19C | 0x802501D4 | size: 0x58
.fn kar_itdata_get_param_float_48_with_pickup_override, global
/* 802501D4 0024CFD4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802501D8 0024CFD8  7C 08 02 A6 */	mflr r0
/* 802501DC 0024CFDC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802501E0 0024CFE0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802501E4 0024CFE4  7C 7F 1B 78 */	mr r31, r3
/* 802501E8 0024CFE8  38 60 00 04 */	li r3, 0x4
/* 802501EC 0024CFEC  48 00 3F 49 */	bl fn_80254134
/* 802501F0 0024CFF0  2C 03 00 00 */	cmpwi r3, 0x0
/* 802501F4 0024CFF4  41 82 00 1C */	beq .L_80250210
/* 802501F8 0024CFF8  80 1F 00 48 */	lwz r0, 0x48(r31)
/* 802501FC 0024CFFC  54 00 07 7B */	rlwinm. r0, r0, 0, 29, 29
/* 80250200 0024D000  41 82 00 10 */	beq .L_80250210
/* 80250204 0024D004  80 6D 07 EC */	lwz r3, lbl_805DD8CC@sda21(r0)
/* 80250208 0024D008  C0 23 01 B4 */	lfs f1, 0x1b4(r3)
/* 8025020C 0024D00C  48 00 00 0C */	b .L_80250218
.L_80250210:
/* 80250210 0024D010  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 80250214 0024D014  C0 23 00 48 */	lfs f1, 0x48(r3)
.L_80250218:
/* 80250218 0024D018  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8025021C 0024D01C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80250220 0024D020  7C 08 03 A6 */	mtlr r0
/* 80250224 0024D024  38 21 00 10 */	addi r1, r1, 0x10
/* 80250228 0024D028  4E 80 00 20 */	blr
.endfn kar_itdata_get_param_float_48_with_pickup_override

# .text:0x1F4 | 0x8025022C | size: 0x58
.fn kar_itdata_get_param_float_4c_with_pickup_override, global
/* 8025022C 0024D02C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250230 0024D030  7C 08 02 A6 */	mflr r0
/* 80250234 0024D034  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250238 0024D038  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8025023C 0024D03C  7C 7F 1B 78 */	mr r31, r3
/* 80250240 0024D040  38 60 00 04 */	li r3, 0x4
/* 80250244 0024D044  48 00 3E F1 */	bl fn_80254134
/* 80250248 0024D048  2C 03 00 00 */	cmpwi r3, 0x0
/* 8025024C 0024D04C  41 82 00 1C */	beq .L_80250268
/* 80250250 0024D050  80 1F 00 48 */	lwz r0, 0x48(r31)
/* 80250254 0024D054  54 00 07 7B */	rlwinm. r0, r0, 0, 29, 29
/* 80250258 0024D058  41 82 00 10 */	beq .L_80250268
/* 8025025C 0024D05C  80 6D 07 EC */	lwz r3, lbl_805DD8CC@sda21(r0)
/* 80250260 0024D060  C0 23 01 B8 */	lfs f1, 0x1b8(r3)
/* 80250264 0024D064  48 00 00 0C */	b .L_80250270
.L_80250268:
/* 80250268 0024D068  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 8025026C 0024D06C  C0 23 00 4C */	lfs f1, 0x4c(r3)
.L_80250270:
/* 80250270 0024D070  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250274 0024D074  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80250278 0024D078  7C 08 03 A6 */	mtlr r0
/* 8025027C 0024D07C  38 21 00 10 */	addi r1, r1, 0x10
/* 80250280 0024D080  4E 80 00 20 */	blr
.endfn kar_itdata_get_param_float_4c_with_pickup_override

# .text:0x24C | 0x80250284 | size: 0x58
.fn kar_itdata_get_param_float_50_with_pickup_override, global
/* 80250284 0024D084  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250288 0024D088  7C 08 02 A6 */	mflr r0
/* 8025028C 0024D08C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250290 0024D090  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80250294 0024D094  7C 7F 1B 78 */	mr r31, r3
/* 80250298 0024D098  38 60 00 04 */	li r3, 0x4
/* 8025029C 0024D09C  48 00 3E 99 */	bl fn_80254134
/* 802502A0 0024D0A0  2C 03 00 00 */	cmpwi r3, 0x0
/* 802502A4 0024D0A4  41 82 00 1C */	beq .L_802502C0
/* 802502A8 0024D0A8  80 1F 00 48 */	lwz r0, 0x48(r31)
/* 802502AC 0024D0AC  54 00 07 7B */	rlwinm. r0, r0, 0, 29, 29
/* 802502B0 0024D0B0  41 82 00 10 */	beq .L_802502C0
/* 802502B4 0024D0B4  80 6D 07 EC */	lwz r3, lbl_805DD8CC@sda21(r0)
/* 802502B8 0024D0B8  C0 23 01 BC */	lfs f1, 0x1bc(r3)
/* 802502BC 0024D0BC  48 00 00 0C */	b .L_802502C8
.L_802502C0:
/* 802502C0 0024D0C0  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 802502C4 0024D0C4  C0 23 00 50 */	lfs f1, 0x50(r3)
.L_802502C8:
/* 802502C8 0024D0C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802502CC 0024D0CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802502D0 0024D0D0  7C 08 03 A6 */	mtlr r0
/* 802502D4 0024D0D4  38 21 00 10 */	addi r1, r1, 0x10
/* 802502D8 0024D0D8  4E 80 00 20 */	blr
.endfn kar_itdata_get_param_float_50_with_pickup_override

# .text:0x2A4 | 0x802502DC | size: 0x58
.fn kar_itdata_get_param_float_54_with_pickup_override, global
/* 802502DC 0024D0DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802502E0 0024D0E0  7C 08 02 A6 */	mflr r0
/* 802502E4 0024D0E4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802502E8 0024D0E8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802502EC 0024D0EC  7C 7F 1B 78 */	mr r31, r3
/* 802502F0 0024D0F0  38 60 00 04 */	li r3, 0x4
/* 802502F4 0024D0F4  48 00 3E 41 */	bl fn_80254134
/* 802502F8 0024D0F8  2C 03 00 00 */	cmpwi r3, 0x0
/* 802502FC 0024D0FC  41 82 00 1C */	beq .L_80250318
/* 80250300 0024D100  80 1F 00 48 */	lwz r0, 0x48(r31)
/* 80250304 0024D104  54 00 07 7B */	rlwinm. r0, r0, 0, 29, 29
/* 80250308 0024D108  41 82 00 10 */	beq .L_80250318
/* 8025030C 0024D10C  80 6D 07 EC */	lwz r3, lbl_805DD8CC@sda21(r0)
/* 80250310 0024D110  C0 23 01 C0 */	lfs f1, 0x1c0(r3)
/* 80250314 0024D114  48 00 00 0C */	b .L_80250320
.L_80250318:
/* 80250318 0024D118  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 8025031C 0024D11C  C0 23 00 54 */	lfs f1, 0x54(r3)
.L_80250320:
/* 80250320 0024D120  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250324 0024D124  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80250328 0024D128  7C 08 03 A6 */	mtlr r0
/* 8025032C 0024D12C  38 21 00 10 */	addi r1, r1, 0x10
/* 80250330 0024D130  4E 80 00 20 */	blr
.endfn kar_itdata_get_param_float_54_with_pickup_override

# .text:0x2FC | 0x80250334 | size: 0xC
.fn kar_itdata_get_param_float_58, global
/* 80250334 0024D134  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 80250338 0024D138  C0 23 00 58 */	lfs f1, 0x58(r3)
/* 8025033C 0024D13C  4E 80 00 20 */	blr
.endfn kar_itdata_get_param_float_58

# .text:0x308 | 0x80250340 | size: 0x20
.fn kar_itdata_clear_motion_accel_and_velocity, global
/* 80250340 0024D140  C0 02 C5 80 */	lfs f0, lbl_805E2C80@sda21(r0)
/* 80250344 0024D144  D0 03 00 C0 */	stfs f0, 0xc0(r3)
/* 80250348 0024D148  D0 03 00 BC */	stfs f0, 0xbc(r3)
/* 8025034C 0024D14C  D0 03 00 B8 */	stfs f0, 0xb8(r3)
/* 80250350 0024D150  D0 03 00 CC */	stfs f0, 0xcc(r3)
/* 80250354 0024D154  D0 03 00 C8 */	stfs f0, 0xc8(r3)
/* 80250358 0024D158  D0 03 00 C4 */	stfs f0, 0xc4(r3)
/* 8025035C 0024D15C  4E 80 00 20 */	blr
.endfn kar_itdata_clear_motion_accel_and_velocity

# .text:0x328 | 0x80250360 | size: 0x60
.fn kar_itdata_set_orientation_axes, global
/* 80250360 0024D160  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80250364 0024D164  7C 08 02 A6 */	mflr r0
/* 80250368 0024D168  90 01 00 24 */	stw r0, 0x24(r1)
/* 8025036C 0024D16C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80250370 0024D170  7C 9F 23 78 */	mr r31, r4
/* 80250374 0024D174  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80250378 0024D178  7C 7E 1B 78 */	mr r30, r3
/* 8025037C 0024D17C  7C A3 2B 78 */	mr r3, r5
/* 80250380 0024D180  38 9E 01 0C */	addi r4, r30, 0x10c
/* 80250384 0024D184  4B E1 29 21 */	bl kar_lbvector_normalize_with_axis_fallback
/* 80250388 0024D188  7F E4 FB 78 */	mr r4, r31
/* 8025038C 0024D18C  38 7E 01 0C */	addi r3, r30, 0x10c
/* 80250390 0024D190  38 A1 00 08 */	addi r5, r1, 0x8
/* 80250394 0024D194  4B E1 2A 3D */	bl kar_lbvector_cross_normalize
/* 80250398 0024D198  38 61 00 08 */	addi r3, r1, 0x8
/* 8025039C 0024D19C  38 9E 01 0C */	addi r4, r30, 0x10c
/* 802503A0 0024D1A0  38 BE 01 00 */	addi r5, r30, 0x100
/* 802503A4 0024D1A4  4B E1 2A 2D */	bl kar_lbvector_cross_normalize
/* 802503A8 0024D1A8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802503AC 0024D1AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802503B0 0024D1B0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802503B4 0024D1B4  7C 08 03 A6 */	mtlr r0
/* 802503B8 0024D1B8  38 21 00 20 */	addi r1, r1, 0x20
/* 802503BC 0024D1BC  4E 80 00 20 */	blr
.endfn kar_itdata_set_orientation_axes

# .text:0x388 | 0x802503C0 | size: 0x40
.fn kar_itdata_apply_model_transform, global
/* 802503C0 0024D1C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802503C4 0024D1C4  7C 08 02 A6 */	mflr r0
/* 802503C8 0024D1C8  38 83 01 00 */	addi r4, r3, 0x100
/* 802503CC 0024D1CC  38 A3 01 0C */	addi r5, r3, 0x10c
/* 802503D0 0024D1D0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802503D4 0024D1D4  38 C3 00 DC */	addi r6, r3, 0xdc
/* 802503D8 0024D1D8  C0 23 00 AC */	lfs f1, 0xac(r3)
/* 802503DC 0024D1DC  C0 03 01 18 */	lfs f0, 0x118(r3)
/* 802503E0 0024D1E0  80 E3 00 00 */	lwz r7, 0x0(r3)
/* 802503E4 0024D1E4  EC 21 00 32 */	fmuls f1, f1, f0
/* 802503E8 0024D1E8  80 67 00 28 */	lwz r3, 0x28(r7)
/* 802503EC 0024D1EC  4B E0 40 29 */	bl kar_gmlanmenu__near_80054414
/* 802503F0 0024D1F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802503F4 0024D1F4  7C 08 03 A6 */	mtlr r0
/* 802503F8 0024D1F8  38 21 00 10 */	addi r1, r1, 0x10
/* 802503FC 0024D1FC  4E 80 00 20 */	blr
.endfn kar_itdata_apply_model_transform

# .text:0x3C8 | 0x80250400 | size: 0x18
.fn kar_itdata_clamp_fall_speed, global
/* 80250400 0024D200  FC 20 08 50 */	fneg f1, f1
/* 80250404 0024D204  C0 03 00 C8 */	lfs f0, 0xc8(r3)
/* 80250408 0024D208  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8025040C 0024D20C  4C 80 00 20 */	bgelr
/* 80250410 0024D210  D0 23 00 C8 */	stfs f1, 0xc8(r3)
/* 80250414 0024D214  4E 80 00 20 */	blr
.endfn kar_itdata_clamp_fall_speed

# .text:0x3E0 | 0x80250418 | size: 0x184
.fn kar_itdata_rotate_orientation_axes, global
/* 80250418 0024D218  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8025041C 0024D21C  7C 08 02 A6 */	mflr r0
/* 80250420 0024D220  90 01 00 64 */	stw r0, 0x64(r1)
/* 80250424 0024D224  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 80250428 0024D228  F3 E1 00 58 */	psq_st f31, 0x58(r1), 0, qr0
/* 8025042C 0024D22C  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 80250430 0024D230  FF E0 08 90 */	fmr f31, f1
/* 80250434 0024D234  2C 04 00 00 */	cmpwi r4, 0x0
/* 80250438 0024D238  7C 7F 1B 78 */	mr r31, r3
/* 8025043C 0024D23C  40 82 00 6C */	bne .L_802504A8
/* 80250440 0024D240  80 DF 01 0C */	lwz r6, 0x10c(r31)
/* 80250444 0024D244  38 7F 01 0C */	addi r3, r31, 0x10c
/* 80250448 0024D248  80 1F 01 10 */	lwz r0, 0x110(r31)
/* 8025044C 0024D24C  38 9F 01 00 */	addi r4, r31, 0x100
/* 80250450 0024D250  38 A1 00 2C */	addi r5, r1, 0x2c
/* 80250454 0024D254  90 C1 00 38 */	stw r6, 0x38(r1)
/* 80250458 0024D258  90 01 00 3C */	stw r0, 0x3c(r1)
/* 8025045C 0024D25C  80 1F 01 14 */	lwz r0, 0x114(r31)
/* 80250460 0024D260  90 01 00 40 */	stw r0, 0x40(r1)
/* 80250464 0024D264  4B E1 29 6D */	bl kar_lbvector_cross_normalize
/* 80250468 0024D268  FC 20 F8 90 */	fmr f1, f31
/* 8025046C 0024D26C  38 61 00 38 */	addi r3, r1, 0x38
/* 80250470 0024D270  38 81 00 2C */	addi r4, r1, 0x2c
/* 80250474 0024D274  4B E1 34 85 */	bl kar_lbvector_rotate_about_axis
/* 80250478 0024D278  38 61 00 38 */	addi r3, r1, 0x38
/* 8025047C 0024D27C  38 9F 01 0C */	addi r4, r31, 0x10c
/* 80250480 0024D280  4B E1 28 25 */	bl kar_lbvector_normalize_with_axis_fallback
/* 80250484 0024D284  38 7F 01 0C */	addi r3, r31, 0x10c
/* 80250488 0024D288  38 9F 01 00 */	addi r4, r31, 0x100
/* 8025048C 0024D28C  38 A1 00 20 */	addi r5, r1, 0x20
/* 80250490 0024D290  4B E1 29 41 */	bl kar_lbvector_cross_normalize
/* 80250494 0024D294  38 61 00 20 */	addi r3, r1, 0x20
/* 80250498 0024D298  38 9F 01 0C */	addi r4, r31, 0x10c
/* 8025049C 0024D29C  38 BF 01 00 */	addi r5, r31, 0x100
/* 802504A0 0024D2A0  4B E1 29 31 */	bl kar_lbvector_cross_normalize
/* 802504A4 0024D2A4  48 00 00 B8 */	b .L_8025055C
.L_802504A8:
/* 802504A8 0024D2A8  2C 04 00 01 */	cmpwi r4, 0x1
/* 802504AC 0024D2AC  40 82 00 58 */	bne .L_80250504
/* 802504B0 0024D2B0  80 BF 01 00 */	lwz r5, 0x100(r31)
/* 802504B4 0024D2B4  38 61 00 38 */	addi r3, r1, 0x38
/* 802504B8 0024D2B8  80 1F 01 04 */	lwz r0, 0x104(r31)
/* 802504BC 0024D2BC  38 9F 01 0C */	addi r4, r31, 0x10c
/* 802504C0 0024D2C0  90 A1 00 38 */	stw r5, 0x38(r1)
/* 802504C4 0024D2C4  90 01 00 3C */	stw r0, 0x3c(r1)
/* 802504C8 0024D2C8  80 1F 01 08 */	lwz r0, 0x108(r31)
/* 802504CC 0024D2CC  90 01 00 40 */	stw r0, 0x40(r1)
/* 802504D0 0024D2D0  4B E1 34 29 */	bl kar_lbvector_rotate_about_axis
/* 802504D4 0024D2D4  38 7F 01 0C */	addi r3, r31, 0x10c
/* 802504D8 0024D2D8  7C 64 1B 78 */	mr r4, r3
/* 802504DC 0024D2DC  4B E1 27 C9 */	bl kar_lbvector_normalize_with_axis_fallback
/* 802504E0 0024D2E0  38 7F 01 0C */	addi r3, r31, 0x10c
/* 802504E4 0024D2E4  38 81 00 38 */	addi r4, r1, 0x38
/* 802504E8 0024D2E8  38 A1 00 14 */	addi r5, r1, 0x14
/* 802504EC 0024D2EC  4B E1 28 E5 */	bl kar_lbvector_cross_normalize
/* 802504F0 0024D2F0  38 61 00 14 */	addi r3, r1, 0x14
/* 802504F4 0024D2F4  38 9F 01 0C */	addi r4, r31, 0x10c
/* 802504F8 0024D2F8  38 BF 01 00 */	addi r5, r31, 0x100
/* 802504FC 0024D2FC  4B E1 28 D5 */	bl kar_lbvector_cross_normalize
/* 80250500 0024D300  48 00 00 5C */	b .L_8025055C
.L_80250504:
/* 80250504 0024D304  2C 04 00 02 */	cmpwi r4, 0x2
/* 80250508 0024D308  40 82 00 54 */	bne .L_8025055C
/* 8025050C 0024D30C  80 BF 01 0C */	lwz r5, 0x10c(r31)
/* 80250510 0024D310  38 61 00 38 */	addi r3, r1, 0x38
/* 80250514 0024D314  80 1F 01 10 */	lwz r0, 0x110(r31)
/* 80250518 0024D318  38 9F 01 00 */	addi r4, r31, 0x100
/* 8025051C 0024D31C  90 A1 00 38 */	stw r5, 0x38(r1)
/* 80250520 0024D320  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80250524 0024D324  80 1F 01 14 */	lwz r0, 0x114(r31)
/* 80250528 0024D328  90 01 00 40 */	stw r0, 0x40(r1)
/* 8025052C 0024D32C  4B E1 33 CD */	bl kar_lbvector_rotate_about_axis
/* 80250530 0024D330  38 61 00 38 */	addi r3, r1, 0x38
/* 80250534 0024D334  38 9F 01 0C */	addi r4, r31, 0x10c
/* 80250538 0024D338  4B E1 27 6D */	bl kar_lbvector_normalize_with_axis_fallback
/* 8025053C 0024D33C  38 7F 01 0C */	addi r3, r31, 0x10c
/* 80250540 0024D340  38 9F 01 00 */	addi r4, r31, 0x100
/* 80250544 0024D344  38 A1 00 08 */	addi r5, r1, 0x8
/* 80250548 0024D348  4B E1 28 89 */	bl kar_lbvector_cross_normalize
/* 8025054C 0024D34C  38 61 00 08 */	addi r3, r1, 0x8
/* 80250550 0024D350  38 9F 01 0C */	addi r4, r31, 0x10c
/* 80250554 0024D354  38 BF 01 00 */	addi r5, r31, 0x100
/* 80250558 0024D358  4B E1 28 79 */	bl kar_lbvector_cross_normalize
.L_8025055C:
/* 8025055C 0024D35C  C0 3F 00 AC */	lfs f1, 0xac(r31)
/* 80250560 0024D360  38 9F 01 00 */	addi r4, r31, 0x100
/* 80250564 0024D364  C0 1F 01 18 */	lfs f0, 0x118(r31)
/* 80250568 0024D368  38 BF 01 0C */	addi r5, r31, 0x10c
/* 8025056C 0024D36C  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 80250570 0024D370  38 DF 00 DC */	addi r6, r31, 0xdc
/* 80250574 0024D374  EC 21 00 32 */	fmuls f1, f1, f0
/* 80250578 0024D378  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8025057C 0024D37C  4B E0 3E 99 */	bl kar_gmlanmenu__near_80054414
/* 80250580 0024D380  E3 E1 00 58 */	psq_l f31, 0x58(r1), 0, qr0
/* 80250584 0024D384  80 01 00 64 */	lwz r0, 0x64(r1)
/* 80250588 0024D388  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 8025058C 0024D38C  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 80250590 0024D390  7C 08 03 A6 */	mtlr r0
/* 80250594 0024D394  38 21 00 60 */	addi r1, r1, 0x60
/* 80250598 0024D398  4E 80 00 20 */	blr
.endfn kar_itdata_rotate_orientation_axes

# .text:0x564 | 0x8025059C | size: 0x15C
.fn kar_itdata_try_update_orientation_from_normals, global
/* 8025059C 0024D39C  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 802505A0 0024D3A0  7C 08 02 A6 */	mflr r0
/* 802505A4 0024D3A4  90 01 00 54 */	stw r0, 0x54(r1)
/* 802505A8 0024D3A8  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 802505AC 0024D3AC  F3 E1 00 48 */	psq_st f31, 0x48(r1), 0, qr0
/* 802505B0 0024D3B0  39 61 00 40 */	addi r11, r1, 0x40
/* 802505B4 0024D3B4  48 15 D5 A1 */	bl _savegpr_27
/* 802505B8 0024D3B8  7C 7B 1B 78 */	mr r27, r3
/* 802505BC 0024D3BC  7C BD 2B 78 */	mr r29, r5
/* 802505C0 0024D3C0  C0 43 00 AC */	lfs f2, 0xac(r3)
/* 802505C4 0024D3C4  7C 9C 23 78 */	mr r28, r4
/* 802505C8 0024D3C8  C0 23 01 18 */	lfs f1, 0x118(r3)
/* 802505CC 0024D3CC  7C DE 33 78 */	mr r30, r6
/* 802505D0 0024D3D0  C0 65 00 04 */	lfs f3, 0x4(r5)
/* 802505D4 0024D3D4  3B E0 00 01 */	li r31, 0x1
/* 802505D8 0024D3D8  C0 02 C5 80 */	lfs f0, lbl_805E2C80@sda21(r0)
/* 802505DC 0024D3DC  EF E2 00 72 */	fmuls f31, f2, f1
/* 802505E0 0024D3E0  FC 03 00 40 */	fcmpo cr0, f3, f0
/* 802505E4 0024D3E4  40 80 00 08 */	bge .L_802505EC
/* 802505E8 0024D3E8  FC 60 18 50 */	fneg f3, f3
.L_802505EC:
/* 802505EC 0024D3EC  C0 3E 00 04 */	lfs f1, 0x4(r30)
/* 802505F0 0024D3F0  C0 02 C5 80 */	lfs f0, lbl_805E2C80@sda21(r0)
/* 802505F4 0024D3F4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802505F8 0024D3F8  40 80 00 08 */	bge .L_80250600
/* 802505FC 0024D3FC  FC 20 08 50 */	fneg f1, f1
.L_80250600:
/* 80250600 0024D400  FC 01 18 00 */	fcmpu cr0, f1, f3
/* 80250604 0024D404  40 82 00 0C */	bne .L_80250610
/* 80250608 0024D408  3B E0 00 00 */	li r31, 0x0
/* 8025060C 0024D40C  48 00 00 C8 */	b .L_802506D4
.L_80250610:
/* 80250610 0024D410  7F A3 EB 78 */	mr r3, r29
/* 80250614 0024D414  7F C4 F3 78 */	mr r4, r30
/* 80250618 0024D418  38 A1 00 08 */	addi r5, r1, 0x8
/* 8025061C 0024D41C  4B E1 27 B5 */	bl kar_lbvector_cross_normalize
/* 80250620 0024D420  28 1C 00 00 */	cmplwi r28, 0x0
/* 80250624 0024D424  40 82 00 14 */	bne .L_80250638
/* 80250628 0024D428  38 6D A2 A0 */	li r3, kar_srcfile_jobj_h_805d7380@sda21
/* 8025062C 0024D42C  38 80 03 E4 */	li r4, 0x3e4
/* 80250630 0024D430  38 AD A2 A8 */	li r5, lbl_805D7388@sda21
/* 80250634 0024D434  48 1D 7E 85 */	bl __assert
.L_80250638:
/* 80250638 0024D438  80 DC 00 38 */	lwz r6, 0x38(r28)
/* 8025063C 0024D43C  FC 20 F8 90 */	fmr f1, f31
/* 80250640 0024D440  80 1C 00 3C */	lwz r0, 0x3c(r28)
/* 80250644 0024D444  7F 83 E3 78 */	mr r3, r28
/* 80250648 0024D448  7F C4 F3 78 */	mr r4, r30
/* 8025064C 0024D44C  7F A5 EB 78 */	mr r5, r29
/* 80250650 0024D450  90 C1 00 14 */	stw r6, 0x14(r1)
/* 80250654 0024D454  38 C1 00 14 */	addi r6, r1, 0x14
/* 80250658 0024D458  90 01 00 18 */	stw r0, 0x18(r1)
/* 8025065C 0024D45C  C0 41 00 14 */	lfs f2, 0x14(r1)
/* 80250660 0024D460  80 1C 00 40 */	lwz r0, 0x40(r28)
/* 80250664 0024D464  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 80250668 0024D468  EC 82 07 F2 */	fmuls f4, f2, f31
/* 8025066C 0024D46C  90 01 00 1C */	stw r0, 0x1c(r1)
/* 80250670 0024D470  EC 60 07 F2 */	fmuls f3, f0, f31
/* 80250674 0024D474  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 80250678 0024D478  D0 81 00 14 */	stfs f4, 0x14(r1)
/* 8025067C 0024D47C  EC 40 07 F2 */	fmuls f2, f0, f31
/* 80250680 0024D480  D0 61 00 18 */	stfs f3, 0x18(r1)
/* 80250684 0024D484  D0 41 00 1C */	stfs f2, 0x1c(r1)
/* 80250688 0024D488  C0 1B 00 DC */	lfs f0, 0xdc(r27)
/* 8025068C 0024D48C  EC 80 20 2A */	fadds f4, f0, f4
/* 80250690 0024D490  D0 81 00 14 */	stfs f4, 0x14(r1)
/* 80250694 0024D494  C0 1B 00 E0 */	lfs f0, 0xe0(r27)
/* 80250698 0024D498  EC 60 18 2A */	fadds f3, f0, f3
/* 8025069C 0024D49C  D0 61 00 18 */	stfs f3, 0x18(r1)
/* 802506A0 0024D4A0  C0 1B 00 E4 */	lfs f0, 0xe4(r27)
/* 802506A4 0024D4A4  EC 40 10 2A */	fadds f2, f0, f2
/* 802506A8 0024D4A8  D0 41 00 1C */	stfs f2, 0x1c(r1)
/* 802506AC 0024D4AC  C0 1B 00 C4 */	lfs f0, 0xc4(r27)
/* 802506B0 0024D4B0  EC 00 20 2A */	fadds f0, f0, f4
/* 802506B4 0024D4B4  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 802506B8 0024D4B8  C0 1B 00 C8 */	lfs f0, 0xc8(r27)
/* 802506BC 0024D4BC  EC 00 18 2A */	fadds f0, f0, f3
/* 802506C0 0024D4C0  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 802506C4 0024D4C4  C0 1B 00 CC */	lfs f0, 0xcc(r27)
/* 802506C8 0024D4C8  EC 00 10 2A */	fadds f0, f0, f2
/* 802506CC 0024D4CC  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 802506D0 0024D4D0  4B E0 3D 45 */	bl kar_gmlanmenu__near_80054414
.L_802506D4:
/* 802506D4 0024D4D4  7F E3 FB 78 */	mr r3, r31
/* 802506D8 0024D4D8  E3 E1 00 48 */	psq_l f31, 0x48(r1), 0, qr0
/* 802506DC 0024D4DC  39 61 00 40 */	addi r11, r1, 0x40
/* 802506E0 0024D4E0  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 802506E4 0024D4E4  48 15 D4 BD */	bl _restgpr_27
/* 802506E8 0024D4E8  80 01 00 54 */	lwz r0, 0x54(r1)
/* 802506EC 0024D4EC  7C 08 03 A6 */	mtlr r0
/* 802506F0 0024D4F0  38 21 00 50 */	addi r1, r1, 0x50
/* 802506F4 0024D4F4  4E 80 00 20 */	blr
.endfn kar_itdata_try_update_orientation_from_normals

# .text:0x6C0 | 0x802506F8 | size: 0x90
.fn kar_itdata_clear_jobj_billboard_flags, global
/* 802506F8 0024D4F8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802506FC 0024D4FC  7C 08 02 A6 */	mflr r0
/* 80250700 0024D500  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250704 0024D504  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80250708 0024D508  7C 9F 23 79 */	mr. r31, r4
/* 8025070C 0024D50C  40 82 00 14 */	bne .L_80250720
/* 80250710 0024D510  38 6D A2 A0 */	li r3, kar_srcfile_jobj_h_805d7380@sda21
/* 80250714 0024D514  38 80 04 AF */	li r4, 0x4af
/* 80250718 0024D518  38 AD A2 A8 */	li r5, lbl_805D7388@sda21
/* 8025071C 0024D51C  48 1D 7D 9D */	bl __assert
.L_80250720:
/* 80250720 0024D520  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80250724 0024D524  28 1F 00 00 */	cmplwi r31, 0x0
/* 80250728 0024D528  54 00 02 4A */	rlwinm r0, r0, 0, 9, 5
/* 8025072C 0024D52C  90 1F 00 14 */	stw r0, 0x14(r31)
/* 80250730 0024D530  41 82 00 44 */	beq .L_80250774
/* 80250734 0024D534  40 82 00 14 */	bne .L_80250748
/* 80250738 0024D538  38 6D A2 A0 */	li r3, kar_srcfile_jobj_h_805d7380@sda21
/* 8025073C 0024D53C  38 80 02 5D */	li r4, 0x25d
/* 80250740 0024D540  38 AD A2 A8 */	li r5, lbl_805D7388@sda21
/* 80250744 0024D544  48 1D 7D 75 */	bl __assert
.L_80250748:
/* 80250748 0024D548  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 8025074C 0024D54C  38 60 00 00 */	li r3, 0x0
/* 80250750 0024D550  54 80 02 11 */	rlwinm. r0, r4, 0, 8, 8
/* 80250754 0024D554  40 82 00 10 */	bne .L_80250764
/* 80250758 0024D558  54 80 06 73 */	rlwinm. r0, r4, 0, 25, 25
/* 8025075C 0024D55C  41 82 00 08 */	beq .L_80250764
/* 80250760 0024D560  38 60 00 01 */	li r3, 0x1
.L_80250764:
/* 80250764 0024D564  2C 03 00 00 */	cmpwi r3, 0x0
/* 80250768 0024D568  40 82 00 0C */	bne .L_80250774
/* 8025076C 0024D56C  7F E3 FB 78 */	mr r3, r31
/* 80250770 0024D570  48 1B D1 BD */	bl HSD_JObjSetMtxDirtySub
.L_80250774:
/* 80250774 0024D574  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250778 0024D578  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8025077C 0024D57C  7C 08 03 A6 */	mtlr r0
/* 80250780 0024D580  38 21 00 10 */	addi r1, r1, 0x10
/* 80250784 0024D584  4E 80 00 20 */	blr
.endfn kar_itdata_clear_jobj_billboard_flags

# .text:0x750 | 0x80250788 | size: 0x94
.fn kar_itdata_distance_between_points, global
/* 80250788 0024D588  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8025078C 0024D58C  C0 23 00 04 */	lfs f1, 0x4(r3)
/* 80250790 0024D590  C0 04 00 04 */	lfs f0, 0x4(r4)
/* 80250794 0024D594  C0 63 00 00 */	lfs f3, 0x0(r3)
/* 80250798 0024D598  EC 21 00 28 */	fsubs f1, f1, f0
/* 8025079C 0024D59C  C0 04 00 00 */	lfs f0, 0x0(r4)
/* 802507A0 0024D5A0  C0 43 00 08 */	lfs f2, 0x8(r3)
/* 802507A4 0024D5A4  EC 63 00 28 */	fsubs f3, f3, f0
/* 802507A8 0024D5A8  C0 04 00 08 */	lfs f0, 0x8(r4)
/* 802507AC 0024D5AC  EC 21 00 72 */	fmuls f1, f1, f1
/* 802507B0 0024D5B0  EC 42 00 28 */	fsubs f2, f2, f0
/* 802507B4 0024D5B4  C0 02 C5 80 */	lfs f0, lbl_805E2C80@sda21(r0)
/* 802507B8 0024D5B8  EC 23 08 FA */	fmadds f1, f3, f3, f1
/* 802507BC 0024D5BC  EC 22 08 BA */	fmadds f1, f2, f2, f1
/* 802507C0 0024D5C0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802507C4 0024D5C4  40 81 00 50 */	ble .L_80250814
/* 802507C8 0024D5C8  FC 40 08 34 */	frsqrte f2, f1
/* 802507CC 0024D5CC  C8 82 C5 88 */	lfd f4, lbl_805E2C88@sda21(r0)
/* 802507D0 0024D5D0  C8 62 C5 90 */	lfd f3, lbl_805E2C90@sda21(r0)
/* 802507D4 0024D5D4  FC 02 00 B2 */	fmul f0, f2, f2
/* 802507D8 0024D5D8  FC 44 00 B2 */	fmul f2, f4, f2
/* 802507DC 0024D5DC  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 802507E0 0024D5E0  FC 42 00 32 */	fmul f2, f2, f0
/* 802507E4 0024D5E4  FC 02 00 B2 */	fmul f0, f2, f2
/* 802507E8 0024D5E8  FC 44 00 B2 */	fmul f2, f4, f2
/* 802507EC 0024D5EC  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 802507F0 0024D5F0  FC 42 00 32 */	fmul f2, f2, f0
/* 802507F4 0024D5F4  FC 02 00 B2 */	fmul f0, f2, f2
/* 802507F8 0024D5F8  FC 44 00 B2 */	fmul f2, f4, f2
/* 802507FC 0024D5FC  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 80250800 0024D600  FC 02 00 32 */	fmul f0, f2, f0
/* 80250804 0024D604  FC 01 00 32 */	fmul f0, f1, f0
/* 80250808 0024D608  FC 00 00 18 */	frsp f0, f0
/* 8025080C 0024D60C  D0 01 00 08 */	stfs f0, 0x8(r1)
/* 80250810 0024D610  C0 21 00 08 */	lfs f1, 0x8(r1)
.L_80250814:
/* 80250814 0024D614  38 21 00 10 */	addi r1, r1, 0x10
/* 80250818 0024D618  4E 80 00 20 */	blr
.endfn kar_itdata_distance_between_points

# .text:0x7E4 | 0x8025081C | size: 0x24
.fn kar_itdata_show_model_all, global
/* 8025081C 0024D61C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250820 0024D620  7C 08 02 A6 */	mflr r0
/* 80250824 0024D624  38 80 00 10 */	li r4, 0x10
/* 80250828 0024D628  90 01 00 14 */	stw r0, 0x14(r1)
/* 8025082C 0024D62C  48 1B B9 49 */	bl HSD_JObjClearFlagsAll
/* 80250830 0024D630  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250834 0024D634  7C 08 03 A6 */	mtlr r0
/* 80250838 0024D638  38 21 00 10 */	addi r1, r1, 0x10
/* 8025083C 0024D63C  4E 80 00 20 */	blr
.endfn kar_itdata_show_model_all

# .text:0x808 | 0x80250840 | size: 0x24
.fn kar_itdata_hide_model_all, global
/* 80250840 0024D640  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250844 0024D644  7C 08 02 A6 */	mflr r0
/* 80250848 0024D648  38 80 00 10 */	li r4, 0x10
/* 8025084C 0024D64C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250850 0024D650  48 1B B5 B1 */	bl HSD_JObjSetFlagsAll
/* 80250854 0024D654  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250858 0024D658  7C 08 03 A6 */	mtlr r0
/* 8025085C 0024D65C  38 21 00 10 */	addi r1, r1, 0x10
/* 80250860 0024D660  4E 80 00 20 */	blr
.endfn kar_itdata_hide_model_all

# .text:0x82C | 0x80250864 | size: 0x2C
.fn kar_itdata_clear_blink_state, global
/* 80250864 0024D664  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250868 0024D668  7C 08 02 A6 */	mflr r0
/* 8025086C 0024D66C  38 80 00 00 */	li r4, 0x0
/* 80250870 0024D670  38 63 01 D8 */	addi r3, r3, 0x1d8
/* 80250874 0024D674  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250878 0024D678  38 A0 00 0C */	li r5, 0xc
/* 8025087C 0024D67C  4B DB 28 85 */	bl memset
/* 80250880 0024D680  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250884 0024D684  7C 08 03 A6 */	mtlr r0
/* 80250888 0024D688  38 21 00 10 */	addi r1, r1, 0x10
/* 8025088C 0024D68C  4E 80 00 20 */	blr
.endfn kar_itdata_clear_blink_state

# .text:0x858 | 0x80250890 | size: 0xB0
.fn kar_itdata_tick_blink_visibility, global
/* 80250890 0024D690  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250894 0024D694  7C 08 02 A6 */	mflr r0
/* 80250898 0024D698  90 01 00 14 */	stw r0, 0x14(r1)
/* 8025089C 0024D69C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802508A0 0024D6A0  7C 7F 1B 78 */	mr r31, r3
/* 802508A4 0024D6A4  80 03 00 00 */	lwz r0, 0x0(r3)
/* 802508A8 0024D6A8  28 00 00 00 */	cmplwi r0, 0x0
/* 802508AC 0024D6AC  41 82 00 7C */	beq .L_80250928
/* 802508B0 0024D6B0  88 1F 01 D9 */	lbz r0, 0x1d9(r31)
/* 802508B4 0024D6B4  7C 00 28 00 */	cmpw r0, r5
/* 802508B8 0024D6B8  41 80 00 0C */	blt .L_802508C4
/* 802508BC 0024D6BC  38 60 00 00 */	li r3, 0x0
/* 802508C0 0024D6C0  48 00 00 6C */	b .L_8025092C
.L_802508C4:
/* 802508C4 0024D6C4  80 7F 01 DC */	lwz r3, 0x1dc(r31)
/* 802508C8 0024D6C8  2C 03 00 00 */	cmpwi r3, 0x0
/* 802508CC 0024D6CC  40 81 00 10 */	ble .L_802508DC
/* 802508D0 0024D6D0  38 03 FF FF */	subi r0, r3, 0x1
/* 802508D4 0024D6D4  90 1F 01 DC */	stw r0, 0x1dc(r31)
/* 802508D8 0024D6D8  48 00 00 50 */	b .L_80250928
.L_802508DC:
/* 802508DC 0024D6DC  90 9F 01 DC */	stw r4, 0x1dc(r31)
/* 802508E0 0024D6E0  88 1F 01 D8 */	lbz r0, 0x1d8(r31)
/* 802508E4 0024D6E4  68 00 00 01 */	xori r0, r0, 0x1
/* 802508E8 0024D6E8  98 1F 01 D8 */	stb r0, 0x1d8(r31)
/* 802508EC 0024D6EC  88 1F 01 D8 */	lbz r0, 0x1d8(r31)
/* 802508F0 0024D6F0  7C 00 07 75 */	extsb. r0, r0
/* 802508F4 0024D6F4  41 82 00 18 */	beq .L_8025090C
/* 802508F8 0024D6F8  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 802508FC 0024D6FC  38 80 00 10 */	li r4, 0x10
/* 80250900 0024D700  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80250904 0024D704  48 1B B8 71 */	bl HSD_JObjClearFlagsAll
/* 80250908 0024D708  48 00 00 20 */	b .L_80250928
.L_8025090C:
/* 8025090C 0024D70C  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 80250910 0024D710  38 80 00 10 */	li r4, 0x10
/* 80250914 0024D714  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80250918 0024D718  48 1B B4 E9 */	bl HSD_JObjSetFlagsAll
/* 8025091C 0024D71C  88 7F 01 D9 */	lbz r3, 0x1d9(r31)
/* 80250920 0024D720  38 03 00 01 */	addi r0, r3, 0x1
/* 80250924 0024D724  98 1F 01 D9 */	stb r0, 0x1d9(r31)
.L_80250928:
/* 80250928 0024D728  38 60 00 01 */	li r3, 0x1
.L_8025092C:
/* 8025092C 0024D72C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250930 0024D730  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80250934 0024D734  7C 08 03 A6 */	mtlr r0
/* 80250938 0024D738  38 21 00 10 */	addi r1, r1, 0x10
/* 8025093C 0024D73C  4E 80 00 20 */	blr
.endfn kar_itdata_tick_blink_visibility

# .text:0x908 | 0x80250940 | size: 0x14
.fn kar_itdata_set_state_358_bit7, global
/* 80250940 0024D740  88 03 03 58 */	lbz r0, 0x358(r3)
/* 80250944 0024D744  38 80 00 01 */	li r4, 0x1
/* 80250948 0024D748  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 8025094C 0024D74C  98 03 03 58 */	stb r0, 0x358(r3)
/* 80250950 0024D750  4E 80 00 20 */	blr
.endfn kar_itdata_set_state_358_bit7

# .text:0x91C | 0x80250954 | size: 0x24
.fn kar_itdata_release_box_generator_slot, global
/* 80250954 0024D754  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80250958 0024D758  7C 08 02 A6 */	mflr r0
/* 8025095C 0024D75C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80250960 0024D760  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80250964 0024D764  4B E9 BD F1 */	bl kar_grboxgenerator__near_800ec754
/* 80250968 0024D768  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8025096C 0024D76C  7C 08 03 A6 */	mtlr r0
/* 80250970 0024D770  38 21 00 10 */	addi r1, r1, 0x10
/* 80250974 0024D774  4E 80 00 20 */	blr
.endfn kar_itdata_release_box_generator_slot

# .text:0x940 | 0x80250978 | size: 0x14
.fn kar_itdata_set_despawn_pause_flag, global
/* 80250978 0024D778  88 03 03 59 */	lbz r0, 0x359(r3)
/* 8025097C 0024D77C  38 80 00 01 */	li r4, 0x1
/* 80250980 0024D780  50 80 0F BC */	rlwimi r0, r4, 1, 30, 30
/* 80250984 0024D784  98 03 03 59 */	stb r0, 0x359(r3)
/* 80250988 0024D788  4E 80 00 20 */	blr
.endfn kar_itdata_set_despawn_pause_flag

# .text:0x954 | 0x8025098C | size: 0x14
.fn kar_itdata_clear_despawn_pause_flag, global
/* 8025098C 0024D78C  88 03 03 59 */	lbz r0, 0x359(r3)
/* 80250990 0024D790  38 80 00 00 */	li r4, 0x0
/* 80250994 0024D794  50 80 0F BC */	rlwimi r0, r4, 1, 30, 30
/* 80250998 0024D798  98 03 03 59 */	stb r0, 0x359(r3)
/* 8025099C 0024D79C  4E 80 00 20 */	blr
.endfn kar_itdata_clear_despawn_pause_flag

# .text:0x968 | 0x802509A0 | size: 0x148
.fn kar_itdata_build_spawn_request, global
/* 802509A0 0024D7A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802509A4 0024D7A4  7C 08 02 A6 */	mflr r0
/* 802509A8 0024D7A8  28 07 00 00 */	cmplwi r7, 0x0
/* 802509AC 0024D7AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 802509B0 0024D7B0  81 61 00 18 */	lwz r11, 0x18(r1)
/* 802509B4 0024D7B4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802509B8 0024D7B8  7C 7F 1B 78 */	mr r31, r3
/* 802509BC 0024D7BC  90 A3 00 08 */	stw r5, 0x8(r3)
/* 802509C0 0024D7C0  80 A1 00 1C */	lwz r5, 0x1c(r1)
/* 802509C4 0024D7C4  90 83 00 04 */	stw r4, 0x4(r3)
/* 802509C8 0024D7C8  80 81 00 20 */	lwz r4, 0x20(r1)
/* 802509CC 0024D7CC  C0 06 00 00 */	lfs f0, 0x0(r6)
/* 802509D0 0024D7D0  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 802509D4 0024D7D4  80 61 00 24 */	lwz r3, 0x24(r1)
/* 802509D8 0024D7D8  C0 06 00 04 */	lfs f0, 0x4(r6)
/* 802509DC 0024D7DC  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 802509E0 0024D7E0  C0 06 00 08 */	lfs f0, 0x8(r6)
/* 802509E4 0024D7E4  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 802509E8 0024D7E8  41 82 00 1C */	beq .L_80250A04
/* 802509EC 0024D7EC  C0 07 00 00 */	lfs f0, 0x0(r7)
/* 802509F0 0024D7F0  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 802509F4 0024D7F4  C0 07 00 04 */	lfs f0, 0x4(r7)
/* 802509F8 0024D7F8  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 802509FC 0024D7FC  C0 07 00 08 */	lfs f0, 0x8(r7)
/* 80250A00 0024D800  D0 1F 00 2C */	stfs f0, 0x2c(r31)
.L_80250A04:
/* 80250A04 0024D804  28 08 00 00 */	cmplwi r8, 0x0
/* 80250A08 0024D808  41 82 00 1C */	beq .L_80250A24
/* 80250A0C 0024D80C  C0 08 00 00 */	lfs f0, 0x0(r8)
/* 80250A10 0024D810  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 80250A14 0024D814  C0 08 00 04 */	lfs f0, 0x4(r8)
/* 80250A18 0024D818  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 80250A1C 0024D81C  C0 08 00 08 */	lfs f0, 0x8(r8)
/* 80250A20 0024D820  D0 1F 00 20 */	stfs f0, 0x20(r31)
.L_80250A24:
/* 80250A24 0024D824  D0 3F 00 30 */	stfs f1, 0x30(r31)
/* 80250A28 0024D828  38 00 00 00 */	li r0, 0x0
/* 80250A2C 0024D82C  91 3F 00 40 */	stw r9, 0x40(r31)
/* 80250A30 0024D830  91 5F 00 44 */	stw r10, 0x44(r31)
/* 80250A34 0024D834  91 7F 00 50 */	stw r11, 0x50(r31)
/* 80250A38 0024D838  90 9F 00 38 */	stw r4, 0x38(r31)
/* 80250A3C 0024D83C  90 7F 00 3C */	stw r3, 0x3c(r31)
/* 80250A40 0024D840  90 BF 00 4C */	stw r5, 0x4c(r31)
/* 80250A44 0024D844  90 1F 00 00 */	stw r0, 0x0(r31)
/* 80250A48 0024D848  4B FF DB C5 */	bl kar_itdata_get_spawned_item_total
/* 80250A4C 0024D84C  90 7F 00 34 */	stw r3, 0x34(r31)
/* 80250A50 0024D850  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 80250A54 0024D854  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80250A58 0024D858  2C 03 00 00 */	cmpwi r3, 0x0
/* 80250A5C 0024D85C  41 82 00 10 */	beq .L_80250A6C
/* 80250A60 0024D860  48 1C DC 09 */	bl HSD_Randi
/* 80250A64 0024D864  90 7F 00 48 */	stw r3, 0x48(r31)
/* 80250A68 0024D868  48 00 00 0C */	b .L_80250A74
.L_80250A6C:
/* 80250A6C 0024D86C  38 00 00 00 */	li r0, 0x0
/* 80250A70 0024D870  90 1F 00 48 */	stw r0, 0x48(r31)
.L_80250A74:
/* 80250A74 0024D874  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 80250A78 0024D878  38 00 00 00 */	li r0, 0x0
/* 80250A7C 0024D87C  80 9F 00 48 */	lwz r4, 0x48(r31)
/* 80250A80 0024D880  80 63 00 24 */	lwz r3, 0x24(r3)
/* 80250A84 0024D884  7C 64 1A 14 */	add r3, r4, r3
/* 80250A88 0024D888  90 7F 00 48 */	stw r3, 0x48(r31)
/* 80250A8C 0024D88C  90 1F 00 54 */	stw r0, 0x54(r31)
/* 80250A90 0024D890  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 80250A94 0024D894  2C 03 00 37 */	cmpwi r3, 0x37
/* 80250A98 0024D898  41 80 00 14 */	blt .L_80250AAC
/* 80250A9C 0024D89C  2C 03 00 3C */	cmpwi r3, 0x3c
/* 80250AA0 0024D8A0  41 81 00 0C */	bgt .L_80250AAC
/* 80250AA4 0024D8A4  90 1F 00 58 */	stw r0, 0x58(r31)
/* 80250AA8 0024D8A8  48 00 00 2C */	b .L_80250AD4
.L_80250AAC:
/* 80250AAC 0024D8AC  38 60 00 04 */	li r3, 0x4
/* 80250AB0 0024D8B0  48 00 36 85 */	bl fn_80254134
/* 80250AB4 0024D8B4  2C 03 00 00 */	cmpwi r3, 0x0
/* 80250AB8 0024D8B8  41 82 00 14 */	beq .L_80250ACC
/* 80250ABC 0024D8BC  80 1F 00 58 */	lwz r0, 0x58(r31)
/* 80250AC0 0024D8C0  60 00 00 04 */	ori r0, r0, 0x4
/* 80250AC4 0024D8C4  90 1F 00 58 */	stw r0, 0x58(r31)
/* 80250AC8 0024D8C8  48 00 00 0C */	b .L_80250AD4
.L_80250ACC:
/* 80250ACC 0024D8CC  38 00 00 00 */	li r0, 0x0
/* 80250AD0 0024D8D0  90 1F 00 58 */	stw r0, 0x58(r31)
.L_80250AD4:
/* 80250AD4 0024D8D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80250AD8 0024D8D8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80250ADC 0024D8DC  7C 08 03 A6 */	mtlr r0
/* 80250AE0 0024D8E0  38 21 00 10 */	addi r1, r1, 0x10
/* 80250AE4 0024D8E4  4E 80 00 20 */	blr
.endfn kar_itdata_build_spawn_request

# .text:0xAB0 | 0x80250AE8 | size: 0x36C
.fn kar_itdata_spawn_item_part_bursts, global
/* 80250AE8 0024D8E8  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 80250AEC 0024D8EC  7C 08 02 A6 */	mflr r0
/* 80250AF0 0024D8F0  90 01 00 94 */	stw r0, 0x94(r1)
/* 80250AF4 0024D8F4  DB E1 00 80 */	stfd f31, 0x80(r1)
/* 80250AF8 0024D8F8  F3 E1 00 88 */	psq_st f31, 0x88(r1), 0, qr0
/* 80250AFC 0024D8FC  DB C1 00 70 */	stfd f30, 0x70(r1)
/* 80250B00 0024D900  F3 C1 00 78 */	psq_st f30, 0x78(r1), 0, qr0
/* 80250B04 0024D904  39 61 00 70 */	addi r11, r1, 0x70
/* 80250B08 0024D908  48 15 D0 45 */	bl _savegpr_25
/* 80250B0C 0024D90C  7C 79 1B 78 */	mr r25, r3
/* 80250B10 0024D910  38 80 00 01 */	li r4, 0x1
/* 80250B14 0024D914  80 63 00 00 */	lwz r3, 0x0(r3)
/* 80250B18 0024D918  4B E0 4F D9 */	bl kar_lbairride__near_80055af0
/* 80250B1C 0024D91C  3C 80 80 49 */	lis r4, lbl_80489F48@ha
/* 80250B20 0024D920  38 A1 00 24 */	addi r5, r1, 0x24
/* 80250B24 0024D924  39 24 9F 48 */	addi r9, r4, lbl_80489F48@l
/* 80250B28 0024D928  38 80 00 00 */	li r4, 0x0
/* 80250B2C 0024D92C  81 09 00 00 */	lwz r8, 0x0(r9)
/* 80250B30 0024D930  80 E9 00 04 */	lwz r7, 0x4(r9)
/* 80250B34 0024D934  80 C9 00 08 */	lwz r6, 0x8(r9)
/* 80250B38 0024D938  80 09 00 0C */	lwz r0, 0xc(r9)
/* 80250B3C 0024D93C  91 01 00 14 */	stw r8, 0x14(r1)
/* 80250B40 0024D940  90 E1 00 18 */	stw r7, 0x18(r1)
/* 80250B44 0024D944  90 C1 00 1C */	stw r6, 0x1c(r1)
/* 80250B48 0024D948  90 01 00 20 */	stw r0, 0x20(r1)
/* 80250B4C 0024D94C  4B E0 33 E9 */	bl kar_gmlanmenu__near_80053f34
/* 80250B50 0024D950  80 19 00 24 */	lwz r0, 0x24(r25)
/* 80250B54 0024D954  2C 00 00 00 */	cmpwi r0, 0x0
/* 80250B58 0024D958  40 82 00 1C */	bne .L_80250B74
/* 80250B5C 0024D95C  80 19 03 5C */	lwz r0, 0x35c(r25)
/* 80250B60 0024D960  2C 00 FF FF */	cmpwi r0, -0x1
/* 80250B64 0024D964  41 82 00 10 */	beq .L_80250B74
/* 80250B68 0024D968  7C 1D 03 78 */	mr r29, r0
/* 80250B6C 0024D96C  3B 40 00 01 */	li r26, 0x1
/* 80250B70 0024D970  48 00 00 68 */	b .L_80250BD8
.L_80250B74:
/* 80250B74 0024D974  80 79 00 3C */	lwz r3, 0x3c(r25)
/* 80250B78 0024D978  38 80 FF FF */	li r4, -0x1
/* 80250B7C 0024D97C  38 A0 00 06 */	li r5, 0x6
/* 80250B80 0024D980  4B E9 AC 65 */	bl kar_grboxgenerator__near_800eb7e4
/* 80250B84 0024D984  7C 7D 1B 78 */	mr r29, r3
/* 80250B88 0024D988  2C 1D 00 03 */	cmpwi r29, 0x3
/* 80250B8C 0024D98C  41 80 00 0C */	blt .L_80250B98
/* 80250B90 0024D990  2C 1D 00 12 */	cmpwi r29, 0x12
/* 80250B94 0024D994  40 81 00 14 */	ble .L_80250BA8
.L_80250B98:
/* 80250B98 0024D998  38 60 00 10 */	li r3, 0x10
/* 80250B9C 0024D99C  48 00 35 99 */	bl fn_80254134
/* 80250BA0 0024D9A0  2C 03 00 00 */	cmpwi r3, 0x0
/* 80250BA4 0024D9A4  41 82 00 30 */	beq .L_80250BD4
.L_80250BA8:
/* 80250BA8 0024D9A8  80 19 00 40 */	lwz r0, 0x40(r25)
/* 80250BAC 0024D9AC  2C 00 00 01 */	cmpwi r0, 0x1
/* 80250BB0 0024D9B0  40 82 00 0C */	bne .L_80250BBC
/* 80250BB4 0024D9B4  3B 40 00 02 */	li r26, 0x2
/* 80250BB8 0024D9B8  48 00 00 20 */	b .L_80250BD8
.L_80250BBC:
/* 80250BBC 0024D9BC  2C 00 00 02 */	cmpwi r0, 0x2
/* 80250BC0 0024D9C0  40 82 00 0C */	bne .L_80250BCC
/* 80250BC4 0024D9C4  3B 40 00 04 */	li r26, 0x4
/* 80250BC8 0024D9C8  48 00 00 10 */	b .L_80250BD8
.L_80250BCC:
/* 80250BCC 0024D9CC  3B 40 00 01 */	li r26, 0x1
/* 80250BD0 0024D9D0  48 00 00 08 */	b .L_80250BD8
.L_80250BD4:
/* 80250BD4 0024D9D4  3B 40 00 01 */	li r26, 0x1
.L_80250BD8:
/* 80250BD8 0024D9D8  38 79 00 08 */	addi r3, r25, 0x8
/* 80250BDC 0024D9DC  38 80 00 00 */	li r4, 0x0
/* 80250BE0 0024D9E0  38 A0 00 10 */	li r5, 0x10
/* 80250BE4 0024D9E4  4B DB 25 1D */	bl memset
/* 80250BE8 0024D9E8  2C 1D FF FF */	cmpwi r29, -0x1
/* 80250BEC 0024D9EC  41 82 02 40 */	beq .L_80250E2C
/* 80250BF0 0024D9F0  C3 E2 C5 80 */	lfs f31, lbl_805E2C80@sda21(r0)
/* 80250BF4 0024D9F4  7F 3E CB 78 */	mr r30, r25
/* 80250BF8 0024D9F8  3B E1 00 14 */	addi r31, r1, 0x14
/* 80250BFC 0024D9FC  3B 60 00 00 */	li r27, 0x0
/* 80250C00 0024DA00  48 00 02 24 */	b .L_80250E24
.L_80250C04:
/* 80250C04 0024DA04  80 99 01 00 */	lwz r4, 0x100(r25)
/* 80250C08 0024DA08  38 60 00 01 */	li r3, 0x1
/* 80250C0C 0024DA0C  80 19 01 04 */	lwz r0, 0x104(r25)
/* 80250C10 0024DA10  90 81 00 08 */	stw r4, 0x8(r1)
/* 80250C14 0024DA14  90 01 00 0C */	stw r0, 0xc(r1)
/* 80250C18 0024DA18  80 19 01 08 */	lwz r0, 0x108(r25)
/* 80250C1C 0024DA1C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80250C20 0024DA20  48 00 21 21 */	bl kar_itparts_can_spawn_more_items
/* 80250C24 0024DA24  2C 03 00 00 */	cmpwi r3, 0x0
/* 80250C28 0024DA28  41 82 02 04 */	beq .L_80250E2C
/* 80250C2C 0024DA2C  C0 1F 00 00 */	lfs f0, 0x0(r31)
/* 80250C30 0024DA30  FC 00 F8 00 */	fcmpu cr0, f0, f31
/* 80250C34 0024DA34  41 82 00 6C */	beq .L_80250CA0
/* 80250C38 0024DA38  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 80250C3C 0024DA3C  C0 03 00 40 */	lfs f0, 0x40(r3)
/* 80250C40 0024DA40  FC 00 00 1E */	fctiwz f0, f0
/* 80250C44 0024DA44  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 80250C48 0024DA48  80 61 00 34 */	lwz r3, 0x34(r1)
/* 80250C4C 0024DA4C  48 1C DA 1D */	bl HSD_Randi
/* 80250C50 0024DA50  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80250C54 0024DA54  3C 00 43 30 */	lis r0, 0x4330
/* 80250C58 0024DA58  90 61 00 3C */	stw r3, 0x3c(r1)
/* 80250C5C 0024DA5C  38 60 00 02 */	li r3, 0x2
/* 80250C60 0024DA60  C8 22 C5 A0 */	lfd f1, lbl_805E2CA0@sda21(r0)
/* 80250C64 0024DA64  90 01 00 38 */	stw r0, 0x38(r1)
/* 80250C68 0024DA68  C8 01 00 38 */	lfd f0, 0x38(r1)
/* 80250C6C 0024DA6C  EF C0 08 28 */	fsubs f30, f0, f1
/* 80250C70 0024DA70  48 1C D9 F9 */	bl HSD_Randi
/* 80250C74 0024DA74  2C 03 00 00 */	cmpwi r3, 0x0
/* 80250C78 0024DA78  41 82 00 0C */	beq .L_80250C84
/* 80250C7C 0024DA7C  C0 02 C5 84 */	lfs f0, lbl_805E2C84@sda21(r0)
/* 80250C80 0024DA80  EF DE 00 32 */	fmuls f30, f30, f0
.L_80250C84:
/* 80250C84 0024DA84  C0 1F 00 00 */	lfs f0, 0x0(r31)
/* 80250C88 0024DA88  38 61 00 08 */	addi r3, r1, 0x8
/* 80250C8C 0024DA8C  C0 22 C5 98 */	lfs f1, lbl_805E2C98@sda21(r0)
/* 80250C90 0024DA90  38 99 01 0C */	addi r4, r25, 0x10c
/* 80250C94 0024DA94  EC 1E 00 2A */	fadds f0, f30, f0
/* 80250C98 0024DA98  EC 21 00 32 */	fmuls f1, f1, f0
/* 80250C9C 0024DA9C  4B E1 2C 5D */	bl kar_lbvector_rotate_about_axis
.L_80250CA0:
/* 80250CA0 0024DAA0  2C 1B 00 00 */	cmpwi r27, 0x0
/* 80250CA4 0024DAA4  41 82 00 14 */	beq .L_80250CB8
/* 80250CA8 0024DAA8  38 60 00 10 */	li r3, 0x10
/* 80250CAC 0024DAAC  48 00 34 89 */	bl fn_80254134
/* 80250CB0 0024DAB0  2C 03 00 00 */	cmpwi r3, 0x0
/* 80250CB4 0024DAB4  41 82 00 0C */	beq .L_80250CC0
.L_80250CB8:
/* 80250CB8 0024DAB8  7F BC EB 78 */	mr r28, r29
/* 80250CBC 0024DABC  48 00 00 14 */	b .L_80250CD0
.L_80250CC0:
/* 80250CC0 0024DAC0  7F A3 EB 78 */	mr r3, r29
/* 80250CC4 0024DAC4  38 80 00 06 */	li r4, 0x6
/* 80250CC8 0024DAC8  4B E9 AD A9 */	bl kar_grboxgenerator__near_800eba70
/* 80250CCC 0024DACC  7C 7C 1B 78 */	mr r28, r3
.L_80250CD0:
/* 80250CD0 0024DAD0  2C 1C FF FF */	cmpwi r28, -0x1
/* 80250CD4 0024DAD4  41 82 01 44 */	beq .L_80250E18
/* 80250CD8 0024DAD8  2C 1A 00 01 */	cmpwi r26, 0x1
/* 80250CDC 0024DADC  40 82 00 70 */	bne .L_80250D4C
/* 80250CE0 0024DAE0  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 80250CE4 0024DAE4  C0 23 00 34 */	lfs f1, 0x34(r3)
/* 80250CE8 0024DAE8  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80250CEC 0024DAEC  EC 01 00 28 */	fsubs f0, f1, f0
/* 80250CF0 0024DAF0  FC 00 00 1E */	fctiwz f0, f0
/* 80250CF4 0024DAF4  D8 01 00 38 */	stfd f0, 0x38(r1)
/* 80250CF8 0024DAF8  80 61 00 3C */	lwz r3, 0x3c(r1)
/* 80250CFC 0024DAFC  48 1C D9 6D */	bl HSD_Randi
/* 80250D00 0024DB00  3C 00 43 30 */	lis r0, 0x4330
/* 80250D04 0024DB04  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80250D08 0024DB08  90 61 00 34 */	stw r3, 0x34(r1)
/* 80250D0C 0024DB0C  7F 83 E3 78 */	mr r3, r28
/* 80250D10 0024DB10  80 8D 07 E8 */	lwz r4, lbl_805DD8C8@sda21(r0)
/* 80250D14 0024DB14  38 A1 00 24 */	addi r5, r1, 0x24
/* 80250D18 0024DB18  90 01 00 30 */	stw r0, 0x30(r1)
/* 80250D1C 0024DB1C  38 C1 00 08 */	addi r6, r1, 0x8
/* 80250D20 0024DB20  C8 22 C5 A0 */	lfd f1, lbl_805E2CA0@sda21(r0)
/* 80250D24 0024DB24  38 E0 00 00 */	li r7, 0x0
/* 80250D28 0024DB28  C8 01 00 30 */	lfd f0, 0x30(r1)
/* 80250D2C 0024DB2C  C0 64 00 30 */	lfs f3, 0x30(r4)
/* 80250D30 0024DB30  38 80 00 02 */	li r4, 0x2
/* 80250D34 0024DB34  EC 00 08 28 */	fsubs f0, f0, f1
/* 80250D38 0024DB38  C0 42 C5 9C */	lfs f2, lbl_805E2C9C@sda21(r0)
/* 80250D3C 0024DB3C  EC 23 00 2A */	fadds f1, f3, f0
/* 80250D40 0024DB40  48 00 26 39 */	bl kar_itparts_spawn_burst_throw_item
/* 80250D44 0024DB44  90 7E 00 08 */	stw r3, 0x8(r30)
/* 80250D48 0024DB48  48 00 00 B8 */	b .L_80250E00
.L_80250D4C:
/* 80250D4C 0024DB4C  80 6D 07 E8 */	lwz r3, lbl_805DD8C8@sda21(r0)
/* 80250D50 0024DB50  C0 23 00 34 */	lfs f1, 0x34(r3)
/* 80250D54 0024DB54  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80250D58 0024DB58  EC 01 00 28 */	fsubs f0, f1, f0
/* 80250D5C 0024DB5C  FC 00 00 1E */	fctiwz f0, f0
/* 80250D60 0024DB60  D8 01 00 38 */	stfd f0, 0x38(r1)
/* 80250D64 0024DB64  80 61 00 3C */	lwz r3, 0x3c(r1)
/* 80250D68 0024DB68  48 1C D9 01 */	bl HSD_Randi
/* 80250D6C 0024DB6C  80 8D 07 E8 */	lwz r4, lbl_805DD8C8@sda21(r0)
/* 80250D70 0024DB70  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80250D74 0024DB74  3C 00 43 30 */	lis r0, 0x4330
/* 80250D78 0024DB78  90 61 00 34 */	stw r3, 0x34(r1)
/* 80250D7C 0024DB7C  C0 24 00 3C */	lfs f1, 0x3c(r4)
/* 80250D80 0024DB80  C0 04 00 38 */	lfs f0, 0x38(r4)
/* 80250D84 0024DB84  90 01 00 30 */	stw r0, 0x30(r1)
/* 80250D88 0024DB88  EC 01 00 28 */	fsubs f0, f1, f0
/* 80250D8C 0024DB8C  C8 42 C5 A0 */	lfd f2, lbl_805E2CA0@sda21(r0)
/* 80250D90 0024DB90  C8 21 00 30 */	lfd f1, 0x30(r1)
/* 80250D94 0024DB94  C0 64 00 30 */	lfs f3, 0x30(r4)
/* 80250D98 0024DB98  FC 00 00 1E */	fctiwz f0, f0
/* 80250D9C 0024DB9C  EC 21 10 28 */	fsubs f1, f1, f2
/* 80250DA0 0024DBA0  D8 01 00 40 */	stfd f0, 0x40(r1)
/* 80250DA4 0024DBA4  EF C3 08 2A */	fadds f30, f3, f1
/* 80250DA8 0024DBA8  80 61 00 44 */	lwz r3, 0x44(r1)
/* 80250DAC 0024DBAC  48 1C D8 BD */	bl HSD_Randi
/* 80250DB0 0024DBB0  3C 00 43 30 */	lis r0, 0x4330
/* 80250DB4 0024DBB4  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80250DB8 0024DBB8  90 61 00 4C */	stw r3, 0x4c(r1)
/* 80250DBC 0024DBBC  FC 20 F0 90 */	fmr f1, f30
/* 80250DC0 0024DBC0  80 8D 07 E8 */	lwz r4, lbl_805DD8C8@sda21(r0)
/* 80250DC4 0024DBC4  7F 83 E3 78 */	mr r3, r28
/* 80250DC8 0024DBC8  90 01 00 48 */	stw r0, 0x48(r1)
/* 80250DCC 0024DBCC  38 A1 00 24 */	addi r5, r1, 0x24
/* 80250DD0 0024DBD0  C8 42 C5 A0 */	lfd f2, lbl_805E2CA0@sda21(r0)
/* 80250DD4 0024DBD4  C8 01 00 48 */	lfd f0, 0x48(r1)
/* 80250DD8 0024DBD8  38 C1 00 08 */	addi r6, r1, 0x8
/* 80250DDC 0024DBDC  C0 64 00 38 */	lfs f3, 0x38(r4)
/* 80250DE0 0024DBE0  38 80 00 02 */	li r4, 0x2
/* 80250DE4 0024DBE4  EC 00 10 28 */	fsubs f0, f0, f2
/* 80250DE8 0024DBE8  C0 82 C5 98 */	lfs f4, lbl_805E2C98@sda21(r0)
/* 80250DEC 0024DBEC  38 E0 00 01 */	li r7, 0x1
/* 80250DF0 0024DBF0  EC 03 00 2A */	fadds f0, f3, f0
/* 80250DF4 0024DBF4  EC 44 00 32 */	fmuls f2, f4, f0
/* 80250DF8 0024DBF8  48 00 25 81 */	bl kar_itparts_spawn_burst_throw_item
/* 80250DFC 0024DBFC  90 7E 00 08 */	stw r3, 0x8(r30)
.L_80250E00:
/* 80250E00 0024DC00  80 7E 00 08 */	lwz r3, 0x8(r30)
/* 80250E04 0024DC04  28 03 00 00 */	cmplwi r3, 0x0
/* 80250E08 0024DC08  41 82 00 10 */	beq .L_80250E18
/* 80250E0C 0024DC0C  80 19 00 00 */	lwz r0, 0x0(r25)
/* 80250E10 0024DC10  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 80250E14 0024DC14  90 03 00 04 */	stw r0, 0x4(r3)
.L_80250E18:
/* 80250E18 0024DC18  3B FF 00 04 */	addi r31, r31, 0x4
/* 80250E1C 0024DC1C  3B DE 00 04 */	addi r30, r30, 0x4
/* 80250E20 0024DC20  3B 7B 00 01 */	addi r27, r27, 0x1
.L_80250E24:
/* 80250E24 0024DC24  7C 1B D0 00 */	cmpw r27, r26
/* 80250E28 0024DC28  41 80 FD DC */	blt .L_80250C04
.L_80250E2C:
/* 80250E2C 0024DC2C  E3 E1 00 88 */	psq_l f31, 0x88(r1), 0, qr0
/* 80250E30 0024DC30  CB E1 00 80 */	lfd f31, 0x80(r1)
/* 80250E34 0024DC34  E3 C1 00 78 */	psq_l f30, 0x78(r1), 0, qr0
/* 80250E38 0024DC38  39 61 00 70 */	addi r11, r1, 0x70
/* 80250E3C 0024DC3C  CB C1 00 70 */	lfd f30, 0x70(r1)
/* 80250E40 0024DC40  48 15 CD 59 */	bl _restgpr_25
/* 80250E44 0024DC44  80 01 00 94 */	lwz r0, 0x94(r1)
/* 80250E48 0024DC48  7C 08 03 A6 */	mtlr r0
/* 80250E4C 0024DC4C  38 21 00 90 */	addi r1, r1, 0x90
/* 80250E50 0024DC50  4E 80 00 20 */	blr
.endfn kar_itdata_spawn_item_part_bursts

# .text:0xE1C | 0x80250E54 | size: 0x14
.fn kar_itdata_set_state_35b_bit7, global
/* 80250E54 0024DC54  88 03 03 5B */	lbz r0, 0x35b(r3)
/* 80250E58 0024DC58  38 80 00 01 */	li r4, 0x1
/* 80250E5C 0024DC5C  50 80 3E 30 */	rlwimi r0, r4, 7, 24, 24
/* 80250E60 0024DC60  98 03 03 5B */	stb r0, 0x35b(r3)
/* 80250E64 0024DC64  4E 80 00 20 */	blr
.endfn kar_itdata_set_state_35b_bit7

# .text:0xE30 | 0x80250E68 | size: 0x8
.fn kar_itdata_set_aux_handle_field_218, global
/* 80250E68 0024DC68  90 83 02 18 */	stw r4, 0x218(r3)
/* 80250E6C 0024DC6C  4E 80 00 20 */	blr
.endfn kar_itdata_set_aux_handle_field_218

# .text:0xE38 | 0x80250E70 | size: 0x1D4
.fn kar_itdata_apply_translucent_material_to_model, global
/* 80250E70 0024DC70  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80250E74 0024DC74  7C 08 02 A6 */	mflr r0
/* 80250E78 0024DC78  90 01 00 24 */	stw r0, 0x24(r1)
/* 80250E7C 0024DC7C  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 80250E80 0024DC80  FF E0 08 90 */	fmr f31, f1
/* 80250E84 0024DC84  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80250E88 0024DC88  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80250E8C 0024DC8C  7C 7E 1B 78 */	mr r30, r3
/* 80250E90 0024DC90  48 00 01 90 */	b .L_80251020
.L_80250E94:
/* 80250E94 0024DC94  7F C3 F3 78 */	mr r3, r30
/* 80250E98 0024DC98  48 1B AE B5 */	bl HSD_JObjGetFlags
/* 80250E9C 0024DC9C  54 60 00 47 */	rlwinm. r0, r3, 0, 1, 3
/* 80250EA0 0024DCA0  41 82 00 1C */	beq .L_80250EBC
/* 80250EA4 0024DCA4  7F C3 F3 78 */	mr r3, r30
/* 80250EA8 0024DCA8  3C 80 70 00 */	lis r4, 0x7000
/* 80250EAC 0024DCAC  48 1B B2 2D */	bl HSD_JObjClearFlags
/* 80250EB0 0024DCB0  7F C3 F3 78 */	mr r3, r30
/* 80250EB4 0024DCB4  3C 80 20 00 */	lis r4, 0x2000
/* 80250EB8 0024DCB8  48 1B AE AD */	bl HSD_JObjSetFlags
.L_80250EBC:
/* 80250EBC 0024DCBC  7F C3 F3 78 */	mr r3, r30
/* 80250EC0 0024DCC0  48 1B AE 8D */	bl HSD_JObjGetFlags
/* 80250EC4 0024DCC4  54 60 02 DB */	rlwinm. r0, r3, 0, 11, 13
/* 80250EC8 0024DCC8  41 82 00 1C */	beq .L_80250EE4
/* 80250ECC 0024DCCC  7F C3 F3 78 */	mr r3, r30
/* 80250ED0 0024DCD0  3C 80 00 1C */	lis r4, 0x1c
/* 80250ED4 0024DCD4  48 1B B2 05 */	bl HSD_JObjClearFlags
/* 80250ED8 0024DCD8  7F C3 F3 78 */	mr r3, r30
/* 80250EDC 0024DCDC  3C 80 00 08 */	lis r4, 0x8
/* 80250EE0 0024DCE0  48 1B AE 85 */	bl HSD_JObjSetFlags
.L_80250EE4:
/* 80250EE4 0024DCE4  83 FE 00 18 */	lwz r31, 0x18(r30)
/* 80250EE8 0024DCE8  48 00 01 18 */	b .L_80251000
.L_80250EEC:
/* 80250EEC 0024DCEC  7F E3 FB 78 */	mr r3, r31
/* 80250EF0 0024DCF0  38 80 00 0A */	li r4, 0xa
/* 80250EF4 0024DCF4  48 1A 35 1D */	bl HSD_DObjClearFlags
/* 80250EF8 0024DCF8  7F E3 FB 78 */	mr r3, r31
/* 80250EFC 0024DCFC  38 80 00 04 */	li r4, 0x4
/* 80250F00 0024DD00  48 1A 34 F9 */	bl HSD_DObjSetFlags
/* 80250F04 0024DD04  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F08 0024DD08  28 03 00 00 */	cmplwi r3, 0x0
/* 80250F0C 0024DD0C  41 82 00 F0 */	beq .L_80250FFC
/* 80250F10 0024DD10  3C 80 28 00 */	lis r4, 0x2800
/* 80250F14 0024DD14  48 1A 89 C9 */	bl HSD_MObjSetCurrent
/* 80250F18 0024DD18  3C 80 40 00 */	lis r4, 0x4000
/* 80250F1C 0024DD1C  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F20 0024DD20  38 84 20 00 */	addi r4, r4, 0x2000
/* 80250F24 0024DD24  48 1A 89 A1 */	bl _HSD_StateInvalidateTexCoordGen
/* 80250F28 0024DD28  FC 20 F8 90 */	fmr f1, f31
/* 80250F2C 0024DD2C  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F30 0024DD30  48 1A 9E 51 */	bl HSD_MObjSetAlpha
/* 80250F34 0024DD34  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F38 0024DD38  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250F3C 0024DD3C  28 03 00 00 */	cmplwi r3, 0x0
/* 80250F40 0024DD40  41 82 00 84 */	beq .L_80250FC4
/* 80250F44 0024DD44  38 00 00 33 */	li r0, 0x33
/* 80250F48 0024DD48  39 00 00 01 */	li r8, 0x1
/* 80250F4C 0024DD4C  98 03 00 00 */	stb r0, 0x0(r3)
/* 80250F50 0024DD50  38 E0 00 04 */	li r7, 0x4
/* 80250F54 0024DD54  38 C0 00 05 */	li r6, 0x5
/* 80250F58 0024DD58  38 A0 00 00 */	li r5, 0x0
/* 80250F5C 0024DD5C  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F60 0024DD60  38 80 00 FF */	li r4, 0xff
/* 80250F64 0024DD64  38 00 00 03 */	li r0, 0x3
/* 80250F68 0024DD68  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250F6C 0024DD6C  99 03 00 04 */	stb r8, 0x4(r3)
/* 80250F70 0024DD70  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F74 0024DD74  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250F78 0024DD78  98 E3 00 05 */	stb r7, 0x5(r3)
/* 80250F7C 0024DD7C  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F80 0024DD80  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250F84 0024DD84  98 C3 00 06 */	stb r6, 0x6(r3)
/* 80250F88 0024DD88  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F8C 0024DD8C  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250F90 0024DD90  98 A3 00 01 */	stb r5, 0x1(r3)
/* 80250F94 0024DD94  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250F98 0024DD98  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250F9C 0024DD9C  98 83 00 02 */	stb r4, 0x2(r3)
/* 80250FA0 0024DDA0  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250FA4 0024DDA4  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250FA8 0024DDA8  98 A3 00 0A */	stb r5, 0xa(r3)
/* 80250FAC 0024DDAC  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250FB0 0024DDB0  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250FB4 0024DDB4  98 E3 00 09 */	stb r7, 0x9(r3)
/* 80250FB8 0024DDB8  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250FBC 0024DDBC  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80250FC0 0024DDC0  98 03 00 0B */	stb r0, 0xb(r3)
.L_80250FC4:
/* 80250FC4 0024DDC4  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250FC8 0024DDC8  80 63 00 08 */	lwz r3, 0x8(r3)
/* 80250FCC 0024DDCC  48 00 00 20 */	b .L_80250FEC
.L_80250FD0:
/* 80250FD0 0024DDD0  80 03 00 4C */	lwz r0, 0x4c(r3)
/* 80250FD4 0024DDD4  54 00 03 0E */	rlwinm r0, r0, 0, 12, 7
/* 80250FD8 0024DDD8  90 03 00 4C */	stw r0, 0x4c(r3)
/* 80250FDC 0024DDDC  80 03 00 4C */	lwz r0, 0x4c(r3)
/* 80250FE0 0024DDE0  64 00 00 30 */	oris r0, r0, 0x30
/* 80250FE4 0024DDE4  90 03 00 4C */	stw r0, 0x4c(r3)
/* 80250FE8 0024DDE8  80 63 00 08 */	lwz r3, 0x8(r3)
.L_80250FEC:
/* 80250FEC 0024DDEC  28 03 00 00 */	cmplwi r3, 0x0
/* 80250FF0 0024DDF0  40 82 FF E0 */	bne .L_80250FD0
/* 80250FF4 0024DDF4  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 80250FF8 0024DDF8  48 1A 9A 89 */	bl HSD_MObjCompileTev
.L_80250FFC:
/* 80250FFC 0024DDFC  83 FF 00 04 */	lwz r31, 0x4(r31)
.L_80251000:
/* 80251000 0024DE00  28 1F 00 00 */	cmplwi r31, 0x0
/* 80251004 0024DE04  40 82 FE E8 */	bne .L_80250EEC
/* 80251008 0024DE08  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 8025100C 0024DE0C  28 03 00 00 */	cmplwi r3, 0x0
/* 80251010 0024DE10  41 82 00 0C */	beq .L_8025101C
/* 80251014 0024DE14  FC 20 F8 90 */	fmr f1, f31
/* 80251018 0024DE18  4B FF FE 59 */	bl kar_itdata_apply_translucent_material_to_model
.L_8025101C:
/* 8025101C 0024DE1C  83 DE 00 08 */	lwz r30, 0x8(r30)
.L_80251020:
/* 80251020 0024DE20  28 1E 00 00 */	cmplwi r30, 0x0
/* 80251024 0024DE24  40 82 FE 70 */	bne .L_80250E94
/* 80251028 0024DE28  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8025102C 0024DE2C  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 80251030 0024DE30  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80251034 0024DE34  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80251038 0024DE38  7C 08 03 A6 */	mtlr r0
/* 8025103C 0024DE3C  38 21 00 20 */	addi r1, r1, 0x20
/* 80251040 0024DE40  4E 80 00 20 */	blr
.endfn kar_itdata_apply_translucent_material_to_model

# .text:0x100C | 0x80251044 | size: 0x64
.fn kar_itdata_begin_model_fade_in, global
/* 80251044 0024DE44  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80251048 0024DE48  7C 08 02 A6 */	mflr r0
/* 8025104C 0024DE4C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80251050 0024DE50  DB E1 00 10 */	stfd f31, 0x10(r1)
/* 80251054 0024DE54  F3 E1 00 18 */	psq_st f31, 0x18(r1), 0, qr0
/* 80251058 0024DE58  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8025105C 0024DE5C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80251060 0024DE60  7C 7E 1B 78 */	mr r30, r3
/* 80251064 0024DE64  FF E0 08 90 */	fmr f31, f1
/* 80251068 0024DE68  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8025106C 0024DE6C  48 00 1C 3D */	bl kar_itparts_show_model_and_clear_hidden_flag
/* 80251070 0024DE70  C0 02 C5 80 */	lfs f0, lbl_805E2C80@sda21(r0)
/* 80251074 0024DE74  D0 1F 00 B0 */	stfs f0, 0xb0(r31)
/* 80251078 0024DE78  D3 FF 00 B4 */	stfs f31, 0xb4(r31)
/* 8025107C 0024DE7C  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 80251080 0024DE80  C0 3F 00 B0 */	lfs f1, 0xb0(r31)
/* 80251084 0024DE84  4B FF FD ED */	bl kar_itdata_apply_translucent_material_to_model
/* 80251088 0024DE88  E3 E1 00 18 */	psq_l f31, 0x18(r1), 0, qr0
/* 8025108C 0024DE8C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80251090 0024DE90  CB E1 00 10 */	lfd f31, 0x10(r1)
/* 80251094 0024DE94  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80251098 0024DE98  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 8025109C 0024DE9C  7C 08 03 A6 */	mtlr r0
/* 802510A0 0024DEA0  38 21 00 20 */	addi r1, r1, 0x20
/* 802510A4 0024DEA4  4E 80 00 20 */	blr
.endfn kar_itdata_begin_model_fade_in

# .text:0x1070 | 0x802510A8 | size: 0x11C
.fn kar_itdata_tick_model_fade_in, global
/* 802510A8 0024DEA8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802510AC 0024DEAC  7C 08 02 A6 */	mflr r0
/* 802510B0 0024DEB0  C0 02 C5 A8 */	lfs f0, lbl_805E2CA8@sda21(r0)
/* 802510B4 0024DEB4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802510B8 0024DEB8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802510BC 0024DEBC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 802510C0 0024DEC0  7C 7E 1B 78 */	mr r30, r3
/* 802510C4 0024DEC4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 802510C8 0024DEC8  C0 3F 00 B0 */	lfs f1, 0xb0(r31)
/* 802510CC 0024DECC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 802510D0 0024DED0  40 80 00 24 */	bge .L_802510F4
/* 802510D4 0024DED4  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 802510D8 0024DED8  4B FF FD 99 */	bl kar_itdata_apply_translucent_material_to_model
/* 802510DC 0024DEDC  C0 3F 00 B0 */	lfs f1, 0xb0(r31)
/* 802510E0 0024DEE0  38 60 00 01 */	li r3, 0x1
/* 802510E4 0024DEE4  C0 1F 00 B4 */	lfs f0, 0xb4(r31)
/* 802510E8 0024DEE8  EC 01 00 2A */	fadds f0, f1, f0
/* 802510EC 0024DEEC  D0 1F 00 B0 */	stfs f0, 0xb0(r31)
/* 802510F0 0024DEF0  48 00 00 BC */	b .L_802511AC
.L_802510F4:
/* 802510F4 0024DEF4  3C 60 80 56 */	lis r3, lbl_8055DD58@ha
/* 802510F8 0024DEF8  80 9F 00 94 */	lwz r4, 0x94(r31)
/* 802510FC 0024DEFC  38 63 DD 58 */	addi r3, r3, lbl_8055DD58@l
/* 80251100 0024DF00  48 1C 71 35 */	bl HSD_ObjFree
/* 80251104 0024DF04  3C 60 80 56 */	lis r3, lbl_8055DD84@ha
/* 80251108 0024DF08  80 9F 00 9C */	lwz r4, 0x9c(r31)
/* 8025110C 0024DF0C  38 63 DD 84 */	addi r3, r3, lbl_8055DD84@l
/* 80251110 0024DF10  48 1C 71 25 */	bl HSD_ObjFree
/* 80251114 0024DF14  3C 60 80 56 */	lis r3, lbl_8055DDB0@ha
/* 80251118 0024DF18  80 9F 00 A4 */	lwz r4, 0xa4(r31)
/* 8025111C 0024DF1C  38 63 DD B0 */	addi r3, r3, lbl_8055DDB0@l
/* 80251120 0024DF20  48 1C 71 15 */	bl HSD_ObjFree
/* 80251124 0024DF24  7F C3 F3 78 */	mr r3, r30
/* 80251128 0024DF28  48 1D 8B 89 */	bl HSD_GObjObjectRemove
/* 8025112C 0024DF2C  7F E3 FB 78 */	mr r3, r31
/* 80251130 0024DF30  48 00 11 19 */	bl kar_itanim_free_collision_handle
/* 80251134 0024DF34  7F C3 F3 78 */	mr r3, r30
/* 80251138 0024DF38  4B FF DD 21 */	bl kar_itdata_load_model_joint
/* 8025113C 0024DF3C  7F E3 FB 78 */	mr r3, r31
/* 80251140 0024DF40  48 00 13 6D */	bl kar_itanim_alloc_animation_work_buffers
/* 80251144 0024DF44  7F C3 F3 78 */	mr r3, r30
/* 80251148 0024DF48  48 00 13 BD */	bl kar_itparts_collect_model_part_tables
/* 8025114C 0024DF4C  7F C3 F3 78 */	mr r3, r30
/* 80251150 0024DF50  48 00 16 D5 */	bl kar_itparts_init_model_group_visibility
/* 80251154 0024DF54  7F E3 FB 78 */	mr r3, r31
/* 80251158 0024DF58  48 00 10 1D */	bl kar_itanim_create_collision_handle
/* 8025115C 0024DF5C  C0 3F 00 AC */	lfs f1, 0xac(r31)
/* 80251160 0024DF60  38 9F 01 00 */	addi r4, r31, 0x100
/* 80251164 0024DF64  C0 1F 01 18 */	lfs f0, 0x118(r31)
/* 80251168 0024DF68  38 BF 01 0C */	addi r5, r31, 0x10c
/* 8025116C 0024DF6C  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 80251170 0024DF70  38 DF 00 DC */	addi r6, r31, 0xdc
/* 80251174 0024DF74  EC 21 00 32 */	fmuls f1, f1, f0
/* 80251178 0024DF78  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8025117C 0024DF7C  4B E0 32 99 */	bl kar_gmlanmenu__near_80054414
/* 80251180 0024DF80  80 7F 01 48 */	lwz r3, 0x148(r31)
/* 80251184 0024DF84  38 80 00 00 */	li r4, 0x0
/* 80251188 0024DF88  C0 3F 00 AC */	lfs f1, 0xac(r31)
/* 8025118C 0024DF8C  38 C0 00 00 */	li r6, 0x0
/* 80251190 0024DF90  80 BF 01 D4 */	lwz r5, 0x1d4(r31)
/* 80251194 0024DF94  4B F3 B2 21 */	bl kar_collision_object_reset_handle
/* 80251198 0024DF98  80 7F 01 48 */	lwz r3, 0x148(r31)
/* 8025119C 0024DF9C  4B F3 B9 69 */	bl kar_collision_object_begin_disable
/* 802511A0 0024DFA0  7F E3 FB 78 */	mr r3, r31
/* 802511A4 0024DFA4  48 00 19 A5 */	bl kar_itparts_init_pickup_collision_shape
/* 802511A8 0024DFA8  38 60 00 00 */	li r3, 0x0
.L_802511AC:
/* 802511AC 0024DFAC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802511B0 0024DFB0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802511B4 0024DFB4  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 802511B8 0024DFB8  7C 08 03 A6 */	mtlr r0
/* 802511BC 0024DFBC  38 21 00 10 */	addi r1, r1, 0x10
/* 802511C0 0024DFC0  4E 80 00 20 */	blr
.endfn kar_itdata_tick_model_fade_in

# .text:0x118C | 0x802511C4 | size: 0x38
.fn kar_itdata_begin_model_fade_out, global
/* 802511C4 0024DFC4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802511C8 0024DFC8  7C 08 02 A6 */	mflr r0
/* 802511CC 0024DFCC  C0 02 C5 A8 */	lfs f0, lbl_805E2CA8@sda21(r0)
/* 802511D0 0024DFD0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802511D4 0024DFD4  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 802511D8 0024DFD8  D0 04 00 B0 */	stfs f0, 0xb0(r4)
/* 802511DC 0024DFDC  D0 24 00 B4 */	stfs f1, 0xb4(r4)
/* 802511E0 0024DFE0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 802511E4 0024DFE4  C0 24 00 B0 */	lfs f1, 0xb0(r4)
/* 802511E8 0024DFE8  4B FF FC 89 */	bl kar_itdata_apply_translucent_material_to_model
/* 802511EC 0024DFEC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802511F0 0024DFF0  7C 08 03 A6 */	mtlr r0
/* 802511F4 0024DFF4  38 21 00 10 */	addi r1, r1, 0x10
/* 802511F8 0024DFF8  4E 80 00 20 */	blr
.endfn kar_itdata_begin_model_fade_out

# .text:0x11C4 | 0x802511FC | size: 0x60
.fn kar_itdata_tick_model_fade_out, global
/* 802511FC 0024DFFC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80251200 0024E000  7C 08 02 A6 */	mflr r0
/* 80251204 0024E004  C0 02 C5 80 */	lfs f0, lbl_805E2C80@sda21(r0)
/* 80251208 0024E008  90 01 00 14 */	stw r0, 0x14(r1)
/* 8025120C 0024E00C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80251210 0024E010  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80251214 0024E014  C0 3F 00 B0 */	lfs f1, 0xb0(r31)
/* 80251218 0024E018  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8025121C 0024E01C  40 81 00 24 */	ble .L_80251240
/* 80251220 0024E020  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80251224 0024E024  4B FF FC 4D */	bl kar_itdata_apply_translucent_material_to_model
/* 80251228 0024E028  C0 3F 00 B0 */	lfs f1, 0xb0(r31)
/* 8025122C 0024E02C  38 60 00 01 */	li r3, 0x1
/* 80251230 0024E030  C0 1F 00 B4 */	lfs f0, 0xb4(r31)
/* 80251234 0024E034  EC 01 00 28 */	fsubs f0, f1, f0
/* 80251238 0024E038  D0 1F 00 B0 */	stfs f0, 0xb0(r31)
/* 8025123C 0024E03C  48 00 00 0C */	b .L_80251248
.L_80251240:
/* 80251240 0024E040  48 00 1A A9 */	bl kar_itparts_hide_model_and_set_hidden_flag
/* 80251244 0024E044  38 60 00 00 */	li r3, 0x0
.L_80251248:
/* 80251248 0024E048  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8025124C 0024E04C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80251250 0024E050  7C 08 03 A6 */	mtlr r0
/* 80251254 0024E054  38 21 00 10 */	addi r1, r1, 0x10
/* 80251258 0024E058  4E 80 00 20 */	blr
.endfn kar_itdata_tick_model_fade_out

# .text:0x1224 | 0x8025125C | size: 0x38
.fn kar_itdata_alloc_kind_work_data, global
/* 8025125C 0024E05C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80251260 0024E060  7C 08 02 A6 */	mflr r0
/* 80251264 0024E064  3C 80 80 56 */	lis r4, lbl_8055DDDC@ha
/* 80251268 0024E068  90 01 00 14 */	stw r0, 0x14(r1)
/* 8025126C 0024E06C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80251270 0024E070  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80251274 0024E074  38 64 DD DC */	addi r3, r4, lbl_8055DDDC@l
/* 80251278 0024E078  48 1C 6E 6D */	bl HSD_ObjAlloc
/* 8025127C 0024E07C  90 7F 01 44 */	stw r3, 0x144(r31)
/* 80251280 0024E080  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80251284 0024E084  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80251288 0024E088  7C 08 03 A6 */	mtlr r0
/* 8025128C 0024E08C  38 21 00 10 */	addi r1, r1, 0x10
/* 80251290 0024E090  4E 80 00 20 */	blr
.endfn kar_itdata_alloc_kind_work_data

# .text:0x125C | 0x80251294 | size: 0xA8
.fn kar_itdata_load_kind_work_defaults, global
/* 80251294 0024E094  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80251298 0024E098  7C 08 02 A6 */	mflr r0
/* 8025129C 0024E09C  3C 80 80 4B */	lis r4, lbl_804B6088@ha
/* 802512A0 0024E0A0  90 01 00 14 */	stw r0, 0x14(r1)
/* 802512A4 0024E0A4  38 84 60 88 */	addi r4, r4, lbl_804B6088@l
/* 802512A8 0024E0A8  80 E3 00 2C */	lwz r7, 0x2c(r3)
/* 802512AC 0024E0AC  80 A7 00 2C */	lwz r5, 0x2c(r7)
/* 802512B0 0024E0B0  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 802512B4 0024E0B4  80 A6 00 00 */	lwz r5, 0x0(r6)
/* 802512B8 0024E0B8  80 06 00 04 */	lwz r0, 0x4(r6)
/* 802512BC 0024E0BC  90 A7 01 18 */	stw r5, 0x118(r7)
/* 802512C0 0024E0C0  90 07 01 1C */	stw r0, 0x11c(r7)
/* 802512C4 0024E0C4  80 A6 00 08 */	lwz r5, 0x8(r6)
/* 802512C8 0024E0C8  80 06 00 0C */	lwz r0, 0xc(r6)
/* 802512CC 0024E0CC  90 A7 01 20 */	stw r5, 0x120(r7)
/* 802512D0 0024E0D0  90 07 01 24 */	stw r0, 0x124(r7)
/* 802512D4 0024E0D4  80 A6 00 10 */	lwz r5, 0x10(r6)
/* 802512D8 0024E0D8  80 06 00 14 */	lwz r0, 0x14(r6)
/* 802512DC 0024E0DC  90 A7 01 28 */	stw r5, 0x128(r7)
/* 802512E0 0024E0E0  90 07 01 2C */	stw r0, 0x12c(r7)
/* 802512E4 0024E0E4  80 A6 00 18 */	lwz r5, 0x18(r6)
/* 802512E8 0024E0E8  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 802512EC 0024E0EC  90 A7 01 30 */	stw r5, 0x130(r7)
/* 802512F0 0024E0F0  90 07 01 34 */	stw r0, 0x134(r7)
/* 802512F4 0024E0F4  80 A6 00 20 */	lwz r5, 0x20(r6)
/* 802512F8 0024E0F8  80 06 00 24 */	lwz r0, 0x24(r6)
/* 802512FC 0024E0FC  90 A7 01 38 */	stw r5, 0x138(r7)
/* 80251300 0024E100  90 07 01 3C */	stw r0, 0x13c(r7)
/* 80251304 0024E104  80 06 00 28 */	lwz r0, 0x28(r6)
/* 80251308 0024E108  90 07 01 40 */	stw r0, 0x140(r7)
/* 8025130C 0024E10C  80 07 00 1C */	lwz r0, 0x1c(r7)
/* 80251310 0024E110  54 00 10 3A */	slwi r0, r0, 2
/* 80251314 0024E114  7C 84 00 2E */	lwzx r4, r4, r0
/* 80251318 0024E118  81 84 00 0C */	lwz r12, 0xc(r4)
/* 8025131C 0024E11C  28 0C 00 00 */	cmplwi r12, 0x0
/* 80251320 0024E120  41 82 00 0C */	beq .L_8025132C
/* 80251324 0024E124  7D 89 03 A6 */	mtctr r12
/* 80251328 0024E128  4E 80 04 21 */	bctrl
.L_8025132C:
/* 8025132C 0024E12C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80251330 0024E130  7C 08 03 A6 */	mtlr r0
/* 80251334 0024E134  38 21 00 10 */	addi r1, r1, 0x10
/* 80251338 0024E138  4E 80 00 20 */	blr
.endfn kar_itdata_load_kind_work_defaults

# .text:0x1304 | 0x8025133C | size: 0xE8
.fn kar_itdata_load_kind_work_defaults_and_init, global
/* 8025133C 0024E13C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80251340 0024E140  7C 08 02 A6 */	mflr r0
/* 80251344 0024E144  3C 80 80 4B */	lis r4, lbl_804B6088@ha
/* 80251348 0024E148  90 01 00 14 */	stw r0, 0x14(r1)
/* 8025134C 0024E14C  38 84 60 88 */	addi r4, r4, lbl_804B6088@l
/* 80251350 0024E150  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80251354 0024E154  93 C1 00 08 */	stw r30, 0x8(r1)
/* 80251358 0024E158  7C 7E 1B 78 */	mr r30, r3
/* 8025135C 0024E15C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80251360 0024E160  80 BF 00 2C */	lwz r5, 0x2c(r31)
/* 80251364 0024E164  80 C5 00 00 */	lwz r6, 0x0(r5)
/* 80251368 0024E168  80 A6 00 00 */	lwz r5, 0x0(r6)
/* 8025136C 0024E16C  80 06 00 04 */	lwz r0, 0x4(r6)
/* 80251370 0024E170  90 BF 01 18 */	stw r5, 0x118(r31)
/* 80251374 0024E174  90 1F 01 1C */	stw r0, 0x11c(r31)
/* 80251378 0024E178  80 A6 00 08 */	lwz r5, 0x8(r6)
/* 8025137C 0024E17C  80 06 00 0C */	lwz r0, 0xc(r6)
/* 80251380 0024E180  90 BF 01 20 */	stw r5, 0x120(r31)
/* 80251384 0024E184  90 1F 01 24 */	stw r0, 0x124(r31)
/* 80251388 0024E188  80 A6 00 10 */	lwz r5, 0x10(r6)
/* 8025138C 0024E18C  80 06 00 14 */	lwz r0, 0x14(r6)
/* 80251390 0024E190  90 BF 01 28 */	stw r5, 0x128(r31)
/* 80251394 0024E194  90 1F 01 2C */	stw r0, 0x12c(r31)
/* 80251398 0024E198  80 A6 00 18 */	lwz r5, 0x18(r6)
/* 8025139C 0024E19C  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 802513A0 0024E1A0  90 BF 01 30 */	stw r5, 0x130(r31)
/* 802513A4 0024E1A4  90 1F 01 34 */	stw r0, 0x134(r31)
/* 802513A8 0024E1A8  80 A6 00 20 */	lwz r5, 0x20(r6)
/* 802513AC 0024E1AC  80 06 00 24 */	lwz r0, 0x24(r6)
/* 802513B0 0024E1B0  90 BF 01 38 */	stw r5, 0x138(r31)
/* 802513B4 0024E1B4  90 1F 01 3C */	stw r0, 0x13c(r31)
/* 802513B8 0024E1B8  80 06 00 28 */	lwz r0, 0x28(r6)
/* 802513BC 0024E1BC  90 1F 01 40 */	stw r0, 0x140(r31)
/* 802513C0 0024E1C0  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 802513C4 0024E1C4  54 00 10 3A */	slwi r0, r0, 2
/* 802513C8 0024E1C8  7C 84 00 2E */	lwzx r4, r4, r0
/* 802513CC 0024E1CC  81 84 00 0C */	lwz r12, 0xc(r4)
/* 802513D0 0024E1D0  28 0C 00 00 */	cmplwi r12, 0x0
/* 802513D4 0024E1D4  41 82 00 0C */	beq .L_802513E0
/* 802513D8 0024E1D8  7D 89 03 A6 */	mtctr r12
/* 802513DC 0024E1DC  4E 80 04 21 */	bctrl
.L_802513E0:
/* 802513E0 0024E1E0  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 802513E4 0024E1E4  3C 60 80 4B */	lis r3, lbl_804B6088@ha
/* 802513E8 0024E1E8  38 63 60 88 */	addi r3, r3, lbl_804B6088@l
/* 802513EC 0024E1EC  54 00 10 3A */	slwi r0, r0, 2
/* 802513F0 0024E1F0  7C 63 00 2E */	lwzx r3, r3, r0
/* 802513F4 0024E1F4  81 83 00 10 */	lwz r12, 0x10(r3)
/* 802513F8 0024E1F8  28 0C 00 00 */	cmplwi r12, 0x0
/* 802513FC 0024E1FC  41 82 00 10 */	beq .L_8025140C
/* 80251400 0024E200  7F C3 F3 78 */	mr r3, r30
/* 80251404 0024E204  7D 89 03 A6 */	mtctr r12
/* 80251408 0024E208  4E 80 04 21 */	bctrl
.L_8025140C:
/* 8025140C 0024E20C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80251410 0024E210  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80251414 0024E214  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 80251418 0024E218  7C 08 03 A6 */	mtlr r0
/* 8025141C 0024E21C  38 21 00 10 */	addi r1, r1, 0x10
/* 80251420 0024E220  4E 80 00 20 */	blr
.endfn kar_itdata_load_kind_work_defaults_and_init

# .text:0x13EC | 0x80251424 | size: 0x80
.fn kar_itdata_init_kind_work_objalloc, global
/* 80251424 0024E224  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80251428 0024E228  7C 08 02 A6 */	mflr r0
/* 8025142C 0024E22C  3C 60 80 4B */	lis r3, lbl_804B61F0@ha
/* 80251430 0024E230  38 80 00 00 */	li r4, 0x0
/* 80251434 0024E234  90 01 00 14 */	stw r0, 0x14(r1)
/* 80251438 0024E238  38 00 00 17 */	li r0, 0x17
/* 8025143C 0024E23C  38 63 61 F0 */	addi r3, r3, lbl_804B61F0@l
/* 80251440 0024E240  38 A0 00 00 */	li r5, 0x0
/* 80251444 0024E244  7C 09 03 A6 */	mtctr r0
.L_80251448:
/* 80251448 0024E248  80 03 00 00 */	lwz r0, 0x0(r3)
/* 8025144C 0024E24C  7C 04 00 00 */	cmpw r4, r0
/* 80251450 0024E250  40 80 00 08 */	bge .L_80251458
/* 80251454 0024E254  7C 04 03 78 */	mr r4, r0
.L_80251458:
/* 80251458 0024E258  84 03 00 04 */	lwzu r0, 0x4(r3)
/* 8025145C 0024E25C  7C 04 00 00 */	cmpw r4, r0
/* 80251460 0024E260  40 80 00 08 */	bge .L_80251468
/* 80251464 0024E264  7C 04 03 78 */	mr r4, r0
.L_80251468:
/* 80251468 0024E268  84 03 00 04 */	lwzu r0, 0x4(r3)
/* 8025146C 0024E26C  7C 04 00 00 */	cmpw r4, r0
/* 80251470 0024E270  40 80 00 08 */	bge .L_80251478
/* 80251474 0024E274  7C 04 03 78 */	mr r4, r0
.L_80251478:
/* 80251478 0024E278  38 63 00 04 */	addi r3, r3, 0x4
/* 8025147C 0024E27C  38 A5 00 02 */	addi r5, r5, 0x2
/* 80251480 0024E280  42 00 FF C8 */	bdnz .L_80251448
/* 80251484 0024E284  3C 60 80 56 */	lis r3, lbl_8055DDDC@ha
/* 80251488 0024E288  38 A0 00 04 */	li r5, 0x4
/* 8025148C 0024E28C  38 63 DD DC */	addi r3, r3, lbl_8055DDDC@l
/* 80251490 0024E290  48 1C 6D CD */	bl HSD_ObjAllocInit
/* 80251494 0024E294  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80251498 0024E298  7C 08 03 A6 */	mtlr r0
/* 8025149C 0024E29C  38 21 00 10 */	addi r1, r1, 0x10
/* 802514A0 0024E2A0  4E 80 00 20 */	blr
.endfn kar_itdata_init_kind_work_objalloc
