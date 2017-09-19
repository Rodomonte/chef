// PREDICT

#include <stdio.h>

int main(){
  int T;
  double p;
  scanf("%d",&T);
  while(T--){
    scanf("%lf",&p);
    if(p < 0.5) p = 1.0-p;
    printf("%f\n",(2.0*(1.0-p)*10000+10000.0)*p);
  }
  return 0;
}
