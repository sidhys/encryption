#include <stdio.h>
#include <Windows.h>

#include ".\include\key.h"
#include ".\include\log.h"

typedef unsigned int uint;

int main(void)
{

  uint a = randomValue(33);

  printf("%u", a);

  return 0;
}
