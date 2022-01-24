#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

#define NO_APP_DATA 2

void dumpData(FILE* dest, char data[]) {
  fprintf(dest,"------------- \n");
  int dataSize = strlen(data);
  printf("[Dump to file] Size of data: %d characters \n", strlen(data));
  fprintf(dest, "%s", data);
};

void raiseError(char msg[], int errorCode) {
  MessageBox(NULL, msg, "Encrypt: Error", MB_OK);
  printf("Process failed with exit code %i", errorCode);
  exit(errorCode);
}

void writeToAppData(char fileName[], char fileContents[])
{
    char * appDataPath = getenv("APPDATA");

    char noAppDataMsg[] = "Failed to locate APPDATA directory.";

    if (!appDataPath)
      raiseError(noAppDataMsg, NO_APP_DATA);

    char buffer[0x400];

    char * subFolderPath = "\\EncryptionTool";

    char * appDataFolderPath = malloc(strlen(appDataPath)
    + strlen(subFolderPath));

    sprintf(appDataFolderPath,"%s%s", appDataPath, subFolderPath);


    CreateDirectory(appDataFolderPath, NULL);

    snprintf(buffer, sizeof(buffer), "%s\\%s", appDataFolderPath, fileName);

    FILE* appdata_file_pointer = fopen(buffer, "w");

    dumpData(appdata_file_pointer, fileContents);
    /* should be enough time to comfortably write data*/
    Sleep(1000);

    fclose(appdata_file_pointer);
}
