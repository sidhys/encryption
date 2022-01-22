#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

unsigned int writeAndReturnKey()
{

  char originalFileName[] = "runtime.jpg";
  char originalFileContents[] = "if you're reading this, dont delete this file ‼️‼️";

  writeToAppData(originalFileName, originalFileContents);

  unsigned int randomInteger = randomValue(99);

  char alternativeDataStreamFileName[] = "runtime.jpg:SECRET";

  char characterKey[sizeof(randomInteger)];

  sprintf(characterKey, "%u", randomInteger);

  writeToAppData(alternativeDataStreamFileName, characterKey); // this does NOT work, function is being dumb (todo: just write a scalled down version of the function that can do this, inside of this file)

  return randomInteger;
}
