#include <stdio.h>
#include <ctype.h>

#define SIZE 2

int getch(void);
void ungetch(char c);

int getint(int *s);

int main()
{
    int c, i;
    int integers[SIZE];

    for (i = 0; i < SIZE; ++i)
        printf("before %d\n", integers[i]);

    for (i = 0; i < SIZE && getint(&integers[i]) != EOF; ++i)
        ;

    for (i = 0; i < SIZE; ++i)
        printf("after %d\n", integers[i]);

    return 0;
}

/*
    Purpose of this excersize is to show a use case of a pointer. getint traverses character by character like getchar.
    And it returns EOF when EOF is reached. EOF is guarnateed to be an int that is represented by no char. However, now
    that we are dealing in ints, its possible a user inputted int conflicts with EOF. So we can't just _return_ the 
    created int just like with getchar. Thus, we use a pointer to fill in the passed-in container with every encountered
    int. Still unclear why we couln't just pass in an array as before. However, that would definitely be a bit more 
    awkward, since we'd also have to pass in the correct index to add to.
    
    Produce a single character from input (like getchar), treating each string of integer characters as a single integer.
    Since EOF could be an integer itself, we can't return the created integer itself from the function.

    plan:
        - Fill the array element with the next integer, return positive number.
        - Return 0 if next character is not a number.
        - Return EOF when reached.
*/
int getint(int *s)
{
    int c, sign, power;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        return 0;
    }
    
    sign = c == '-' ? -1 : 1;
    if (c == '-' || c == '+')
        c = getch();

    for (*s = 0; isdigit(c); c = getch())
        *s = *s * 10 + (c - '0');
    
    *s = *s * sign;

    printf("debug *s: %d\n", *s);
    if (c != EOF)
        ungetch(c);

    /*
        we return a positive number (or OEF) to indidcate that an integer was added (or OEF, or added plus EOF).
        we can't just return 1 because
            - it's possible it was EOF and not integer was added
            - we need to return EOF
            - I hate this function.
    */
    return c; 
}

#define BUFSIZE 1000

char buffer[BUFSIZ]; /* buffer for getchar */
int cursor = -1; /* position of the last added item */

int getch(void)
{
    return (cursor > -1) ? buffer[cursor--] : getchar();
}

void ungetch(char c)
{
    buffer[++cursor] = c;
}