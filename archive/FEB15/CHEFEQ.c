// CHEFEQ

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

int a[100001];
int main(){
  int T,N, i,t,m;
  T = getn();
  while(T--){
    N = getn(), m = 0;
    memset(a, 0, 100001<<2);
    for(i = 0; i < N; ++i){
      t = ++a[getn()];
      m = (t > m) ? t : m;
    }
    printf("%d\n", N-m);
  }
  return 0;
}
