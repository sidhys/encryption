/* This file simply provides a command-line interface for the encryption program. 
  See other files for encryption source code. */


#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"
#include ".\include\encrypt.h"

typedef unsigned int uint;


int main(int argc, char *argv[]) 
{

  if (argc < 3) {
    printf("Please supply three arguments. \n Ex. program.exe C:\file1.txt C:\file2.txt 99 \n");
    return 3;
  }


  const char* origPath = argv[0];
  const char* finalPath = argv[1];
  int randUpperBound = argv[2];


  encryptFile(origPath, finalPath, randUpperBound); 


  return 0;

}
