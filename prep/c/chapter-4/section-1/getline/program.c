#include <stdio.h>

#define MAXLINE 1000

/*
    The purpose of this function (among strindex and a main program that "grep"s for a pattern)
    is to show the basics of breaking a program down into function pieces. In particular,
    separating a pogram conceptually into pieces through functions, and separating functions
    into separate files that can be compiled together.

    Get a line of input.

    plan:
        - expect a char pointer as a container for the found line, and an int limit as maximum number of chars per line
        - interact with input internally, calling getchar for get each character from a input stream
        - return length of line or 0 if no characters remaining.
*/
int mygetline(char *line, int lim);

int main()
{
    char line[MAXLINE];

    while (mygetline(line, MAXLINE) > 0) {
        printf("line %s", line);
    }

    return 0;
}

int mygetline(char *line, int lim)
{
    int c, i = 0;

    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n') 
        line[i++] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i;
}