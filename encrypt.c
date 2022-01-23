#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint; 

void encryptFile(const char * fileName, int upperGeneratedRandomBound) {
    /* 1: keygen */

    uint inacc_key = writeAndReturnKey(upperGeneratedRandomBound);

    char alternativeDataStreamFileName[] = "runtime.jpg:SECRET";
    
    char * appDataPath = getenv("APPDATA");
    char * subFolderPath = "\\EncryptionTool";

    char * alternativeDataStreamPath = malloc(strlen(appDataPath) +
                                            strlen(subFolderPath) +
                            strlen(alternativeDataStreamFileName));

    sprintf(alternativeDataStreamPath, "%s%s\\%s", appDataPath,
              subFolderPath, alternativeDataStreamFileName);

    printf("\n path: %s", alternativeDataStreamPath);

    FILE* key_stream_pointer = fopen(alternativeDataStreamPath, "r");

    char readKey[255];
    fgets(readKey, 255, (FILE*) key_stream_pointer);

    const uint keySize = strlen(readKey);

    uint *key_arr = (malloc(sizeof(readKey))); 

    printf("\n key: %s", readKey);

    for (int i = 0; readKey[i] != 0; i++)   {
        key_arr[i] = readKey[i] - '0';
        printf("\n value: %u \n ", key_arr[i]);
    }
    



}
