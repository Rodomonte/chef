// EGRCAKE

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int gcd(int a, int b){
  return b ? gcd(b,a%b) : a;
}

int main(){
  int T,N,M, g;
  T = getn();
  while(T--){
    N = getn(), M = getn();
    if(!M)
      M = N;
    g = gcd(N, M);
    if(g == 1)
      printf("Yes\n");
    else
      printf("No %d\n", N/g);
  }
  return 0;
}
