// UNICOURS

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,A, i,m;

  T = getn();
  while(T--){
    N = getn(), m = 0;
    for(i = 0; i < N; ++i){
      A = getn();
      if(A > m)
        m = A;
    }
    printf("%d\n", N-m);
  }
  return 0;
}
