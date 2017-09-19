// RAINBOWB

#include <stdio.h>

#define ll long long
#define MOD 1000000007

int main(){
  int N, i,j,k,a[5],r;
  ll n;
  scanf("%d", &N);
  if(N < 13){
    printf("0\n");
    return 0;
  }
  N = (N - 13) >> 1, r = 0;
  for(i = 5; i <= N+5; i++){
    for(j = 0; j < 5; j++)
      a[j] = i-j;
    for(j = 5; j >= 2; j--)
      for(k = 0; k < 5; k++)
        if(a[k] % j == 0){
          a[k] /= j;
          break;
        }
    n = 1;
    for(j = 0; j < 5; j++)
      n = (n * a[j]) % MOD;
    r = (r + n) % MOD;
  }
  printf("%d\n", r);
  return 0;
}
