#include <stdio.h>
#include ".\include\key.h"

typedef unsigned int uint;

int main(void)
{

  printf("-----DEBUG-----");

  uint identifier = hardwareGUID();

  printf("%d", identifier);

  return 0;
}
