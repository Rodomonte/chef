// CHEFTEAM

#include <stdio.h>

#define ull unsigned long long
ull gcd(ull a, ull b){
  ull t = 0;
  while(b > 0){
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int main(){
  int T;
  scanf("%d",&T);
  ull N, K, i, g, r;
  while(T--){
    scanf("%llu %llu",&N,&K);
    if(K > N){
      printf("0\n");
      continue;
    }else if(K > N - K)
      K = N - K;
    r = 1;
    for(i = 1; i <= K; i++){
      g = gcd(r, i);
      r /= g;
      r *= (N - i + 1) / (i / g);
    }
    printf("%llu\n",r);
  }
  return 0;
}
