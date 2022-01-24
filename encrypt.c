#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint; 

#define ZERO_KEY_LENGTH_OR_UNREADABLE 4
#define ASCII_VALUE_ADDITION_FAILURE 1

int getLen(unsigned int x) {
    if (x >= 1000000000000) return 13;
    if (x >= 100000000000) return 12;
    if (x >= 10000000000) return 11;
    if (x >= 1000000000) return 10;
    if (x >= 100000000)  return 9;
    if (x >= 10000000)   return 8;
    if (x >= 1000000)    return 7;
    if (x >= 100000)     return 6;
    if (x >= 10000)      return 5;
    if (x >= 1000)       return 4;
    if (x >= 100)        return 3;
    if (x >= 10)         return 2;
    return 1;
}



void encryptFile(const char * fileName, int upperGeneratedRandomBound) {
    
    /* 1: keygen */

    uint _generatedKey = writeAndReturnKey(upperGeneratedRandomBound);

    printf("%u", _generatedKey);


    /* The following segment of code is no longer useful, however could 
    be useful if anyone were to pick up this project. */

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

    ~~ read from file ~~

    --------------------------------------------------------- */ 

  /* 2: encrypting */

  /* Adding an ASCII value to each byte, correlated to the previously generated key. */

    int keyLength = getLen(_generatedKey);
  
    char zeroKeyLenMsg = "Generated key length is 0 or unreadable";

    if (keyLength == 0) 
      raiseError(zeroKeyLenMsg, ZERO_KEY_LENGTH_OR_UNREADABLE);

    for (size_t i; i < keyLength; i++) {

    }


}
