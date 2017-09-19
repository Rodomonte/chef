// RECRECOV

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::fill;
using std::min;
using std::vector;

#define gc getchar_unlocked
#define pb push_back
#define INF 2147483647

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct E {
  int t,r,f,c;
  E(int t0, int r0, int f0, int c0):
      t(t0), r(r0), f(f0), c(c0) {}
};

int dist[202], q[202], work[202];
vector<E> g[202];

bool dinic_bfs() {
  fill(dist, dist + 202, -1);
  dist[0] = 0;
  int qt = 0;
  q[qt++] = 0;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < (int) g[u].size(); j++) {
      E &e = g[u][j];
      int v = e.t;
      if (dist[v] < 0 && e.f < e.c) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[201] >= 0;
}

int dinic_dfs(int u, int f) {
  if (u == 201)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    E &e = g[u][i];
    if (e.c <= e.f) continue;
    int v = e.t;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.c - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.r].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow() {
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + 202, 0);
    while (int delta = dinic_dfs(0, INF))
      result += delta;
  }
  return result;
}

int main(){
  int T,N,M,A,B, i;
  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < 202; ++i)
      g[i].clear();
    for(i = 0; i < M; ++i){
      A = getn(), B = getn();
      g[A].pb(E(B+100, g[B+100].size(), 0, 1));
      g[B+100].pb(E(A, g[A].size()-1, 0, 0));
      if(g[B+100].size() == 1){
        g[B+100].pb(E(201, g[201].size(), 0, 1));
        g[201].pb(E(B+100, g[B+100].size()-1, 0, 0));
      }
    }
    for(i = 1; i <= 100; ++i){
      if(!g[i].empty()){
        g[0].pb(E(i, g[i].size(), 0, 1));
        g[i].pb(E(0, g[0].size()-1, 0, 0));
      }
    }

    /*
    for(i = 0; i < 202; ++i){
      if(g[i].empty())
  continue;
      printf("g[%d]:", i);
      for(int j = 0; j < g[i].size(); ++j)
  printf(" %d(%d)", g[i][j].t, g[i][j].c);
      printf("\n");
    }
    */

    printf("%d\n", N-maxFlow());
  }
  return 0;
}
