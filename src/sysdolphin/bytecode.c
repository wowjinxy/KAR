#include <global.h>
#include <kar/math.h>
#include <sysdolphin/list.h>
#include <sysdolphin/random.h>

typedef union {
    void* p;
    int i;
    f32 f;
} ByteCodeVal;

extern HSD_SList* HSD_SListPrepend(HSD_SList* list, void* data);

extern void OSReport(const char*, ...);
extern void HSD_Panic(const char* file, s32 line, const char* msg);

extern f64 kar_log(f64 x);
extern f64 kar_exp(f64 x);
extern f64 kar_fmod(f64 x, f64 y); /* fmod */
extern f64 kar_pow(f64 x, f64 y);

f32 kar_math_bytecode_sinf_approx(f32 x);
f32 kar_math_bytecode_cosf_approx(f32 x);

#define BC_DEG_TO_RAD 0.017453292519943295
#define BC_RAD_TO_DEG 57.29577951308232

char ByteCodeSourceFile[] = "bytecode.c";

char ByteCodeEmptyAssert[4] = "";
char ByteCodeAssertStack[] = "stack";

#define BC_ASSERT_MSG(line, cond, msg) \
    ((cond) ? ((void) 0) : __assert(ByteCodeSourceFile, line, msg))

static inline f32 bytecode_sqrtf(f32 x)
{
    if (x > 0.0F) {
        f64 guess = __frsqrte((f64) x);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        return (f32) (x * guess);
    }
    return x;
}

float HSD_ByteCodeEval(u8* bytecode, f32* args, s32 nb_args)
{
    HSD_SList* stack;
    int i;
    u8 last_command;
    s32 operand_count;
    u32 operand;
    HSD_SList* list;
    f32 fv, f0, f1;
    s32 d0, d1;

    stack = NULL;
    operand_count = 0;

    if (bytecode == NULL) {
        return 0.0F;
    }

    for (;;) {
        if (operand_count > 0) {
            operand_count--;
            operand = (operand << 8) | *bytecode;
            bytecode++;

            if (operand_count != 0) {
                continue;
            }

            switch (last_command) {
            case 2:
                BC_ASSERT_MSG(281, operand < nb_args, "operand < nb_args");
                stack = HSD_SListPrepend(
                    stack, (void*) ((ByteCodeVal*) &args[operand])->i);
                break;
            case 5:
                for (i = 0; i < operand; i++) {
                    stack = HSD_SListRemove(stack);
                }
                break;
            case 0x3C: {
                list = stack;
                i = 0;
                while (list != NULL && i < operand) {
                    list = list->next;
                    i++;
                }
                if (list == NULL) {
                    OSReport("specified stack doesn't exist (%d).\n", operand);
                    HSD_Panic(ByteCodeSourceFile, 299, ByteCodeEmptyAssert);
                } else {
                    stack = HSD_SListPrepend(stack, list->data);
                }
                break;
            }
            case 3:
                BC_ASSERT_MSG(307, stack, ByteCodeAssertStack);
                if ((int) stack->data != 0) {
                    bytecode += operand;
                }
                stack = HSD_SListRemove(stack);
                break;
            case 4:
                bytecode += operand;
                break;
            case 6:
                stack = HSD_SListPrepend(stack, (void*) operand);
                break;
            case 0xFF:
                HSD_Panic(ByteCodeSourceFile, 0x143, "not yet implemented.\n");
                /* fallthrough */
            default:
                HSD_Panic(ByteCodeSourceFile, 0x146, "unexpected byte code.\n");
                break;
            }
            continue;
        }

        last_command = *bytecode++;
        switch (last_command) {
        case 0:
            break;
        case 1:
            BC_ASSERT_MSG(339, stack, ByteCodeAssertStack);
            f0 = ((ByteCodeVal*) &stack->data)->f;
            while (stack != NULL) {
                stack = HSD_SListRemove(stack);
            }
            return f0;
        case 5:
        case 0x3C:
        case 0xFF:
            operand_count = 1;
            operand = 0;
            break;
        case 2:
        case 3:
        case 4:
            operand_count = 2;
            operand = 0;
            break;
        case 6:
            operand_count = 4;
            operand = 0;
            break;
        case 7:
            BC_ASSERT_MSG(376, stack, ByteCodeAssertStack);
            {
                ((ByteCodeVal*) &stack->data)->i =
                    (int) ((ByteCodeVal*) &stack->data)->f;
            }
            break;
        case 8:
            BC_ASSERT_MSG(381, stack, ByteCodeAssertStack);
            {
                fv = (f32) ((ByteCodeVal*) &stack->data)->i;
                stack->data = *(void**) &fv;
            }
            break;
        case 9:
            BC_ASSERT_MSG(387, stack, ByteCodeAssertStack);
            fv = -(((ByteCodeVal*) &stack->data)->f);
            stack->data = *(void**) &fv;
            break;
        case 0x0A:
            BC_ASSERT_MSG(393, stack, ByteCodeAssertStack);
            ((ByteCodeVal*) &stack->data)->i =
                -((ByteCodeVal*) &stack->data)->i;
            break;
        case 0x0B:
            BC_ASSERT_MSG(399, stack, ByteCodeAssertStack);
            ((ByteCodeVal*) &stack->data)->i = HSD_Randi(2);
            break;
        case 0x0C:
            BC_ASSERT_MSG(405, stack, ByteCodeAssertStack);
            fv = HSD_Randf();
            stack->data = *(void**) &fv;
            break;
        case 0x0D:
            BC_ASSERT_MSG(411, stack, ByteCodeAssertStack);
            fv = kar_math_bytecode_sinf_approx(
                (f32) (BC_DEG_TO_RAD * (f64) ((ByteCodeVal*) &stack->data)->f));
            stack->data = *(void**) &fv;
            break;
        case 0x0E:
            BC_ASSERT_MSG(417, stack, ByteCodeAssertStack);
            fv = kar_math_bytecode_cosf_approx(
                (f32) (BC_DEG_TO_RAD * (f64) ((ByteCodeVal*) &stack->data)->f));
            stack->data = *(void**) &fv;
            break;
        case 0x0F:
            BC_ASSERT_MSG(423, stack, ByteCodeAssertStack);
            fv = (f32) tan(
                (f32) (BC_DEG_TO_RAD * (f64) ((ByteCodeVal*) &stack->data)->f));
            stack->data = *(void**) &fv;
            break;
        case 0x10:
            BC_ASSERT_MSG(429, stack, ByteCodeAssertStack);
            fv = (f32) (BC_RAD_TO_DEG *
                        kar_asin(((ByteCodeVal*) &stack->data)->f));
            stack->data = *(void**) &fv;
            break;
        case 0x11:
            BC_ASSERT_MSG(435, stack, ByteCodeAssertStack);
            fv = (f32) (BC_RAD_TO_DEG *
                        kar_acos(((ByteCodeVal*) &stack->data)->f));
            stack->data = *(void**) &fv;
            break;
        case 0x12:
            BC_ASSERT_MSG(441, stack, ByteCodeAssertStack);
            fv = (f32) (BC_RAD_TO_DEG *
                        kar_atan(((ByteCodeVal*) &stack->data)->f));
            stack->data = *(void**) &fv;
            break;
        case 0x13:
            BC_ASSERT_MSG(447, stack, ByteCodeAssertStack);
            fv = (f32) kar_log(((ByteCodeVal*) &stack->data)->f);
            stack->data = *(void**) &fv;
            break;
        case 0x14:
            BC_ASSERT_MSG(453, stack, ByteCodeAssertStack);
            fv = (f32) kar_exp(((ByteCodeVal*) &stack->data)->f);
            stack->data = *(void**) &fv;
            break;
        case 0x15:
            BC_ASSERT_MSG(459, stack, ByteCodeAssertStack);
            if (((ByteCodeVal*) &stack->data)->f < 0.0F) {
                fv = -(((ByteCodeVal*) &stack->data)->f);
                stack->data = *(void**) &fv;
            }
            break;
        case 0x28:
            BC_ASSERT_MSG(467, stack, ByteCodeAssertStack);
            {
                d0 = ((ByteCodeVal*) &stack->data)->i;
                if (d0 < 0) {
                    ((ByteCodeVal*) &stack->data)->i = -d0;
                }
            }
            break;
        case 0x16:
            BC_ASSERT_MSG(474, stack, ByteCodeAssertStack);
            fv = bytecode_sqrtf(((ByteCodeVal*) &stack->data)->f);
            stack->data = *(void**) &fv;
            break;
        case 0x31:
            BC_ASSERT_MSG(480, stack, ByteCodeAssertStack);
            stack->data = (void*) !(s32) stack->data;
            break;
        case 0x17:
            BC_ASSERT_MSG(501, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(501, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            fv = ((ByteCodeVal*) &stack->data)->f + f0;
            stack->data = *(void**) &fv;
            break;
        case 0x18:
            BC_ASSERT_MSG(507, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(507, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            fv = ((ByteCodeVal*) &stack->data)->f - f0;
            stack->data = *(void**) &fv;
            break;
        case 0x19:
            BC_ASSERT_MSG(513, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(513, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            fv = ((ByteCodeVal*) &stack->data)->f * f0;
            stack->data = *(void**) &fv;
            break;
        case 0x1A:
            BC_ASSERT_MSG(519, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(519, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            fv = ((ByteCodeVal*) &stack->data)->f / f0;
            stack->data = *(void**) &fv;
            break;
        case 0x1B:
            BC_ASSERT_MSG(525, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(525, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            fv = (f32) kar_fmod(
                ((ByteCodeVal*) &stack->data)->f, f0);
            stack->data = *(void**) &fv;
            break;
        case 0x1C:
            BC_ASSERT_MSG(531, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(531, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i + d1);
            break;
        case 0x1D:
            BC_ASSERT_MSG(536, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(536, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i - d1);
            break;
        case 0x1E:
            BC_ASSERT_MSG(541, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(541, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i * d1);
            break;
        case 0x1F:
            BC_ASSERT_MSG(546, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(546, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i / d1);
            break;
        case 0x20:
            BC_ASSERT_MSG(551, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(551, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            d0 = ((ByteCodeVal*) &stack->data)->i;
            ((ByteCodeVal*) &stack->data)->i = (d0 % d1);
            break;
        case 0x21:
            BC_ASSERT_MSG(556, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(556, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            fv = (f32) kar_pow(((ByteCodeVal*) &stack->data)->f, f0);
            stack->data = *(void**) &fv;
            break;
        case 0x22:
            BC_ASSERT_MSG(562, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(562, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            if (((ByteCodeVal*) &stack->data)->f > f0) {
                stack->data = *(void**) &f0;
            }
            break;
        case 0x23:
            BC_ASSERT_MSG(569, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(569, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            if (((ByteCodeVal*) &stack->data)->f < f0) {
                stack->data = *(void**) &f0;
            }
            break;
        case 0x24:
            BC_ASSERT_MSG(576, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(576, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            if (((ByteCodeVal*) &stack->data)->i > d1) {
                ((ByteCodeVal*) &stack->data)->i = d1;
            }
            break;
        case 0x25:
            BC_ASSERT_MSG(583, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(583, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            if (((ByteCodeVal*) &stack->data)->i < d1) {
                ((ByteCodeVal*) &stack->data)->i = d1;
            }
            break;
        case 0x26: {
            f32 result;
            BC_ASSERT_MSG(590, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(590, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            f1 = ((ByteCodeVal*) &stack->data)->f;
            if (f0 == 0.0F) {
                result = f1 >= 0.0F ? 1.5707964F : -1.5707964F;
            } else {
                result = (f32) kar_atan2(f1, f0);
            }
            fv = (f32) (BC_RAD_TO_DEG * result);
            stack->data = *(void**) &fv;
            break;
        }
        case 0x33:
            BC_ASSERT_MSG(596, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(596, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            f1 = ((ByteCodeVal*) &stack->data)->f;
            ((ByteCodeVal*) &stack->data)->i = (f1 < f0);
            break;
        case 0x34:
            BC_ASSERT_MSG(601, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(601, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            f1 = ((ByteCodeVal*) &stack->data)->f;
            ((ByteCodeVal*) &stack->data)->i = (f1 > f0);
            break;
        case 0x35:
            BC_ASSERT_MSG(606, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(606, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->f <= f0);
            break;
        case 0x36:
            BC_ASSERT_MSG(611, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(611, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            f1 = ((ByteCodeVal*) &stack->data)->f;
            ((ByteCodeVal*) &stack->data)->i = (f1 >= f0);
            break;
        case 0x37:
            BC_ASSERT_MSG(616, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(616, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            f1 = ((ByteCodeVal*) &stack->data)->f;
            ((ByteCodeVal*) &stack->data)->i = (f1 == f0);
            break;
        case 0x38:
            BC_ASSERT_MSG(621, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(621, stack->next, "stack->next");
            f0 = ((ByteCodeVal*) &stack->data)->f;
            stack = HSD_SListRemove(stack);
            f1 = ((ByteCodeVal*) &stack->data)->f;
            ((ByteCodeVal*) &stack->data)->i = (f1 != f0);
            break;
        case 0x29:
            BC_ASSERT_MSG(626, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(626, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i < d1);
            break;
        case 0x2A:
            BC_ASSERT_MSG(631, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(631, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i > d1);
            break;
        case 0x2B:
            BC_ASSERT_MSG(636, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(636, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i <= d1);
            break;
        case 0x2C:
            BC_ASSERT_MSG(641, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(641, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i >= d1);
            break;
        case 0x2D:
            BC_ASSERT_MSG(646, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(646, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i == d1);
            break;
        case 0x2E:
            BC_ASSERT_MSG(651, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(651, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            ((ByteCodeVal*) &stack->data)->i =
                (((ByteCodeVal*) &stack->data)->i != d1);
            break;
        case 0x2F:
            BC_ASSERT_MSG(656, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(656, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            d0 = ((ByteCodeVal*) &stack->data)->i;
            {
                int val = 0;
                if (d0 != 0 && d1 != 0) {
                    val = 1;
                }
                ((ByteCodeVal*) &stack->data)->i = val;
            }
            break;
        case 0x30:
            BC_ASSERT_MSG(661, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(661, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            d0 = ((ByteCodeVal*) &stack->data)->i;
            {
                int val = 1;
                if (d0 == 0 && d1 == 0) {
                    val = 0;
                }
                ((ByteCodeVal*) &stack->data)->i = val;
            }
            break;
        case 0x32:
            BC_ASSERT_MSG(666, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(666, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            d0 = ((ByteCodeVal*) &stack->data)->i;
            ((ByteCodeVal*) &stack->data)->i =
                (d0 == 0 && d1 != 0) || (d0 != 0 && d1 == 0);
            break;
        case 0x39:
            BC_ASSERT_MSG(671, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(671, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            stack->data = (void*) (((ByteCodeVal*) &stack->data)->i & d1);
            break;
        case 0x3A:
            BC_ASSERT_MSG(676, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(676, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            stack->data = (void*) (((ByteCodeVal*) &stack->data)->i | d1);
            break;
        case 0x3B:
            BC_ASSERT_MSG(681, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(681, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            stack->data = (void*) (((ByteCodeVal*) &stack->data)->i ^ d1);
            break;
        case 0x27:
            BC_ASSERT_MSG(687, stack, ByteCodeAssertStack);
            BC_ASSERT_MSG(687, stack->next, "stack->next");
            d1 = ((ByteCodeVal*) &stack->data)->i;
            stack = HSD_SListRemove(stack);
            d0 = ((ByteCodeVal*) &stack->data)->i;
            ((ByteCodeVal*) &stack->data)->i = (d0 + HSD_Randi((d1 - d0) + 1));
            break;
        default:
            OSReport("unexpected opcode 0x%x.\n", last_command);
            HSD_Panic(ByteCodeSourceFile, 693, "unexpected opcode 0x%x.\n");
            break;
        }
    }
}

static inline f32 kar_bc_poly(f32 y)
{
    f32 z;

    if (y <= 0.7853981633974483) {
        z = y * y;
        return y *
               (1.0F -
                z * __fnmsubs(z, __fnmsubs(0.00019587841F, z, 0.008332824F),
                              0.16666669F));
    }
    z = (f32) (1.5707963267948966 - (f64) y);
    z = z * z;
    return 0.9999998F -
           z * __fnmsubs(z, __fnmsubs(0.0013400711F, z, 0.04163633F),
                         0.49999395F);
}

static inline f32 kar_bc_half(f32 y)
{
    if (y <= 1.5707963267948966) {
        return kar_bc_poly(y);
    }
    return kar_bc_poly((f32) (3.141592653589793 - (f64) y));
}

static inline f32 kar_bc_sin_reduce(f32 y)
{
    while (y > 6.283185307179586) {
        y = (f32) (y - 6.283185307179586);
    }
    if (y <= 3.141592653589793) {
        return kar_bc_half(y);
    }
    return -kar_bc_half((f32) (y - 3.141592653589793));
}

f32 kar_math_bytecode_cosf_approx(f32 x)
{
    f32 y;

    if (x != 0.0F) {
        y = (f32) ((f64) x + 1.5707963267948966);
        if (y < 0.0F) {
            return -kar_bc_sin_reduce(-y);
        }
        return kar_bc_sin_reduce(y);
    }
    return 1.0F;
}

f32 kar_math_bytecode_sinf_approx(f32 x)
{
    if (x != 0.0F) {
        if (x < 0.0F) {
            return -kar_bc_sin_reduce(-x);
        }
        return kar_bc_sin_reduce(x);
    }
    return 0.0F;
}
