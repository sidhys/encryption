#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint; 

void encryptFile(const char * fileName, int upperGeneratedRandomBound) {
    /* 1: keygen */

    uint generatedKey = writeAndReturnKey(upperGeneratedRandomBound);


    /* Commented out part is frankly useless, used it before 
    I started returning the key in the same function where 
    it was written. */

    /* ---------------------------------------------------------
    char * operation = "Get-Content -path";
    char * appDataPath = getenv("APPDATA");
    char * subFolderPath = "\\EncryptionTool";
    char * alternativeDataStreamFileName =  "runtime.jpg -stream SECRET";
    char * outputDirection = " | Out-File -FilePath ";
    char * outPath = "temp.tmp";
    char * powershellCommand = malloc(strlen(appDataPath) +
                                            strlen(operation) + 
                                            strlen(subFolderPath) +
                               strlen(alternativeDataStreamFileName) +
                                        strlen(outputDirection) + 
                                        strlen(appDataPath) + 
                                        strlen (subFolderPath) + 
                                        strlen(outPath));

    printf("\n Survived allocation! \n");

    sprintf(powershellCommand, "%s %s%s\\%s%s%s%s%s", operation, appDataPath,
              subFolderPath, alternativeDataStreamFileName, outputDirection,
            appDataPath, subFolderPath, outPath);

    printf("Powershell command: %s", *powershellCommand);

    --------------------------------------------------------- */ 


}
