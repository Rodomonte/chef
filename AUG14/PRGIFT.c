// PRGIFT

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,K,A, i,e;
  T = getn();
  while(T--){
    N = getn(), K = getn(), e = 0;
    for(i = 0; i < N; i++){
      A = getn();
      if(!(A&1))
        e++;
    }
    printf(((!K&&N>e)||(K&&e>=K))?"YES\n":"NO\n");
  }
  return 0;
}
