// CHRECT

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T = getn(),N,M,K, r;
  while(T--){
    N = getn(), M = getn(), K = getn();
    if((N == 1 && M == 1) || (N == 1 && M == 2) || (N == 2 && M == 1))
      r = 0;
    else if(N == 1 || M == 1)
      r = K;
    else if(K % 2 == 0)
      r = K / 2;
    else
      r = K / 2 + 1;
    printf("%d\n",r);
  }
  return 0;
}
