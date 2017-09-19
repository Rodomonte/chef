// HBIRD

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

#define gc getchar_unlocked
#define vec vector
#define pb push_back
#define MX 1000000000

using std::vec;
using std::multiset;

inline int geti(){
  char c = gc(), f = 1; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f; }

int NM;
vector<int> h;
bool ins(int n){
  if(!n) return false;
  if(NM > 100000 && n > 1000) return true;
  if(NM > 10000 && n > 10000) return true;
  h.pb(n); return false;
}

vec<vec<int> > a,d;
vec<int> b;
vec<vec<vec<int> > > t,u,v,w;
int main(){
  int T,N,M,Q,G, i,j,k,n,s;
  vec<int>::iterator it;
  multiset<int>::iterator its;

  N = geti(), M = geti(), Q = geti(), NM = N*M;
  for(i = 0; i < N; ++i){
    a.pb(vec<int>());
    for(j = 0; j < M; ++j) a[i].pb(geti());
  }

  for(i = 0; i < N; ++i) d.pb(vec<int>());
  for(j = 0; j < M; ++j){
    d[0].pb(a[0][j]);
    for(i = 1; i < N; ++i) d[i].pb(a[i][j] + d[i-1][j]);
  }

  for(i = 0; i < N; ++i){
    t.pb(vec<vec<int> >()), u.pb(vec<vec<int> >());
    v.pb(vec<vec<int> >()), w.pb(vec<vec<int> >());
    for(j = 0; j < M; ++j){
      t[i].pb(vec<int>()), u[i].pb(vec<int>());
      v[i].pb(vec<int>()), w[i].pb(vec<int>());

      s = a[i][j], t[i][j].pb(s);
      for(k = j-1, n = 2; k >= 0 && i-n >= 0; --k, ++n){
        s += d[i][k] - d[i-n][k], t[i][j].pb(s); if(ins(s)) break; }
      if(k >= 0 && i-n == -1){ s += d[i][k], t[i][j].pb(s); ins(s); }

      s = a[i][j], u[i][j].pb(s);
      if(!i) for(k = j-1, n = 1; k >= 0 && i+n < N; --k, ++n){
          s += d[i+n][k], u[i][j].pb(s); if(ins(s)) break; }
      else for(k = j-1, n = 1; k >= 0 && i+n < N; --k, ++n){
          s += d[i+n][k] - d[i-1][k], u[i][j].pb(s); if(ins(s)) break; }

      s = a[i][j], v[i][j].pb(s);
      for(k = j+1, n = 2; k < M && i-n >= 0; ++k, ++n){
        s += d[i][k] - d[i-n][k], v[i][j].pb(s); if(ins(s)) break; }
      if(k < M && i-n == -1){ s += d[i][k], v[i][j].pb(s); ins(s); }

      s = a[i][j], w[i][j].pb(s);
      if(!i) for(k = j+1, n = 1; k < M && i+n < N; ++k, ++n){
          s += d[i+n][k], w[i][j].pb(s); if(ins(s)) break; }
      else for(k = j+1, n = 1; k < M && i+n < N; ++k, ++n){
          s += d[i+n][k] - d[i-1][k], w[i][j].pb(s); if(ins(s)) break; }
    }
  }

  for(i = 0; i < v.size(); ++i){
    for(j = 0; j < v[i].size(); ++j){
      for(k = 1; k < v[i][j].size() && j+(k<<1) < M; ++k)
        if(t[i][j+(k<<1)].size() <= k-1 ||
           ins(v[i][j][k] + t[i][j+(k<<1)][k-1])) break;
      for(k = 1; k < v[i][j].size() && i+k < N; ++k)
        if(w[i+1][j+1].size() <= k-1 ||
           ins(v[i][j][k] + w[i+1][j+1][k-1])) break;
    }
  }

  for(i = 0; i < u.size(); ++i){
    for(j = 0; j < u[i].size(); ++j){
      for(k = 1; k < u[i][j].size() && i-k >= 0; ++k)
        if(t[i-1][j-1].size() <= k-1 ||
           ins(u[i][j][k] + t[i-1][j-1][k-1])) break;
      for(k = 1; k < u[i][j].size() && j-(k<<1) >= 0; ++k)
        if(w[i][j-(k<<1)].size() <= k-1 ||
           ins(u[i][j][k] + w[i][j-(k<<1)][k-1])) break;
    }
  }

  if(h.empty()){ while(Q--) geti(), printf("0\n"); return 0; }
  std::sort(h.begin(), h.end());
  for(i = s = 0; i < h.size() && s <= MX; ++i) s += h[i], b.pb(s);

  while(Q--){
    G = geti();
    it = std::upper_bound(b.begin(), b.end(), G);
    printf("%d\n", (int)(it - b.begin()));
  }
  return 0;
}
