// ALICGARD

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back
#define MN 196

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int abs(int a){
  return (a < 0) ? -a : a;
}

struct P {
  int x,y;
  P(int x0, int y0): x(x0), y(y0) {}
};

int a[MN][MN], l[MN][MN], r[MN][MN], p[MN][MN], f[MN][MN]={{0}};
int main(){
  int N,F,PEN,X,Y,A,B,C,D, i,j,k,x,y,t,m,xt,yt;
  vector<P> b;

  N = getn(), F = getn(), X = getn()-1, Y = getn()-1, PEN = getn();
  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      a[i][j] = getn(), p[i][j] = -1000;
  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      l[i][j] = getn();
  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      r[i][j] = getn();
  for(k = 0; k < F; ++k){
    A = getn()-1, B = getn()-1, C = getn()-1, D = getn()-1;
    for(i = A, t = 0; i <= C; ++i)
      for(j = B; j <= D; ++j)
        t += a[i][j];
    for(i = A; i <= C; ++i)
      f[i][B] = f[i][D] = t;
    for(j = B; j <= D; ++j)
      f[A][j] = f[C][j] = t;
  }


  x = X, y = Y, t = 0;
  while(1){
    b.clear();
    if(x > 0 && y > 0) b.pb(P(x-1, y-1));
    if(y > 0) b.pb(P(x, y-1));
    if(x < N-1 && y > 0) b.pb(P(x+1, y-1));
    if(x < N-1) b.pb(P(x+1, y));
    if(x < N-1 && y < N-1) b.pb(P(x+1, y+1));
    if(y < N-1) b.pb(P(x, y+1));
    if(x > 0 && y < N-1) b.pb(P(x-1, y+1));
    if(x > 0) b.pb(P(x-1, y));

    m = 0;
    for(i = 0; i < b.size(); ++i){
      xt = b[i].x, yt = b[i].y;
      if(l[xt][yt] > m && !f[xt][yt] && t-p[xt][yt] > r[xt][yt])
        m = l[xt][yt], j = i;
    }
    if(!m) break;
    x = b[j].x, y = b[j].y;

    printf("MOVE %d %d\n", x+1, y+1);
    p[x][y] = t, --l[x][y], ++t;
  }

  printf("EXIT\n");
  return 0;
}
