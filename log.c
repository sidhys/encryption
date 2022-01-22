#include <Windows.h>
#include <stdio.h>
#include ".\include\log.h"


void dumpData(FILE* dest, char data[]) {
  fprintf(dest,"------------- \n");
  int dataSize = sizeof(data)/sizeof(data[0]);
  for (size_t i = 0; i < dataSize; i++) {
    fprintf(dest, "%d", data[i]);
  };
};

void raiseError(char msg[], unsigned int errorCode) {
  MessageBox(NULL, msg, "Encrypt: Error", MB_OK);
  // dump error info somewhere 
  for(;;)
    Sleep(1000);
}
