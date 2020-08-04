#include <stdio.h>

void stringpcopy(char *to, char *from);
void stringcopy(char *to, char *from);
void print_section_title(char *title);
void print_int(char *title, int d);

int x, y;
int *ip;

int main(void) {
  printf("Hello World");

  ip = &x;
  x = 10;

  printf("hello x through ip %d\n", *ip);
  *ip = 9;
  printf("hello change to x through change to ip %d\n", x);

  ip = &y;
  y = 20;
  printf("hello y through ip %d\n", *ip);

  printf("now x can change %d\n", ++x);
  printf("without changing ip %d\n", *ip);
  
  printf("we can increment y, ip %d\n", ++*ip);
  printf("through ip as well, y %d\n", y);

  char to[20];
  stringcopy(to, "hello buddy");
  printf("copied string %s \n", to);

  print_section_title("Understanding pointer arithmetic");

  int second = 9;
  int *ip2 = &second;
  
  printf("\n### test *ip++ ###\n");
  print_int("ip2", (long)ip2);
  print_int("*ip2++", *(ip2++));
  print_int("second", second);
  print_int("ip2", (long)ip2);

  int *ip3 = &second;
  printf("\n### test *++ip ###\n");
  print_int("ip3", (long)ip3);
  print_int("*++ip3", *++ip3);
  print_int("second", second);
  print_int("ip3 ", (long)ip3 );

  int *ip4 = &second;
  printf("\n### test ++*ip ###\n");
  print_int("ip4", (long)ip4);
  print_int("++*ip4", ++*ip4);
  print_int("second", second);
  print_int("ip4", (long)ip4);
  return 0;
}

void stringpcopy(char *to, char *from)
{
  
}

void stringcopy(char *to, char *from)
{
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}

void print_section_title(char *title)
{
  printf("\n### \n%s\n###\n\n", title);
}

void print_int(char *title, int d)
{
  printf("%s: %d\n", title, d);
}