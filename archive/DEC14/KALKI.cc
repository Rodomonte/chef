// KALKI

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using std::vector;

#define gc getchar_unlocked
#define pb push_back

inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int n){
  return (n < 0) ? 0-n : n;
}

int min(int a, int b){
  return (a < b) ? a : b;
}

struct P {
  int x,y;
  vector<int> n;
};

P a[401];

double dist(int i, int j){
  int dx = abs(a[i].x - a[j].x), dy = abs(a[i].y - a[j].y);
  return sqrt(dx*dx + dy*dy);
}

int main(){
  int T,N, i,j,k,l,mi,mj,mk,ml;
  double m,d, b[401][401];
  vector<int> v;
  vector<vector<int> > g;
  T = getn();
  while(T--){
    N = getn();
    g.clear();
    for(i = 1; i <= N; ++i){
      a[i].x = getn(), a[i].y = getn(), a[i].n.clear();
      v.clear(), v.pb(i);
      g.pb(v);
    }
    for(i = 1; i < N; ++i)
      for(j = i+1; j <= N; ++j)
        b[i][j] = b[j][i] = dist(i, j);
    while(g.size() > 1){
      m = 1000;
      for(i = 0; i < g.size(); ++i)
        if(g[i].size() < m)
          m = g[i].size(), mi = i;
      m = 10000.0;
      //for(i = 0; i < g.size()-1; ++i){
      i = mi;
      for(j = 0; j < g.size(); ++j){
        if(j == i)
          continue;
        for(k = 0; k < g[i].size(); ++k){
          for(l = 0; l < g[j].size(); ++l){
            d = b[g[i][k]][g[j][l]];
            if(d < m)
              m = d, mi = i, mj = j, mk = k, ml = l;
          }
        }
      }
      //}
      if(m == 10000.0)
        continue;
      a[g[mi][mk]].n.pb(g[mj][ml]);
      a[g[mj][ml]].n.pb(g[mi][mk]);
      //printf("P%d:(%d,%d) <-> P%d:(%d,%d)\n", g[mi][mk], a[g[mi][mk]].x,
      //       a[g[mi][mk]].y, g[mj][ml], a[g[mj][ml]].x, a[g[mj][ml]].y);
      for(i = 0; i < g[mj].size(); ++i)
        g[mi].pb(g[mj][i]);
      g.erase(g.begin() + mj);
    }
    for(i = 1; i <= N; ++i)
      for(j = 0; j < a[i].n.size(); ++j)
        if(i < a[i].n[j])
          printf("%d %d\n", i, a[i].n[j]);
  }
  return 0;
}
