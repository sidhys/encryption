/* Everything related to key generation. */

#ifndef key
#define key

#include <Windows.h>

unsigned int randomValue(int upperBound);

void writeToAppData(char fileName[], char fileContents[]);

#endif
