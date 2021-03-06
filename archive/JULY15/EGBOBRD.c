// EGBOBRD

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,A, i;
  ll K, n,r,m;
  T = getn();
  while(T--){
    scanf("%d %lld", &N, &K);
    n = 0, r = 0;
    for(i = 0; i < N; ++i){
      A = getn();
      if(n)
        --n;
      if(!n)
  n = K, ++r;
      if(A <= n){
        n -= A;
  continue;
      }
      A -= n, ++r;
      m = A % K;
      if(m)
        r += A / K, n = K - m;
      else
  r += A / K - 1, n = 0;
    }
    printf("%lld\n", r);
  }
  return 0;
}
