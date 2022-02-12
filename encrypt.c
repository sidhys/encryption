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


/*------------------------------*/

void encryptFile(const char * origFileName, const char* finalFileName,  int upperGeneratedRandomBound) {
    
    /* 1: keygen */

    uint _generatedKey = writeAndReturnKey(upperGeneratedRandomBound);

    printf(": %u \n ", _generatedKey);

  /* 2: encrypting */

  /* Adding an ASCII value to each byte, correlated to the previously generated key. */

    int keyLength = getLen(_generatedKey);
  
    char zeroKeyLenMsg[] = "Generated key length is 0 or unreadable";
    char negativeKeyMsg[] = "Generated key (of type unsigned int) is somehow negative.";
  
    if (keyLength == 0) 
      raiseError(zeroKeyLenMsg, ZERO_KEY_LENGTH_OR_UNREADABLE);


    uint oneDigitArray[13] = {0};

    uint i;

    for (i = 0; i < keyLength; i++) {

      if (_generatedKey < 0) 
        raiseError(negativeKeyMsg, NEGATIVE_UNSIGNED_INT);

      uint digit = (uint)(_generatedKey / pow (10, i)) % 10;
    
      oneDigitArray[i] = digit; 

    }


  FILE* origFile = fopen(origFileName, "r");
  char currLine[256];
  FILE* finalFile = fopen(finalFileName, "a");

  int random_loop_value1;
  int random_loop_value2;

  while (fgets(currLine, sizeof(currLine), origFile)) {

      for (random_loop_value1 = 0; random_loop_value1 < sizeof(currLine); random_loop_value1++) 
        {

          if (random_loop_value2 > 12) 
            random_loop_value2 = 0;
    
          char throw_away_value = currLine[random_loop_value1] + (int) oneDigitArray[random_loop_value2];

          fprintf(finalFile, throw_away_value);

          random_loop_value2++;

        }

        fprintf(finalFile, "\n");

  };

  fclose(origFile);
  fclose(finalFile);
    
}
