#include <stdio.h>

/* The purpose of this program is to introduce arrays and if, else if, else control flow */
int main()
{
  int c, i, nwhite, nother;
  int ndigits[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; i++) {
    ndigits[i] = 0;
  }

  while ((c = getchar()) != EOF)
  {
    if (c >= '0' && c <= '9')
      ++ndigits[c - '0'];
    else if (c == '\n' || c == '\t' || c == ' ')
      ++nwhite;
    else 
      ++nother;
  }
  
  for (i = 0; i < 10; i++)
    printf(" %d:%d", i, ndigits[i]);

  printf(" white:%d", nwhite);
  printf(" other:%d", nother);
}