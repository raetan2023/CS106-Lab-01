#include <stdio.h>

/* 
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and & 
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ & |
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y)
{
    /*
    match:
        case 1: match on 1 -> x & y
        case 2: match on 0 -> ~(x | y) OR ~x & ~ y
    */

    // my prev ans: return ~((x | y) & ~(x & y)); after demorgan will be ~(x | y) | (x & y) which matches our cases
    
    return ~(~(~x & ~y) & ~(x & y)); //i try not to use the | operator lmao
}

int test_bitMatch(int x, int y)
{
    int i;
    int result = 0;
    for (i = 0; i < 32; i++) {
        int mask = 1 << i;
        int bit = (x & mask) == (y & mask);
        result |= bit << i;
    }
    return result;
}

int main(void)
{
    int x = 0x7;
    int y = 0xE;
    printf("expected: %x\n", bitMatch(x, y));
    printf("actual  : %x\n", test_bitMatch(x, y));
}
