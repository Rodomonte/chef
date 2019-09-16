// CHEARMY

#include <stdio.h>
#include <string.h>

#define ll long long

ll pow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1) r *= n;
    n *= n, e >>= 1;
  }
  return r;
}

int main(){
  int T, i;
  ll K, n,r;

  scanf("%d", &T);
  while(T--){
    scanf("%lld", &K);

    --K, r = 0;
    while(K){
      i = 0, n = 5;
      while(n <= K) ++i, n *= 5;
      n /= 5;
      while(n <= K) K -= n, r += (pow(10, i)<<1);
    }

    printf("%lld\n", r);
  }
  return 0;
}
