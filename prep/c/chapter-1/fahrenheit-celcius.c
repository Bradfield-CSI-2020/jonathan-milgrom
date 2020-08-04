#include <stdio.h>

int main()
{
  int fahr;
  float celc;
  int lower = 0, upper = 300, step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celc = 5 * (fahr - 32.0) / 9;
    printf("%d\t%.1f\n", fahr, celc);
    fahr = fahr + step;
  }
}