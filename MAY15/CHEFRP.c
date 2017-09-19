// CHEFRP

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[100000];
int main(){
  int T,N, i,f,m,r;
  T = getn();
  while(T--){
    N = getn(), r = f = 0, m = 10000;
    for(i = 0; i < N; ++i){
      a[i] = getn();
      if(a[i] < 2)
        f = 1;
      if(a[i] < m)
        m = a[i];
      r += a[i];
    }
    r = f ? -1 : r-m+2;
    printf("%d\n", r);
  }
  return 0;
}
