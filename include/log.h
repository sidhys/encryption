/* Everything related to logging. */
#pragma once
#include <Windows.h>
#include <stdio.h>
#include <cstring>

void dumpData(
    FILE* dest,
    char data[]
);

void raiseError(
    char msg[],
    unsigned int errorCode; 
)
