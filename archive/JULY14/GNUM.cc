// GNUM

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::fill;
using std::min;

#define gc getchar_unlocked
#define pb push_back
#define map unordered_map
#define INF 2147483647
#define MAXN 323403

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

struct E {
  int t,r,f,c;
  E(int t0, int r0, int f0, int c0):
      t(t0), r(r0), f(f0), c(c0) {}
};

int NN, dist[MAXN], q[MAXN], work[MAXN];
vector<E> g[MAXN];

bool dinic_bfs() {
  fill(dist, dist + NN, -1);
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
  return dist[1] >= 0;
}

int dinic_dfs(int u, int f) {
  if (u == 1)
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
    fill(work, work + NN, 0);
    while (int delta = dinic_dfs(0, INF))
      result += delta;
  }
  return result;
}

int sv[31608]={0};
int pr[3401],pr2[3401];

void fac(int n, vector<int>* f){
  int i;
  for(i = 0; i < 3401; i++){
    if(pr2[i] > n)
      break;
    if(n%pr[i])
      continue;
    f->pb(pr[i]);
    while(n%pr[i] == 0)
      n /= pr[i];
  }
  if(n > 1)
    f->pb(n);
}

vector<int> f[400][400];
int main(){
  int T,N, a[400],b[400], i,j,k,m,n,p;
  vector<int> fa[400],fb[400];
  int pa[3401];
  map<int,int> pm;
  map<int,int>::iterator it;
  bool p1a[3401],p2a[3401];
  map<int,bool> p1,p2;

  // Sieve
  for(i = 2, p = 0; i <= 31607; i++){
    if(sv[i] == -1)
      continue;
    sv[i] = p, pr[p] = i, pr2[p] = i*i, p++;
    for(j = i+i; j <= 31607; j += i)
      sv[j] = -1;
  }

  // Factorize input
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; i++){
      a[i] = getn();
      fa[i].clear();
      fac(a[i], fa+i);
    }
    for(i = 0; i < N; i++){
      b[i] = getn();
      fb[i].clear();
      fac(b[i], fb+i);
    }

    // Map useful gcd factors
    fill(p1a, p1a+3401, false);
    fill(p2a, p2a+3401, false);
    p1.clear(), p2.clear();
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        f[i][j].clear();
        if(a[i] == b[j])
          continue;
        std::set_intersection(fa[i].begin(), fa[i].end(), fb[j].begin(),
            fb[j].end(), std::back_inserter(f[i][j]));
        if(!f[i][j].size())
          continue;
        if(a[i] < b[j]){
          for(k = 0; k < f[i][j].size(); k++){
            p = f[i][j][k];
            if(p <= 31607)
              p1a[sv[p]] = true;
            else
              p1[p] = true;
          }
        }else{
          for(k = 0; k < f[i][j].size(); k++){
            p = f[i][j][k];
            if(p <= 31607)
              p2a[sv[p]] = true;
            else
              p2[p] = true;
          }
        }
      }
    }

    // Connect flow nodes
    fill(pa, pa+3401, -1);
    pm.clear();
    NN = 2, g[0].clear(), g[1].clear();
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        if(!f[i][j].size())
          continue;
        if(a[i] < b[j]){
          m = NN++, g[m].clear();
          // Source -> S1
          g[0].pb(E(m, g[m].size(), 0, 1));
          g[m].pb(E(0, g[0].size()-1, 0, 0));
          // S1 -> Factors
          for(k = 0; k < f[i][j].size(); k++){
            p = f[i][j][k];
            if(p <= 31607){
              if(!p1a[sv[p]] || !p2a[sv[p]])
                continue;
              n = pa[sv[p]];
              if(n == -1)
                pa[sv[p]] = n = NN++, g[n].clear();
            }else{
              if(p1.find(p) == p1.end() || p2.find(p) == p2.end())
                continue;
              it = pm.find(p);
              if(it == pm.end())
                pm[p] = n = NN++, g[n].clear();
              else
                n = it->second;
            }
            g[m].pb(E(n, g[n].size(), 0, 1));
            g[n].pb(E(m, g[m].size()-1, 0, 0));
          }

        }else{
          n = NN++, g[n].clear();
          // S2 -> Sink
          g[n].pb(E(1, g[1].size(), 0, 1));
          g[1].pb(E(n, g[n].size()-1, 0, 0));
          // Factors -> S2
          for(k = 0; k < f[i][j].size(); k++){
            p = f[i][j][k];
            if(p <= 31607){
              if(!p1a[sv[p]] || !p2a[sv[p]])
                continue;
              m = pa[sv[p]];
              if(m == -1)
                pa[sv[p]] = m = NN++, g[m].clear();
            }else{
              if(p1.find(p) == p1.end() || p2.find(p) == p2.end())
                continue;
              it = pm.find(p);
              if(it == pm.end())
                pm[p] = m = NN++, g[m].clear();
              else
                m = it->second;
            }
            g[m].pb(E(n, g[n].size(), 0, 1));
            g[n].pb(E(m, g[m].size()-1, 0, 0));
          }
        }
      }
    }

    printf("%d\n",maxFlow());
  }
  return 0;
}
