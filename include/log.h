/* Everything related to logging. */

#ifndef log
#define log

#include <Windows.h>
#include <stdio.h>

void dumpData(
    FILE* dest,
    char data[]
);

void raiseError(
    char msg[],
    int errorCode
);
void writeToAppData(char fileName[], char fileContents[]);


#endif
