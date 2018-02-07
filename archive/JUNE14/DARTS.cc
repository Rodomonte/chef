// DARTS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using std::vector;

#define pb push_back
#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

double abs(double d){
  return (d < 0.0) ? 0.0-d : d;
}
struct P {
  double x,y;
  P(): x(0.0), y(0.0) {}
  P(double x0, double y0): x(x0), y(y0) {}
  void set(double x1, double y1){ x = x1; y = y1; }
  P& operator+=(const P &o){ x += o.x; y += o.y; return *this; }
  P& operator/=(const double d){ x /= d; y /= d; return *this; }
  double rad(){ return /*sqrt(*/abs(x)*abs(x)+abs(y)*abs(y)/*)*/; }
};

int main(){
  int N,M,S, i,j,k,h,s,t;
  double C,D, x,y;
  P a[26][4]; // [Score][-/x1/x2/x3]: Avg pos
  vector<P> b[26][4];

  // PRACTICE
  setlinebuf(stdout);
  N = 100000;
  printf("%d\n",N);
  for(i = 0, x = -1.0; i < 316; i++, x += 0.00635){
    for(j = 0, y = -1.0; j < 316; j++, y += 0.00635){
      P p(x,y);
      if(p.rad() > 1.1)
        continue;
      printf("%lf %lf\n",x,y);
      N--;
      scanf("%lf %lf",&C,&D);
      M = getn(), S = getn();
      P q(C,D);
      if(!S)// || (S==1 && q.rad() < 0.6))
        continue;
      b[S][M].pb(q);
    }
  }
  x = y = 0.0;
  while(N--){
    printf("%lf %lf\n",x,y);
    scanf("%lf %lf",&C,&D);
    M = getn(), S = getn();
  }

  // LEARN
  for(i = 1; i <= 25; i++){
    for(j = 2; j <= 3; j++){
      a[i][j].set(0.0,0.0);
      if(!b[i][j].size())
        continue;
      for(k = 0; k < b[i][j].size(); k++)
        a[i][j] += b[i][j][k];
      a[i][j] /= b[i][j].size();
    }
    a[i][1].set(0.0,0.0);
    if(!b[i][1].size())
      continue;
    for(k = s = 0; k < b[i][1].size(); k++)
      if(b[i][1][k].rad() > a[i][3].rad())
        a[i][1] += b[i][1][k], s++;
    a[i][1] /= s;
  }

  // PLAY
  N = 99996, h = 3, s = 501, t = 0;
  while(N || h){
    if(s-t >= 62)
      x = a[20][3].x, y = a[20][3].y;
    else if(s-t >= 51 && s-t <= 61)
      x = a[s-t-50][1].x, y = a[s-t-50][1].y;
    else if(s-t >= 41 && s-t <= 49)
      x = a[s-t-40][1].x, y = a[s-t-40][1].y;
    else if((s-t >= 2 && s-t <= 40 && !((s-t)&1)) || s-t == 50)
      x = a[(s-t)>>1][2].x, y = a[(s-t)>>1][2].y;
    else if(s-t >= 3 && s-t <= 39 && (s-t)&1)
      x = a[1][1].x, y = a[1][1].y;
    else // INVALID: SIGNAL FPE
      s /= 0;
    printf("%lf %lf\n",x,y);
    h--;
    scanf("%lf %lf",&C,&D);
    M = getn(), S = getn();
    t += S * M;
    if(s-t == 1 || s-t < 0 || (s-t == 0 && M != 2)){
      t = 0;
      if(N < 3)
        h = N, N = 0;
      else
        h = 3, N -= 3;
    }else if(s-t == 0){
      s = 501, t = 0;
      if(N < 3-h)
        h += N, N = 0;
      else
        N -= 3-h, h = 3;
    }else if(!h){
      s -= t, t = 0;
      if(N < 3)
        h = N, N = 0;
      else
        h = 3, N -= 3;
    }
  }

  return 0;
}
