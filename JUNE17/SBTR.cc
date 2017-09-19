// SBTR

#include <stdio.h>
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
  int c,g;
  vector<int> n;
};

P a[10001];

bool cmp(int i, int j){
  return a[i].c > a[j].c;
}

int main(){
  int N,M,U,V, i,j,k,m,n,s, mi;
  vector<int> b,h;
  vector<vector<int> > g;

  N = getn(), M = getn(), s = 0;
  for(i = 1; i <= N; ++i)
    s += (a[i].c = getn()), a[i].g = -1, b.pb(i);
  for(i = 0; i < M; ++i)
    U = getn(), V = getn(), a[U].n.pb(V), a[V].n.pb(U);

  sort(b.begin(), b.end(), cmp);
  for(i = 0; i < N; ++i){
    if(!i && N > 1 && a[b[i]].n.size() == N-1 && a[b[i+1]].n.size() == 3 &&
       a[b[i]].c < s/2) continue;
    h.clear(), h.resize(g.size());
    for(j = 0; j < a[b[i]].n.size(); ++j)
      if(a[a[b[i]].n[j]].g != -1)
        ++h[a[a[b[i]].n[j]].g];
    for(m = j = 0; j < h.size(); ++j)
      if(h[j] > m) m = h[j];
    if(m > 1) continue;
    if(!m){
      vector<int> gn;
      gn.pb(b[i]), a[b[i]].g = g.size(), g.pb(gn);
      continue;
    }

    for(m = j = 0; j < h.size(); ++j)
      if(h[j] == 1 && g[j].size() > m)
        m = g[j].size(), mi = j;
    g[mi].pb(b[i]), a[b[i]].g = mi;
    for(j = 0; j < h.size(); ++j){
      if(!h[j] || j == mi) continue;
      for(k = 0; k < g[j].size(); ++k)
        g[mi].pb(g[j][k]), a[g[j][k]].g = mi;
      g[j].clear();
    }
  }

  for(m = i = 0; i < g.size(); ++i){
    for(n = j = 0; j < g[i].size(); ++j)
      n += a[g[i][j]].c;
    if(n > m) m = n, mi = i;
  }

  h.clear(), h.resize(N+1);
  for(j = 0; j < g[mi].size(); ++j)
    h[g[mi][j]] = 1;
  printf("%d\n", N-g[mi].size());
  for(j = 1; j <= N; ++j)
    if(!h[j]) printf("%d ", j);
  printf("\n");
  return 0;
}
