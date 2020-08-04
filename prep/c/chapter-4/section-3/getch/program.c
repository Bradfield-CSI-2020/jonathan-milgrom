#include <stdio.h>

#define BUFSIZE 1000

int getch(void);
void ungetch(char c);

/*
    The purpose of getch in the book (among getop and the polish calculator) is to show the scoping and usefulness
    of external variables - i.e. variables that are external to a function defintion. Notice in this case, that
    buffer, cursor must be used by both getch/ungetch and so are positioned external to both.

    The idea behind getch is to create a wrapper around getchar that allows the caller
    to push a character back into "unread" mode, so that the next time getch is called,
    the "unread" character can be read anew. This is useful when the characterization of
    a string of characters requires that an extra character be read (e.g. "when have the digits finished?")
    and that extra character may have value for the subsequent characterization and cannot
    be forgotten

    plan: buffer the getchar call with any ungetched characters. 
*/
int main()
{
    int c;

    ungetch('\n');
    ungetch('\n');
    ungetch('\n');
    while((c = getch()) != EOF)
        printf("c: %c", c);

}

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