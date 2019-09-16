// J7

#include <stdio.h>
#include <math.h>

int main(){
  int T, P, S;
  float r, m;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&P,&S);
    r = (P - (float)sqrt((float)(P * P - 24 * S))) / 12;
    m = r * (S / 2 - P * r / 4 + r * r);
    printf("%.2f\n",m);
  }
  return 0;
}
