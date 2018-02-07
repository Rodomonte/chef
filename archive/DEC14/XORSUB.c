// XORSUB

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char a[1024];
  int T,N,K,X, i,j,r;
  T = getn();
  while(T--){
    N = getn(), K = getn();
    memset(a, 0, 1024);
    a[0] = 1, r = 0;
    for(i = 0; i < N; ++i){
      X = getn();
      for(j = 0; j < 1024; ++j){
        if(a[j]){
          a[X ^ j] = 1;
          if((K^(X^j)) > r)
            r = (K^(X^j));
        }
      }
    }
    printf("%d\n", r);
  }
  return 0;
}