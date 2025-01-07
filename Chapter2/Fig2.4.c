/*
This shows code using casting to access and print the 
byte representations of different program objects.
We use typedef to define data type byte_pointer as a
pointer to an object of type unsigned char

Such a byte pointer references a sequenbce of bytes 
where each byte is ocnsidered to be a nonnegative int.
*/

#include <stdio.h>

typedef unsigned char *byte_pointer;

/*
is given the address of a sequence of bytes, indicated
by a byte pointer and a byte count. The byte count is
specified as having data type size_t, the preferred 
data type for expressing the sizes of data structures.
It prints the individual bytes in hexadecimal. The C
formatting directive %.2x indicates that an int should
be printed in hex w/ 2 digits
*/
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for(i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
        
    printf("\n");
}

/*
Procedures show_int, show_float, and show_pointer 
demonstrate how to use procedure show_bytes to print
byte representations of each respective type

Observe that they simply pass show_bytes a pointer &x
to their argument x, casting the pointer to be of type
unsigned char *. This pointer will then be to the 
lowest byte address occupied by the object

These procedures use sizeof operator to determine the
number of bytes used by the object

In general the expression sizeof(T) returns the number
of bytes equired to store an object of type T. Using
this allows for better portability across different
machines
*/
void show_int (int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}


/*
12345 = 0x00003039 in hex. For int data, we get 
identical results for all machines except for byte
ordering. The least significant byte value of 0x39 is
printed first for Linux 32, Windows,and Linux 64, which
indicates that they are little-endian machines. Sun
has it showing up last, hence making Sun a big-endian
machine.

Similarly, the bytes of the float data are identical
except for byte ordering

Pointer values however are completely different,
different machines/OS configs use different
conventions for storage allocation
*/
int main()
{
    test_show_bytes(12345);
    return 0;
}