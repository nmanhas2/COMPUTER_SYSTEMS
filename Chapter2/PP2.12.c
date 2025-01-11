#include <stdio.h>

/*
    Write C expressions, in terms of variable x. The code
    should work for any word size >= 8. Show the result of
    evaluating the expressions for x = 0x87654321
*/
const __uint64_t x = 0x87654321;

int main()
{
    printf("A. 0x%x\n", x&0xFF); //A. The least significant byte of x
    printf("B. 0x%x\n", x^~0xFF); //B. All but the LSBY of x complemented, w/ LSBY unchanged
    printf("C. 0x%x\n", x|0xFF); //C. LSBY set to all ones, all other bytes of x left unchanged
}