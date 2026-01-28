#include <stdio.h>

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
    // tmin is just complement of tmax
    return ~(1 << 31) ;

    //alt ans
    // ((unsigned int)(~0)) >> 1

    //or treat tmin as unsigned then -1
}

int test_tmax(void)
{
    return 0x7FFFFFFF;
}

int main(void)
{
    printf("expected: %x\n", tmax());
    printf("actual  : %x\n", test_tmax());
}
