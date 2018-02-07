// GUESS

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

inline ll getn(){
  ll n = 0;
  char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

int main(){
  ll T,N,M, p;
  T = getn();
  while(T--){
    N = getn(), M = getn();
    if(N == 1 && M == 1){
      printf("0/1\n");
    }else if(N&1 && M&1){
      p = N * M;
      printf("%lld/%lld\n",(p-1)>>1,p);
    }else{
      printf("1/2\n");
    }
  }
  return 0;
}
