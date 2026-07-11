#ifndef _robj_alloc_h_
#define _robj_alloc_h_

#include <sysdolphin/objalloc.h>

void HSD_RObjInitAllocData(void);
HSD_ObjAllocData* HSD_RObjGetAllocData(void);
HSD_ObjAllocData* HSD_RvalueObjGetAllocData(void);
void _HSD_RObjForgetMemory(void);

#endif
