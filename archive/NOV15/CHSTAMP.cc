// CHSTAMP

#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

#define ll long long
#define gc getchar_unlocked
#define pb push_back

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

struct P {
  bool f;
  int m;
  vector<int> n;
};
P g[100001];

int dfs(int p){
  if(g[p].f)
    return g[p].m;
  for(int i = 0; i < g[p].n.size(); ++i)
    g[p].m = max(g[p].m, dfs(g[p].n[i]));
  g[p].f = true;
  return g[p].m;
}

int a[50001], p[50001];
vector<vector<int> > b[50001];
map<int,int> m[50001];
int main(){
  int T,N,M,D,A,B, i,j,k,t,x,y,gn;
  ll r;
  map<int,int>::iterator it,it2;

  T = getn();
  while(T--){
    for(i = 1; i <= 50000; ++i){
      a[i] = 0;
      b[i].clear();
      m[i].clear();
      g[i].m = i, g[i].f = false;
      g[i].n.clear();
      p[i] = i;
    }
    gn = i;

    N = getn(), M = getn();
    for(i = 0; i < N; ++i)
      ++a[getn()];
    for(i = 0; i < M; ++i){
      D = getn(), A = getn(), B = getn();
      if(A == B)
  continue;
      it = m[D].find(A), it2 = m[D].find(B);
      if(it == m[D].end()){
        if(it2 == m[D].end()){
    vector<int> bn;
    bn.pb(A);
    bn.pb(B);
    m[D][A] = m[D][B] = b[D].size();
      b[D].pb(bn);
  }else{
    y = it2->second;
    m[D][A] = y;
    b[D][y].pb(A);
  }
      }else if(it2 == m[D].end()){
  x = it->second;
  m[D][B] = x;
  b[D][x].pb(B);
      }else if(it->second != it2->second){
        x = it->second, y = it2->second;
  if(b[D][x].size() < b[D][y].size())
    t = x, x = y, y = t;
  for(j = 0; j < b[D][y].size(); ++j){
    t = b[D][y][j];
    b[D][x].pb(t);
    m[D][t] = x;
  }
  b[D][y].clear();
      }
    }

    for(i = 1; i <= 50000; ++i){
      for(j = 0; j < b[i].size(); ++j){
        if(b[i][j].empty())
    continue;
  g[gn].f = false;
  g[gn].n.clear();
  g[gn].m = 0;
  for(k = 0; k < b[i][j].size(); ++k){
    t = b[i][j][k];
    g[gn].m = max(g[gn].m, t);
    g[p[t]].n.pb(gn);
    p[t] = gn;
  }
  ++gn;
      }
    }

    r = 0;
    for(i = 1; i <= 50000; ++i){
      if(!a[i])
  continue;
      r += (ll)a[i] * dfs(i);
    }
    printf("%lld\n", r);

    /*
    for(i = 1; i < gn; ++i){
      if(g[i].n.size() == 0 && i <= 50000)
  continue;
      printf("g[%d]: m=%d f=%d n=[", i, g[i].m, g[i].f);
      for(int j = 0; j < g[i].n.size(); ++j)
  printf("%d,", g[i].n[j]);
      printf("]\n");
    }
    */
  }
  return 0;
}
