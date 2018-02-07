// BANROB

#include <stdio.h>
#include <math.h>

int main(){
  int T,M;
  double P, r;

  scanf("%d", &T);
  while(T--){
    scanf("%d %lf", &M, &P);
    r = P * (pow(-1.0,M)*pow(P,M)-1.0) / (P+1.0);
    r += 1.0 - pow(-1.0,M)*pow(P,M);
    r *= 1000000000.0;
    printf("%.4lf %.4lf\n", r, 1000000000.0-r);
  }
  return 0;
}
