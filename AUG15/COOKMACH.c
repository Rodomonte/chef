// COOKMACH

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char p2(int n){
  int p = 1;
  while(p < n)
    p <<= 1;
  return (p == n);
}

int main(){
  int T,A,B, r;
  T = getn();
  while(T--){
    A = getn(), B = getn(), r = 0;
    while(!p2(A) || A > B)
      A >>= 1, ++r;
    while(A < B)
      A <<= 1, ++r;
    printf("%d\n", r);
  }
  return 0;
}
