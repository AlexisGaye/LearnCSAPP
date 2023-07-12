int isAsciiDigit(int x) {
  int a;
  int b;
  int c = (~x) +1;
  a = 0x39 + c;
  b= x+(~0x30 +1);
  a = (a >> 7)  ;     //这里为什么对两个同时进行格式化后报错 虽然这里并不需要格式化                   
  b = (b >> 7)  ;     //但是多次验证得到：只对一个数进行格式化就不会报错 why
  a = a | b;
  return !a;
}

int floatFloat2Int(unsigned uf) {   // int 转化为 float
  
     
  if (uf == 0x80000000)
     return 0xcf000000;
     
  if (uf == 0x0)
    return 0x3f800000;
     
  unsigned s = uf & (0x1 <<31);
  if (s)
     uf = -uf ;      //负数转化为正数
      
  int i = 0;
  int tmp = 1;
  while (uf >> i)
  {
    i++;
    tmp =(tmp << 1) | 1;
  }
  tmp = tmp >> 1;
  int exp = 127 + i - 1;        //exp = E + bias
  int frac = frac << (24 - i);
  return ( s<<31) + (exp <<23) +frac;
}

int main ()
{
  int x = floatFloat2Int (0x0);
  printf("%d", x);
  return 0;
}
