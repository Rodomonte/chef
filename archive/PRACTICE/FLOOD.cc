// FLOOD

#include <stdio.h>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

#define gc getchar_unlocked
#define pb push_back
#define INF 2000000000
#define MAXN 1200

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P {
  bool u;
  int x,y,d,g,c;
  vector<int> n,p;
};

P a[40000];
vector<vector<int> > g;

void dfs(int k, int gi){
  int i;
  if(a[k].d != -1 || a[k].g != -1) return;
  g[gi].pb(k), a[k].g = gi;
  for(i = 0; i < a[k].n.size(); ++i)
    dfs(a[k].n[i], gi);
}

int main(){
  int T,M,N, i,j,k,ii,jj,kk,mi, m,n,t,gn;
  queue<int> q;

  T = getn();
  while(T--){
    M = getn(), N = getn(), g.clear();
    for(k = i = 0; i < M; ++i){
      for(j = 0; j < N; ++j, ++k){
        a[k].x = i, a[k].y = j, a[k].d = getn(), a[k].u = false,
        a[k].g = -1, a[k].n.clear();
        if(i > 0 && j > 0)     a[k].n.pb(k-N-1);
        if(i > 0)              a[k].n.pb(k-N);
        if(i > 0 && j < N-1)   a[k].n.pb(k-N+1);
        if(j < N-1)            a[k].n.pb(k+1);
        if(i < M-1 && j < N-1) a[k].n.pb(k+N+1);
        if(i < M-1)            a[k].n.pb(k+N);
        if(i < M-1 && j > 0)   a[k].n.pb(k+N-1);
        if(j > 0)              a[k].n.pb(k-1);
      }
    }

    for(k = 0; k < M*N; ++k){
      if(a[k].d != -1 || a[k].g != -1) continue;
      g.pb(vector<int>());
      dfs(k, g.size()-1);
    }

    gn = g.size();
    for(i = 0; i < g.size(); ++i){
      if(gn == 1) break;
      if(g[i].empty()) continue;
      //! Probably TLE
      for(k = 0; k < M*N; ++k)
        a[k].c = INF, a[k].p.clear();
      while(!q.empty()) q.pop();
      for(j = 0; j < g[i].size(); ++j)
        q.push(g[i][j]), a[g[i][j]].c = 0;
      m = INF, n = 0;

      while(!q.empty() && (n < MAXN || m == INF)){
        k = q.front(), q.pop();
        for(j = 0; j < a[k].n.size(); ++j){
          ii = a[k].n[j];
          if(a[ii].g == i) continue;
          if(a[ii].c == INF && a[ii].g == -1) q.push(ii), ++n;
          t = a[k].c + ((a[ii].d == -1) ? 0 : a[ii].d);
          if(t < a[ii].c){
            a[ii].c = t, a[ii].p = a[k].p, a[ii].p.pb(ii);
            if(a[ii].g != -1 && a[ii].c < m)
              m = a[ii].c, mi = ii;
          }
        }
      }

      for(j = 0; j < a[mi].p.size()-1; ++j){
        k = a[mi].p[j], g[a[mi].g].pb(k), a[k].g = a[mi].g, a[k].u = true;
        for(ii = 0; ii < a[k].n.size(); ++ii){
          jj = a[k].n[ii], t = a[jj].g;
          if(t == -1 || t == a[mi].g) continue;
          for(kk = 0; kk < g[t].size(); ++kk)
            g[a[mi].g].pb(g[t][kk]), a[g[t][kk]].g = a[mi].g;
          g[t].clear(), --gn;
        }
      }
    }

    for(n = j = k = 0; k < M*N; ++k)
      if(a[k].u) n += a[k].d, ++j;
    printf("%d\n%d\n", n, j);
    for(k = 0; k < M*N; ++k)
      if(a[k].u) printf("%d %d\n", a[k].x+1, a[k].y+1);
    printf("\n");
  }
  return 0;
}
