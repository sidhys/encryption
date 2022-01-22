#include <stdio.h>
#include <Windows.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint;

int main(void)
{
  FILE* dest1 = fopen("C:\\Users\\Sid\\Desktop\\lol.txt:test", "w");
  char buffer[255];
  // FILE* dest2 = fopen("C:\\Users\\Sid\\Desktop\\lol.txt:other", "w");
  char data1[] = "ddsadaas";
  fprintf(dest1, "%s", data1);
  Sleep(1000);
  fgets(buffer, 255, (FILE*) dest1);
  printf("buffer: %s", buffer);
  // void dumpData(FILE* dest2, char data2[]);
  fclose(dest1);

  return 0;
}
