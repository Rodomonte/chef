// BFORG

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P {
  int x,y,g,md;
};

P a[201];

double dist(int i, int j){
  return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y));
}
bool cmp(const vector<int>& a, const vector<int>& b){
  return dist(a[0], a[1]) > dist(b[0], b[1]);
}

int main(){
  int T,N,K, i,j,k, ti,ii,mi;
  double m,m2,t;
  vector<vector<int> > g;

  T = getn();
  for(ti = 1; ti <= T; ++ti){
    N = getn(), K = getn(), g.clear();
    for(i = 1; i <= N; ++i)
      a[i].x = getn(), a[i].y = getn(), a[i].g = -1;

    // Initial N/2 groups of 2
    for(i = 1; i <= N; ++i){
      if(a[i].g != -1) continue;
      vector<int> v;
      v.pb(i), a[i].g = g.size(), m = 4000.0;
      for(j = i+1; j <= N; ++j){
        if(a[j].g != -1) continue;
        t = dist(i, j);
        if(t < m) m = t, k = j;
      }
      v.pb(k), a[k].g = g.size(), g.pb(v);
    }

    // Split until K groups
    sort(g.begin(), g.end(), cmp);
    for(i = 0; i < g.size()-K; ++i){
      for(j = 0; j < g[i].size(); ++j){
        m = 4000.0;
        for(k = g.size()-K; k < g.size(); ++k){
          m2 = 0.0;
          for(ii = 0; ii < g[k].size(); ++ii){
            t = dist(g[i][j], g[k][ii]);
            if(t > m2) m2 = t;
          }
          if(m2 < m) m = m2, mi = k;
        }
        a[g[i][j]].g = mi, g[mi].pb(g[i][j]);
      }
      g[i].clear();
    }

    //! Swap between groups

    printf("case %d Y\n", ti);
    for(i = 0; i < g.size(); ++i){
      if(g[i].empty()) continue;
      sort(g[i].begin(), g[i].end());
      printf("%d", g[i].size());
      for(j = 0; j < g[i].size(); ++j)
        printf(" %d", g[i][j]);
      printf("\n");
    }
  }
  return 0;
}
