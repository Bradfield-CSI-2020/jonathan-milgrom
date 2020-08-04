#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float celc(float fahr)
{
  return 5.0/9.0 * (fahr - 32);
}

int main()
{
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%3d\t%6.1f\n", fahr, celc(fahr));
  }
}