// BROKPHON

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
  int T,N,A,B, i,t,r;
  T = getn();
  while(T--){
    N = getn(), B = getn(), r = t = 0;
    for(i = 1; i < N; ++i){
      A = getn();
      if(A != B){
        ++r;
        if(!t)
          ++r;
        t = 1;
      }else
        t = 0;
      B = A;
    }
    printf("%d\n", r);
  }
  return 0;
}
