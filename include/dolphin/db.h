#ifndef _DB_H_
#define _DB_H_

#include <dolphin/types.h>

void DBInit(void);
BOOL DBIsDebuggerPresent(void);
void DBPrintf(char* msg, ...);

#endif
