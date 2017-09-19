// WDTBAM

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
  char a[1000];
  int T,N,W, i, w,m;
  T = getn();
  while(T--){
    N = getn(), w = m = 0;
    for(i = 0; i < N; ++i)
      a[i] = gc();
    gc();
    for(i = 0; i < N; ++i)
      if(gc() != a[i])
  ++w;
    for(i = 0; i < N-w+1; ++i){
      W = getn();
      if(W > m)
  m = W;
    }
    for(i = 0; i < w; ++i)
      getn();
    printf("%d\n", w ? m : W);
  }
  return 0;
}
