// POINTS

#include <stdio.h>
#include <math.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int N = getn(), P,p, x,y;
  while(N--){
    int a[10001][2];
    for(p = 0; p < 10001; p++){
      a[p][0] = 10001;
      a[p][1] = -1;
    }
    int xmin = 10001, xmax = -1;
    P = getn();
    for(p = 0; p < P; p++){
      x = getn(), y = getn();
      if(x < xmin) xmin = x;
      if(x > xmax) xmax = x;
      if(y < a[x][0]) a[x][0] = y;
      if(y > a[x][1]) a[x][1] = y;
    }
    double d = 0;
    int xp = -1, yp = -1;
    for(x = xmin; x <= xmax; x++){
      if(a[x][1] == -1) continue;
      if(xp != -1) d += sqrt((xp-x)*(xp-x)+(yp-a[x][1])*(yp-a[x][1]));
      d += a[x][1] - a[x][0];
      xp = x;
      yp = a[x][0];
    }
    printf("%.2f\n",d);
  }
  return 0;
}
