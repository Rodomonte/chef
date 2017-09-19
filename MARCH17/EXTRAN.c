// EXTRAN

#include <stdio.h>

#define gc getchar_unlocked
#define MX 100000

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[MX<<1];
int main(){
  int T,N,X, i,j,e,x;
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < (N<<1); ++i)
      a[i] = 0;
    e = 0, a[N] = getn();
    for(i = 1; i < N; ++i){
      X = getn(), j = X - a[N] + N;
      if(j < 1 || j >= (N<<1) || a[j])
        ++e, x = X;
      else
        a[j] = X;
    }
    if(!e)
      for(i = 1; i < (N<<1)-1; ++i)
        if(!a[i-1] && !a[i+1]){
          e = 1, x = a[i];
          break;
        }
    printf("%d\n", (e > 1) ? a[N] : x);
  }
  return 0;
}
