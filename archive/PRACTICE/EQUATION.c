// EQUATION

#include <stdio.h>

/* INCOMPLETE */
#define getchar_unlocked getchar

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
long long f(int n){
  if(n < 0) return 0;
  return ((long long)(n+1)*(n+2)*(n+3)) / 6;
}
int main(){
  int T = getn(), N, A,B,C;
  long long r;
  while(T--){
    N = getn(), A = getn(), B = getn(), C = getn();
    r = f(N) - f(N-A-1) - f(N-B-1) - f(N-C-1) + f(N-A-B-2)
      + f(N-B-C-2) + f(N-A-C-2) - f(N-A-B-C-3);
    printf("%lld\n",r);
  }
  return 0;
}
