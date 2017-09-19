// TIMEASR

#include <stdio.h>

double dabs(double d){
  if(d < 0.0)
    return 0.0 - d;
  return d;
}

int main(){
  int T, h,m;
  double A, ha,ma, r[12][60];

  for(h = 0; h < 12; ++h){
    for(m = 0; m < 60; ++m){
      ha = (double)h * (360.0/12.0) + (double)m * (360.0/12.0/60.0);
      ma = (double)m * (360.0/60.0);
      r[h][m] = dabs(ha - ma);
      if(r[h][m] > 180.0)
  r[h][m] = 360.0 - r[h][m];
    }
  }

  scanf("%d", &T);
  while(T--){
    scanf("%lf", &A);
    for(h = 0; h < 12; ++h)
      for(m = 0; m < 60; ++m)
        if(dabs(r[h][m] - A) < 1.0/120.0)
    printf("%.2d:%.2d\n", h, m);
  }
  return 0;
}
