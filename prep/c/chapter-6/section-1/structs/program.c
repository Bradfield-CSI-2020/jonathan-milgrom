#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point addpoint(struct point s1, struct point s2);
struct point makepoint(int x, int y);
void printpoint(char *message, struct point p);

int main()
{
    struct point p1 = { 100, 200 };

    printpoint("struct order", p1);
    printpoint("can we add", addpoint(p1, makepoint(300, 400)));
    printpoint("pass by value?", p1);
}

struct point addpoint(struct point s1, struct point s2)
{
    s1.x += s2.x;
    s1.y += s2.y;
    return s1;
}

struct point makepoint(int x, int y)
{
    struct point s1 = {x, y};
    return s1;
}

void printpoint(char *message, struct point p)
{
    printf("%s x: %d, y: %d\n", message, p.x, p.y);
}