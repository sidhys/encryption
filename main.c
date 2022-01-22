#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint;

int main(void)
{
  // FILE* dest1 = fopen("C:\\Users\\Sid\\Desktop\\lol.txt:test", "w");
  // char buffer[255];
  // char data1[] = "ddsadaas";
  // fprintf(dest1, "%s", data1);
  // fclose(dest1);


  uint random = randomValue(99);

  printf("%u", random);

  return 0;
}
