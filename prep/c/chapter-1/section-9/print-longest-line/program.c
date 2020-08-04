#include <stdio.h>

#define MAX_LINE_SIZE 1000

/*
  Need to call this _my_getline b/c apparently standard lib has a getline
*/
int mygetline(char line[], int maxline);
void copy(char from[], char to[]);

/*
  Write a program that prints the longest line of text from the inputted text stream.
 */
int main()
{
    int maxlength, linelength, i;
    char line[MAX_LINE_SIZE];
    char longest[MAX_LINE_SIZE];

    maxlength = 0;
    while ((linelength = mygetline(line, MAX_LINE_SIZE)) > 0) {
        if (linelength > maxlength) {
            maxlength = linelength;
            copy(line, longest);
        }
    }

    if (maxlength > 0)
        printf("%s", longest);

    return 0;
}

/*
  i. Add a new line from beginning of shared array to a marker ('\0')
  ii. Return length of line if line exists (even a line with just new line character would have length 1); 0 otherwise.
*/
int mygetline(char line[], int maxline)
{
    int i, c;

    for (i = 0; (c = getchar()) != EOF && i < maxline && c != '\n'; i++)
        line[i] = c;

    // if there was a line, do some housekeeping
    // note: the end marker is placed at an index equal to the lenght of the array, which means the array occupies one more slot than its length.
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char from[], char to[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}