#include <sysdolphin/object.h>

extern HSD_ClassInfo hsdClass;
extern char hsdObj_library_string[];
extern char HSD_ObjClassName[8];

void ObjInfoInit(void)
{
    hsdInitClassInfo(&hsdObj, &hsdClass,
        hsdObj_library_string, HSD_ObjClassName,
        sizeof(HSD_ObjInfo), sizeof(HSD_Obj));
}
