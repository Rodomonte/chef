// CHEFSTON

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

int A[100000];
int main(){
  int T,N,K,B, i;
  ll m,n;
  T = getn();
  while(T--){
    N = getn(), K = getn(), m = 0;
    for(i = 0; i < N; ++i)
      A[i] = getn();
    for(i = 0; i < N; ++i){
      B = getn(), n = (ll)B * (K / A[i]);
      if(n > m)
        m = n;
    }
    printf("%lld\n", m);
  }
  return 0;
}
