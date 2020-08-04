#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <locale.h>

int main()
{
    setlocale(LC_NUMERIC, "");
    printf("INT_MAX: %'d\n", INT_MAX);
    printf("INT_MIN: %'d\n", INT_MIN);
    printf("LONG_MAX: %E\n", LONG_MAX);
    printf("LONG_MIN: %.E\n", LONG_MIN);
    printf("CHAR_MAX: %'d\n", CHAR_MAX);
    printf("CHAR_MIN: %'d\n", CHAR_MIN);
    return 0;
}
