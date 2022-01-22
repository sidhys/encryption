#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include ".\include\log.h"


void dumpData(FILE* dest, char data[]) {
  fprintf(dest,"------------- \n");
  int dataSize = strlen(data);
  printf("[Dump to file] Size of data: %d characters \n", strlen(data));\
  fprintf(dest, "%s", data);
};

void raiseError(char msg[], int errorCode) {
  MessageBox(NULL, msg, "Encrypt: Error", MB_OK);
  // todo: dump error info somewhere
  exit(errorCode);
}
