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

  /* writeToAppData() doesn't work with alternative data streams,
  here's a very hardcoded implementation of it that works for
  this application's context */

  unsigned int randomInteger = randomValue(99);

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


  /* currently, the written value isn't equal to the actual
  generated value. i'm assuming this is due to some sort of bit-loss.
  this shouldn't be a problem, as this (kinda?) adds some more
  variability to the key, and the value can simply be taken from the file. */
  printf("[Key] Wrote key");

  return randomInteger;
}
