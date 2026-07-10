#include <sysdolphin/object.h>

extern HSD_ClassInfo hsdObj;
extern HSD_ClassInfo hsdClass;
extern char hsdObj_library_string[];
extern char lbl_805DCD10[8];

void ObjInfoInit(void)
{
    hsdInitClassInfo(&hsdObj, &hsdClass,
        hsdObj_library_string, lbl_805DCD10,
        sizeof(HSD_ObjInfo), sizeof(HSD_Obj));
}
