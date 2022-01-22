
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

unsigned int randomValue(int upperBound)
{
    HW_PROFILE_INFO hwProfileInfo;

    if (GetCurrentHwProfile(&hwProfileInfo))
		{
      char charProfileGUID[0x400];

      snprintf(charProfileGUID,
        sizeof(charProfileGUID),
        "%s",
        hwProfileInfo.szHwProfileGuid);

      int profileGuidVal;
      for (size_t i = 0; i < 4; ++i) {
          int x = strtol(&charProfileGUID[i], NULL, 10);
          profileGuidVal = 10 * profileGuidVal + x;
      };

      return (unsigned int) profileGuidVal;

    } else
		{
        char errorMessage[] = "Failed to obtain hardware profile info.";
        unsigned int errorCode = 3;
        raiseError(errorMessage, errorCode);
    }
}


void writeToAppData(char fileName[], char fileContents[])
{
    char * appDataPath = getenv("APPDATA");

    char noAppDataMsg[] = "Failed to locate APPDATA directory.";
    int noAppDataCode = 1001;

    if (!appDataPath)
      raiseError(noAppDataMsg, noAppDataCode);

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
