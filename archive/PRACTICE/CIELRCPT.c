// CIELRCPT

#include <stdio.h>
#include <math.h>

int main(){
  int T, P;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&P);
    int m=0, i=11, e;
    while(P){
      e = pow(2,i--);
      m += P / e;
      P %= e;
    }
    printf("%d\n",m);
  }
  return 0;
}
