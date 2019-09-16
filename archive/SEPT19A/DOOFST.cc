// DOOFST

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

#define str std::string
#define vec std::vector
#define umap std::unordered_map
#define pb push_back
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct E {
  bool g;
  int i,j;
};

bool b[100001];
int gi[100001];
E e[200000];
umap<int, int> a[100001];
int main(){
  bool z;
  int N,M, i,j,k, n;
  vec<str> r;
  vec<vec<int> > g;
  umap<int, int>::iterator it,jt;

  N = getn(), M = getn();
  if(N == 1 || !M){ printf("0\n"); return 0; }
  for(i = 0; i < M; ++i)
    e[i].i = getn(), e[i].j = getn(), e[i].g = false,
    a[e[i].i][e[i].j] = a[e[i].j][e[i].i] = i;

  for(i = 0; i < M; ++i){
    if(e[i].g) continue;
    for(j = 1; j <= N; ++j){
      if(j == e[i].i || j == e[i].j) continue;
      it = a[e[i].i].find(j), jt = a[e[i].j].find(j);
      if(it == a[e[i].i].end() && jt == a[e[i].j].end()){
        printf("-1\n"); return 0; }
      if(it != a[e[i].i].end()) e[it->second].g = true;
      else if(jt != a[e[i].j].end()) e[jt->second].g = true;
    }
  }

  for(i = 1; i <= N; ++i)
    gi[i] = -1;
  for(i = 1; i <= N; ++i){
    if(gi[i] != -1) continue;
    g.pb(vec<int>());
    for(j = 1; j <= N; ++j)
      b[j] = true;
    for(it = a[i].begin(); it != a[i].end(); ++it)
      b[it->first] = false;
    for(j = 1; j <= N; ++j)
      if(b[j]) g.back().pb(j), gi[j] = g.size()-1;
  }

  n = 1;
  while((n << 1) < g.size())
    n <<= 1;
  while(n){
    r.pb(""), z = true;
    for(i = 1; i <= N; ++i)
      b[i] = true;
    for(i = 0; i < g.size(); i += n, z = !z)
      for(j = i; j < g.size() && j < i+n; ++j)
        for(k = 0; k < g[j].size(); ++k)
          if(z) b[g[j][k]] = false;
    for(i = 1; i <= N; ++i)
      r.back() += b[i] ? "1" : "0";
    n >>= 1;
  }

  if(r.size() * N > 1000000){ printf("-1\n"); return 0; }
  printf("%d\n", r.size());
  for(i = 0; i < r.size(); ++i)
    printf("%s\n", r[i].c_str());
  return 0;
}
