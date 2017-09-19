// EFFDELIV

#include <stdio.h>
#include <set>
#include <utility>
#include <vector>

using std::set;
using std::pair;
using std::make_pair;
using std::vector;

#define gc getchar_unlocked
#define pb push_back
#define MAX 1000000000

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct R {
  int d,l;
  R(int d0, int l0): d(d0), l(l0) {}
};
struct O {
  int i,d,w,p;
  O(int i0, int d0, int w0, int p0): i(i0), d(d0), w(w0), p(p0) {}
};
struct P {
  vector<R> r;
  vector<O> o;
};
struct C {
  int a,o,d;
  vector<int> p;
};

P a[100001];
int N, md[100001], pv[100001], it;

void dijk(int s, int t){
  int i,d,u,v,w;
  for(i = 1; i <= N; ++i)
    md[i] = MAX;
  md[s] = 0;
  set<pair<int, int> > q;
  q.insert(make_pair(0, s));
  while(!q.empty()){
    d = q.begin()->first, u = q.begin()->second;
    if(t == u)
      break;
    q.erase(q.begin());
    for(i = 0; i < a[u].r.size(); ++i){
      v = a[u].r[i].d, w = a[u].r[i].l + d;
      if(w < md[v]){
        q.erase(make_pair(md[v], v));
  md[v] = w, pv[v] = u;
  q.insert(make_pair(md[v], v));
      }
    }
    it += a[u].r.size();
  }
}

int r[300000][2];
int main(){
  int M,K,S,D,W,X,Y,Z, i,j,k,l,t,rn;
  double d,m;
  set<pair<int, int> > b;
  vector<C> c;

  N = getn(), M = getn();
  for(i = 0; i < M; ++i){
    X = getn(), Y = getn(), Z = getn();
    a[X].r.pb(R(Y, Z));
    a[Y].r.pb(R(X, Z));
  }
  K = getn();
  for(i = 1; i <= K; ++i){
    X = getn(), Y = getn(), W = getn(), Z = getn();
    a[X].o.pb(O(i, Y, W, Z));
  }
  S = getn(), D = getn(), W = getn();

  X = 6;
  rn = it = 0;
  while(1){
    dijk(S, -1);

    // Add highest profit candidate
    c.clear();
    t = 0, k = -1;
    for(i = 1; i <= N; ++i)
      for(j = 0; j < a[i].o.size(); ++j)
        if(a[i].o[j].p > t)
    t = a[i].o[j].p, k = i, l = j;
    if(k != -1){
      C cm;
      cm.a = k, cm.o = l, cm.d = md[k];
      while(k != S){
  cm.p.pb(k);
  k = pv[k];
      }
      for(i = 0; i < (cm.p.size()>>1); ++i){
  t = cm.p[i];
  cm.p[i] = cm.p[cm.p.size()-i-1];
  cm.p[cm.p.size()-i-1] = t;
      }
      c.pb(cm);
    }

    // Find X closest nodes with orders
    b.clear();
    for(i = 1; i <= N; ++i){
      if(a[i].o.empty() || md[i] > D)
  continue;
      if(b.size() < X || md[i] < MAX-b.begin()->first){
  if(b.size() >= X)
          b.erase(b.begin());
  b.insert(make_pair(MAX-md[i], i));
      }
    }
    while(!b.empty() && c.size() < X){
      i = b.begin()->second;
      for(j = 0; j < a[i].o.size() && c.size() < X; ++j){
  if(!c.empty() && i == c[0].a && j == c[0].o)
    continue;
        C cn;
        cn.a = i, cn.o = j, cn.d = md[i];
        k = i;
  while(k != S){
    cn.p.pb(k);
    k = pv[k];
  }
  for(k = 0; k < (cn.p.size()>>1); ++k){
    t = cn.p[k];
    cn.p[k] = cn.p[cn.p.size()-k-1];
    cn.p[cn.p.size()-k-1] = t;
  }
  c.pb(cn);
      }
      b.erase(b.begin());
    }

    // Find distance of each order and best p/d
    m = 0.0, k = -1;
    for(i = 0; i < c.size(); ++i){
      j = a[c[i].a].o[c[i].o].d;
      dijk(c[i].a, j);
      c[i].d += md[j];
      if(c[i].d > D)
  continue;
      vector<int> p2;
      while(j != c[i].a){
        p2.pb(j);
  j = pv[j];
      }
      for(j = p2.size()-1; j >= 0; --j)
        c[i].p.pb(p2[j]);
      d = (double)a[c[i].a].o[c[i].o].p / (double)c[i].d;
      if(d > m)
  m = d, k = i;
    }
    if(k == -1)
      break;

    // Travel best candidate
    t = a[c[k].a].o[c[k].o].i;
    if(c[k].a == S)
      r[rn][0] = 1, r[rn++][1] = t;
    for(i = 0; i < c[k].p.size(); ++i){
      S = c[k].p[i];
      r[rn][0] = 0, r[rn++][1] = S;
      if(c[k].p[i] == c[k].a)
        r[rn][0] = 1, r[rn++][1] = t;
    }
    r[rn][0] = 2, r[rn++][1] = t;
    a[c[k].a].o.erase(a[c[k].a].o.begin()+c[k].o);
    D -= c[k].d;

    if(it > 20000000)
      break;
  }

  printf("%d\n", rn);
  for(i = 0; i < rn; ++i)
    printf("%d %d\n", r[i][0], r[i][1]);
  return 0;
}
