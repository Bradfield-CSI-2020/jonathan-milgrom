#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void printargs(char *argv[]);
int mygetline(char *line, int maxline);

/*
    return 0 if strings are equal, <0 ('a' is less than 'b' for example) if s < t, >0 if s > t.
*/
int mystrcmp(char *s, char *t);

/*
    Print each line that includes a matching substring.

        format: find -x -n pattern
        optional flags
            -x: negative pattern (everything line that doesnt match pattern)
            -n: print line number

    plan:
        - parse keyword/options
            - 
        - get matching lines from input
            - getline
            - if match, print line
 */

int main(int argc /* argument count */, char *argv[] /* array of pointers to each space-separated command line argument as a strings */)
{
    printargs(argv);

    argv++, argc--; // ./a.out registers as an argument, which we want to ignore.

    if (!argc) {
        printf("Use command 'find' to start program.\n");
        return 0;
    }

    if (mystrcmp("find", *argv++) /* returns zero if equal */) {
        printf("Use command 'find' to start program.\n");
        return 0;
    }

    char line[MAXLINE];

    while (mygetline(line, MAXLINE) > 0) {
        if (strstr(line, *argv) != NULL)
            printf("%s", line);
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

int mystrcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}

void printargs(char *argv[])
{
    printf("argv:\n");
    for (int i= 0; argv[i]; i++)
        printf("%d: %s\n", i, argv[i]);
}