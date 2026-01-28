#include <stdio.h>

/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n)
{
    /*
    (1 << 31) n = 1: 1000 0000...
    (1 << 31) >> 1 n = 2: 1100 0000...
    (1 << 31) >> 2 n = 3: 1110 0000...

    (1 << 31) >> (n + -1 which is n + ~0) n = 32: 1111 1111.....

    ((1 << 31) >> (n + ~0) works for all n except 0 hence now we need an if else

    */

    
    // 1. Create a mask: if n is 0, mask is 0. If n > 0, mask is all 1s.
    // !!n gives 0 or 1. Negating it gives 0x0 or 0xFFFFFFFF.
    int mask = -!!n;

    // 2. Calculate the shifted value. 
    // We use (n + ~0) to get shifts of 0, 1, 2...31.
    // This is safe to calculate, but we only "keep" it if n != 0.
    int shifted = (1 << 31) >> (n + ~0);

    // 3. Apply the mask
    // If mask is 0, result is 0. If mask is 1s, result is shifted.
    return mask & shifted;



    // int mask = 0 << 31;
    // return (0 << 31 & mask) | ((1 << 31) >> (n + ~0) & ~mask);
    
}

int test_upperBits(int x)
{
    int result = 0;
    int i;
    for (i = 0; i < x; i++)
        result |= (1 << (31 - i));
    return result;
}

int main(void)
{
    int x = 0;
    printf("expected: %x\n", upperBits(x));
    printf("actual  : %x\n", test_upperBits(x));
}
