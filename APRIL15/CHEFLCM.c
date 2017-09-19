// CHEFLCM

#include <stdio.h>

int main(){
  int T,N, d;
  long long r;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    r = 0;
    for(d = 1; d*d <= N; ++d){
      if(N % d == 0){
        r += N / d;
        if(d*d != N)
          r += d;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
