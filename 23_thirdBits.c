#include <stdio.h>

/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */

 // 492492..
 // 0100 1001 0010...
int thirdBits(void)
{

    /* 1. Start with a 9-bit pattern: 001 001 001 (which is 0x49) */
    int x = 0x49; 
    
    /* 2. Shift it left by 9 and OR it with itself to get 18 bits of the pattern */
    /* Pattern becomes: 001001001 001001001 (0x9249) */
    x = x | (x << 9); 
    
    /* 3. Shift that 18-bit chunk left by 18 and OR it with the original */
    /* This covers all 32 bits (and actually goes up to 36) */
    /* Pattern: ...01001001001001001001001001001 */
    return x | (x << 18);
    
}

int test_thirdBits(void)
{
    int result = 0;
    int i;
    for (i = 0; i < 32; i += 3)
        result |= 1 << i;
    return result;
}

int main(void)
{
    printf("expected: %x\n", thirdBits());
    printf("actual  : %x\n", test_thirdBits());
}
