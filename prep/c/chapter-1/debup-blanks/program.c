#include <stdio.h>

int main()
{
  int prev_was_blank = 0, c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' && prev_was_blank) {
      continue;
    }
    prev_was_blank = c == ' ' ? 1 : 0;
    putchar(c);
  }

}