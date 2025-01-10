#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y; //step 1
    *x = *x ^ *y; //step 2
    *y = *x ^ *y; //step 3
}

//when we try this with 1,2,3,4, it works how you'd expect, but when we try 1,2,3,4,5, it doesn't.
//the middle number will always be odd because of an odd lengthed array.
void reverse_array(int a[], int cnt)
{
    int first, last;
    for(first = 0, last = cnt-1;
        first <= last; //change to first < last to make it work properly
        first++, last--)
        inplace_swap(&a[first], &a[last]);
}



int main()
{
    int len = 5;
    int i;
    int a[] = {1, 2, 3, 4, 5};
    reverse_array(a, len);
    for(i = 0; i < len; i++)
    {
        printf("%i\n", a[i]);
    }
}