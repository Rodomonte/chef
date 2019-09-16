// POINTCN

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using std::sort;
using std::vector;
using std::set;

#define ull unsigned long long
#define gc getchar_unlocked
#define pb push_back
#define INF 2000000000
#define EM 4

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }

ull s[2];
ull xorshift128plus() {
  ull x,y;
  x = s[0], y = s[1], x ^= x << 23;
  s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
  return s[0] = y;
}

struct P {
  int g,h;
  set<int> n;
};
struct G {
  int o;
  vector<int> g;
};

char r[1000][1000];
int c[1000][1000], h[1000][1000];
P a[1000];
int main(){
  bool f;
  int T,N,C,H, i,j,k, m,t,u,v, gn;
  vector<G> g;
  set<int>::iterator it;

  T = getn();
  while(T--){
    N = getn(), C = getn(), H = getn();
    for(i = 0; i < N; ++i){
      c[i][i] = 0;
      scanf("%llu %llu", &s[0], &s[1]);
      for(j = i+1; j < N; ++j)
        c[i][j] = c[j][i] = xorshift128plus() % (C+1);
    }
    for(i = 0; i < N; ++i){
      scanf("%llu %llu", &s[0], &s[1]);
      for(j = 0; j < N; ++j)
        h[i][j] = xorshift128plus() % (H+1);
    }

    // for(i = 0; i < N; ++i){
    //   for(j = 0; j < N; ++j) printf("= ", h[i][j]);
    //   printf("\n");
    // }

    for(i = 0; i < N; ++i)
      for(j = 1, m = INF; j <= EM; ++j)
        if(h[i][j] * j < m) m = h[i][j] * j, a[i].h = j;

    g.clear(), gn = N;
    for(i = 0; i < N; ++i){
      a[i].n.clear(), a[i].g = i;
      G gi; gi.o = a[i].h, gi.g.pb(i), g.pb(gi);
    }

    for(i = 0; i < N; ++i){
      while(a[i].h){
        for(j = 0, m = INF, f = false; j < N; ++j){
          if(i == j || !a[j].h || a[i].n.find(j) != a[i].n.end() ||
             (gn > 2 && g[a[i].g].o == 1 && g[a[j].g].o == 1)) continue;
          if(a[i].g != a[j].g) f = true;
          if((a[i].g != a[j].g || !f) && c[i][j] < m) m = c[i][j], k = j;
        }
        if(m == INF) break;

        a[i].n.insert(k), a[k].n.insert(i), --a[i].h, --a[k].h;
        //printf("Connected %d to %d cost %d\n", i, k, c[i][k]);
        if(a[i].g != a[k].g){
          t = (g[a[i].g].g.size() < g[a[k].g].g.size()) ? a[i].g : a[k].g;
          u = (g[a[i].g].g.size() < g[a[k].g].g.size()) ? a[k].g : a[i].g;
          for(j = 0; j < g[t].g.size(); ++j)
            g[u].g.pb(g[t].g[j]), a[g[t].g[j]].g = u;
          g[u].o += g[t].o - 2, g[t].g.clear(), g[t].o = 0, --gn;
        }
      }
    }

    while(gn > 1){
      for(i = 0, m = INF; i < N; ++i){
        for(j = 0; j < N; ++j){
          if(a[i].g == a[j].g) continue;
          t = c[i][j] + (h[i][a[i].n.size()+1] - h[i][a[i].n.size()]) +
                        (h[j][a[j].n.size()+1] - h[j][a[j].n.size()]);
          if(t < m) m = t, u = i, v = j;
        }
      }

      a[u].n.insert(v), a[v].n.insert(u);
      i = (g[a[u].g].g.size() < g[a[v].g].g.size()) ? a[u].g : a[v].g;
      j = (g[a[u].g].g.size() < g[a[v].g].g.size()) ? a[v].g : a[u].g;
      for(k = 0; k < g[i].g.size(); ++k)
        g[j].g.pb(g[i].g[k]), a[g[i].g[k]].g = j;
      g[j].o += g[i].o - 2, g[i].g.clear(), g[i].o = 0, --gn;
    }

    for(i = 0; i < N; ++i) for(j = 0; j < N; ++j) r[i][j] = 0;
    for(i = 0; i < N; ++i) for(it = a[i].n.begin(); it != a[i].n.end(); ++it)
      r[i][*it] = r[*it][i] = 1;
    for(i = 0; i < N; ++i){
      for(j = 0; j < N; ++j) printf("%d", r[i][j]);
      printf("\n");
    }
  }
  return 0;
}
