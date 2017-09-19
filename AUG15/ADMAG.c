// GRGUY

#include <stdio.h>

#define ll long long

int main(){
  int T, r;
  long long N, n,p,t;
  scanf("%d", &T);
  while(T--){
    scanf("%lld", &N);
    if(N <= 3){
      printf("%lld\n", N);
      continue;
    }
    n = 3, p = 2, r = 3;
    while(n < N)
      t = n, n += p, p = t, ++r;
    if(n > N)
      --r;
    printf("%d\n", r);
  }
  return 0;
}
