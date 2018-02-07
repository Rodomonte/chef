// SUBINC

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
  int T,N,A, i,p,s;
  ll r;
  T = getn();
  while(T--){
    N = getn(), p = s = r = 0;
    for(i = 0; i < N; ++i){
      A = getn();
      if(A < p){
        r += ((ll)s*(s+1))>>1;
  s = 1;
      }else
        ++s;
      p = A;
    }
    r += ((ll)s*(s+1))>>1;
    printf("%lld\n", r);
  }
  return 0;
}
