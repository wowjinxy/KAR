.include "macros.inc"
.file "gryaku.c"

# 0x800F3F9C..0x800F57EC | size: 0x1850
.text
.balign 4

# .text:0x0 | 0x800F3F9C | size: 0x2C0
.fn kar_gryaku_apply_random_group_limits, global
/* 800F3F9C 000F0D9C  94 21 FE 80 */	stwu r1, -0x180(r1)
/* 800F3FA0 000F0DA0  7C 08 02 A6 */	mflr r0
/* 800F3FA4 000F0DA4  90 01 01 84 */	stw r0, 0x184(r1)
/* 800F3FA8 000F0DA8  39 61 01 80 */	addi r11, r1, 0x180
/* 800F3FAC 000F0DAC  48 2B 9B 8D */	bl _savegpr_20
/* 800F3FB0 000F0DB0  7C 7F 1B 78 */	mr r31, r3
/* 800F3FB4 000F0DB4  3C 80 80 4A */	lis r4, kar_src_ground_804a57e8@ha
/* 800F3FB8 000F0DB8  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800F3FBC 000F0DBC  3B C4 57 E8 */	addi r30, r4, kar_src_ground_804a57e8@l
/* 800F3FC0 000F0DC0  80 63 00 04 */	lwz r3, 0x4(r3)
/* 800F3FC4 000F0DC4  28 03 00 00 */	cmplwi r3, 0x0
/* 800F3FC8 000F0DC8  41 82 02 7C */	beq .L_800F4244
/* 800F3FCC 000F0DCC  82 C3 00 E4 */	lwz r22, 0xe4(r3)
/* 800F3FD0 000F0DD0  48 00 00 08 */	b .L_800F3FD8
/* 800F3FD4 000F0DD4  48 00 02 70 */	b .L_800F4244
.L_800F3FD8:
/* 800F3FD8 000F0DD8  3B 00 00 00 */	li r24, 0x0
/* 800F3FDC 000F0DDC  3B 41 00 30 */	addi r26, r1, 0x30
/* 800F3FE0 000F0DE0  93 01 00 30 */	stw r24, 0x30(r1)
/* 800F3FE4 000F0DE4  7F 1D C3 78 */	mr r29, r24
/* 800F3FE8 000F0DE8  93 01 00 34 */	stw r24, 0x34(r1)
/* 800F3FEC 000F0DEC  93 01 00 38 */	stw r24, 0x38(r1)
/* 800F3FF0 000F0DF0  93 01 00 3C */	stw r24, 0x3c(r1)
/* 800F3FF4 000F0DF4  93 01 00 40 */	stw r24, 0x40(r1)
/* 800F3FF8 000F0DF8  93 01 00 44 */	stw r24, 0x44(r1)
/* 800F3FFC 000F0DFC  93 01 00 48 */	stw r24, 0x48(r1)
/* 800F4000 000F0E00  93 01 00 4C */	stw r24, 0x4c(r1)
/* 800F4004 000F0E04  93 01 00 50 */	stw r24, 0x50(r1)
/* 800F4008 000F0E08  93 01 00 54 */	stw r24, 0x54(r1)
/* 800F400C 000F0E0C  93 01 00 58 */	stw r24, 0x58(r1)
/* 800F4010 000F0E10  93 01 00 5C */	stw r24, 0x5c(r1)
/* 800F4014 000F0E14  93 01 00 60 */	stw r24, 0x60(r1)
/* 800F4018 000F0E18  93 01 00 64 */	stw r24, 0x64(r1)
/* 800F401C 000F0E1C  93 01 00 68 */	stw r24, 0x68(r1)
/* 800F4020 000F0E20  93 01 00 6C */	stw r24, 0x6c(r1)
/* 800F4024 000F0E24  93 01 00 70 */	stw r24, 0x70(r1)
/* 800F4028 000F0E28  93 01 00 74 */	stw r24, 0x74(r1)
/* 800F402C 000F0E2C  93 01 00 78 */	stw r24, 0x78(r1)
/* 800F4030 000F0E30  93 01 00 7C */	stw r24, 0x7c(r1)
/* 800F4034 000F0E34  48 00 00 88 */	b .L_800F40BC
.L_800F4038:
/* 800F4038 000F0E38  2C 18 00 00 */	cmpwi r24, 0x0
/* 800F403C 000F0E3C  38 00 00 00 */	li r0, 0x0
/* 800F4040 000F0E40  41 80 00 10 */	blt .L_800F4050
/* 800F4044 000F0E44  7C 18 18 00 */	cmpw r24, r3
/* 800F4048 000F0E48  40 80 00 08 */	bge .L_800F4050
/* 800F404C 000F0E4C  38 00 00 01 */	li r0, 0x1
.L_800F4050:
/* 800F4050 000F0E50  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F4054 000F0E54  40 82 00 14 */	bne .L_800F4068
/* 800F4058 000F0E58  38 7E 00 00 */	addi r3, r30, 0x0
/* 800F405C 000F0E5C  38 BE 00 0C */	addi r5, r30, 0xc
/* 800F4060 000F0E60  38 80 08 65 */	li r4, 0x865
/* 800F4064 000F0E64  48 33 44 55 */	bl __assert
.L_800F4068:
/* 800F4068 000F0E68  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F406C 000F0E6C  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F4070 000F0E70  80 03 00 10 */	lwz r0, 0x10(r3)
/* 800F4074 000F0E74  7E 80 EA 14 */	add r20, r0, r29
/* 800F4078 000F0E78  80 14 00 08 */	lwz r0, 0x8(r20)
/* 800F407C 000F0E7C  2C 00 FF FF */	cmpwi r0, -0x1
/* 800F4080 000F0E80  41 82 00 34 */	beq .L_800F40B4
/* 800F4084 000F0E84  2C 00 00 14 */	cmpwi r0, 0x14
/* 800F4088 000F0E88  41 80 00 14 */	blt .L_800F409C
/* 800F408C 000F0E8C  38 7E 00 3C */	addi r3, r30, 0x3c
/* 800F4090 000F0E90  38 BE 00 78 */	addi r5, r30, 0x78
/* 800F4094 000F0E94  38 80 00 4B */	li r4, 0x4b
/* 800F4098 000F0E98  48 33 44 21 */	bl __assert
.L_800F409C:
/* 800F409C 000F0E9C  80 14 00 08 */	lwz r0, 0x8(r20)
/* 800F40A0 000F0EA0  38 81 00 30 */	addi r4, r1, 0x30
/* 800F40A4 000F0EA4  54 05 10 3A */	slwi r5, r0, 2
/* 800F40A8 000F0EA8  7C 64 28 2E */	lwzx r3, r4, r5
/* 800F40AC 000F0EAC  38 03 00 01 */	addi r0, r3, 0x1
/* 800F40B0 000F0EB0  7C 04 29 2E */	stwx r0, r4, r5
.L_800F40B4:
/* 800F40B4 000F0EB4  3B BD 00 0C */	addi r29, r29, 0xc
/* 800F40B8 000F0EB8  3B 18 00 01 */	addi r24, r24, 0x1
.L_800F40BC:
/* 800F40BC 000F0EBC  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F40C0 000F0EC0  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F40C4 000F0EC4  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800F40C8 000F0EC8  7C 18 18 00 */	cmpw r24, r3
/* 800F40CC 000F0ECC  41 80 FF 6C */	blt .L_800F4038
/* 800F40D0 000F0ED0  3B 00 00 00 */	li r24, 0x0
/* 800F40D4 000F0ED4  7F 1B C3 78 */	mr r27, r24
.L_800F40D8:
/* 800F40D8 000F0ED8  80 1A 00 00 */	lwz r0, 0x0(r26)
/* 800F40DC 000F0EDC  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F40E0 000F0EE0  41 82 01 50 */	beq .L_800F4230
/* 800F40E4 000F0EE4  80 76 00 00 */	lwz r3, 0x0(r22)
/* 800F40E8 000F0EE8  3A 80 00 00 */	li r20, 0x0
/* 800F40EC 000F0EEC  38 00 00 00 */	li r0, 0x0
/* 800F40F0 000F0EF0  7E A3 D8 2E */	lwzx r21, r3, r27
/* 800F40F4 000F0EF4  2C 15 00 00 */	cmpwi r21, 0x0
/* 800F40F8 000F0EF8  40 81 00 10 */	ble .L_800F4108
/* 800F40FC 000F0EFC  2C 15 00 0A */	cmpwi r21, 0xa
/* 800F4100 000F0F00  40 80 00 08 */	bge .L_800F4108
/* 800F4104 000F0F04  38 00 00 01 */	li r0, 0x1
.L_800F4108:
/* 800F4108 000F0F08  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F410C 000F0F0C  40 82 00 14 */	bne .L_800F4120
/* 800F4110 000F0F10  38 7E 00 3C */	addi r3, r30, 0x3c
/* 800F4114 000F0F14  38 BE 00 A4 */	addi r5, r30, 0xa4
/* 800F4118 000F0F18  38 80 00 59 */	li r4, 0x59
/* 800F411C 000F0F1C  48 33 43 9D */	bl __assert
.L_800F4120:
/* 800F4120 000F0F20  38 61 00 80 */	addi r3, r1, 0x80
/* 800F4124 000F0F24  38 80 00 32 */	li r4, 0x32
/* 800F4128 000F0F28  4B FE 70 81 */	bl kar_grparts__near_800db1a8
/* 800F412C 000F0F2C  3B 21 00 08 */	addi r25, r1, 0x8
/* 800F4130 000F0F30  3B 80 00 00 */	li r28, 0x0
/* 800F4134 000F0F34  7F 37 CB 78 */	mr r23, r25
/* 800F4138 000F0F38  48 00 00 2C */	b .L_800F4164
.L_800F413C:
/* 800F413C 000F0F3C  80 1A 00 00 */	lwz r0, 0x0(r26)
/* 800F4140 000F0F40  7C 7C 00 50 */	subf r3, r28, r0
/* 800F4144 000F0F44  48 32 A5 25 */	bl HSD_Randi
/* 800F4148 000F0F48  7C 64 1B 78 */	mr r4, r3
/* 800F414C 000F0F4C  38 61 00 80 */	addi r3, r1, 0x80
/* 800F4150 000F0F50  38 A0 00 32 */	li r5, 0x32
/* 800F4154 000F0F54  4B FE 70 E1 */	bl kar_grcommon__800db234
/* 800F4158 000F0F58  90 77 00 00 */	stw r3, 0x0(r23)
/* 800F415C 000F0F5C  3A F7 00 04 */	addi r23, r23, 0x4
/* 800F4160 000F0F60  3B 9C 00 01 */	addi r28, r28, 0x1
.L_800F4164:
/* 800F4164 000F0F64  7C 1C A8 00 */	cmpw r28, r21
/* 800F4168 000F0F68  41 80 FF D4 */	blt .L_800F413C
/* 800F416C 000F0F6C  3A E0 00 00 */	li r23, 0x0
/* 800F4170 000F0F70  7E FD BB 78 */	mr r29, r23
/* 800F4174 000F0F74  7E FC BB 78 */	mr r28, r23
/* 800F4178 000F0F78  48 00 00 A4 */	b .L_800F421C
.L_800F417C:
/* 800F417C 000F0F7C  2C 17 00 00 */	cmpwi r23, 0x0
/* 800F4180 000F0F80  38 00 00 00 */	li r0, 0x0
/* 800F4184 000F0F84  41 80 00 10 */	blt .L_800F4194
/* 800F4188 000F0F88  7C 17 18 00 */	cmpw r23, r3
/* 800F418C 000F0F8C  40 80 00 08 */	bge .L_800F4194
/* 800F4190 000F0F90  38 00 00 01 */	li r0, 0x1
.L_800F4194:
/* 800F4194 000F0F94  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F4198 000F0F98  40 82 00 14 */	bne .L_800F41AC
/* 800F419C 000F0F9C  38 7E 00 00 */	addi r3, r30, 0x0
/* 800F41A0 000F0FA0  38 BE 00 0C */	addi r5, r30, 0xc
/* 800F41A4 000F0FA4  38 80 08 65 */	li r4, 0x865
/* 800F41A8 000F0FA8  48 33 43 11 */	bl __assert
.L_800F41AC:
/* 800F41AC 000F0FAC  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F41B0 000F0FB0  38 1D 00 08 */	addi r0, r29, 0x8
/* 800F41B4 000F0FB4  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F41B8 000F0FB8  80 63 00 10 */	lwz r3, 0x10(r3)
/* 800F41BC 000F0FBC  7C 03 00 2E */	lwzx r0, r3, r0
/* 800F41C0 000F0FC0  7C 00 C0 00 */	cmpw r0, r24
/* 800F41C4 000F0FC4  40 82 00 4C */	bne .L_800F4210
/* 800F41C8 000F0FC8  7F 23 CB 78 */	mr r3, r25
/* 800F41CC 000F0FCC  38 80 00 00 */	li r4, 0x0
/* 800F41D0 000F0FD0  7E A9 03 A6 */	mtctr r21
/* 800F41D4 000F0FD4  2C 15 00 00 */	cmpwi r21, 0x0
/* 800F41D8 000F0FD8  40 81 00 1C */	ble .L_800F41F4
.L_800F41DC:
/* 800F41DC 000F0FDC  80 03 00 00 */	lwz r0, 0x0(r3)
/* 800F41E0 000F0FE0  7C 14 00 00 */	cmpw r20, r0
/* 800F41E4 000F0FE4  41 82 00 10 */	beq .L_800F41F4
/* 800F41E8 000F0FE8  38 63 00 04 */	addi r3, r3, 0x4
/* 800F41EC 000F0FEC  38 84 00 01 */	addi r4, r4, 0x1
/* 800F41F0 000F0FF0  42 00 FF EC */	bdnz .L_800F41DC
.L_800F41F4:
/* 800F41F4 000F0FF4  7C 04 A8 00 */	cmpw r4, r21
/* 800F41F8 000F0FF8  40 82 00 14 */	bne .L_800F420C
/* 800F41FC 000F0FFC  80 7F 07 10 */	lwz r3, 0x710(r31)
/* 800F4200 000F1000  38 80 00 00 */	li r4, 0x0
/* 800F4204 000F1004  7C 63 E0 2E */	lwzx r3, r3, r28
/* 800F4208 000F1008  48 00 15 3D */	bl kar_gryaku_set_active_state
.L_800F420C:
/* 800F420C 000F100C  3A 94 00 01 */	addi r20, r20, 0x1
.L_800F4210:
/* 800F4210 000F1010  3B BD 00 0C */	addi r29, r29, 0xc
/* 800F4214 000F1014  3B 9C 00 04 */	addi r28, r28, 0x4
/* 800F4218 000F1018  3A F7 00 01 */	addi r23, r23, 0x1
.L_800F421C:
/* 800F421C 000F101C  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F4220 000F1020  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F4224 000F1024  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800F4228 000F1028  7C 17 18 00 */	cmpw r23, r3
/* 800F422C 000F102C  41 80 FF 50 */	blt .L_800F417C
.L_800F4230:
/* 800F4230 000F1030  3B 18 00 01 */	addi r24, r24, 0x1
/* 800F4234 000F1034  3B 7B 00 04 */	addi r27, r27, 0x4
/* 800F4238 000F1038  2C 18 00 14 */	cmpwi r24, 0x14
/* 800F423C 000F103C  3B 5A 00 04 */	addi r26, r26, 0x4
/* 800F4240 000F1040  41 80 FE 98 */	blt .L_800F40D8
.L_800F4244:
/* 800F4244 000F1044  39 61 01 80 */	addi r11, r1, 0x180
/* 800F4248 000F1048  48 2B 99 3D */	bl _restgpr_20
/* 800F424C 000F104C  80 01 01 84 */	lwz r0, 0x184(r1)
/* 800F4250 000F1050  7C 08 03 A6 */	mtlr r0
/* 800F4254 000F1054  38 21 01 80 */	addi r1, r1, 0x180
/* 800F4258 000F1058  4E 80 00 20 */	blr
.endfn kar_gryaku_apply_random_group_limits

# .text:0x2C0 | 0x800F425C | size: 0x140
.fn kar_gryaku_init_common_yaku_objects, global
/* 800F425C 000F105C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F4260 000F1060  7C 08 02 A6 */	mflr r0
/* 800F4264 000F1064  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F4268 000F1068  39 61 00 30 */	addi r11, r1, 0x30
/* 800F426C 000F106C  48 2B 98 E1 */	bl _savegpr_25
/* 800F4270 000F1070  7C 7B 1B 78 */	mr r27, r3
/* 800F4274 000F1074  3C 60 80 4A */	lis r3, ground_stage_yaku_callback_table@ha
/* 800F4278 000F1078  80 1B 00 04 */	lwz r0, 0x4(r27)
/* 800F427C 000F107C  3C 80 80 4A */	lis r4, kar_src_ground_804a57e8@ha
/* 800F4280 000F1080  38 63 32 2C */	addi r3, r3, ground_stage_yaku_callback_table@l
/* 800F4284 000F1084  54 00 10 3A */	slwi r0, r0, 2
/* 800F4288 000F1088  3B E4 57 E8 */	addi r31, r4, kar_src_ground_804a57e8@l
/* 800F428C 000F108C  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F4290 000F1090  81 83 00 04 */	lwz r12, 0x4(r3)
/* 800F4294 000F1094  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F4298 000F1098  41 82 00 10 */	beq .L_800F42A8
/* 800F429C 000F109C  80 7B 00 00 */	lwz r3, 0x0(r27)
/* 800F42A0 000F10A0  7D 89 03 A6 */	mtctr r12
/* 800F42A4 000F10A4  4E 80 04 21 */	bctrl
.L_800F42A8:
/* 800F42A8 000F10A8  80 7B 00 08 */	lwz r3, 0x8(r27)
/* 800F42AC 000F10AC  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F42B0 000F10B0  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F42B4 000F10B4  54 03 10 3A */	slwi r3, r0, 2
/* 800F42B8 000F10B8  48 32 8C 2D */	bl HSD_Alloc
/* 800F42BC 000F10BC  3B C0 00 00 */	li r30, 0x0
/* 800F42C0 000F10C0  3C 80 80 4A */	lis r4, gryaku_common_kind_factory_table@ha
/* 800F42C4 000F10C4  90 7B 07 10 */	stw r3, 0x710(r27)
/* 800F42C8 000F10C8  7F DD F3 78 */	mr r29, r30
/* 800F42CC 000F10CC  3B 44 5B A8 */	addi r26, r4, gryaku_common_kind_factory_table@l
/* 800F42D0 000F10D0  3B 80 00 00 */	li r28, 0x0
/* 800F42D4 000F10D4  48 00 00 94 */	b .L_800F4368
.L_800F42D8:
/* 800F42D8 000F10D8  2C 1C 00 00 */	cmpwi r28, 0x0
/* 800F42DC 000F10DC  38 00 00 00 */	li r0, 0x0
/* 800F42E0 000F10E0  41 80 00 10 */	blt .L_800F42F0
/* 800F42E4 000F10E4  7C 1C 18 00 */	cmpw r28, r3
/* 800F42E8 000F10E8  40 80 00 08 */	bge .L_800F42F0
/* 800F42EC 000F10EC  38 00 00 01 */	li r0, 0x1
.L_800F42F0:
/* 800F42F0 000F10F0  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F42F4 000F10F4  40 82 00 14 */	bne .L_800F4308
/* 800F42F8 000F10F8  38 7F 00 00 */	addi r3, r31, 0x0
/* 800F42FC 000F10FC  38 BF 00 0C */	addi r5, r31, 0xc
/* 800F4300 000F1100  38 80 08 65 */	li r4, 0x865
/* 800F4304 000F1104  48 33 41 B5 */	bl __assert
.L_800F4308:
/* 800F4308 000F1108  80 7B 00 08 */	lwz r3, 0x8(r27)
/* 800F430C 000F110C  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F4310 000F1110  80 03 00 10 */	lwz r0, 0x10(r3)
/* 800F4314 000F1114  7F 20 F2 14 */	add r25, r0, r30
/* 800F4318 000F1118  80 19 00 00 */	lwz r0, 0x0(r25)
/* 800F431C 000F111C  2C 00 00 10 */	cmpwi r0, 0x10
/* 800F4320 000F1120  41 80 00 14 */	blt .L_800F4334
/* 800F4324 000F1124  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4328 000F1128  38 BF 00 48 */	addi r5, r31, 0x48
/* 800F432C 000F112C  38 80 00 2A */	li r4, 0x2a
/* 800F4330 000F1130  48 33 41 89 */	bl __assert
.L_800F4334:
/* 800F4334 000F1134  80 99 00 00 */	lwz r4, 0x0(r25)
/* 800F4338 000F1138  80 7B 00 00 */	lwz r3, 0x0(r27)
/* 800F433C 000F113C  54 80 10 3A */	slwi r0, r4, 2
/* 800F4340 000F1140  80 B9 00 04 */	lwz r5, 0x4(r25)
/* 800F4344 000F1144  7D 9A 00 2E */	lwzx r12, r26, r0
/* 800F4348 000F1148  7D 89 03 A6 */	mtctr r12
/* 800F434C 000F114C  4E 80 04 21 */	bctrl
/* 800F4350 000F1150  80 03 00 2C */	lwz r0, 0x2c(r3)
/* 800F4354 000F1154  3B DE 00 0C */	addi r30, r30, 0xc
/* 800F4358 000F1158  80 7B 07 10 */	lwz r3, 0x710(r27)
/* 800F435C 000F115C  3B 9C 00 01 */	addi r28, r28, 0x1
/* 800F4360 000F1160  7C 03 E9 2E */	stwx r0, r3, r29
/* 800F4364 000F1164  3B BD 00 04 */	addi r29, r29, 0x4
.L_800F4368:
/* 800F4368 000F1168  80 7B 00 08 */	lwz r3, 0x8(r27)
/* 800F436C 000F116C  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F4370 000F1170  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800F4374 000F1174  7C 1C 18 00 */	cmpw r28, r3
/* 800F4378 000F1178  41 80 FF 60 */	blt .L_800F42D8
/* 800F437C 000F117C  7F 63 DB 78 */	mr r3, r27
/* 800F4380 000F1180  4B FF FC 1D */	bl kar_gryaku_apply_random_group_limits
/* 800F4384 000F1184  39 61 00 30 */	addi r11, r1, 0x30
/* 800F4388 000F1188  48 2B 98 11 */	bl _restgpr_25
/* 800F438C 000F118C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F4390 000F1190  7C 08 03 A6 */	mtlr r0
/* 800F4394 000F1194  38 21 00 30 */	addi r1, r1, 0x30
/* 800F4398 000F1198  4E 80 00 20 */	blr
.endfn kar_gryaku_init_common_yaku_objects

# .text:0x400 | 0x800F439C | size: 0x60
.fn kar_gryaku_destroy_all_common_yaku_objects, global
/* 800F439C 000F119C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F43A0 000F11A0  7C 08 02 A6 */	mflr r0
/* 800F43A4 000F11A4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F43A8 000F11A8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F43AC 000F11AC  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F43B0 000F11B0  7C 7E 1B 78 */	mr r30, r3
/* 800F43B4 000F11B4  80 8D 12 54 */	lwz r4, lbl_805DE334@sda21(r0)
/* 800F43B8 000F11B8  83 E4 00 20 */	lwz r31, 0x20(r4)
/* 800F43BC 000F11BC  48 00 00 10 */	b .L_800F43CC
.L_800F43C0:
/* 800F43C0 000F11C0  7F E3 FB 78 */	mr r3, r31
/* 800F43C4 000F11C4  48 33 4B A1 */	bl HSD_GObjDestroy
/* 800F43C8 000F11C8  83 FF 00 08 */	lwz r31, 0x8(r31)
.L_800F43CC:
/* 800F43CC 000F11CC  28 1F 00 00 */	cmplwi r31, 0x0
/* 800F43D0 000F11D0  40 82 FF F0 */	bne .L_800F43C0
/* 800F43D4 000F11D4  80 7E 07 10 */	lwz r3, 0x710(r30)
/* 800F43D8 000F11D8  28 03 00 00 */	cmplwi r3, 0x0
/* 800F43DC 000F11DC  41 82 00 08 */	beq .L_800F43E4
/* 800F43E0 000F11E0  48 32 8A D5 */	bl HSD_Free
.L_800F43E4:
/* 800F43E4 000F11E4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F43E8 000F11E8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F43EC 000F11EC  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F43F0 000F11F0  7C 08 03 A6 */	mtlr r0
/* 800F43F4 000F11F4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F43F8 000F11F8  4E 80 00 20 */	blr
.endfn kar_gryaku_destroy_all_common_yaku_objects

# .text:0x460 | 0x800F43FC | size: 0x10
.fn kar_gryaku_reset_global_tables, global
/* 800F43FC 000F11FC  38 00 00 00 */	li r0, 0x0
/* 800F4400 000F1200  90 0D 05 E0 */	stw r0, lbl_805DD6C0@sda21(r0)
/* 800F4404 000F1204  90 0D 05 E4 */	stw r0, lbl_805DD6C4@sda21(r0)
/* 800F4408 000F1208  4E 80 00 20 */	blr
.endfn kar_gryaku_reset_global_tables

# .text:0x470 | 0x800F440C | size: 0x24
.fn kar_gryaku_load_yaku_assets, global
/* 800F440C 000F120C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F4410 000F1210  7C 08 02 A6 */	mflr r0
/* 800F4414 000F1214  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F4418 000F1218  48 00 3E 3D */	bl kar_yk_assets_load_ykcommon_archive
/* 800F441C 000F121C  48 00 3E 85 */	bl kar_ya_assets_load_yakumono_archive
/* 800F4420 000F1220  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F4424 000F1224  7C 08 03 A6 */	mtlr r0
/* 800F4428 000F1228  38 21 00 10 */	addi r1, r1, 0x10
/* 800F442C 000F122C  4E 80 00 20 */	blr
.endfn kar_gryaku_load_yaku_assets

# .text:0x494 | 0x800F4430 | size: 0x3C
.fn kar_gryaku_check_classical_scaling_node, global
/* 800F4430 000F1230  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F4434 000F1234  7C 08 02 A6 */	mflr r0
/* 800F4438 000F1238  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F443C 000F123C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F4440 000F1240  83 E4 00 00 */	lwz r31, 0x0(r4)
/* 800F4444 000F1244  48 31 79 09 */	bl HSD_JObjGetFlags
/* 800F4448 000F1248  54 60 07 39 */	rlwinm. r0, r3, 0, 28, 28
/* 800F444C 000F124C  40 82 00 0C */	bne .L_800F4458
/* 800F4450 000F1250  38 00 00 00 */	li r0, 0x0
/* 800F4454 000F1254  90 1F 00 00 */	stw r0, 0x0(r31)
.L_800F4458:
/* 800F4458 000F1258  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F445C 000F125C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F4460 000F1260  7C 08 03 A6 */	mtlr r0
/* 800F4464 000F1264  38 21 00 10 */	addi r1, r1, 0x10
/* 800F4468 000F1268  4E 80 00 20 */	blr
.endfn kar_gryaku_check_classical_scaling_node

# .text:0x4D0 | 0x800F446C | size: 0x200
.fn kar_gryaku_create_yaku_from_main_kind, global
/* 800F446C 000F126C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F4470 000F1270  7C 08 02 A6 */	mflr r0
/* 800F4474 000F1274  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F4478 000F1278  39 61 00 20 */	addi r11, r1, 0x20
/* 800F447C 000F127C  48 2B 96 D9 */	bl _savegpr_27
/* 800F4480 000F1280  7C 9B 23 79 */	mr. r27, r4
/* 800F4484 000F1284  3C 80 80 4A */	lis r4, kar_src_ground_804a57e8@ha
/* 800F4488 000F1288  83 AD 05 EC */	lwz r29, lbl_805DD6CC@sda21(r0)
/* 800F448C 000F128C  3B E4 57 E8 */	addi r31, r4, kar_src_ground_804a57e8@l
/* 800F4490 000F1290  7C 7E 1B 78 */	mr r30, r3
/* 800F4494 000F1294  38 80 00 00 */	li r4, 0x0
/* 800F4498 000F1298  41 80 00 1C */	blt .L_800F44B4
/* 800F449C 000F129C  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800F44A0 000F12A0  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F44A4 000F12A4  80 03 00 04 */	lwz r0, 0x4(r3)
/* 800F44A8 000F12A8  7C 1B 00 00 */	cmpw r27, r0
/* 800F44AC 000F12AC  40 80 00 08 */	bge .L_800F44B4
/* 800F44B0 000F12B0  38 80 00 01 */	li r4, 0x1
.L_800F44B4:
/* 800F44B4 000F12B4  2C 04 00 00 */	cmpwi r4, 0x0
/* 800F44B8 000F12B8  40 82 00 14 */	bne .L_800F44CC
/* 800F44BC 000F12BC  38 7F 00 00 */	addi r3, r31, 0x0
/* 800F44C0 000F12C0  38 BF 00 F4 */	addi r5, r31, 0xf4
/* 800F44C4 000F12C4  38 80 08 27 */	li r4, 0x827
/* 800F44C8 000F12C8  48 33 3F F1 */	bl __assert
.L_800F44CC:
/* 800F44CC 000F12CC  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800F44D0 000F12D0  57 60 10 3A */	slwi r0, r27, 2
/* 800F44D4 000F12D4  83 6D 05 EC */	lwz r27, lbl_805DD6CC@sda21(r0)
/* 800F44D8 000F12D8  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F44DC 000F12DC  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800F44E0 000F12E0  7F 83 00 2E */	lwzx r28, r3, r0
/* 800F44E4 000F12E4  28 1C 00 00 */	cmplwi r28, 0x0
/* 800F44E8 000F12E8  40 82 00 24 */	bne .L_800F450C
/* 800F44EC 000F12EC  7F C4 F3 78 */	mr r4, r30
/* 800F44F0 000F12F0  38 7F 00 E8 */	addi r3, r31, 0xe8
/* 800F44F4 000F12F4  4C C6 31 82 */	crclr cr1eq
/* 800F44F8 000F12F8  48 2E 07 F1 */	bl OSReport
/* 800F44FC 000F12FC  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4500 000F1300  38 80 00 C0 */	li r4, 0xc0
/* 800F4504 000F1304  38 AD 90 C8 */	li r5, lbl_805D61A8@sda21
/* 800F4508 000F1308  48 33 3F B1 */	bl __assert
.L_800F450C:
/* 800F450C 000F130C  38 60 00 0F */	li r3, 0xf
/* 800F4510 000F1310  38 80 00 08 */	li r4, 0x8
/* 800F4514 000F1314  38 A0 00 00 */	li r5, 0x0
/* 800F4518 000F1318  48 33 4A 11 */	bl HSD_GObjCreate
/* 800F451C 000F131C  3C 80 80 55 */	lis r4, gryaku_userdata_objalloc_data@ha
/* 800F4520 000F1320  7C 7F 1B 78 */	mr r31, r3
/* 800F4524 000F1324  38 04 75 84 */	addi r0, r4, gryaku_userdata_objalloc_data@l
/* 800F4528 000F1328  7C 03 03 78 */	mr r3, r0
/* 800F452C 000F132C  48 32 3B B9 */	bl HSD_ObjAlloc
/* 800F4530 000F1330  7C 7D 1B 78 */	mr r29, r3
/* 800F4534 000F1334  3C 80 80 0F */	lis r4, kar_gryaku_free_userdata@ha
/* 800F4538 000F1338  38 A4 4F 0C */	addi r5, r4, kar_gryaku_free_userdata@l
/* 800F453C 000F133C  7F E3 FB 78 */	mr r3, r31
/* 800F4540 000F1340  38 80 00 0E */	li r4, 0xe
/* 800F4544 000F1344  7F A6 EB 78 */	mr r6, r29
/* 800F4548 000F1348  48 33 57 C5 */	bl HSD_GObjUserDataLink
/* 800F454C 000F134C  80 DB 06 FC */	lwz r6, 0x6fc(r27)
/* 800F4550 000F1350  7F E3 FB 78 */	mr r3, r31
/* 800F4554 000F1354  7F C4 F3 78 */	mr r4, r30
/* 800F4558 000F1358  7F 85 E3 78 */	mr r5, r28
/* 800F455C 000F135C  38 06 00 01 */	addi r0, r6, 0x1
/* 800F4560 000F1360  90 1B 06 FC */	stw r0, 0x6fc(r27)
/* 800F4564 000F1364  48 00 07 ED */	bl kar_gryaku_init_userdata_base
/* 800F4568 000F1368  7F E3 FB 78 */	mr r3, r31
/* 800F456C 000F136C  48 00 21 01 */	bl kar_gryakuanim_init_efdata_state
/* 800F4570 000F1370  7F E3 FB 78 */	mr r3, r31
/* 800F4574 000F1374  38 80 FF FF */	li r4, -0x1
/* 800F4578 000F1378  48 00 2D 55 */	bl kar_gryakueffect_init_rough_state
/* 800F457C 000F137C  7F E3 FB 78 */	mr r3, r31
/* 800F4580 000F1380  48 00 12 19 */	bl kar_gryaku_noop_init_callback
/* 800F4584 000F1384  7F A3 EB 78 */	mr r3, r29
/* 800F4588 000F1388  48 00 2D 81 */	bl kar_gryakueffect_init_anchor_transform
/* 800F458C 000F138C  38 00 00 00 */	li r0, 0x0
/* 800F4590 000F1390  7F A3 EB 78 */	mr r3, r29
/* 800F4594 000F1394  90 1D 00 70 */	stw r0, 0x70(r29)
/* 800F4598 000F1398  48 00 2E 65 */	bl kar_gryakueffect_sync_root_anchor_jobj_matrix
/* 800F459C 000F139C  7F A3 EB 78 */	mr r3, r29
/* 800F45A0 000F13A0  48 00 1C D5 */	bl kar_gryakuanim_init_collision_records
/* 800F45A4 000F13A4  7F A3 EB 78 */	mr r3, r29
/* 800F45A8 000F13A8  48 00 32 35 */	bl kar_gryakueffect_init_audio_rail_state
/* 800F45AC 000F13AC  7F A3 EB 78 */	mr r3, r29
/* 800F45B0 000F13B0  48 00 1D E5 */	bl kar_gryakuanim_init_display_bbox_records
/* 800F45B4 000F13B4  7F A3 EB 78 */	mr r3, r29
/* 800F45B8 000F13B8  48 00 3E CD */	bl kar_gryakulib_init_clobject_handle
/* 800F45BC 000F13BC  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_main@ha
/* 800F45C0 000F13C0  7F E3 FB 78 */	mr r3, r31
/* 800F45C4 000F13C4  38 84 52 84 */	addi r4, r4, kar_gryaku_proc_update_main@l
/* 800F45C8 000F13C8  38 A0 00 01 */	li r5, 0x1
/* 800F45CC 000F13CC  48 33 42 D9 */	bl HSD_GObjProcCreate
/* 800F45D0 000F13D0  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_effect_anim@ha
/* 800F45D4 000F13D4  7F E3 FB 78 */	mr r3, r31
/* 800F45D8 000F13D8  38 84 52 E8 */	addi r4, r4, kar_gryaku_proc_update_effect_anim@l
/* 800F45DC 000F13DC  38 A0 00 04 */	li r5, 0x4
/* 800F45E0 000F13E0  48 33 42 C5 */	bl HSD_GObjProcCreate
/* 800F45E4 000F13E4  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_f8@ha
/* 800F45E8 000F13E8  7F E3 FB 78 */	mr r3, r31
/* 800F45EC 000F13EC  38 84 53 40 */	addi r4, r4, kar_gryaku_proc_callback_f8@l
/* 800F45F0 000F13F0  38 A0 00 05 */	li r5, 0x5
/* 800F45F4 000F13F4  48 33 42 B1 */	bl HSD_GObjProcCreate
/* 800F45F8 000F13F8  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_fc@ha
/* 800F45FC 000F13FC  7F E3 FB 78 */	mr r3, r31
/* 800F4600 000F1400  38 84 53 74 */	addi r4, r4, kar_gryaku_proc_callback_fc@l
/* 800F4604 000F1404  38 A0 00 06 */	li r5, 0x6
/* 800F4608 000F1408  48 33 42 9D */	bl HSD_GObjProcCreate
/* 800F460C 000F140C  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_108_and_draw@ha
/* 800F4610 000F1410  7F E3 FB 78 */	mr r3, r31
/* 800F4614 000F1414  38 84 53 A8 */	addi r4, r4, kar_gryaku_proc_callback_108_and_draw@l
/* 800F4618 000F1418  38 A0 00 07 */	li r5, 0x7
/* 800F461C 000F141C  48 33 42 89 */	bl HSD_GObjProcCreate
/* 800F4620 000F1420  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_collision_libs@ha
/* 800F4624 000F1424  7F E3 FB 78 */	mr r3, r31
/* 800F4628 000F1428  38 84 53 FC */	addi r4, r4, kar_gryaku_proc_update_collision_libs@l
/* 800F462C 000F142C  38 A0 00 09 */	li r5, 0x9
/* 800F4630 000F1430  48 33 42 75 */	bl HSD_GObjProcCreate
/* 800F4634 000F1434  3C 80 80 0F */	lis r4, kar_gryaku_proc_apply_motion_callbacks@ha
/* 800F4638 000F1438  7F E3 FB 78 */	mr r3, r31
/* 800F463C 000F143C  38 84 54 54 */	addi r4, r4, kar_gryaku_proc_apply_motion_callbacks@l
/* 800F4640 000F1440  38 A0 00 0A */	li r5, 0xa
/* 800F4644 000F1444  48 33 42 61 */	bl HSD_GObjProcCreate
/* 800F4648 000F1448  7F E3 FB 78 */	mr r3, r31
/* 800F464C 000F144C  48 00 08 55 */	bl kar_gryaku_reset_motion_draw_state
/* 800F4650 000F1450  7F E3 FB 78 */	mr r3, r31
/* 800F4654 000F1454  39 61 00 20 */	addi r11, r1, 0x20
/* 800F4658 000F1458  48 2B 95 49 */	bl _restgpr_27
/* 800F465C 000F145C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4660 000F1460  7C 08 03 A6 */	mtlr r0
/* 800F4664 000F1464  38 21 00 20 */	addi r1, r1, 0x20
/* 800F4668 000F1468  4E 80 00 20 */	blr
.endfn kar_gryaku_create_yaku_from_main_kind

# .text:0x6D0 | 0x800F466C | size: 0x260
.fn kar_gryaku_create_yaku_with_effect_index, global
/* 800F466C 000F146C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F4670 000F1470  7C 08 02 A6 */	mflr r0
/* 800F4674 000F1474  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F4678 000F1478  39 61 00 30 */	addi r11, r1, 0x30
/* 800F467C 000F147C  48 2B 94 D1 */	bl _savegpr_25
/* 800F4680 000F1480  7C 9A 23 79 */	mr. r26, r4
/* 800F4684 000F1484  3C 80 80 4A */	lis r4, kar_src_ground_804a57e8@ha
/* 800F4688 000F1488  83 2D 05 EC */	lwz r25, lbl_805DD6CC@sda21(r0)
/* 800F468C 000F148C  3B E4 57 E8 */	addi r31, r4, kar_src_ground_804a57e8@l
/* 800F4690 000F1490  7C 7B 1B 78 */	mr r27, r3
/* 800F4694 000F1494  7C BC 2B 78 */	mr r28, r5
/* 800F4698 000F1498  38 80 00 00 */	li r4, 0x0
/* 800F469C 000F149C  41 80 00 1C */	blt .L_800F46B8
/* 800F46A0 000F14A0  80 79 00 08 */	lwz r3, 0x8(r25)
/* 800F46A4 000F14A4  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F46A8 000F14A8  80 03 00 04 */	lwz r0, 0x4(r3)
/* 800F46AC 000F14AC  7C 1A 00 00 */	cmpw r26, r0
/* 800F46B0 000F14B0  40 80 00 08 */	bge .L_800F46B8
/* 800F46B4 000F14B4  38 80 00 01 */	li r4, 0x1
.L_800F46B8:
/* 800F46B8 000F14B8  2C 04 00 00 */	cmpwi r4, 0x0
/* 800F46BC 000F14BC  40 82 00 14 */	bne .L_800F46D0
/* 800F46C0 000F14C0  38 7F 00 00 */	addi r3, r31, 0x0
/* 800F46C4 000F14C4  38 BF 00 F4 */	addi r5, r31, 0xf4
/* 800F46C8 000F14C8  38 80 08 27 */	li r4, 0x827
/* 800F46CC 000F14CC  48 33 3D ED */	bl __assert
.L_800F46D0:
/* 800F46D0 000F14D0  80 79 00 08 */	lwz r3, 0x8(r25)
/* 800F46D4 000F14D4  57 40 10 3A */	slwi r0, r26, 2
/* 800F46D8 000F14D8  83 AD 05 EC */	lwz r29, lbl_805DD6CC@sda21(r0)
/* 800F46DC 000F14DC  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F46E0 000F14E0  80 63 00 00 */	lwz r3, 0x0(r3)
/* 800F46E4 000F14E4  7F 43 00 2E */	lwzx r26, r3, r0
/* 800F46E8 000F14E8  28 1A 00 00 */	cmplwi r26, 0x0
/* 800F46EC 000F14EC  40 82 00 24 */	bne .L_800F4710
/* 800F46F0 000F14F0  7F 64 DB 78 */	mr r4, r27
/* 800F46F4 000F14F4  38 7F 00 E8 */	addi r3, r31, 0xe8
/* 800F46F8 000F14F8  4C C6 31 82 */	crclr cr1eq
/* 800F46FC 000F14FC  48 2E 05 ED */	bl OSReport
/* 800F4700 000F1500  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4704 000F1504  38 80 00 C0 */	li r4, 0xc0
/* 800F4708 000F1508  38 AD 90 C8 */	li r5, lbl_805D61A8@sda21
/* 800F470C 000F150C  48 33 3D AD */	bl __assert
.L_800F4710:
/* 800F4710 000F1510  38 60 00 0F */	li r3, 0xf
/* 800F4714 000F1514  38 80 00 08 */	li r4, 0x8
/* 800F4718 000F1518  38 A0 00 00 */	li r5, 0x0
/* 800F471C 000F151C  48 33 48 0D */	bl HSD_GObjCreate
/* 800F4720 000F1520  3C 80 80 55 */	lis r4, gryaku_userdata_objalloc_data@ha
/* 800F4724 000F1524  7C 7E 1B 78 */	mr r30, r3
/* 800F4728 000F1528  38 04 75 84 */	addi r0, r4, gryaku_userdata_objalloc_data@l
/* 800F472C 000F152C  7C 03 03 78 */	mr r3, r0
/* 800F4730 000F1530  48 32 39 B5 */	bl HSD_ObjAlloc
/* 800F4734 000F1534  7C 79 1B 78 */	mr r25, r3
/* 800F4738 000F1538  3C 80 80 0F */	lis r4, kar_gryaku_free_userdata@ha
/* 800F473C 000F153C  38 A4 4F 0C */	addi r5, r4, kar_gryaku_free_userdata@l
/* 800F4740 000F1540  7F C3 F3 78 */	mr r3, r30
/* 800F4744 000F1544  38 80 00 0E */	li r4, 0xe
/* 800F4748 000F1548  7F 26 CB 78 */	mr r6, r25
/* 800F474C 000F154C  48 33 55 C1 */	bl HSD_GObjUserDataLink
/* 800F4750 000F1550  80 DD 06 FC */	lwz r6, 0x6fc(r29)
/* 800F4754 000F1554  7F C3 F3 78 */	mr r3, r30
/* 800F4758 000F1558  7F 64 DB 78 */	mr r4, r27
/* 800F475C 000F155C  7F 45 D3 78 */	mr r5, r26
/* 800F4760 000F1560  38 06 00 01 */	addi r0, r6, 0x1
/* 800F4764 000F1564  90 1D 06 FC */	stw r0, 0x6fc(r29)
/* 800F4768 000F1568  48 00 05 E9 */	bl kar_gryaku_init_userdata_base
/* 800F476C 000F156C  7F C3 F3 78 */	mr r3, r30
/* 800F4770 000F1570  48 00 1E FD */	bl kar_gryakuanim_init_efdata_state
/* 800F4774 000F1574  7F C3 F3 78 */	mr r3, r30
/* 800F4778 000F1578  7F 84 E3 78 */	mr r4, r28
/* 800F477C 000F157C  48 00 2B 51 */	bl kar_gryakueffect_init_rough_state
/* 800F4780 000F1580  7F C3 F3 78 */	mr r3, r30
/* 800F4784 000F1584  48 00 10 15 */	bl kar_gryaku_noop_init_callback
/* 800F4788 000F1588  7F 23 CB 78 */	mr r3, r25
/* 800F478C 000F158C  48 00 2B 7D */	bl kar_gryakueffect_init_anchor_transform
/* 800F4790 000F1590  2C 1C FF FF */	cmpwi r28, -0x1
/* 800F4794 000F1594  41 82 00 18 */	beq .L_800F47AC
/* 800F4798 000F1598  80 7D 01 04 */	lwz r3, 0x104(r29)
/* 800F479C 000F159C  57 80 18 38 */	slwi r0, r28, 3
/* 800F47A0 000F15A0  7C 03 00 2E */	lwzx r0, r3, r0
/* 800F47A4 000F15A4  90 19 00 70 */	stw r0, 0x70(r25)
/* 800F47A8 000F15A8  48 00 00 0C */	b .L_800F47B4
.L_800F47AC:
/* 800F47AC 000F15AC  38 00 00 00 */	li r0, 0x0
/* 800F47B0 000F15B0  90 19 00 70 */	stw r0, 0x70(r25)
.L_800F47B4:
/* 800F47B4 000F15B4  7F 23 CB 78 */	mr r3, r25
/* 800F47B8 000F15B8  48 00 2C 45 */	bl kar_gryakueffect_sync_root_anchor_jobj_matrix
/* 800F47BC 000F15BC  7F 23 CB 78 */	mr r3, r25
/* 800F47C0 000F15C0  48 00 1A B5 */	bl kar_gryakuanim_init_collision_records
/* 800F47C4 000F15C4  7F 23 CB 78 */	mr r3, r25
/* 800F47C8 000F15C8  48 00 30 15 */	bl kar_gryakueffect_init_audio_rail_state
/* 800F47CC 000F15CC  7F 23 CB 78 */	mr r3, r25
/* 800F47D0 000F15D0  48 00 1B C5 */	bl kar_gryakuanim_init_display_bbox_records
/* 800F47D4 000F15D4  7F 23 CB 78 */	mr r3, r25
/* 800F47D8 000F15D8  48 00 3C AD */	bl kar_gryakulib_init_clobject_handle
/* 800F47DC 000F15DC  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_main@ha
/* 800F47E0 000F15E0  7F C3 F3 78 */	mr r3, r30
/* 800F47E4 000F15E4  38 84 52 84 */	addi r4, r4, kar_gryaku_proc_update_main@l
/* 800F47E8 000F15E8  38 A0 00 01 */	li r5, 0x1
/* 800F47EC 000F15EC  48 33 40 B9 */	bl HSD_GObjProcCreate
/* 800F47F0 000F15F0  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_effect_anim@ha
/* 800F47F4 000F15F4  7F C3 F3 78 */	mr r3, r30
/* 800F47F8 000F15F8  38 84 52 E8 */	addi r4, r4, kar_gryaku_proc_update_effect_anim@l
/* 800F47FC 000F15FC  38 A0 00 04 */	li r5, 0x4
/* 800F4800 000F1600  48 33 40 A5 */	bl HSD_GObjProcCreate
/* 800F4804 000F1604  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_f8@ha
/* 800F4808 000F1608  7F C3 F3 78 */	mr r3, r30
/* 800F480C 000F160C  38 84 53 40 */	addi r4, r4, kar_gryaku_proc_callback_f8@l
/* 800F4810 000F1610  38 A0 00 05 */	li r5, 0x5
/* 800F4814 000F1614  48 33 40 91 */	bl HSD_GObjProcCreate
/* 800F4818 000F1618  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_fc@ha
/* 800F481C 000F161C  7F C3 F3 78 */	mr r3, r30
/* 800F4820 000F1620  38 84 53 74 */	addi r4, r4, kar_gryaku_proc_callback_fc@l
/* 800F4824 000F1624  38 A0 00 06 */	li r5, 0x6
/* 800F4828 000F1628  48 33 40 7D */	bl HSD_GObjProcCreate
/* 800F482C 000F162C  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_108_and_draw@ha
/* 800F4830 000F1630  7F C3 F3 78 */	mr r3, r30
/* 800F4834 000F1634  38 84 53 A8 */	addi r4, r4, kar_gryaku_proc_callback_108_and_draw@l
/* 800F4838 000F1638  38 A0 00 07 */	li r5, 0x7
/* 800F483C 000F163C  48 33 40 69 */	bl HSD_GObjProcCreate
/* 800F4840 000F1640  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_collision_libs@ha
/* 800F4844 000F1644  7F C3 F3 78 */	mr r3, r30
/* 800F4848 000F1648  38 84 53 FC */	addi r4, r4, kar_gryaku_proc_update_collision_libs@l
/* 800F484C 000F164C  38 A0 00 09 */	li r5, 0x9
/* 800F4850 000F1650  48 33 40 55 */	bl HSD_GObjProcCreate
/* 800F4854 000F1654  3C 80 80 0F */	lis r4, kar_gryaku_proc_apply_motion_callbacks@ha
/* 800F4858 000F1658  7F C3 F3 78 */	mr r3, r30
/* 800F485C 000F165C  38 84 54 54 */	addi r4, r4, kar_gryaku_proc_apply_motion_callbacks@l
/* 800F4860 000F1660  38 A0 00 0A */	li r5, 0xa
/* 800F4864 000F1664  48 33 40 41 */	bl HSD_GObjProcCreate
/* 800F4868 000F1668  7F C3 F3 78 */	mr r3, r30
/* 800F486C 000F166C  48 00 06 35 */	bl kar_gryaku_reset_motion_draw_state
/* 800F4870 000F1670  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 800F4874 000F1674  38 01 00 0C */	addi r0, r1, 0xc
/* 800F4878 000F1678  38 A0 00 01 */	li r5, 0x1
/* 800F487C 000F167C  3C 80 80 0F */	lis r4, kar_gryaku_check_classical_scaling_node@ha
/* 800F4880 000F1680  90 A1 00 0C */	stw r5, 0xc(r1)
/* 800F4884 000F1684  38 84 44 30 */	addi r4, r4, kar_gryaku_check_classical_scaling_node@l
/* 800F4888 000F1688  38 A1 00 08 */	addi r5, r1, 0x8
/* 800F488C 000F168C  90 01 00 08 */	stw r0, 0x8(r1)
/* 800F4890 000F1690  48 31 3F 65 */	bl HSD_JObjWalkTree
/* 800F4894 000F1694  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800F4898 000F1698  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F489C 000F169C  40 82 00 14 */	bne .L_800F48B0
/* 800F48A0 000F16A0  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F48A4 000F16A4  38 BF 01 28 */	addi r5, r31, 0x128
/* 800F48A8 000F16A8  38 80 01 36 */	li r4, 0x136
/* 800F48AC 000F16AC  48 33 3C 0D */	bl __assert
.L_800F48B0:
/* 800F48B0 000F16B0  7F C3 F3 78 */	mr r3, r30
/* 800F48B4 000F16B4  39 61 00 30 */	addi r11, r1, 0x30
/* 800F48B8 000F16B8  48 2B 92 E1 */	bl _restgpr_25
/* 800F48BC 000F16BC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F48C0 000F16C0  7C 08 03 A6 */	mtlr r0
/* 800F48C4 000F16C4  38 21 00 30 */	addi r1, r1, 0x30
/* 800F48C8 000F16C8  4E 80 00 20 */	blr
.endfn kar_gryaku_create_yaku_with_effect_index

# .text:0x930 | 0x800F48CC | size: 0x200
.fn kar_gryaku_create_yaku_from_secondary_kind, global
/* 800F48CC 000F16CC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F48D0 000F16D0  7C 08 02 A6 */	mflr r0
/* 800F48D4 000F16D4  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F48D8 000F16D8  39 61 00 20 */	addi r11, r1, 0x20
/* 800F48DC 000F16DC  48 2B 92 79 */	bl _savegpr_27
/* 800F48E0 000F16E0  7C 9B 23 79 */	mr. r27, r4
/* 800F48E4 000F16E4  3C 80 80 4A */	lis r4, kar_src_ground_804a57e8@ha
/* 800F48E8 000F16E8  83 AD 05 EC */	lwz r29, lbl_805DD6CC@sda21(r0)
/* 800F48EC 000F16EC  3B E4 57 E8 */	addi r31, r4, kar_src_ground_804a57e8@l
/* 800F48F0 000F16F0  7C 7E 1B 78 */	mr r30, r3
/* 800F48F4 000F16F4  38 80 00 00 */	li r4, 0x0
/* 800F48F8 000F16F8  41 80 00 1C */	blt .L_800F4914
/* 800F48FC 000F16FC  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800F4900 000F1700  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F4904 000F1704  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F4908 000F1708  7C 1B 00 00 */	cmpw r27, r0
/* 800F490C 000F170C  40 80 00 08 */	bge .L_800F4914
/* 800F4910 000F1710  38 80 00 01 */	li r4, 0x1
.L_800F4914:
/* 800F4914 000F1714  2C 04 00 00 */	cmpwi r4, 0x0
/* 800F4918 000F1718  40 82 00 14 */	bne .L_800F492C
/* 800F491C 000F171C  38 7F 00 00 */	addi r3, r31, 0x0
/* 800F4920 000F1720  38 BF 01 48 */	addi r5, r31, 0x148
/* 800F4924 000F1724  38 80 08 46 */	li r4, 0x846
/* 800F4928 000F1728  48 33 3B 91 */	bl __assert
.L_800F492C:
/* 800F492C 000F172C  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800F4930 000F1730  57 60 10 3A */	slwi r0, r27, 2
/* 800F4934 000F1734  83 6D 05 EC */	lwz r27, lbl_805DD6CC@sda21(r0)
/* 800F4938 000F1738  80 63 00 40 */	lwz r3, 0x40(r3)
/* 800F493C 000F173C  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800F4940 000F1740  7F 83 00 2E */	lwzx r28, r3, r0
/* 800F4944 000F1744  28 1C 00 00 */	cmplwi r28, 0x0
/* 800F4948 000F1748  40 82 00 24 */	bne .L_800F496C
/* 800F494C 000F174C  7F C4 F3 78 */	mr r4, r30
/* 800F4950 000F1750  38 7F 00 E8 */	addi r3, r31, 0xe8
/* 800F4954 000F1754  4C C6 31 82 */	crclr cr1eq
/* 800F4958 000F1758  48 2E 03 91 */	bl OSReport
/* 800F495C 000F175C  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4960 000F1760  38 80 00 C0 */	li r4, 0xc0
/* 800F4964 000F1764  38 AD 90 C8 */	li r5, lbl_805D61A8@sda21
/* 800F4968 000F1768  48 33 3B 51 */	bl __assert
.L_800F496C:
/* 800F496C 000F176C  38 60 00 0F */	li r3, 0xf
/* 800F4970 000F1770  38 80 00 08 */	li r4, 0x8
/* 800F4974 000F1774  38 A0 00 00 */	li r5, 0x0
/* 800F4978 000F1778  48 33 45 B1 */	bl HSD_GObjCreate
/* 800F497C 000F177C  3C 80 80 55 */	lis r4, gryaku_userdata_objalloc_data@ha
/* 800F4980 000F1780  7C 7F 1B 78 */	mr r31, r3
/* 800F4984 000F1784  38 04 75 84 */	addi r0, r4, gryaku_userdata_objalloc_data@l
/* 800F4988 000F1788  7C 03 03 78 */	mr r3, r0
/* 800F498C 000F178C  48 32 37 59 */	bl HSD_ObjAlloc
/* 800F4990 000F1790  7C 7D 1B 78 */	mr r29, r3
/* 800F4994 000F1794  3C 80 80 0F */	lis r4, kar_gryaku_free_userdata@ha
/* 800F4998 000F1798  38 A4 4F 0C */	addi r5, r4, kar_gryaku_free_userdata@l
/* 800F499C 000F179C  7F E3 FB 78 */	mr r3, r31
/* 800F49A0 000F17A0  38 80 00 0E */	li r4, 0xe
/* 800F49A4 000F17A4  7F A6 EB 78 */	mr r6, r29
/* 800F49A8 000F17A8  48 33 53 65 */	bl HSD_GObjUserDataLink
/* 800F49AC 000F17AC  80 DB 06 FC */	lwz r6, 0x6fc(r27)
/* 800F49B0 000F17B0  7F E3 FB 78 */	mr r3, r31
/* 800F49B4 000F17B4  7F C4 F3 78 */	mr r4, r30
/* 800F49B8 000F17B8  7F 85 E3 78 */	mr r5, r28
/* 800F49BC 000F17BC  38 06 00 01 */	addi r0, r6, 0x1
/* 800F49C0 000F17C0  90 1B 06 FC */	stw r0, 0x6fc(r27)
/* 800F49C4 000F17C4  48 00 03 8D */	bl kar_gryaku_init_userdata_base
/* 800F49C8 000F17C8  7F E3 FB 78 */	mr r3, r31
/* 800F49CC 000F17CC  48 00 1C A1 */	bl kar_gryakuanim_init_efdata_state
/* 800F49D0 000F17D0  7F E3 FB 78 */	mr r3, r31
/* 800F49D4 000F17D4  38 80 FF FF */	li r4, -0x1
/* 800F49D8 000F17D8  48 00 28 F5 */	bl kar_gryakueffect_init_rough_state
/* 800F49DC 000F17DC  7F E3 FB 78 */	mr r3, r31
/* 800F49E0 000F17E0  48 00 0D B9 */	bl kar_gryaku_noop_init_callback
/* 800F49E4 000F17E4  7F A3 EB 78 */	mr r3, r29
/* 800F49E8 000F17E8  48 00 29 21 */	bl kar_gryakueffect_init_anchor_transform
/* 800F49EC 000F17EC  38 00 00 00 */	li r0, 0x0
/* 800F49F0 000F17F0  7F A3 EB 78 */	mr r3, r29
/* 800F49F4 000F17F4  90 1D 00 70 */	stw r0, 0x70(r29)
/* 800F49F8 000F17F8  48 00 2A 05 */	bl kar_gryakueffect_sync_root_anchor_jobj_matrix
/* 800F49FC 000F17FC  7F A3 EB 78 */	mr r3, r29
/* 800F4A00 000F1800  48 00 18 75 */	bl kar_gryakuanim_init_collision_records
/* 800F4A04 000F1804  7F A3 EB 78 */	mr r3, r29
/* 800F4A08 000F1808  48 00 2D D5 */	bl kar_gryakueffect_init_audio_rail_state
/* 800F4A0C 000F180C  7F A3 EB 78 */	mr r3, r29
/* 800F4A10 000F1810  48 00 19 85 */	bl kar_gryakuanim_init_display_bbox_records
/* 800F4A14 000F1814  7F A3 EB 78 */	mr r3, r29
/* 800F4A18 000F1818  48 00 3A 6D */	bl kar_gryakulib_init_clobject_handle
/* 800F4A1C 000F181C  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_main@ha
/* 800F4A20 000F1820  7F E3 FB 78 */	mr r3, r31
/* 800F4A24 000F1824  38 84 52 84 */	addi r4, r4, kar_gryaku_proc_update_main@l
/* 800F4A28 000F1828  38 A0 00 01 */	li r5, 0x1
/* 800F4A2C 000F182C  48 33 3E 79 */	bl HSD_GObjProcCreate
/* 800F4A30 000F1830  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_effect_anim@ha
/* 800F4A34 000F1834  7F E3 FB 78 */	mr r3, r31
/* 800F4A38 000F1838  38 84 52 E8 */	addi r4, r4, kar_gryaku_proc_update_effect_anim@l
/* 800F4A3C 000F183C  38 A0 00 04 */	li r5, 0x4
/* 800F4A40 000F1840  48 33 3E 65 */	bl HSD_GObjProcCreate
/* 800F4A44 000F1844  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_f8@ha
/* 800F4A48 000F1848  7F E3 FB 78 */	mr r3, r31
/* 800F4A4C 000F184C  38 84 53 40 */	addi r4, r4, kar_gryaku_proc_callback_f8@l
/* 800F4A50 000F1850  38 A0 00 05 */	li r5, 0x5
/* 800F4A54 000F1854  48 33 3E 51 */	bl HSD_GObjProcCreate
/* 800F4A58 000F1858  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_fc@ha
/* 800F4A5C 000F185C  7F E3 FB 78 */	mr r3, r31
/* 800F4A60 000F1860  38 84 53 74 */	addi r4, r4, kar_gryaku_proc_callback_fc@l
/* 800F4A64 000F1864  38 A0 00 06 */	li r5, 0x6
/* 800F4A68 000F1868  48 33 3E 3D */	bl HSD_GObjProcCreate
/* 800F4A6C 000F186C  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_108_and_draw@ha
/* 800F4A70 000F1870  7F E3 FB 78 */	mr r3, r31
/* 800F4A74 000F1874  38 84 53 A8 */	addi r4, r4, kar_gryaku_proc_callback_108_and_draw@l
/* 800F4A78 000F1878  38 A0 00 07 */	li r5, 0x7
/* 800F4A7C 000F187C  48 33 3E 29 */	bl HSD_GObjProcCreate
/* 800F4A80 000F1880  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_collision_libs@ha
/* 800F4A84 000F1884  7F E3 FB 78 */	mr r3, r31
/* 800F4A88 000F1888  38 84 53 FC */	addi r4, r4, kar_gryaku_proc_update_collision_libs@l
/* 800F4A8C 000F188C  38 A0 00 09 */	li r5, 0x9
/* 800F4A90 000F1890  48 33 3E 15 */	bl HSD_GObjProcCreate
/* 800F4A94 000F1894  3C 80 80 0F */	lis r4, kar_gryaku_proc_apply_motion_callbacks@ha
/* 800F4A98 000F1898  7F E3 FB 78 */	mr r3, r31
/* 800F4A9C 000F189C  38 84 54 54 */	addi r4, r4, kar_gryaku_proc_apply_motion_callbacks@l
/* 800F4AA0 000F18A0  38 A0 00 0A */	li r5, 0xa
/* 800F4AA4 000F18A4  48 33 3E 01 */	bl HSD_GObjProcCreate
/* 800F4AA8 000F18A8  7F E3 FB 78 */	mr r3, r31
/* 800F4AAC 000F18AC  48 00 03 F5 */	bl kar_gryaku_reset_motion_draw_state
/* 800F4AB0 000F18B0  7F E3 FB 78 */	mr r3, r31
/* 800F4AB4 000F18B4  39 61 00 20 */	addi r11, r1, 0x20
/* 800F4AB8 000F18B8  48 2B 90 E9 */	bl _restgpr_27
/* 800F4ABC 000F18BC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4AC0 000F18C0  7C 08 03 A6 */	mtlr r0
/* 800F4AC4 000F18C4  38 21 00 20 */	addi r1, r1, 0x20
/* 800F4AC8 000F18C8  4E 80 00 20 */	blr
.endfn kar_gryaku_create_yaku_from_secondary_kind

# .text:0xB30 | 0x800F4ACC | size: 0x54
.fn kar_gryaku_get_common_kind_data, global
/* 800F4ACC 000F18CC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F4AD0 000F18D0  7C 08 02 A6 */	mflr r0
/* 800F4AD4 000F18D4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F4AD8 000F18D8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F4ADC 000F18DC  7C 7F 1B 78 */	mr r31, r3
/* 800F4AE0 000F18E0  2C 1F 00 10 */	cmpwi r31, 0x10
/* 800F4AE4 000F18E4  41 80 00 1C */	blt .L_800F4B00
/* 800F4AE8 000F18E8  3C 60 80 4A */	lis r3, kar_src_gryaku_804a5824@ha
/* 800F4AEC 000F18EC  3C A0 80 4A */	lis r5, lbl_804A596C@ha
/* 800F4AF0 000F18F0  38 63 58 24 */	addi r3, r3, kar_src_gryaku_804a5824@l
/* 800F4AF4 000F18F4  38 80 01 4E */	li r4, 0x14e
/* 800F4AF8 000F18F8  38 A5 59 6C */	addi r5, r5, lbl_804A596C@l
/* 800F4AFC 000F18FC  48 33 39 BD */	bl __assert
.L_800F4B00:
/* 800F4B00 000F1900  80 6D 05 E4 */	lwz r3, lbl_805DD6C4@sda21(r0)
/* 800F4B04 000F1904  57 E0 10 3A */	slwi r0, r31, 2
/* 800F4B08 000F1908  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F4B0C 000F190C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F4B10 000F1910  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F4B14 000F1914  7C 08 03 A6 */	mtlr r0
/* 800F4B18 000F1918  38 21 00 10 */	addi r1, r1, 0x10
/* 800F4B1C 000F191C  4E 80 00 20 */	blr
.endfn kar_gryaku_get_common_kind_data

# .text:0xB84 | 0x800F4B20 | size: 0x230
.fn kar_gryaku_create_common_yaku_by_kind, global
/* 800F4B20 000F1920  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F4B24 000F1924  7C 08 02 A6 */	mflr r0
/* 800F4B28 000F1928  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F4B2C 000F192C  39 61 00 30 */	addi r11, r1, 0x30
/* 800F4B30 000F1930  48 2B 90 1D */	bl _savegpr_25
/* 800F4B34 000F1934  7C 79 1B 78 */	mr r25, r3
/* 800F4B38 000F1938  3C 60 80 4A */	lis r3, kar_src_ground_804a57e8@ha
/* 800F4B3C 000F193C  2C 19 00 10 */	cmpwi r25, 0x10
/* 800F4B40 000F1940  7C 9D 23 78 */	mr r29, r4
/* 800F4B44 000F1944  3B E3 57 E8 */	addi r31, r3, kar_src_ground_804a57e8@l
/* 800F4B48 000F1948  41 80 00 14 */	blt .L_800F4B5C
/* 800F4B4C 000F194C  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4B50 000F1950  38 BF 01 84 */	addi r5, r31, 0x184
/* 800F4B54 000F1954  38 80 01 4E */	li r4, 0x14e
/* 800F4B58 000F1958  48 33 39 61 */	bl __assert
.L_800F4B5C:
/* 800F4B5C 000F195C  80 6D 05 E4 */	lwz r3, lbl_805DD6C4@sda21(r0)
/* 800F4B60 000F1960  57 20 10 3A */	slwi r0, r25, 2
/* 800F4B64 000F1964  83 4D 05 EC */	lwz r26, lbl_805DD6CC@sda21(r0)
/* 800F4B68 000F1968  7F 83 00 2E */	lwzx r28, r3, r0
/* 800F4B6C 000F196C  28 1C 00 00 */	cmplwi r28, 0x0
/* 800F4B70 000F1970  40 82 00 24 */	bne .L_800F4B94
/* 800F4B74 000F1974  7F 24 CB 78 */	mr r4, r25
/* 800F4B78 000F1978  38 7F 00 E8 */	addi r3, r31, 0xe8
/* 800F4B7C 000F197C  4C C6 31 82 */	crclr cr1eq
/* 800F4B80 000F1980  48 2E 01 69 */	bl OSReport
/* 800F4B84 000F1984  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4B88 000F1988  38 80 00 C0 */	li r4, 0xc0
/* 800F4B8C 000F198C  38 AD 90 C8 */	li r5, lbl_805D61A8@sda21
/* 800F4B90 000F1990  48 33 39 29 */	bl __assert
.L_800F4B94:
/* 800F4B94 000F1994  38 60 00 0F */	li r3, 0xf
/* 800F4B98 000F1998  38 80 00 08 */	li r4, 0x8
/* 800F4B9C 000F199C  38 A0 00 00 */	li r5, 0x0
/* 800F4BA0 000F19A0  48 33 43 89 */	bl HSD_GObjCreate
/* 800F4BA4 000F19A4  3C 80 80 55 */	lis r4, gryaku_userdata_objalloc_data@ha
/* 800F4BA8 000F19A8  7C 7E 1B 78 */	mr r30, r3
/* 800F4BAC 000F19AC  38 04 75 84 */	addi r0, r4, gryaku_userdata_objalloc_data@l
/* 800F4BB0 000F19B0  7C 03 03 78 */	mr r3, r0
/* 800F4BB4 000F19B4  48 32 35 31 */	bl HSD_ObjAlloc
/* 800F4BB8 000F19B8  7C 7B 1B 78 */	mr r27, r3
/* 800F4BBC 000F19BC  3C 80 80 0F */	lis r4, kar_gryaku_free_userdata@ha
/* 800F4BC0 000F19C0  38 A4 4F 0C */	addi r5, r4, kar_gryaku_free_userdata@l
/* 800F4BC4 000F19C4  7F C3 F3 78 */	mr r3, r30
/* 800F4BC8 000F19C8  38 80 00 0E */	li r4, 0xe
/* 800F4BCC 000F19CC  7F 66 DB 78 */	mr r6, r27
/* 800F4BD0 000F19D0  48 33 51 3D */	bl HSD_GObjUserDataLink
/* 800F4BD4 000F19D4  80 DA 06 FC */	lwz r6, 0x6fc(r26)
/* 800F4BD8 000F19D8  7F C3 F3 78 */	mr r3, r30
/* 800F4BDC 000F19DC  7F 24 CB 78 */	mr r4, r25
/* 800F4BE0 000F19E0  7F 85 E3 78 */	mr r5, r28
/* 800F4BE4 000F19E4  38 06 00 01 */	addi r0, r6, 0x1
/* 800F4BE8 000F19E8  90 1A 06 FC */	stw r0, 0x6fc(r26)
/* 800F4BEC 000F19EC  48 00 01 65 */	bl kar_gryaku_init_userdata_base
/* 800F4BF0 000F19F0  7F C3 F3 78 */	mr r3, r30
/* 800F4BF4 000F19F4  48 00 1A 79 */	bl kar_gryakuanim_init_efdata_state
/* 800F4BF8 000F19F8  7F C3 F3 78 */	mr r3, r30
/* 800F4BFC 000F19FC  7F A4 EB 78 */	mr r4, r29
/* 800F4C00 000F1A00  48 00 26 CD */	bl kar_gryakueffect_init_rough_state
/* 800F4C04 000F1A04  7F C3 F3 78 */	mr r3, r30
/* 800F4C08 000F1A08  48 00 0B 91 */	bl kar_gryaku_noop_init_callback
/* 800F4C0C 000F1A0C  7F 63 DB 78 */	mr r3, r27
/* 800F4C10 000F1A10  48 00 26 F9 */	bl kar_gryakueffect_init_anchor_transform
/* 800F4C14 000F1A14  2C 1D FF FF */	cmpwi r29, -0x1
/* 800F4C18 000F1A18  41 82 00 18 */	beq .L_800F4C30
/* 800F4C1C 000F1A1C  80 7A 01 04 */	lwz r3, 0x104(r26)
/* 800F4C20 000F1A20  57 A0 18 38 */	slwi r0, r29, 3
/* 800F4C24 000F1A24  7C 03 00 2E */	lwzx r0, r3, r0
/* 800F4C28 000F1A28  90 1B 00 70 */	stw r0, 0x70(r27)
/* 800F4C2C 000F1A2C  48 00 00 0C */	b .L_800F4C38
.L_800F4C30:
/* 800F4C30 000F1A30  38 00 00 00 */	li r0, 0x0
/* 800F4C34 000F1A34  90 1B 00 70 */	stw r0, 0x70(r27)
.L_800F4C38:
/* 800F4C38 000F1A38  7F 63 DB 78 */	mr r3, r27
/* 800F4C3C 000F1A3C  48 00 27 C1 */	bl kar_gryakueffect_sync_root_anchor_jobj_matrix
/* 800F4C40 000F1A40  7F 63 DB 78 */	mr r3, r27
/* 800F4C44 000F1A44  48 00 16 31 */	bl kar_gryakuanim_init_collision_records
/* 800F4C48 000F1A48  7F 63 DB 78 */	mr r3, r27
/* 800F4C4C 000F1A4C  48 00 2B 91 */	bl kar_gryakueffect_init_audio_rail_state
/* 800F4C50 000F1A50  7F 63 DB 78 */	mr r3, r27
/* 800F4C54 000F1A54  48 00 17 41 */	bl kar_gryakuanim_init_display_bbox_records
/* 800F4C58 000F1A58  7F 63 DB 78 */	mr r3, r27
/* 800F4C5C 000F1A5C  48 00 38 29 */	bl kar_gryakulib_init_clobject_handle
/* 800F4C60 000F1A60  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_main@ha
/* 800F4C64 000F1A64  7F C3 F3 78 */	mr r3, r30
/* 800F4C68 000F1A68  38 84 52 84 */	addi r4, r4, kar_gryaku_proc_update_main@l
/* 800F4C6C 000F1A6C  38 A0 00 01 */	li r5, 0x1
/* 800F4C70 000F1A70  48 33 3C 35 */	bl HSD_GObjProcCreate
/* 800F4C74 000F1A74  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_effect_anim@ha
/* 800F4C78 000F1A78  7F C3 F3 78 */	mr r3, r30
/* 800F4C7C 000F1A7C  38 84 52 E8 */	addi r4, r4, kar_gryaku_proc_update_effect_anim@l
/* 800F4C80 000F1A80  38 A0 00 04 */	li r5, 0x4
/* 800F4C84 000F1A84  48 33 3C 21 */	bl HSD_GObjProcCreate
/* 800F4C88 000F1A88  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_f8@ha
/* 800F4C8C 000F1A8C  7F C3 F3 78 */	mr r3, r30
/* 800F4C90 000F1A90  38 84 53 40 */	addi r4, r4, kar_gryaku_proc_callback_f8@l
/* 800F4C94 000F1A94  38 A0 00 05 */	li r5, 0x5
/* 800F4C98 000F1A98  48 33 3C 0D */	bl HSD_GObjProcCreate
/* 800F4C9C 000F1A9C  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_fc@ha
/* 800F4CA0 000F1AA0  7F C3 F3 78 */	mr r3, r30
/* 800F4CA4 000F1AA4  38 84 53 74 */	addi r4, r4, kar_gryaku_proc_callback_fc@l
/* 800F4CA8 000F1AA8  38 A0 00 06 */	li r5, 0x6
/* 800F4CAC 000F1AAC  48 33 3B F9 */	bl HSD_GObjProcCreate
/* 800F4CB0 000F1AB0  3C 80 80 0F */	lis r4, kar_gryaku_proc_callback_108_and_draw@ha
/* 800F4CB4 000F1AB4  7F C3 F3 78 */	mr r3, r30
/* 800F4CB8 000F1AB8  38 84 53 A8 */	addi r4, r4, kar_gryaku_proc_callback_108_and_draw@l
/* 800F4CBC 000F1ABC  38 A0 00 07 */	li r5, 0x7
/* 800F4CC0 000F1AC0  48 33 3B E5 */	bl HSD_GObjProcCreate
/* 800F4CC4 000F1AC4  3C 80 80 0F */	lis r4, kar_gryaku_proc_update_collision_libs@ha
/* 800F4CC8 000F1AC8  7F C3 F3 78 */	mr r3, r30
/* 800F4CCC 000F1ACC  38 84 53 FC */	addi r4, r4, kar_gryaku_proc_update_collision_libs@l
/* 800F4CD0 000F1AD0  38 A0 00 09 */	li r5, 0x9
/* 800F4CD4 000F1AD4  48 33 3B D1 */	bl HSD_GObjProcCreate
/* 800F4CD8 000F1AD8  3C 80 80 0F */	lis r4, kar_gryaku_proc_apply_motion_callbacks@ha
/* 800F4CDC 000F1ADC  7F C3 F3 78 */	mr r3, r30
/* 800F4CE0 000F1AE0  38 84 54 54 */	addi r4, r4, kar_gryaku_proc_apply_motion_callbacks@l
/* 800F4CE4 000F1AE4  38 A0 00 0A */	li r5, 0xa
/* 800F4CE8 000F1AE8  48 33 3B BD */	bl HSD_GObjProcCreate
/* 800F4CEC 000F1AEC  7F C3 F3 78 */	mr r3, r30
/* 800F4CF0 000F1AF0  48 00 01 B1 */	bl kar_gryaku_reset_motion_draw_state
/* 800F4CF4 000F1AF4  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 800F4CF8 000F1AF8  38 01 00 0C */	addi r0, r1, 0xc
/* 800F4CFC 000F1AFC  38 A0 00 01 */	li r5, 0x1
/* 800F4D00 000F1B00  3C 80 80 0F */	lis r4, kar_gryaku_check_classical_scaling_node@ha
/* 800F4D04 000F1B04  90 A1 00 0C */	stw r5, 0xc(r1)
/* 800F4D08 000F1B08  38 84 44 30 */	addi r4, r4, kar_gryaku_check_classical_scaling_node@l
/* 800F4D0C 000F1B0C  38 A1 00 08 */	addi r5, r1, 0x8
/* 800F4D10 000F1B10  90 01 00 08 */	stw r0, 0x8(r1)
/* 800F4D14 000F1B14  48 31 3A E1 */	bl HSD_JObjWalkTree
/* 800F4D18 000F1B18  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800F4D1C 000F1B1C  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F4D20 000F1B20  40 82 00 14 */	bne .L_800F4D34
/* 800F4D24 000F1B24  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4D28 000F1B28  38 BF 01 28 */	addi r5, r31, 0x128
/* 800F4D2C 000F1B2C  38 80 01 5C */	li r4, 0x15c
/* 800F4D30 000F1B30  48 33 37 89 */	bl __assert
.L_800F4D34:
/* 800F4D34 000F1B34  7F C3 F3 78 */	mr r3, r30
/* 800F4D38 000F1B38  39 61 00 30 */	addi r11, r1, 0x30
/* 800F4D3C 000F1B3C  48 2B 8E 5D */	bl _restgpr_25
/* 800F4D40 000F1B40  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F4D44 000F1B44  7C 08 03 A6 */	mtlr r0
/* 800F4D48 000F1B48  38 21 00 30 */	addi r1, r1, 0x30
/* 800F4D4C 000F1B4C  4E 80 00 20 */	blr
.endfn kar_gryaku_create_common_yaku_by_kind

# .text:0xDB4 | 0x800F4D50 | size: 0x150
.fn kar_gryaku_init_userdata_base, global
/* 800F4D50 000F1B50  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F4D54 000F1B54  7C 08 02 A6 */	mflr r0
/* 800F4D58 000F1B58  38 C0 00 00 */	li r6, 0x0
/* 800F4D5C 000F1B5C  C0 22 90 E0 */	lfs f1, lbl_805DF7E0@sda21(r0)
/* 800F4D60 000F1B60  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F4D64 000F1B64  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800F4D68 000F1B68  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F4D6C 000F1B6C  90 9F 00 04 */	stw r4, 0x4(r31)
/* 800F4D70 000F1B70  90 BF 00 08 */	stw r5, 0x8(r31)
/* 800F4D74 000F1B74  90 7F 00 00 */	stw r3, 0x0(r31)
/* 800F4D78 000F1B78  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F4D7C 000F1B7C  50 C0 3E 30 */	rlwimi r0, r6, 7, 24, 24
/* 800F4D80 000F1B80  98 1F 01 2C */	stb r0, 0x12c(r31)
/* 800F4D84 000F1B84  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F4D88 000F1B88  50 C0 36 72 */	rlwimi r0, r6, 6, 25, 25
/* 800F4D8C 000F1B8C  98 1F 01 2C */	stb r0, 0x12c(r31)
/* 800F4D90 000F1B90  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F4D94 000F1B94  50 C0 26 F6 */	rlwimi r0, r6, 4, 27, 27
/* 800F4D98 000F1B98  98 1F 01 2C */	stb r0, 0x12c(r31)
/* 800F4D9C 000F1B9C  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F4DA0 000F1BA0  50 C0 1F 38 */	rlwimi r0, r6, 3, 28, 28
/* 800F4DA4 000F1BA4  98 1F 01 2C */	stb r0, 0x12c(r31)
/* 800F4DA8 000F1BA8  D0 3F 00 A4 */	stfs f1, 0xa4(r31)
/* 800F4DAC 000F1BAC  C0 1F 00 A4 */	lfs f0, 0xa4(r31)
/* 800F4DB0 000F1BB0  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 800F4DB4 000F1BB4  41 82 00 1C */	beq .L_800F4DD0
/* 800F4DB8 000F1BB8  3C 60 80 4A */	lis r3, kar_src_gryaku_804a5824@ha
/* 800F4DBC 000F1BBC  3C A0 80 4A */	lis r5, lbl_804A5990@ha
/* 800F4DC0 000F1BC0  38 63 58 24 */	addi r3, r3, kar_src_gryaku_804a5824@l
/* 800F4DC4 000F1BC4  38 80 01 7B */	li r4, 0x17b
/* 800F4DC8 000F1BC8  38 A5 59 90 */	addi r5, r5, lbl_804A5990@l
/* 800F4DCC 000F1BCC  48 33 36 ED */	bl __assert
.L_800F4DD0:
/* 800F4DD0 000F1BD0  C0 22 90 E4 */	lfs f1, lbl_805DF7E4@sda21(r0)
/* 800F4DD4 000F1BD4  7F E3 FB 78 */	mr r3, r31
/* 800F4DD8 000F1BD8  C0 02 90 E0 */	lfs f0, lbl_805DF7E0@sda21(r0)
/* 800F4DDC 000F1BDC  38 81 00 14 */	addi r4, r1, 0x14
/* 800F4DE0 000F1BE0  D0 21 00 14 */	stfs f1, 0x14(r1)
/* 800F4DE4 000F1BE4  38 A1 00 08 */	addi r5, r1, 0x8
/* 800F4DE8 000F1BE8  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 800F4DEC 000F1BEC  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 800F4DF0 000F1BF0  D0 21 00 08 */	stfs f1, 0x8(r1)
/* 800F4DF4 000F1BF4  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 800F4DF8 000F1BF8  D0 21 00 10 */	stfs f1, 0x10(r1)
/* 800F4DFC 000F1BFC  48 00 39 89 */	bl kar_gryakulib_set_orientation_basis
/* 800F4E00 000F1C00  38 A0 00 00 */	li r5, 0x0
/* 800F4E04 000F1C04  3C 60 80 4A */	lis r3, gryaku_kind_function_table@ha
/* 800F4E08 000F1C08  90 BF 00 A0 */	stw r5, 0xa0(r31)
/* 800F4E0C 000F1C0C  38 80 00 05 */	li r4, 0x5
/* 800F4E10 000F1C10  C0 02 90 E4 */	lfs f0, lbl_805DF7E4@sda21(r0)
/* 800F4E14 000F1C14  38 00 FF FF */	li r0, -0x1
/* 800F4E18 000F1C18  38 63 5B E8 */	addi r3, r3, gryaku_kind_function_table@l
/* 800F4E1C 000F1C1C  D0 1F 00 AC */	stfs f0, 0xac(r31)
/* 800F4E20 000F1C20  90 9F 00 B0 */	stw r4, 0xb0(r31)
/* 800F4E24 000F1C24  90 BF 00 F0 */	stw r5, 0xf0(r31)
/* 800F4E28 000F1C28  90 BF 00 F4 */	stw r5, 0xf4(r31)
/* 800F4E2C 000F1C2C  90 BF 00 F8 */	stw r5, 0xf8(r31)
/* 800F4E30 000F1C30  90 BF 00 FC */	stw r5, 0xfc(r31)
/* 800F4E34 000F1C34  90 BF 01 08 */	stw r5, 0x108(r31)
/* 800F4E38 000F1C38  90 BF 01 00 */	stw r5, 0x100(r31)
/* 800F4E3C 000F1C3C  90 BF 01 04 */	stw r5, 0x104(r31)
/* 800F4E40 000F1C40  90 1F 00 74 */	stw r0, 0x74(r31)
/* 800F4E44 000F1C44  90 BF 00 78 */	stw r5, 0x78(r31)
/* 800F4E48 000F1C48  90 1F 00 7C */	stw r0, 0x7c(r31)
/* 800F4E4C 000F1C4C  90 BF 00 80 */	stw r5, 0x80(r31)
/* 800F4E50 000F1C50  80 9F 00 04 */	lwz r4, 0x4(r31)
/* 800F4E54 000F1C54  54 80 10 3A */	slwi r0, r4, 2
/* 800F4E58 000F1C58  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F4E5C 000F1C5C  28 03 00 00 */	cmplwi r3, 0x0
/* 800F4E60 000F1C60  41 82 00 18 */	beq .L_800F4E78
/* 800F4E64 000F1C64  2C 04 00 46 */	cmpwi r4, 0x46
/* 800F4E68 000F1C68  40 80 00 10 */	bge .L_800F4E78
/* 800F4E6C 000F1C6C  80 03 00 00 */	lwz r0, 0x0(r3)
/* 800F4E70 000F1C70  90 1F 00 84 */	stw r0, 0x84(r31)
/* 800F4E74 000F1C74  48 00 00 0C */	b .L_800F4E80
.L_800F4E78:
/* 800F4E78 000F1C78  38 00 00 00 */	li r0, 0x0
/* 800F4E7C 000F1C7C  90 1F 00 84 */	stw r0, 0x84(r31)
.L_800F4E80:
/* 800F4E80 000F1C80  38 00 00 00 */	li r0, 0x0
/* 800F4E84 000F1C84  90 1F 00 B4 */	stw r0, 0xb4(r31)
/* 800F4E88 000F1C88  90 1F 00 B8 */	stw r0, 0xb8(r31)
/* 800F4E8C 000F1C8C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800F4E90 000F1C90  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F4E94 000F1C94  7C 08 03 A6 */	mtlr r0
/* 800F4E98 000F1C98  38 21 00 30 */	addi r1, r1, 0x30
/* 800F4E9C 000F1C9C  4E 80 00 20 */	blr
.endfn kar_gryaku_init_userdata_base

# .text:0xF04 | 0x800F4EA0 | size: 0x6C
.fn kar_gryaku_reset_motion_draw_state, global
/* 800F4EA0 000F1CA0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F4EA4 000F1CA4  7C 08 02 A6 */	mflr r0
/* 800F4EA8 000F1CA8  C0 22 90 E4 */	lfs f1, lbl_805DF7E4@sda21(r0)
/* 800F4EAC 000F1CAC  38 80 00 00 */	li r4, 0x0
/* 800F4EB0 000F1CB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F4EB4 000F1CB4  38 A0 00 02 */	li r5, 0x2
/* 800F4EB8 000F1CB8  C0 02 90 E0 */	lfs f0, lbl_805DF7E0@sda21(r0)
/* 800F4EBC 000F1CBC  38 C0 00 00 */	li r6, 0x0
/* 800F4EC0 000F1CC0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F4EC4 000F1CC4  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F4EC8 000F1CC8  38 60 00 00 */	li r3, 0x0
/* 800F4ECC 000F1CCC  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F4ED0 000F1CD0  50 60 2E B4 */	rlwimi r0, r3, 5, 26, 26
/* 800F4ED4 000F1CD4  98 1F 01 2C */	stb r0, 0x12c(r31)
/* 800F4ED8 000F1CD8  D0 3F 00 E0 */	stfs f1, 0xe0(r31)
/* 800F4EDC 000F1CDC  D0 3F 00 E4 */	stfs f1, 0xe4(r31)
/* 800F4EE0 000F1CE0  D0 1F 00 E8 */	stfs f0, 0xe8(r31)
/* 800F4EE4 000F1CE4  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 800F4EE8 000F1CE8  C0 3F 00 A4 */	lfs f1, 0xa4(r31)
/* 800F4EEC 000F1CEC  48 09 74 C9 */	bl kar_collision_object_reset_handle
/* 800F4EF0 000F1CF0  7F E3 FB 78 */	mr r3, r31
/* 800F4EF4 000F1CF4  48 00 42 71 */	bl kar_gryakucommon_reset_opcode_cursor
/* 800F4EF8 000F1CF8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F4EFC 000F1CFC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F4F00 000F1D00  7C 08 03 A6 */	mtlr r0
/* 800F4F04 000F1D04  38 21 00 10 */	addi r1, r1, 0x10
/* 800F4F08 000F1D08  4E 80 00 20 */	blr
.endfn kar_gryaku_reset_motion_draw_state

# .text:0xF70 | 0x800F4F0C | size: 0xF8
.fn kar_gryaku_free_userdata, global
/* 800F4F0C 000F1D0C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F4F10 000F1D10  7C 08 02 A6 */	mflr r0
/* 800F4F14 000F1D14  3C 80 80 4A */	lis r4, kar_src_ground_804a57e8@ha
/* 800F4F18 000F1D18  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F4F1C 000F1D1C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F4F20 000F1D20  3B E4 57 E8 */	addi r31, r4, kar_src_ground_804a57e8@l
/* 800F4F24 000F1D24  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F4F28 000F1D28  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F4F2C 000F1D2C  7C 7D 1B 78 */	mr r29, r3
/* 800F4F30 000F1D30  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800F4F34 000F1D34  83 CD 05 EC */	lwz r30, lbl_805DD6CC@sda21(r0)
/* 800F4F38 000F1D38  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F4F3C 000F1D3C  28 00 00 00 */	cmplwi r0, 0x0
/* 800F4F40 000F1D40  41 82 00 14 */	beq .L_800F4F54
/* 800F4F44 000F1D44  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4F48 000F1D48  38 BF 01 C8 */	addi r5, r31, 0x1c8
/* 800F4F4C 000F1D4C  38 80 01 D5 */	li r4, 0x1d5
/* 800F4F50 000F1D50  48 33 35 69 */	bl __assert
.L_800F4F54:
/* 800F4F54 000F1D54  80 1D 00 04 */	lwz r0, 0x4(r29)
/* 800F4F58 000F1D58  3C 60 80 4A */	lis r3, gryaku_kind_function_table@ha
/* 800F4F5C 000F1D5C  38 63 5B E8 */	addi r3, r3, gryaku_kind_function_table@l
/* 800F4F60 000F1D60  54 00 10 3A */	slwi r0, r0, 2
/* 800F4F64 000F1D64  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F4F68 000F1D68  28 03 00 00 */	cmplwi r3, 0x0
/* 800F4F6C 000F1D6C  41 82 00 1C */	beq .L_800F4F88
/* 800F4F70 000F1D70  81 83 00 08 */	lwz r12, 0x8(r3)
/* 800F4F74 000F1D74  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F4F78 000F1D78  41 82 00 10 */	beq .L_800F4F88
/* 800F4F7C 000F1D7C  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 800F4F80 000F1D80  7D 89 03 A6 */	mtctr r12
/* 800F4F84 000F1D84  4E 80 04 21 */	bctrl
.L_800F4F88:
/* 800F4F88 000F1D88  7F A3 EB 78 */	mr r3, r29
/* 800F4F8C 000F1D8C  48 00 35 F1 */	bl kar_gryakulib_free_clobject_handle
/* 800F4F90 000F1D90  7F A3 EB 78 */	mr r3, r29
/* 800F4F94 000F1D94  48 00 28 B9 */	bl kar_gryakueffect_stop_audio_rail_state
/* 800F4F98 000F1D98  7F A3 EB 78 */	mr r3, r29
/* 800F4F9C 000F1D9C  48 00 14 79 */	bl kar_gryakuanim_free_display_bbox_records
/* 800F4FA0 000F1DA0  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 800F4FA4 000F1DA4  48 00 17 05 */	bl kar_gryakuanim_destroy_efdata_state
/* 800F4FA8 000F1DA8  7F A3 EB 78 */	mr r3, r29
/* 800F4FAC 000F1DAC  48 00 23 BD */	bl kar_gryakueffect_free_anchor_transform
/* 800F4FB0 000F1DB0  3C 60 80 55 */	lis r3, gryaku_userdata_objalloc_data@ha
/* 800F4FB4 000F1DB4  7F A4 EB 78 */	mr r4, r29
/* 800F4FB8 000F1DB8  38 63 75 84 */	addi r3, r3, gryaku_userdata_objalloc_data@l
/* 800F4FBC 000F1DBC  48 32 32 79 */	bl HSD_ObjFree
/* 800F4FC0 000F1DC0  80 1E 06 FC */	lwz r0, 0x6fc(r30)
/* 800F4FC4 000F1DC4  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F4FC8 000F1DC8  41 81 00 14 */	bgt .L_800F4FDC
/* 800F4FCC 000F1DCC  38 7F 00 3C */	addi r3, r31, 0x3c
/* 800F4FD0 000F1DD0  38 BF 01 E4 */	addi r5, r31, 0x1e4
/* 800F4FD4 000F1DD4  38 80 01 F0 */	li r4, 0x1f0
/* 800F4FD8 000F1DD8  48 33 34 E1 */	bl __assert
.L_800F4FDC:
/* 800F4FDC 000F1DDC  80 7E 06 FC */	lwz r3, 0x6fc(r30)
/* 800F4FE0 000F1DE0  38 03 FF FF */	subi r0, r3, 0x1
/* 800F4FE4 000F1DE4  90 1E 06 FC */	stw r0, 0x6fc(r30)
/* 800F4FE8 000F1DE8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F4FEC 000F1DEC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F4FF0 000F1DF0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F4FF4 000F1DF4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4FF8 000F1DF8  7C 08 03 A6 */	mtlr r0
/* 800F4FFC 000F1DFC  38 21 00 20 */	addi r1, r1, 0x20
/* 800F5000 000F1E00  4E 80 00 20 */	blr
.endfn kar_gryaku_free_userdata

# .text:0x1068 | 0x800F5004 | size: 0xD4
.fn kar_gryaku_dispatch_map_collision_response, global
/* 800F5004 000F1E04  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F5008 000F1E08  7C 08 02 A6 */	mflr r0
/* 800F500C 000F1E0C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F5010 000F1E10  39 61 00 20 */	addi r11, r1, 0x20
/* 800F5014 000F1E14  48 2B 8B 3D */	bl _savegpr_26
/* 800F5018 000F1E18  7C 7B 1B 79 */	mr. r27, r3
/* 800F501C 000F1E1C  7C 9C 23 78 */	mr r28, r4
/* 800F5020 000F1E20  7C BD 2B 78 */	mr r29, r5
/* 800F5024 000F1E24  7C DE 33 78 */	mr r30, r6
/* 800F5028 000F1E28  7C FF 3B 78 */	mr r31, r7
/* 800F502C 000F1E2C  40 82 00 0C */	bne .L_800F5038
/* 800F5030 000F1E30  38 60 00 00 */	li r3, 0x0
/* 800F5034 000F1E34  48 00 00 8C */	b .L_800F50C0
.L_800F5038:
/* 800F5038 000F1E38  83 5B 00 2C */	lwz r26, 0x2c(r27)
/* 800F503C 000F1E3C  3C 60 80 4A */	lis r3, gryaku_kind_function_table@ha
/* 800F5040 000F1E40  38 63 5B E8 */	addi r3, r3, gryaku_kind_function_table@l
/* 800F5044 000F1E44  38 80 00 00 */	li r4, 0x0
/* 800F5048 000F1E48  80 1A 00 04 */	lwz r0, 0x4(r26)
/* 800F504C 000F1E4C  54 00 10 3A */	slwi r0, r0, 2
/* 800F5050 000F1E50  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F5054 000F1E54  28 03 00 00 */	cmplwi r3, 0x0
/* 800F5058 000F1E58  41 82 00 14 */	beq .L_800F506C
/* 800F505C 000F1E5C  80 03 00 04 */	lwz r0, 0x4(r3)
/* 800F5060 000F1E60  28 00 00 00 */	cmplwi r0, 0x0
/* 800F5064 000F1E64  41 82 00 08 */	beq .L_800F506C
/* 800F5068 000F1E68  38 80 00 01 */	li r4, 0x1
.L_800F506C:
/* 800F506C 000F1E6C  2C 04 00 00 */	cmpwi r4, 0x0
/* 800F5070 000F1E70  40 82 00 1C */	bne .L_800F508C
/* 800F5074 000F1E74  3C 60 80 4A */	lis r3, kar_src_gryaku_804a5824@ha
/* 800F5078 000F1E78  3C A0 80 4A */	lis r5, lbl_804A59E0@ha
/* 800F507C 000F1E7C  38 63 58 24 */	addi r3, r3, kar_src_gryaku_804a5824@l
/* 800F5080 000F1E80  38 80 02 06 */	li r4, 0x206
/* 800F5084 000F1E84  38 A5 59 E0 */	addi r5, r5, lbl_804A59E0@l
/* 800F5088 000F1E88  48 33 34 31 */	bl __assert
.L_800F508C:
/* 800F508C 000F1E8C  80 1A 00 04 */	lwz r0, 0x4(r26)
/* 800F5090 000F1E90  3C 60 80 4A */	lis r3, gryaku_kind_function_table@ha
/* 800F5094 000F1E94  38 A3 5B E8 */	addi r5, r3, gryaku_kind_function_table@l
/* 800F5098 000F1E98  7F 63 DB 78 */	mr r3, r27
/* 800F509C 000F1E9C  54 00 10 3A */	slwi r0, r0, 2
/* 800F50A0 000F1EA0  7F 84 E3 78 */	mr r4, r28
/* 800F50A4 000F1EA4  7D 05 00 2E */	lwzx r8, r5, r0
/* 800F50A8 000F1EA8  7F A5 EB 78 */	mr r5, r29
/* 800F50AC 000F1EAC  7F C6 F3 78 */	mr r6, r30
/* 800F50B0 000F1EB0  7F E7 FB 78 */	mr r7, r31
/* 800F50B4 000F1EB4  81 88 00 04 */	lwz r12, 0x4(r8)
/* 800F50B8 000F1EB8  7D 89 03 A6 */	mtctr r12
/* 800F50BC 000F1EBC  4E 80 04 21 */	bctrl
.L_800F50C0:
/* 800F50C0 000F1EC0  39 61 00 20 */	addi r11, r1, 0x20
/* 800F50C4 000F1EC4  48 2B 8A D9 */	bl _restgpr_26
/* 800F50C8 000F1EC8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F50CC 000F1ECC  7C 08 03 A6 */	mtlr r0
/* 800F50D0 000F1ED0  38 21 00 20 */	addi r1, r1, 0x20
/* 800F50D4 000F1ED4  4E 80 00 20 */	blr
.endfn kar_gryaku_dispatch_map_collision_response

# .text:0x113C | 0x800F50D8 | size: 0xCC
.fn kar_gryaku_dispatch_grcoll_callback, global
/* 800F50D8 000F1ED8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F50DC 000F1EDC  7C 08 02 A6 */	mflr r0
/* 800F50E0 000F1EE0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F50E4 000F1EE4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F50E8 000F1EE8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F50EC 000F1EEC  7C BE 2B 78 */	mr r30, r5
/* 800F50F0 000F1EF0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F50F4 000F1EF4  7C 9D 23 78 */	mr r29, r4
/* 800F50F8 000F1EF8  93 81 00 10 */	stw r28, 0x10(r1)
/* 800F50FC 000F1EFC  7C 7C 1B 79 */	mr. r28, r3
/* 800F5100 000F1F00  41 82 00 84 */	beq .L_800F5184
/* 800F5104 000F1F04  83 FC 00 2C */	lwz r31, 0x2c(r28)
/* 800F5108 000F1F08  3C 60 80 4A */	lis r3, gryaku_kind_function_table@ha
/* 800F510C 000F1F0C  38 63 5B E8 */	addi r3, r3, gryaku_kind_function_table@l
/* 800F5110 000F1F10  38 80 00 00 */	li r4, 0x0
/* 800F5114 000F1F14  80 1F 00 04 */	lwz r0, 0x4(r31)
/* 800F5118 000F1F18  54 00 10 3A */	slwi r0, r0, 2
/* 800F511C 000F1F1C  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F5120 000F1F20  28 03 00 00 */	cmplwi r3, 0x0
/* 800F5124 000F1F24  41 82 00 14 */	beq .L_800F5138
/* 800F5128 000F1F28  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F512C 000F1F2C  28 00 00 00 */	cmplwi r0, 0x0
/* 800F5130 000F1F30  41 82 00 08 */	beq .L_800F5138
/* 800F5134 000F1F34  38 80 00 01 */	li r4, 0x1
.L_800F5138:
/* 800F5138 000F1F38  2C 04 00 00 */	cmpwi r4, 0x0
/* 800F513C 000F1F3C  40 82 00 1C */	bne .L_800F5158
/* 800F5140 000F1F40  3C 60 80 4A */	lis r3, kar_src_gryaku_804a5824@ha
/* 800F5144 000F1F44  3C A0 80 4A */	lis r5, lbl_804A5A24@ha
/* 800F5148 000F1F48  38 63 58 24 */	addi r3, r3, kar_src_gryaku_804a5824@l
/* 800F514C 000F1F4C  38 80 02 15 */	li r4, 0x215
/* 800F5150 000F1F50  38 A5 5A 24 */	addi r5, r5, lbl_804A5A24@l
/* 800F5154 000F1F54  48 33 33 65 */	bl __assert
.L_800F5158:
/* 800F5158 000F1F58  80 1F 00 04 */	lwz r0, 0x4(r31)
/* 800F515C 000F1F5C  3C 60 80 4A */	lis r3, gryaku_kind_function_table@ha
/* 800F5160 000F1F60  38 A3 5B E8 */	addi r5, r3, gryaku_kind_function_table@l
/* 800F5164 000F1F64  7F 83 E3 78 */	mr r3, r28
/* 800F5168 000F1F68  54 00 10 3A */	slwi r0, r0, 2
/* 800F516C 000F1F6C  7F A4 EB 78 */	mr r4, r29
/* 800F5170 000F1F70  7C C5 00 2E */	lwzx r6, r5, r0
/* 800F5174 000F1F74  7F C5 F3 78 */	mr r5, r30
/* 800F5178 000F1F78  81 86 00 0C */	lwz r12, 0xc(r6)
/* 800F517C 000F1F7C  7D 89 03 A6 */	mtctr r12
/* 800F5180 000F1F80  4E 80 04 21 */	bctrl
.L_800F5184:
/* 800F5184 000F1F84  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F5188 000F1F88  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F518C 000F1F8C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F5190 000F1F90  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F5194 000F1F94  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800F5198 000F1F98  7C 08 03 A6 */	mtlr r0
/* 800F519C 000F1F9C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F51A0 000F1FA0  4E 80 00 20 */	blr
.endfn kar_gryaku_dispatch_grcoll_callback

# .text:0x1208 | 0x800F51A4 | size: 0xE0
.fn kar_gryaku_dispatch_grlib2_callback, global
/* 800F51A4 000F1FA4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F51A8 000F1FA8  7C 08 02 A6 */	mflr r0
/* 800F51AC 000F1FAC  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F51B0 000F1FB0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F51B4 000F1FB4  7C BF 2B 78 */	mr r31, r5
/* 800F51B8 000F1FB8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F51BC 000F1FBC  7C 9E 23 78 */	mr r30, r4
/* 800F51C0 000F1FC0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F51C4 000F1FC4  7C 7D 1B 79 */	mr. r29, r3
/* 800F51C8 000F1FC8  93 81 00 10 */	stw r28, 0x10(r1)
/* 800F51CC 000F1FCC  40 82 00 18 */	bne .L_800F51E4
/* 800F51D0 000F1FD0  3C 60 80 4A */	lis r3, kar_src_gryaku_804a5824@ha
/* 800F51D4 000F1FD4  38 80 02 21 */	li r4, 0x221
/* 800F51D8 000F1FD8  38 63 58 24 */	addi r3, r3, kar_src_gryaku_804a5824@l
/* 800F51DC 000F1FDC  38 AD 90 D0 */	li r5, lbl_805D61B0@sda21
/* 800F51E0 000F1FE0  48 33 32 D9 */	bl __assert
.L_800F51E4:
/* 800F51E4 000F1FE4  83 9D 00 2C */	lwz r28, 0x2c(r29)
/* 800F51E8 000F1FE8  3C 60 80 4A */	lis r3, gryaku_kind_function_table@ha
/* 800F51EC 000F1FEC  38 63 5B E8 */	addi r3, r3, gryaku_kind_function_table@l
/* 800F51F0 000F1FF0  38 80 00 00 */	li r4, 0x0
/* 800F51F4 000F1FF4  80 1C 00 04 */	lwz r0, 0x4(r28)
/* 800F51F8 000F1FF8  54 00 10 3A */	slwi r0, r0, 2
/* 800F51FC 000F1FFC  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F5200 000F2000  28 03 00 00 */	cmplwi r3, 0x0
/* 800F5204 000F2004  41 82 00 14 */	beq .L_800F5218
/* 800F5208 000F2008  80 03 00 10 */	lwz r0, 0x10(r3)
/* 800F520C 000F200C  28 00 00 00 */	cmplwi r0, 0x0
/* 800F5210 000F2010  41 82 00 08 */	beq .L_800F5218
/* 800F5214 000F2014  38 80 00 01 */	li r4, 0x1
.L_800F5218:
/* 800F5218 000F2018  2C 04 00 00 */	cmpwi r4, 0x0
/* 800F521C 000F201C  40 82 00 1C */	bne .L_800F5238
/* 800F5220 000F2020  3C 60 80 4A */	lis r3, kar_src_gryaku_804a5824@ha
/* 800F5224 000F2024  3C A0 80 4A */	lis r5, lbl_804A5A74@ha
/* 800F5228 000F2028  38 63 58 24 */	addi r3, r3, kar_src_gryaku_804a5824@l
/* 800F522C 000F202C  38 80 02 26 */	li r4, 0x226
/* 800F5230 000F2030  38 A5 5A 74 */	addi r5, r5, lbl_804A5A74@l
/* 800F5234 000F2034  48 33 32 85 */	bl __assert
.L_800F5238:
/* 800F5238 000F2038  80 1C 00 04 */	lwz r0, 0x4(r28)
/* 800F523C 000F203C  3C 60 80 4A */	lis r3, gryaku_kind_function_table@ha
/* 800F5240 000F2040  38 A3 5B E8 */	addi r5, r3, gryaku_kind_function_table@l
/* 800F5244 000F2044  7F A3 EB 78 */	mr r3, r29
/* 800F5248 000F2048  54 00 10 3A */	slwi r0, r0, 2
/* 800F524C 000F204C  7F C4 F3 78 */	mr r4, r30
/* 800F5250 000F2050  7C C5 00 2E */	lwzx r6, r5, r0
/* 800F5254 000F2054  7F E5 FB 78 */	mr r5, r31
/* 800F5258 000F2058  81 86 00 10 */	lwz r12, 0x10(r6)
/* 800F525C 000F205C  7D 89 03 A6 */	mtctr r12
/* 800F5260 000F2060  4E 80 04 21 */	bctrl
/* 800F5264 000F2064  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F5268 000F2068  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F526C 000F206C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F5270 000F2070  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F5274 000F2074  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800F5278 000F2078  7C 08 03 A6 */	mtlr r0
/* 800F527C 000F207C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F5280 000F2080  4E 80 00 20 */	blr
.endfn kar_gryaku_dispatch_grlib2_callback

# .text:0x12E8 | 0x800F5284 | size: 0x64
.fn kar_gryaku_proc_update_main, global
/* 800F5284 000F2084  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F5288 000F2088  7C 08 02 A6 */	mflr r0
/* 800F528C 000F208C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F5290 000F2090  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F5294 000F2094  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F5298 000F2098  7C 7E 1B 78 */	mr r30, r3
/* 800F529C 000F209C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F52A0 000F20A0  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 800F52A4 000F20A4  48 09 85 AD */	bl kar_clobject__near_8018d850
/* 800F52A8 000F20A8  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 800F52AC 000F20AC  48 09 7A 25 */	bl kar_collision_object_tick_state_timers
/* 800F52B0 000F20B0  7F C3 F3 78 */	mr r3, r30
/* 800F52B4 000F20B4  48 00 06 91 */	bl kar_gryakuanim_update_current_anim_frame
/* 800F52B8 000F20B8  81 9F 00 F0 */	lwz r12, 0xf0(r31)
/* 800F52BC 000F20BC  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F52C0 000F20C0  41 82 00 10 */	beq .L_800F52D0
/* 800F52C4 000F20C4  7F C3 F3 78 */	mr r3, r30
/* 800F52C8 000F20C8  7D 89 03 A6 */	mtctr r12
/* 800F52CC 000F20CC  4E 80 04 21 */	bctrl
.L_800F52D0:
/* 800F52D0 000F20D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F52D4 000F20D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F52D8 000F20D8  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F52DC 000F20DC  7C 08 03 A6 */	mtlr r0
/* 800F52E0 000F20E0  38 21 00 10 */	addi r1, r1, 0x10
/* 800F52E4 000F20E4  4E 80 00 20 */	blr
.endfn kar_gryaku_proc_update_main

# .text:0x134C | 0x800F52E8 | size: 0x58
.fn kar_gryaku_proc_update_effect_anim, global
/* 800F52E8 000F20E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F52EC 000F20EC  7C 08 02 A6 */	mflr r0
/* 800F52F0 000F20F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F52F4 000F20F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F52F8 000F20F8  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F52FC 000F20FC  81 9F 00 F4 */	lwz r12, 0xf4(r31)
/* 800F5300 000F2100  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F5304 000F2104  41 82 00 0C */	beq .L_800F5310
/* 800F5308 000F2108  7D 89 03 A6 */	mtctr r12
/* 800F530C 000F210C  4E 80 04 21 */	bctrl
.L_800F5310:
/* 800F5310 000F2110  88 1F 01 2C */	lbz r0, 0x12c(r31)
/* 800F5314 000F2114  54 00 CF FF */	extrwi. r0, r0, 1, 24
/* 800F5318 000F2118  41 82 00 0C */	beq .L_800F5324
/* 800F531C 000F211C  7F E3 FB 78 */	mr r3, r31
/* 800F5320 000F2120  48 00 20 DD */	bl kar_gryakueffect_sync_root_anchor_jobj_matrix
.L_800F5324:
/* 800F5324 000F2124  7F E3 FB 78 */	mr r3, r31
/* 800F5328 000F2128  48 00 0F 9D */	bl kar_gryakuanim_update_collision_transforms
/* 800F532C 000F212C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F5330 000F2130  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F5334 000F2134  7C 08 03 A6 */	mtlr r0
/* 800F5338 000F2138  38 21 00 10 */	addi r1, r1, 0x10
/* 800F533C 000F213C  4E 80 00 20 */	blr
.endfn kar_gryaku_proc_update_effect_anim

# .text:0x13A4 | 0x800F5340 | size: 0x34
.fn kar_gryaku_proc_callback_f8, global
/* 800F5340 000F2140  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F5344 000F2144  7C 08 02 A6 */	mflr r0
/* 800F5348 000F2148  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F534C 000F214C  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800F5350 000F2150  81 84 00 F8 */	lwz r12, 0xf8(r4)
/* 800F5354 000F2154  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F5358 000F2158  41 82 00 0C */	beq .L_800F5364
/* 800F535C 000F215C  7D 89 03 A6 */	mtctr r12
/* 800F5360 000F2160  4E 80 04 21 */	bctrl
.L_800F5364:
/* 800F5364 000F2164  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F5368 000F2168  7C 08 03 A6 */	mtlr r0
/* 800F536C 000F216C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F5370 000F2170  4E 80 00 20 */	blr
.endfn kar_gryaku_proc_callback_f8

# .text:0x13D8 | 0x800F5374 | size: 0x34
.fn kar_gryaku_proc_callback_fc, global
/* 800F5374 000F2174  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F5378 000F2178  7C 08 02 A6 */	mflr r0
/* 800F537C 000F217C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F5380 000F2180  80 83 00 2C */	lwz r4, 0x2c(r3)
/* 800F5384 000F2184  81 84 00 FC */	lwz r12, 0xfc(r4)
/* 800F5388 000F2188  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F538C 000F218C  41 82 00 0C */	beq .L_800F5398
/* 800F5390 000F2190  7D 89 03 A6 */	mtctr r12
/* 800F5394 000F2194  4E 80 04 21 */	bctrl
.L_800F5398:
/* 800F5398 000F2198  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F539C 000F219C  7C 08 03 A6 */	mtlr r0
/* 800F53A0 000F21A0  38 21 00 10 */	addi r1, r1, 0x10
/* 800F53A4 000F21A4  4E 80 00 20 */	blr
.endfn kar_gryaku_proc_callback_fc

# .text:0x140C | 0x800F53A8 | size: 0x54
.fn kar_gryaku_proc_callback_108_and_draw, global
/* 800F53A8 000F21A8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F53AC 000F21AC  7C 08 02 A6 */	mflr r0
/* 800F53B0 000F21B0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F53B4 000F21B4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F53B8 000F21B8  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F53BC 000F21BC  81 9F 01 08 */	lwz r12, 0x108(r31)
/* 800F53C0 000F21C0  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F53C4 000F21C4  41 82 00 0C */	beq .L_800F53D0
/* 800F53C8 000F21C8  7D 89 03 A6 */	mtctr r12
/* 800F53CC 000F21CC  4E 80 04 21 */	bctrl
.L_800F53D0:
/* 800F53D0 000F21D0  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 800F53D4 000F21D4  38 80 00 00 */	li r4, 0x0
/* 800F53D8 000F21D8  C0 3F 00 A4 */	lfs f1, 0xa4(r31)
/* 800F53DC 000F21DC  38 A0 00 02 */	li r5, 0x2
/* 800F53E0 000F21E0  38 C0 00 00 */	li r6, 0x0
/* 800F53E4 000F21E4  48 09 71 05 */	bl kar_collision_object_update_handle_transform
/* 800F53E8 000F21E8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F53EC 000F21EC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F53F0 000F21F0  7C 08 03 A6 */	mtlr r0
/* 800F53F4 000F21F4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F53F8 000F21F8  4E 80 00 20 */	blr
.endfn kar_gryaku_proc_callback_108_and_draw

# .text:0x1460 | 0x800F53FC | size: 0x58
.fn kar_gryaku_proc_update_collision_libs, global
/* 800F53FC 000F21FC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F5400 000F2200  7C 08 02 A6 */	mflr r0
/* 800F5404 000F2204  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F5408 000F2208  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F540C 000F220C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 800F5410 000F2210  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 800F5414 000F2214  48 09 7B 51 */	bl kar_collision_object_begin_global_update
/* 800F5418 000F2218  7F E3 FB 78 */	mr r3, r31
/* 800F541C 000F221C  48 00 31 85 */	bl kar_gryakulib_register_global_list28_clobjects
/* 800F5420 000F2220  7F E3 FB 78 */	mr r3, r31
/* 800F5424 000F2224  48 00 31 D9 */	bl kar_gryakulib_register_global_list24_clobjects
/* 800F5428 000F2228  7F E3 FB 78 */	mr r3, r31
/* 800F542C 000F222C  48 00 32 2D */	bl kar_gryakulib_register_wneffect_clobjects
/* 800F5430 000F2230  80 7F 00 EC */	lwz r3, 0xec(r31)
/* 800F5434 000F2234  48 09 84 45 */	bl kar_clobject__near_8018d878
/* 800F5438 000F2238  7F E3 FB 78 */	mr r3, r31
/* 800F543C 000F223C  48 00 32 79 */	bl kar_gryakulib_update_clobject_damage_source
/* 800F5440 000F2240  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F5444 000F2244  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F5448 000F2248  7C 08 03 A6 */	mtlr r0
/* 800F544C 000F224C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F5450 000F2250  4E 80 00 20 */	blr
.endfn kar_gryaku_proc_update_collision_libs

# .text:0x14B8 | 0x800F5454 | size: 0xF4
.fn kar_gryaku_proc_apply_motion_callbacks, global
/* 800F5454 000F2254  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800F5458 000F2258  7C 08 02 A6 */	mflr r0
/* 800F545C 000F225C  90 01 00 44 */	stw r0, 0x44(r1)
/* 800F5460 000F2260  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 800F5464 000F2264  F3 E1 00 38 */	psq_st f31, 0x38(r1), 0, qr0
/* 800F5468 000F2268  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 800F546C 000F226C  F3 C1 00 28 */	psq_st f30, 0x28(r1), 0, qr0
/* 800F5470 000F2270  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F5474 000F2274  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F5478 000F2278  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F547C 000F227C  7C 7D 1B 78 */	mr r29, r3
/* 800F5480 000F2280  C0 02 90 E4 */	lfs f0, lbl_805DF7E4@sda21(r0)
/* 800F5484 000F2284  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 800F5488 000F2288  80 9E 00 EC */	lwz r4, 0xec(r30)
/* 800F548C 000F228C  3B E4 00 1C */	addi r31, r4, 0x1c
/* 800F5490 000F2290  38 84 00 64 */	addi r4, r4, 0x64
/* 800F5494 000F2294  C3 FF 00 08 */	lfs f31, 0x8(r31)
/* 800F5498 000F2298  C3 DF 00 0C */	lfs f30, 0xc(r31)
/* 800F549C 000F229C  FC 1F 00 00 */	fcmpu cr0, f31, f0
/* 800F54A0 000F22A0  41 82 00 3C */	beq .L_800F54DC
/* 800F54A4 000F22A4  FC 20 F0 90 */	fmr f1, f30
/* 800F54A8 000F22A8  7F C3 F3 78 */	mr r3, r30
/* 800F54AC 000F22AC  48 00 32 B1 */	bl kar_gryakulib_accumulate_clobject_timer
/* 800F54B0 000F22B0  81 9E 01 00 */	lwz r12, 0x100(r30)
/* 800F54B4 000F22B4  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F54B8 000F22B8  41 82 00 14 */	beq .L_800F54CC
/* 800F54BC 000F22BC  7F A3 EB 78 */	mr r3, r29
/* 800F54C0 000F22C0  7F E4 FB 78 */	mr r4, r31
/* 800F54C4 000F22C4  7D 89 03 A6 */	mtctr r12
/* 800F54C8 000F22C8  4E 80 04 21 */	bctrl
.L_800F54CC:
/* 800F54CC 000F22CC  7F A3 EB 78 */	mr r3, r29
/* 800F54D0 000F22D0  7F E4 FB 78 */	mr r4, r31
/* 800F54D4 000F22D4  48 00 32 AD */	bl kar_gryakulib_noop_callback
/* 800F54D8 000F22D8  48 00 00 24 */	b .L_800F54FC
.L_800F54DC:
/* 800F54DC 000F22DC  80 04 00 00 */	lwz r0, 0x0(r4)
/* 800F54E0 000F22E0  28 00 00 00 */	cmplwi r0, 0x0
/* 800F54E4 000F22E4  41 82 00 18 */	beq .L_800F54FC
/* 800F54E8 000F22E8  81 9E 01 04 */	lwz r12, 0x104(r30)
/* 800F54EC 000F22EC  28 0C 00 00 */	cmplwi r12, 0x0
/* 800F54F0 000F22F0  41 82 00 0C */	beq .L_800F54FC
/* 800F54F4 000F22F4  7D 89 03 A6 */	mtctr r12
/* 800F54F8 000F22F8  4E 80 04 21 */	bctrl
.L_800F54FC:
/* 800F54FC 000F22FC  C0 02 90 E4 */	lfs f0, lbl_805DF7E4@sda21(r0)
/* 800F5500 000F2300  FC 1F 00 00 */	fcmpu cr0, f31, f0
/* 800F5504 000F2304  40 82 00 18 */	bne .L_800F551C
/* 800F5508 000F2308  FC 1E 00 00 */	fcmpu cr0, f30, f0
/* 800F550C 000F230C  41 82 00 10 */	beq .L_800F551C
/* 800F5510 000F2310  FC 20 F0 90 */	fmr f1, f30
/* 800F5514 000F2314  7F C3 F3 78 */	mr r3, r30
/* 800F5518 000F2318  48 00 32 45 */	bl kar_gryakulib_accumulate_clobject_timer
.L_800F551C:
/* 800F551C 000F231C  E3 E1 00 38 */	psq_l f31, 0x38(r1), 0, qr0
/* 800F5520 000F2320  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 800F5524 000F2324  E3 C1 00 28 */	psq_l f30, 0x28(r1), 0, qr0
/* 800F5528 000F2328  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 800F552C 000F232C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F5530 000F2330  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F5534 000F2334  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800F5538 000F2338  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F553C 000F233C  7C 08 03 A6 */	mtlr r0
/* 800F5540 000F2340  38 21 00 40 */	addi r1, r1, 0x40
/* 800F5544 000F2344  4E 80 00 20 */	blr
.endfn kar_gryaku_proc_apply_motion_callbacks

# .text:0x15AC | 0x800F5548 | size: 0x1FC
.fn kar_gryaku_set_path_node_motion, global
/* 800F5548 000F2348  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F554C 000F234C  7C 08 02 A6 */	mflr r0
/* 800F5550 000F2350  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F5554 000F2354  39 61 00 20 */	addi r11, r1, 0x20
/* 800F5558 000F2358  DB E1 00 28 */	stfd f31, 0x28(r1)
/* 800F555C 000F235C  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 800F5560 000F2360  48 2B 85 F5 */	bl _savegpr_27
/* 800F5564 000F2364  7C 7D 1B 78 */	mr r29, r3
/* 800F5568 000F2368  7C 9F 23 78 */	mr r31, r4
/* 800F556C 000F236C  93 E3 00 74 */	stw r31, 0x74(r3)
/* 800F5570 000F2370  FF C0 08 90 */	fmr f30, f1
/* 800F5574 000F2374  FF E0 10 90 */	fmr f31, f2
/* 800F5578 000F2378  7C BB 2B 78 */	mr r27, r5
/* 800F557C 000F237C  80 63 00 EC */	lwz r3, 0xec(r3)
/* 800F5580 000F2380  7C DE 33 78 */	mr r30, r6
/* 800F5584 000F2384  7C FC 3B 78 */	mr r28, r7
/* 800F5588 000F2388  48 09 72 9D */	bl kar_collision_object_flush_dirty_motion_slots
/* 800F558C 000F238C  88 1D 01 2C */	lbz r0, 0x12c(r29)
/* 800F5590 000F2390  54 00 DF FF */	extrwi. r0, r0, 1, 26
/* 800F5594 000F2394  41 82 00 0C */	beq .L_800F55A0
/* 800F5598 000F2398  7F A3 EB 78 */	mr r3, r29
/* 800F559C 000F239C  48 00 2E 4D */	bl kar_gryakulib_refresh_clobject_slots
.L_800F55A0:
/* 800F55A0 000F23A0  57 80 07 BD */	rlwinm. r0, r28, 0, 30, 30
/* 800F55A4 000F23A4  40 82 00 24 */	bne .L_800F55C8
/* 800F55A8 000F23A8  80 7D 00 EC */	lwz r3, 0xec(r29)
/* 800F55AC 000F23AC  80 03 00 84 */	lwz r0, 0x84(r3)
/* 800F55B0 000F23B0  2C 00 00 00 */	cmpwi r0, 0x0
/* 800F55B4 000F23B4  41 82 00 0C */	beq .L_800F55C0
/* 800F55B8 000F23B8  38 00 00 00 */	li r0, 0x0
/* 800F55BC 000F23BC  90 03 00 84 */	stw r0, 0x84(r3)
.L_800F55C0:
/* 800F55C0 000F23C0  80 7D 00 EC */	lwz r3, 0xec(r29)
/* 800F55C4 000F23C4  48 09 70 A5 */	bl kar_collision_object_flush_sweep_points_if_dirty
.L_800F55C8:
/* 800F55C8 000F23C8  80 1D 00 78 */	lwz r0, 0x78(r29)
/* 800F55CC 000F23CC  7C 1F 00 00 */	cmpw r31, r0
/* 800F55D0 000F23D0  41 80 00 18 */	blt .L_800F55E8
/* 800F55D4 000F23D4  7C 00 F8 50 */	subf r0, r0, r31
/* 800F55D8 000F23D8  80 7D 00 84 */	lwz r3, 0x84(r29)
/* 800F55DC 000F23DC  54 00 20 36 */	slwi r0, r0, 4
/* 800F55E0 000F23E0  7F E3 02 14 */	add r31, r3, r0
/* 800F55E4 000F23E4  48 00 00 10 */	b .L_800F55F4
.L_800F55E8:
/* 800F55E8 000F23E8  80 7D 00 80 */	lwz r3, 0x80(r29)
/* 800F55EC 000F23EC  57 E0 20 36 */	slwi r0, r31, 4
/* 800F55F0 000F23F0  7F E3 02 14 */	add r31, r3, r0
.L_800F55F4:
/* 800F55F4 000F23F4  57 80 07 7B */	rlwinm. r0, r28, 0, 29, 29
/* 800F55F8 000F23F8  40 82 00 FC */	bne .L_800F56F4
/* 800F55FC 000F23FC  2C 1E FF FF */	cmpwi r30, -0x1
/* 800F5600 000F2400  93 7D 00 7C */	stw r27, 0x7c(r29)
/* 800F5604 000F2404  40 82 00 74 */	bne .L_800F5678
/* 800F5608 000F2408  80 1D 00 7C */	lwz r0, 0x7c(r29)
/* 800F560C 000F240C  2C 00 FF FF */	cmpwi r0, -0x1
/* 800F5610 000F2410  41 82 00 4C */	beq .L_800F565C
/* 800F5614 000F2414  80 7D 00 08 */	lwz r3, 0x8(r29)
/* 800F5618 000F2418  1C 00 00 14 */	mulli r0, r0, 0x14
/* 800F561C 000F241C  FC 20 F0 90 */	fmr f1, f30
/* 800F5620 000F2420  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800F5624 000F2424  FC 40 F8 90 */	fmr f2, f31
/* 800F5628 000F2428  7C 03 02 14 */	add r0, r3, r0
/* 800F562C 000F242C  90 1D 00 B4 */	stw r0, 0xb4(r29)
/* 800F5630 000F2430  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 800F5634 000F2434  48 00 03 45 */	bl kar_gryakuanim_start_local_path_anim
/* 800F5638 000F2438  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 800F563C 000F243C  48 00 04 89 */	bl kar_gryakuanim_step_local_anim_frame
/* 800F5640 000F2440  80 9D 00 B4 */	lwz r4, 0xb4(r29)
/* 800F5644 000F2444  7F A3 EB 78 */	mr r3, r29
/* 800F5648 000F2448  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800F564C 000F244C  48 00 3B 01 */	bl kar_gryakucommon_set_opcode_stream
/* 800F5650 000F2450  7F A3 EB 78 */	mr r3, r29
/* 800F5654 000F2454  48 00 39 DD */	bl kar_gryakucommon_run_opcode_stream
/* 800F5658 000F2458  48 00 00 9C */	b .L_800F56F4
.L_800F565C:
/* 800F565C 000F245C  38 00 00 00 */	li r0, 0x0
/* 800F5660 000F2460  90 1D 00 B4 */	stw r0, 0xb4(r29)
/* 800F5664 000F2464  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 800F5668 000F2468  48 00 06 31 */	bl kar_gryakuanim_bind_local_default_anim
/* 800F566C 000F246C  7F A3 EB 78 */	mr r3, r29
/* 800F5670 000F2470  48 00 3A F5 */	bl kar_gryakucommon_reset_opcode_cursor
/* 800F5674 000F2474  48 00 00 80 */	b .L_800F56F4
.L_800F5678:
/* 800F5678 000F2478  80 1D 00 7C */	lwz r0, 0x7c(r29)
/* 800F567C 000F247C  80 6D 05 EC */	lwz r3, lbl_805DD6CC@sda21(r0)
/* 800F5680 000F2480  2C 00 FF FF */	cmpwi r0, -0x1
/* 800F5684 000F2484  41 82 00 54 */	beq .L_800F56D8
/* 800F5688 000F2488  80 63 00 08 */	lwz r3, 0x8(r3)
/* 800F568C 000F248C  1C 00 00 14 */	mulli r0, r0, 0x14
/* 800F5690 000F2490  FC 20 F0 90 */	fmr f1, f30
/* 800F5694 000F2494  7F C4 F3 78 */	mr r4, r30
/* 800F5698 000F2498  80 63 00 10 */	lwz r3, 0x10(r3)
/* 800F569C 000F249C  FC 40 F8 90 */	fmr f2, f31
/* 800F56A0 000F24A0  7C 03 02 14 */	add r0, r3, r0
/* 800F56A4 000F24A4  90 1D 00 B4 */	stw r0, 0xb4(r29)
/* 800F56A8 000F24A8  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 800F56AC 000F24AC  48 00 06 3D */	bl kar_gryakuanim_start_global_anim_entry
/* 800F56B0 000F24B0  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 800F56B4 000F24B4  7F C4 F3 78 */	mr r4, r30
/* 800F56B8 000F24B8  48 00 06 F5 */	bl kar_gryakuanim_step_global_anim_frame
/* 800F56BC 000F24BC  80 9D 00 B4 */	lwz r4, 0xb4(r29)
/* 800F56C0 000F24C0  7F A3 EB 78 */	mr r3, r29
/* 800F56C4 000F24C4  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800F56C8 000F24C8  48 00 3A 85 */	bl kar_gryakucommon_set_opcode_stream
/* 800F56CC 000F24CC  7F A3 EB 78 */	mr r3, r29
/* 800F56D0 000F24D0  48 00 39 61 */	bl kar_gryakucommon_run_opcode_stream
/* 800F56D4 000F24D4  48 00 00 20 */	b .L_800F56F4
.L_800F56D8:
/* 800F56D8 000F24D8  38 00 00 00 */	li r0, 0x0
/* 800F56DC 000F24DC  7F C4 F3 78 */	mr r4, r30
/* 800F56E0 000F24E0  90 1D 00 B4 */	stw r0, 0xb4(r29)
/* 800F56E4 000F24E4  80 7D 00 00 */	lwz r3, 0x0(r29)
/* 800F56E8 000F24E8  48 00 08 55 */	bl kar_gryakuanim_bind_global_anim_jobj
/* 800F56EC 000F24EC  7F A3 EB 78 */	mr r3, r29
/* 800F56F0 000F24F0  48 00 3A 75 */	bl kar_gryakucommon_reset_opcode_cursor
.L_800F56F4:
/* 800F56F4 000F24F4  80 7F 00 00 */	lwz r3, 0x0(r31)
/* 800F56F8 000F24F8  38 00 00 00 */	li r0, 0x0
/* 800F56FC 000F24FC  90 7D 00 F0 */	stw r3, 0xf0(r29)
/* 800F5700 000F2500  80 7F 00 04 */	lwz r3, 0x4(r31)
/* 800F5704 000F2504  90 7D 00 F4 */	stw r3, 0xf4(r29)
/* 800F5708 000F2508  80 7F 00 08 */	lwz r3, 0x8(r31)
/* 800F570C 000F250C  90 7D 00 F8 */	stw r3, 0xf8(r29)
/* 800F5710 000F2510  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800F5714 000F2514  90 7D 00 FC */	stw r3, 0xfc(r29)
/* 800F5718 000F2518  90 1D 01 08 */	stw r0, 0x108(r29)
/* 800F571C 000F251C  90 1D 01 00 */	stw r0, 0x100(r29)
/* 800F5720 000F2520  90 1D 01 04 */	stw r0, 0x104(r29)
/* 800F5724 000F2524  CB E1 00 28 */	lfd f31, 0x28(r1)
/* 800F5728 000F2528  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 800F572C 000F252C  39 61 00 20 */	addi r11, r1, 0x20
/* 800F5730 000F2530  48 2B 84 71 */	bl _restgpr_27
/* 800F5734 000F2534  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F5738 000F2538  7C 08 03 A6 */	mtlr r0
/* 800F573C 000F253C  38 21 00 30 */	addi r1, r1, 0x30
/* 800F5740 000F2540  4E 80 00 20 */	blr
.endfn kar_gryaku_set_path_node_motion

# .text:0x17A8 | 0x800F5744 | size: 0x54
.fn kar_gryaku_set_active_state, global
/* 800F5744 000F2544  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F5748 000F2548  7C 08 02 A6 */	mflr r0
/* 800F574C 000F254C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F5750 000F2550  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F5754 000F2554  7C 9F 23 78 */	mr r31, r4
/* 800F5758 000F2558  7F E5 00 34 */	cntlzw r5, r31
/* 800F575C 000F255C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 800F5760 000F2560  7C 7E 1B 78 */	mr r30, r3
/* 800F5764 000F2564  88 03 01 2C */	lbz r0, 0x12c(r3)
/* 800F5768 000F2568  50 A0 F7 38 */	rlwimi r0, r5, 30, 28, 28
/* 800F576C 000F256C  98 03 01 2C */	stb r0, 0x12c(r3)
/* 800F5770 000F2570  48 00 0B BD */	bl kar_gryakuanim_set_collision_face_flag
/* 800F5774 000F2574  7F C3 F3 78 */	mr r3, r30
/* 800F5778 000F2578  7F E4 FB 78 */	mr r4, r31
/* 800F577C 000F257C  48 00 0B E5 */	bl kar_gryakuanim_apply_zone_enabled_state
/* 800F5780 000F2580  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F5784 000F2584  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F5788 000F2588  83 C1 00 08 */	lwz r30, 0x8(r1)
/* 800F578C 000F258C  7C 08 03 A6 */	mtlr r0
/* 800F5790 000F2590  38 21 00 10 */	addi r1, r1, 0x10
/* 800F5794 000F2594  4E 80 00 20 */	blr
.endfn kar_gryaku_set_active_state

# .text:0x17FC | 0x800F5798 | size: 0x4
.fn kar_gryaku_noop_init_callback, global
/* 800F5798 000F2598  4E 80 00 20 */	blr
.endfn kar_gryaku_noop_init_callback

# .text:0x1800 | 0x800F579C | size: 0x50
.fn kar_gryaku_play_anim_entry, global
/* 800F579C 000F259C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F57A0 000F25A0  7C 08 02 A6 */	mflr r0
/* 800F57A4 000F25A4  7C AB 2B 78 */	mr r11, r5
/* 800F57A8 000F25A8  7C CA 33 78 */	mr r10, r6
/* 800F57AC 000F25AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F57B0 000F25B0  7C E8 3B 78 */	mr r8, r7
/* 800F57B4 000F25B4  1C 04 00 14 */	mulli r0, r4, 0x14
/* 800F57B8 000F25B8  7C 85 23 78 */	mr r5, r4
/* 800F57BC 000F25BC  81 23 00 2C */	lwz r9, 0x2c(r3)
/* 800F57C0 000F25C0  7D 66 5B 78 */	mr r6, r11
/* 800F57C4 000F25C4  7D 47 53 78 */	mr r7, r10
/* 800F57C8 000F25C8  80 69 00 08 */	lwz r3, 0x8(r9)
/* 800F57CC 000F25CC  80 83 00 08 */	lwz r4, 0x8(r3)
/* 800F57D0 000F25D0  38 69 00 64 */	addi r3, r9, 0x64
/* 800F57D4 000F25D4  7C 84 02 14 */	add r4, r4, r0
/* 800F57D8 000F25D8  4B FE 61 C9 */	bl kar_granim__800db9a0
/* 800F57DC 000F25DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F57E0 000F25E0  7C 08 03 A6 */	mtlr r0
/* 800F57E4 000F25E4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F57E8 000F25E8  4E 80 00 20 */	blr
.endfn kar_gryaku_play_anim_entry

# 0x804A57E8..0x804A5AC0 | size: 0x2D8
.data
.balign 8

# .data:0x0 | 0x804A57E8 | size: 0x3C
.obj kar_src_ground_804a57e8, global
	.4byte 0x67726F75
	.4byte 0x6E642E68
	.4byte 0x00000000
	.4byte 0x30203C3D
	.4byte 0x206E756D
	.4byte 0x20262620
	.4byte 0x6E756D20
	.4byte 0x3C206772
	.4byte 0x47657459
	.4byte 0x616B7543
	.4byte 0x6F6D6D6F
	.4byte 0x6E446174
	.4byte 0x614E756D
	.4byte 0x28677029
	.4byte 0x00000000
.endobj kar_src_ground_804a57e8

# .data:0x3C | 0x804A5824 | size: 0x148
.obj kar_src_gryaku_804a5824, global
	.4byte 0x67727961
	.4byte 0x6B752E63
	.4byte 0x00000000
	.4byte 0x636F6D6D
	.4byte 0x6F6E5F64
	.4byte 0x6174612D
	.4byte 0x3E6B696E
	.4byte 0x64203C20
	.4byte 0x47725F59
	.4byte 0x616B754B
	.4byte 0x696E645F
	.4byte 0x436F6D6D
	.4byte 0x6F6E5465
	.4byte 0x726D696E
	.4byte 0x61746500
	.4byte 0x636F6D6D
	.4byte 0x6F6E5F64
	.4byte 0x6174612D
	.4byte 0x3E67726F
	.4byte 0x7570203C
	.4byte 0x20477259
	.4byte 0x616B7543
	.4byte 0x6F6D6D6F
	.4byte 0x6E5F4772
	.4byte 0x6F75705F
	.4byte 0x4D617800
	.4byte 0x30203C20
	.4byte 0x72616E64
	.4byte 0x6F6D5F73
	.4byte 0x65745F6E
	.4byte 0x756D2026
	.4byte 0x26207261
	.4byte 0x6E646F6D
	.4byte 0x5F736574
	.4byte 0x5F6E756D
	.4byte 0x203C2047
	.4byte 0x7259616B
	.4byte 0x75436F6D
	.4byte 0x6D6F6E5F
	.4byte 0x52616E64
	.4byte 0x6F6D5F53
	.4byte 0x65745F4E
	.4byte 0x756D0000
	.4byte 0x6B696E64
	.4byte 0x203D2025
	.4byte 0x640A0000
	.4byte 0x30203C3D
	.4byte 0x20646174
	.4byte 0x615F6B69
	.4byte 0x6E642026
	.4byte 0x26206461
	.4byte 0x74615F6B
	.4byte 0x696E6420
	.4byte 0x3C206772
	.4byte 0x47657459
	.4byte 0x616B7544
	.4byte 0x6174614E
	.4byte 0x756D2867
	.4byte 0x70290000
	.4byte 0x67725961
	.4byte 0x6B754368
	.4byte 0x6B436C61
	.4byte 0x73736963
	.4byte 0x616C5363
	.4byte 0x616C696E
	.4byte 0x6728676F
	.4byte 0x626A2900
	.4byte 0x30203C3D
	.4byte 0x20646174
	.4byte 0x615F6B69
	.4byte 0x6E642026
	.4byte 0x26206461
	.4byte 0x74615F6B
	.4byte 0x696E6420
	.4byte 0x3C206772
	.4byte 0x47657459
	.4byte 0x616B7553
	.4byte 0x74617469
	.4byte 0x63446174
	.4byte 0x614E756D
	.4byte 0x28677029
	.4byte 0x00000000
.endobj kar_src_gryaku_804a5824

# .data:0x184 | 0x804A596C | size: 0x23
.obj lbl_804A596C, global
	.string "kind < Gr_YakuKind_CommonTerminate"
.endobj lbl_804A596C

# .data:0x1A7 | 0x804A598F | size: 0x1
.obj gap_07_804A598F_data, global
.hidden gap_07_804A598F_data
	.byte 0x00
.endobj gap_07_804A598F_data

# .data:0x1A8 | 0x804A5990 | size: 0x50
.obj lbl_804A5990, global
	.4byte 0x6779702D
	.4byte 0x3E736361
	.4byte 0x6C65203D
	.4byte 0x3D204772
	.4byte 0x5F446566
	.4byte 0x61756C74
	.4byte 0x5363616C
	.4byte 0x65000000
	.4byte 0x2179616B
	.4byte 0x755F6461
	.4byte 0x74612D3E
	.4byte 0x6C6F6361
	.4byte 0x6C436F6C
	.4byte 0x6C446174
	.4byte 0x61000000
	.4byte 0x67702D3E
	.4byte 0x79616B75
	.4byte 0x5F6E756D
	.4byte 0x203E2030
	.4byte 0x00000000
.endobj lbl_804A5990

# .data:0x1F8 | 0x804A59E0 | size: 0x44
.obj lbl_804A59E0, global
	.string "grYakuFuncTable[gyp->kind] && grYakuFuncTable[gyp->kind]->coll_func"
.endobj lbl_804A59E0

# .data:0x23C | 0x804A5A24 | size: 0x4D
.obj lbl_804A5A24, global
	.string "grYakuFuncTable[gyp->kind] && grYakuFuncTable[gyp->kind]->adhere_update_func"
.endobj lbl_804A5A24

# .data:0x289 | 0x804A5A71 | size: 0x3
.obj gap_07_804A5A71_data, global
.hidden gap_07_804A5A71_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A5A71_data

# .data:0x28C | 0x804A5A74 | size: 0x49
.obj lbl_804A5A74, global
	.string "grYakuFuncTable[gyp->kind] && grYakuFuncTable[gyp->kind]->get_point_func"
.endobj lbl_804A5A74

# .data:0x2D5 | 0x804A5ABD | size: 0x3
.obj gap_07_804A5ABD_data, global
.hidden gap_07_804A5ABD_data
	.byte 0x00, 0x00, 0x00
.endobj gap_07_804A5ABD_data

# 0x805D61A8..0x805D61B8 | size: 0x10
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x805D61A8 | size: 0x5
.obj lbl_805D61A8, global
	.string "data"
.endobj lbl_805D61A8

# .sdata:0x5 | 0x805D61AD | size: 0x3
.obj gap_09_805D61AD_sdata, global
.hidden gap_09_805D61AD_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D61AD_sdata

# .sdata:0x8 | 0x805D61B0 | size: 0x5
.obj lbl_805D61B0, global
	.string "gobj"
.endobj lbl_805D61B0

# .sdata:0xD | 0x805D61B5 | size: 0x3
.obj gap_09_805D61B5_sdata, global
.hidden gap_09_805D61B5_sdata
	.byte 0x00, 0x00, 0x00
.endobj gap_09_805D61B5_sdata

# 0x805DD6C0..0x805DD718 | size: 0x58
.section .sbss, "wa", @nobits
.balign 8

# .sbss:0x0 | 0x805DD6C0 | size: 0x4
.obj lbl_805DD6C0, global
	.skip 0x4
.endobj lbl_805DD6C0

# .sbss:0x4 | 0x805DD6C4 | size: 0x4
.obj lbl_805DD6C4, global
	.skip 0x4
.endobj lbl_805DD6C4

# .sbss:0x8 | 0x805DD6C8 | size: 0x4
.obj lbl_805DD6C8, global
	.skip 0x4
.endobj lbl_805DD6C8

# .sbss:0xC | 0x805DD6CC | size: 0x4
.obj lbl_805DD6CC, global
	.skip 0x4
.endobj lbl_805DD6CC

# .sbss:0x10 | 0x805DD6D0 | size: 0x4
.obj lbl_805DD6D0, global
	.skip 0x4
.endobj lbl_805DD6D0

# .sbss:0x14 | 0x805DD6D4 | size: 0x4
.obj lbl_805DD6D4, global
	.skip 0x4
.endobj lbl_805DD6D4

# .sbss:0x18 | 0x805DD6D8 | size: 0x4
.obj lbl_805DD6D8, global
	.skip 0x4
.endobj lbl_805DD6D8

# .sbss:0x1C | 0x805DD6DC | size: 0x4
.obj lbl_805DD6DC, global
	.skip 0x4
.endobj lbl_805DD6DC

# .sbss:0x20 | 0x805DD6E0 | size: 0x4
.obj lbl_805DD6E0, global
	.skip 0x4
.endobj lbl_805DD6E0

# .sbss:0x24 | 0x805DD6E4 | size: 0x4
.obj lbl_805DD6E4, global
	.skip 0x4
.endobj lbl_805DD6E4

# .sbss:0x28 | 0x805DD6E8 | size: 0x4
.obj lbl_805DD6E8, global
	.skip 0x4
.endobj lbl_805DD6E8

# .sbss:0x2C | 0x805DD6EC | size: 0x4
.obj lbl_805DD6EC, global
	.skip 0x4
.endobj lbl_805DD6EC

# .sbss:0x30 | 0x805DD6F0 | size: 0x8
.obj lbl_805DD6F0, global
	.skip 0x8
.endobj lbl_805DD6F0

# .sbss:0x38 | 0x805DD6F8 | size: 0x8
.obj lbl_805DD6F8, global
	.skip 0x8
.endobj lbl_805DD6F8

# .sbss:0x40 | 0x805DD700 | size: 0x4
.obj lbl_805DD700, global
	.skip 0x4
.endobj lbl_805DD700

# .sbss:0x44 | 0x805DD704 | size: 0x4
.obj lbl_805DD704, global
	.skip 0x4
.endobj lbl_805DD704

# .sbss:0x48 | 0x805DD708 | size: 0x2
.obj lbl_805DD708, global
	.skip 0x2
.endobj lbl_805DD708

# .sbss:0x4A | 0x805DD70A | size: 0x2
.obj gap_10_805DD70A_sbss, global
.hidden gap_10_805DD70A_sbss
	.skip 0x2
.endobj gap_10_805DD70A_sbss

# .sbss:0x4C | 0x805DD70C | size: 0x4
.obj lbl_805DD70C, global
	.skip 0x4
.endobj lbl_805DD70C

# .sbss:0x50 | 0x805DD710 | size: 0x4
.obj lbl_805DD710, global
	.skip 0x4
.endobj lbl_805DD710

# .sbss:0x54 | 0x805DD714 | size: 0x4
.obj lbl_805DD714, global
	.skip 0x4
.endobj lbl_805DD714

# 0x805DF7E0..0x805DF7E8 | size: 0x8
.section .sdata2, "a"
.balign 8

# .sdata2:0x0 | 0x805DF7E0 | size: 0x4
.obj lbl_805DF7E0, global
	.float 1
.endobj lbl_805DF7E0

# .sdata2:0x4 | 0x805DF7E4 | size: 0x4
.obj lbl_805DF7E4, global
	.float 0
.endobj lbl_805DF7E4
