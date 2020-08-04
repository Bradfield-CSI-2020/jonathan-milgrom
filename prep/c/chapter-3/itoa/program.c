#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(short int n, char s[]);
void reverse(char s[]);
char dtoc(short int i);

/*
    Convert an integer to a string.

    Purpose of this program in the book is to show off a useful do / while loop. Here we want the do to happen whether or not the first
    while loop is satisfied so that n's < 10 still result in string with a single element.

    I've also used this exercise to
        - mess around with (signed) short ints. Looks like we've confirmed a 2's compliments implementation since 32768 (2^16 / 2), on the high end,
            and -32769 (-2^16 / 2 - 1), on the low end, throw compiler errors
        - understand the edge case of mutiplying a INT16_MIN by -1 in a 2's compliment implementation - spoiler alert: this actually maps number back to itself, yay.
*/
int main()
{
    char s[10] = "abcd";
    reverse(s);
    printf("%s\n", s);

    char a[10];
    itoa(1234, a);
    printf("string: %s\n", a);
    itoa(-1234, a);
    printf("string: %s\n", a);
    // 2^16 / 2 - 1
    itoa(32767, a);
    printf("string: %s\n", a);
    // - 2^16 / 2
    itoa(INT16_MIN, a);
    printf("string: %s\n", a);
    // - 2^16 / 2 - 1
    itoa(-32767, a);
    printf("string: %s\n", a);

    // COMPILER ERROR b/c 32768 is above the range of signed 2^16 numbers in 2's compliment representation
    // itoa(32768 /* - 2^16 / 2 */, a);
    // printf("32768: %s\n", a);

    // COMPILER ERROR b/c -32769 is below the range of signed 2^16 numbers in 2's compliment representation
    // itoa(-32769 /* - 2^16 / 2 - 1  */, a);
    // printf("-32769: %s\n", a);
}

void itoa(short int n, char s[])
{
    printf("itoa called with n: %d\n", n);
    int sign = n;
    int i = 0;
    
    char c;
    do {
        s[i++] = dtoc(abs(n % 10));
    } while (n /= 10);

    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/*
    Convert a digit to a char.

    Since ASCII representation of characters are sequential, adding a digit e.g. 6 plus '0' will give us the number
    representingn '6'.
*/
char dtoc(short int i)
{
    return i + '0';
}
