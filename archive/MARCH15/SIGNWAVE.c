// SIGNWAVE

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
  int T,S,C,K, i,j;
  ll a[101], p;
  T = getn();
  while(T--){
    S = getn(), C = getn(), K = getn();
    for(i = 1; i <= 100; ++i)
      a[i] = 0;
    if(S){
      a[1] = 3, p = 2;
      for(i = 2; i <= S; ++i){
        for(j = 100; j >= 2; --j)
          a[j] = a[j-1];
        a[1] = p;
        p <<= 1;
      }
    }
    if(C){
      p = 2;
      for(i = 1; i <= C; ++i){
        if(S > i){
          a[S-i] -= p;
          a[S-i+1] += p;
        }else{
          a[1] += p;
        }
        p <<= 1;
      }
    }
    p = 0;
    for(i = K; i <= 100; ++i)
      p += a[i];
    printf("%lld\n", p);
  }
  return 0;
}
