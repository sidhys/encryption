#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint;

int main(void)
{

   FILE* dest1 = fopen("C:\\Users\\Sid\\Appdata\\Roaming\\EncryptionTool\\runtime.jpg:SECRET", "r");

    char buffer[255];
     fgets(buffer, 255, (FILE*) dest1);
     printf("buffer %s", buffer);
    // char data1[] = "ddsadaas";
    // fprintf(dest1, "%s", data1);
    // fclose(dest1);


  // uint random = writeAndReturnKey(99);
  //
  // printf("%u", random);

  return 0;

}
