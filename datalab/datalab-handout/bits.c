/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int a = ~(x&~y);
  int b = ~(~x&y);
  return ~(a&b);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int a=1;
  a=a<<31;
  return a;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {//x:0111111      注意：  ~是指按位取反   这里的目的是为了让最后结果得到一个0，再对0取！就可以返回1来达到统一格式的目的
  int a = x+1;  //a:1,000000        
  x =x+a;       //x:1,111111
  x =~x ;       //x:0,000000
  a = !a;        //a:0            why?
  x =x +a;      //x:0,000000        
  return !x;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2   
 */
int allOddBits(int x) {
  int num8 = 0xAA;                 // 这里需要注意的是奇数位是从前往后开始的
  int num16 = (num8<<8) | 0xAA;
  int num24 = (num16<<8) | 0xAA;
  int num32 = (num24<<8) | 0xAA;
  x = (x & num32) ^ ( num32);    
  return !x;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  x = (~x)+1;
  return x;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a;
  int b;
  int c = (~x) +1;
  a = 0x39 + c;
  b= x+(~0x30 +1);
  a = (a >> 31) ;     //这里为什么对两个同时进行格式化后报错 虽然这里并不需要格式化                   
  b = (b >> 31) ;     //但是多次验证得到：只对一个数进行格式化就不会报错 why
  a = a | b;
  return !a;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x = !!x;
  int a = (~x) +1;
  return (a&y)|((~a)&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int flag;
  int tmpx = x >>31&1;          
  int tmpy = y >>31&1;
  flag = tmpx ^tmpy;
  
  int daxiao = y+(~x+1);
  daxiao = daxiao >>31&1;      // 这里要注意格式化tmpx和tmpy，这里进行的是算数右移，如果符号位为1，则tmpx的值为111111（我记得这里的右移是一律被看做算数右移）
  return (flag & tmpx) | (!daxiao&!flag);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {           //利用了只有0的相反数是0
  int a = (~x)+1;
  a = a >>31 & 1;
  x = x >>31 & 1;
  x = x|a;
  x = ~x;
  x = x&1;
  return x;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {     //等等，负数的符号位貌似在最高位上
  int flag = 0;
  flag = x >> 31;
  x = (~flag & x) | (~x & flag);
  
  int b16 = !!(x>>16);   // 判断高十六位是否有1
  b16 = b16 << 4;        // 记录此时能确定有的位数，若高16位有1，则最低为10000 =>16
  x = x >> b16;          // 如果此时有1 则右移16位，方便检查低16位
  int b8 = !!(x>>8);
  b8 = b8 << 3;          //判断高8位
  x = x >> b8;
  int b4 = !!(x>>4);    
  b4 = b4 << 2;          // 判断高四位
  x = x >> b4;
  int b2 = !!(x>>2);
  b2 = b2 << 1;          //判断高二位
  x = x >> b2;
  int b1 = !!(x>>1);     
  b1 = b1 << 1;          //判断最高位           //注释中说明的是32位时判断的情况，只是举例子
  x = x >> b1;
  int b0 = x;
  return b0 + b1 + b2 + b4 + b8 + b16 + 1;     //别忘记加上符号位
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) { 
  unsigned s = uf & (0x1 <<31);           //取出每个部分
  unsigned exp = (uf & (0xff <<23))>>23;
  unsigned frac = uf & 0x7fffff;
  
  if(exp == 0xff)
  {
    return uf;
  }
  if(exp == 0)
  {
    frac = frac << 1;
  }
  else
  {
    exp = exp + 1;
  }
  if(exp == 0xff)
  {
    return s | 0x7f800000;
  }
  return s | (exp<<23) | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {   // float 转化为 int  这波纯笨比 看错题了www
  int s = (uf & (1 << 31)) >> 31 & 1 ;
  unsigned exp = (uf & 0x7f800000) >> 23;
  unsigned frac = uf & 0x7fffff ;
  
  int E = exp - 127;
  if (E<0) 
    return 0;
  else if (E > 32) 
  { 
    return 0x80000000u;
  }
  else
  {
    frac = frac | (1 << 23);
    if (E<23)
      frac = frac >> (23 - E);
    else
      frac = frac << (E - 23);
  }
  
  if (s)
  return -frac; 
  return frac;
 
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that 	is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  if (x > 127)           //返回NAN
  {
    return 0xFF << 23;  
  }
  
  if (x < -148)          //太小返回0
  {
    return 0;
  }
  
  if (x >= -126)        //规格化数
  {
    int exp = x + 127;
    return (exp <<23);
  }
  
  int t = 148 + x;     //非规格化数
  return (1 << t); 
}
