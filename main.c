#include <stdio.h>
#include <Windows.h>
#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint;
char noAppDataMsg[] =
"\n Failed to retrieve your computer's appdata path. Try re-running the program";
int noAppDataCode = 1001;


int main(void)
{

  char* appDataPath = getenv("APPDATA");
  if (!appDataPath) {
    raiseError(noAppDataMsg, noAppDataCode);
  };

  char buffer[0x400];
  snprintf(buffer, sizeof(buffer), "%s\\dn.txt", appDataPath);
  FILE* dn = fopen(buffer, "w");
  dumpData(dn, noAppDataMsg);
  printf("Wrote data to %s\\dn.txt", appDataPath);
  Sleep(5000);
  fclose(dn);
  return 0;
}
