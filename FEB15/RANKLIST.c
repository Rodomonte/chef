// RANKLIST

#include <stdio.h>

#define ll long long

int main(){
  int T,N, i,r;
  ll S,d;
  scanf("%d", &T);
  while(T--){
    scanf("%d %lld", &N, &S);
    d = (((ll)N*(N+1))>>1) - S, r = 0;
    for(i = N; i >= 1; --i){
      if(d <= 0)
        break;
      d -= i-1;
      ++r;
    }
    printf("%d\n", r);
  }
  return 0;
}
