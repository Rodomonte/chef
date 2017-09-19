// SPCANDY

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long
inline ll getn(){
  char c = gc();
  ll n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  ll T,N,K;
  T = getn();
  while(T--){
    N = getn(), K = getn();
    printf("%lld %lld\n",K?N/K:0,K?N%K:N);
  }
  return 0;
}
