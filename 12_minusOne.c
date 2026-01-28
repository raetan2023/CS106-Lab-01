#include <stdio.h>

/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
    // alt answer: ~1+1
    return ~(0 << 31);
}

int test_minusOne(void)
{
    return -1;
}

int main(void)
{
    printf("expected: %x\n", minusOne());
    printf("actual  : %x\n", test_minusOne());
}
