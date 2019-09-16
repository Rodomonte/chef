// RRMATRIX

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < 48) c = gc();
  while(c > 47)
    n = (n<<3) + (n<<1) + c - 48, c = gc();
  return n;
}

int gcd(int a, int b){
  int n;
  while(b)
    n = b, b = a % n, a = n;
  return a;
}
int main(){
  int T = getn();
  while(T--)
    printf("%d\n",gcd(getn()-1,getn()-1)+1);
  return 0;
}
