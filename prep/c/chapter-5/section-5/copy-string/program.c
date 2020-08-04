#include <stdio.h>

void stringpcopy(char *to, char *from);
void stringcopy(char *to, char *from);

char to[20];
char to2[20];
char to3[20];

int main()
{
    stringcopy(to, "hello buddy");
    printf("1. copied string %s \n", to);
    stringpcopy(to2, "hello buddy");
    printf("2. copied string %s \n", to2);

    char h = 'h';
    stringpcopy(to3, &h);
    printf("3. hello normal char pointer that has no list apparatus? \n", to3);
}

void stringpcopy(char *to, char *from)
{
    while ((*to = *from) != '\0') {
        to++;
        from++;
    }
}

void stringcopy(char *to, char *from)
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}