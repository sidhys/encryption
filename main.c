#include <stdio.h>
#include <Windows.h>
#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint;

int main(void)
{

  printf("-----DEBUG-----");

  uint identifier = hardwareGUID();

  printf("%d", identifier);


/* this works: 
  FILE* dest = fopen("C:\\Users\\Sid\\Desktop\\log.txt", "w");
  char data[] = "testing";
  dumpData(dest, data);
  fclose(dest); */

  return 0;
}
