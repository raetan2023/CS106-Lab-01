#include <stdio.h>

/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x)
{
    /*
    all upper 16 bit must be sign ext
    the bit in the 15 pos should be the sign bit

    conclusion:
    when the upper 17 bits are the same, the int can fit in short
    */

    return !((x >> 15) ^ (x >> 16)); //first row ^ second row
    
}

int test_fitsShort(int x)
{
    short int sx = (short int) x;
    return x == sx;
}

int main(void)
{
    int x = 0x00007FFF ;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
}
