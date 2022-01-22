#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include ".\include\log.h"


void dumpData(FILE* dest, char data[]) {
  fprintf(dest,"------------- \n");
  int dataSize = strlen(data);
  printf("[dump] size of data %d \n", strlen(data));
  for (size_t i = 0; i < dataSize; i++) {
    fprintf(dest, "%c", data[i]);
  };
};

void raiseError(char msg[], int errorCode) {
  MessageBox(NULL, msg, "Encrypt: Error", MB_OK);
  // todo: dump error info somewhere
  exit(errorCode);
}
