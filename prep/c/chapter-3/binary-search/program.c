#include <stdio.h>

int binarysearch(int item, int orderedlist[], int max);

int main()
{
    int ten[10], nine[9], i;

    for (i = 0; i < 10; ++i) {
        ten[i] = i * 2;
    }

    printf("TEN\n");
    printf("where's 0:%d\n", binarysearch(0, ten, 10));
    printf("where's 1:%d\n", binarysearch(1, ten, 10));
    printf("where's 2:%d\n", binarysearch(2, ten, 10));
    printf("where's 3:%d\n", binarysearch(3, ten, 10));
    printf("where's 4:%d\n", binarysearch(4, ten, 10));

    for (i = 0; i < 9; ++i) {
        nine[i] = i * 2;
    }

    printf("NINE\n");
    printf("where's 0:%d\n", binarysearch(0, nine, 9));
    printf("where's 1:%d\n", binarysearch(1, nine, 9));
    printf("where's 2:%d\n", binarysearch(2, nine, 9));
    printf("where's 3:%d\n", binarysearch(3, nine, 9));
    printf("where's 4:%d\n", binarysearch(4, nine, 9));
}

/*
    Purpose of this exercise in the book is to show the commonality of the if, else if, else decision tree.
    I am implementing to practice with c.
    
    problem: find a in item in a sorted array
    plan:
        - locate mid point
        - if item is equal to mid, return index
        - it item is greater than mid, mark mid as low and repeat
        - if item is less than id, mark mid as high and repeat
        - high == low, return false
*/
int binarysearch(int item, int orderedlist[], int max /* max size of array */)
{
    int low, high, mid;

    low = 0;
    high = max - 1; // max index
    while (low <= high) {
        int guess;

        mid = (high + low) / 2; // fractions are truncated
        guess = orderedlist[mid];

        if (guess == item)
            return mid;
        else if (item < guess)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
