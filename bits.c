/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(x & y) & ~(~x & ~y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    int sx=(x>>31);
    int sy=(y>>31);
    if(!(x^y)){
        return 1;
    }
    if(!(sx^sy)&&x&&y){
        return 1;
    }
    return 0;
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int ans=0;
    int shift;
    shift = (v > 0xFFFF) << 4;
    ans= ans|shift;
    v = v >> shift;
    shift =(v > 0xFF) << 3;
    ans=ans|shift;
    v = v >> shift;
    shift = (v > 0xF) << 2;
    ans=ans|shift;
    v = v >> shift;
    shift= ( v > 0x3 ) << 1;
    ans=ans|shift;
    v = v >> shift;
    ans=ans|(v> 0x1);
    return ans;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int n1 = n << 3;
    int m1 = m << 3;
    int nbyte = (x >> n1) & 0xFF;
    int mbyte = (x >> m1) & 0xFF;
    int mask = (0xFF << n1) | (0xFF << m1);
    x = x & ~mask;
    return x | (nbyte << m1) | (mbyte << n1);
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    v=(v>>16)|(v<<16);
    v=((v&0xFF00FF00)>>8)|((v&0x00FF00FF)<<8);
    v=((v&0xF0F0F0F0)>>4)|((v&0x0F0F0F0F)<<4);
    v=((v&0xCCCCCCCC)>>2)|((v&0x33333333)<<2);
    v=((v&0xAAAAAAAA)>>1)|((v&0x55555555)<<1);
    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int newx = x >> n;
    int mask = ~(((1<<31)>>n)<<1) ;
    return newx & mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int ans = 0;
    int allOne;
    int old = x;

    allOne = !~(x >> 16);
    ans = ans + (allOne << 4);
    x = x << (allOne << 4);

    allOne = !~(x >> 24);
    ans = ans + (allOne << 3);
    x = x << (allOne << 3);

    allOne = !~(x >> 28);
    ans = ans + (allOne << 2);
    x = x << (allOne << 2);

    allOne = !~(x >> 30);
    ans = ans + (allOne << 1);
    x = x << (allOne << 1);

    ans = ans + ((x >> 31) & 1);
    ans = ans + !~old;
    return ans;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned sign;
    unsigned abs;
    unsigned exp;
    unsigned frac;
    unsigned round;
    unsigned half;
    int shift;

    if (x == 0) {
        return 0;
    }

    sign = x & 0x80000000;
    abs = x;

    if (sign) {
        abs = -abs;
    }

    shift = 0;
    while ((abs >> shift) > 1) {
        shift = shift + 1;
    }

    exp = shift + 127;

    if (shift < 24) {
        frac = (abs << (23 - shift)) & 0x7FFFFF;
    } else {
        shift = shift - 23;
        frac = abs >> shift;
        round = abs & ((1 << shift) - 1);
        half = 1 << (shift - 1);

        if (round > half) {
            frac = frac + 1;
        } else {
            if (round == half) {
                if (frac & 1) {
                    frac = frac + 1;
                }
            }
        }

        if (frac >> 24) {
            exp = exp + 1;
            frac = frac >> 1;
        }

        frac = frac & 0x7FFFFF;
    }

    return sign | (exp << 23) | frac;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sign = uf & 0x80000000;
    unsigned exp = uf & 0x7F800000;
    unsigned frac = uf & 0x007FFFFF;

    if (exp == 0x7F800000) {
        return uf;
    }
    if(exp ==0){
        frac = frac << 1;
        return sign | exp | frac;
    }
    exp = exp + 0x00800000;
    return sign | exp | frac;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign = uf2 >> 31;
    unsigned exp = (uf2 >> 20) & 0x7FF;
    unsigned val = 0x80000000 | ((uf2 & 0xFFFFF) << 11) | (uf1 >> 21);

    if (exp < 1023) {
        return 0;
    }

    if (exp > 1054) {
        return 0x80000000;
    }

    val = val >> (1054 - exp);

    if (sign) {
        if (val > 0x80000000) {
            return 0x80000000;
        }
        return -val;
    } else {
        if (val > 0x7FFFFFFF) {
            return 0x80000000;
        }
        return val;
    }
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    int exp;

    if (x < -149) {
        return 0;
    }

    if (x < -126) {
        return 1 << (x + 149);
    }

    if (x > 127) {
        return 0xFF << 23;
    }

    exp = x + 127;
    return exp << 23;
}