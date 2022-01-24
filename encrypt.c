#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint; 

#define ZERO_KEY_LENGTH_OR_UNREADABLE 4
#define ASCII_VALUE_ADDITION_FAILURE 1
#define NEGATIVE_UNSIGNED_INT 5

/* Helper functions 
--------------------------------*/

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

unsigned long long untilOneDigitIsLeftHelper(int len) {
  if (len == 13) return 10000000000000; 
  if (len == 12) return 1000000000000;
  if (len == 11) return 100000000000;
  if (len == 10) return 10000000000; 
  if (len == 9) return 1000000000;
  if (len == 8) return 100000000;
  if (len == 7) return 10000000; 
  if (len == 6) return 1000000;
  if (len == 5) return 100000;
  if (len == 4) return 10000; 
  if (len == 3) return 1000;
  if (len == 2) return 100;
  if (len == 1) return 10; 
}

/*------------------------------*/

void encryptFile(const char * fileName, int upperGeneratedRandomBound) {
    
    /* 1: keygen */

    uint _generatedKey = writeAndReturnKey(upperGeneratedRandomBound);

    printf(": %u \n ", _generatedKey);


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
  
    char zeroKeyLenMsg[] = "Generated key length is 0 or unreadable";
    char negativeKeyMsg[] = "Generated key (of type unsigned int) is somehow negative.";
  
    if (keyLength == 0) 
      raiseError(zeroKeyLenMsg, ZERO_KEY_LENGTH_OR_UNREADABLE);


  /* this where it gets very messy */

    int oneDigitArray[13];

    int i;

    for (i = 0; i < keyLength; i++) {

      printf("\n [debug] count %i \n ", i);

      unsigned int whileLoopVal = untilOneDigitIsLeftHelper(i);

      int __generatedKey = _generatedKey; 

    /* On some runs, __generatedKey became negative,
       despite being equal to an unsigned int (_generatedKey) */

      if (__generatedKey < 0) 
        raiseError(negativeKeyMsg, NEGATIVE_UNSIGNED_INT);


  printf("%d", __generatedKey);

    /* program currently dies after this */

      // while(__generatedKey >= whileLoopVal) {
      //     __generatedKey = __generatedKey / 10;
      // }  

      printf("\n %d element is %d \n", i, __generatedKey);
      

    }


}
