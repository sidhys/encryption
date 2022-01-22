#include <stdio.h>
#include <Windows.h>
#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint;

int main(void)
{

  printf("-----DEBUG-----");

  uint identifier = randomValue(4);

  printf("%d", identifier);

char a[] = "testing";
raiseError(a, 1);

/* this works:
  FILE* dest = fopen("C:\\Users\\Sid\\Desktop\\log.txt", "w");
  char data[] = "testing";
  dumpData(dest, data);
  fclose(dest); */

  return 0;
}
