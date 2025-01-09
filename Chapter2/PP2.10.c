#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y; //step 1
    printf("%i\n", *y);
    printf("%i\n", *x);
    *x = *x ^ *y; //step 2
    printf("%i\n", *y);
    printf("%i\n", *x);
    *y = *x ^ *y; //step 3
    printf("%i\n", *y);
    printf("%i\n", *x);
}

int main()
{
    int x = 0;
    int y = 1;
    inplace_swap(&x, &y);
}