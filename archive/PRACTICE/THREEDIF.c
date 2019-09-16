// THREEDIF

#include <stdio.h>

#define MOD 1000000007
int main(){
  int T;
  long long i,j,k,t;
  scanf("%d\n",&T);
  while(T--){
    scanf("%lld %lld %lld",&i,&j,&k);
    if(j < i) t=i, i=j, j=t;
    if(k < j) t=j, j=k, k=t;
    if(j < i) t=i, i=j, j=t;
    printf("%lld\n",((((i%MOD)*((j-1)%MOD))%MOD)*((k-2)%MOD))%MOD);
  }
  return 0;
}
