#include <stdio.h>
#include <Windows.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint;
char noAppDataMsg[] =
"\n Failed to retrieve your computer's appdata path. Try re-running the program.";
int noAppDataCode = 1001;


int main(void)
{

   char fileName[] = "test.txt";
   char fileContents[] = "test tester testing tested";
      writeToAppData(fileName, fileContents);


  return 0;
}
