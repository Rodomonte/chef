// SHOP2

#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using std::sort;
using std::pair;
using std::make_pair;
using std::vector;
using std::set;

#define uset std::unordered_set
#define umap std::unordered_map
#define gc getchar
#define pb push_back
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a < b) ? a : b; }

struct E {
  int n,d;
  E(int _n, int _d): n(_n), d(_d) {}
};
struct P {
  int d,p;
  vector<E> n;
  uset<int> b;
};
struct I {
  bool v;
  int w,s;
  umap<int,int> c;
};
struct S {
  int i,j,k;
  double d;
  S(int _i, int _j, int _k, double _d): i(_i), j(_j), k(_k), d(_d) {}
};

int N, p[1001][1001];
P a[1001];
I c[501];

bool cmp(int i, int j){ return c[i].c.size() < c[j].c.size(); }
bool cmp2(S& s1, S& s2){ return s1.d > s2.d; }

void ds(int s){
  int i, c,t,u,v,w;
  set<pair<int, int> > q;
  for(i = 1; i <= N; ++i) a[i].d = INF, a[i].p = -1;
  a[s].d = 0, q.insert(make_pair(a[s].d, s));
  while(!q.empty()){
    c = q.begin()->first, u = q.begin()->second, q.erase(q.begin());
    for(i = 0; i < a[u].n.size(); ++i){
      v = a[u].n[i].n, w = a[u].n[i].d, t = c+w;
      if(t < a[v].d){
        if(a[v].d != INF)
          q.erase(q.find(make_pair(a[v].d, v)));
        a[v].d = t, a[v].p = u, q.insert(make_pair(a[v].d, v));
      }
    }
  }
}

int main(){
  int M,K,F,P,B,X,Y,Z, i,j,k, f,m,n,z;
  double d,t;
  vector<int> b,r;
  vector<S> e;
  uset<int> s;
  uset<int>::iterator it,jt;
  umap<int,int>::iterator mt;

  N = getn(), M = getn(), K = getn(), F = getn();
  for(i = 1; i <= K; ++i){
    P = getn(), c[i].w = getn(), b.pb(i);
    for(j = 0; j < P; ++j)
      B = getn(), c[i].c[B] = getn();
  }
  for(i = 0; i < M; ++i){
    X = getn(), Y = getn(), Z = getn();
    a[X].n.pb(E(Y, Z)), a[Y].n.pb(E(X, Z));
  }

  for(i = 1; i < N; ++i){
    ds(i);
    for(j = i+1; j <= N; ++j)
      p[i][j] = p[j][i] = a[j].d;
  }
  sort(b.begin(), b.end(), cmp), f = 0;

  for(i = 0; i < K; ++i){
    m = INF;
    for(mt = c[b[i]].c.begin(); mt != c[b[i]].c.end(); ++mt)
      if(p[mt->first][N] < m) m = p[mt->first][N], k = mt->first;
    s.insert(k), a[k].b.insert(b[i]), c[b[i]].s = k, f += c[b[i]].c[k];
  }

  /*
  printf("\ns:");
  for(it = s.begin(); it != s.end(); ++it)
    printf(" %d", *it);
  printf("\n");
  for(i = 1; i <= N; ++i){
    printf("a[%d].b:");
    for(it = a[i].b.begin(); it != a[i].b.end(); ++it)
      printf(" %d", *it);
    printf("\n");
  }
  printf("f=%d F=%d\n", f,F);
  */

  while(f > F){
    e.clear();
    for(i = 1; i <= K; ++i){
      c[i].v = false;
      for(mt = c[i].c.begin(); mt != c[i].c.end(); ++mt){
        j = c[i].s, k = mt->first;
        if(j == k) continue;
        d = 1, t = c[i].c[j] - c[i].c[k];
        if(t < 0) d = 0;
        else d *= t;
        t = p[k][N] - p[j][N];
        if(t < 0) d *= -t;
        else d /= t;
        e.pb(S(i, j, k, d));
      }
    }
    sort(e.begin(), e.end(), cmp2);

    /*
    printf("e:");
    for(i = 0; i < e.size(); ++i)
      printf(" (%d,%d,%d)", e[i].i, e[i].j, e[i].k);
    printf("\n");
    gc();
    */

    for(i = 0; i < e.size(); ++i){
      if(e[i].d == 0) break;
      if(c[e[i].i].v) continue;
      a[e[i].j].b.erase(a[e[i].j].b.find(e[i].i));
      a[e[i].k].b.insert(e[i].i);
      if(a[e[i].j].b.empty()) s.erase(s.find(e[i].j));
      if(a[e[i].k].b.size() == 1) s.insert(e[i].k);
      c[e[i].i].s = e[i].k, c[e[i].i].v = true;
      f -= c[e[i].i].c[e[i].j] - c[e[i].i].c[e[i].k];
    }
  }

  /*
  printf("\ns:");
  for(it = s.begin(); it != s.end(); ++it)
    printf(" %d", *it);
  printf("\n");
  for(i = 1; i <= N; ++i){
    printf("a[%d].b:");
    for(it = a[i].b.begin(); it != a[i].b.end(); ++it)
      printf(" %d", *it);
    printf("\n");
  }
  */

  i = 1, z = s.size();
  for(j = 0; j < z; ++j){
    m = INF;
    for(it = s.begin(); it != s.end(); ++it){
      n = 0;
      for(jt = a[*it].b.begin(); jt != a[*it].b.end(); ++jt)
        n += c[*jt].w;
      if(n /** p[i][*it]*/ < m) m = n /** p[i][*it]*/, k = *it;
    }

    ds(i), b.clear();
    while(k != i) b.pb(k), k = a[k].p;
    for(k = b.size()-1; k >= 0; --k) r.pb(b[k]), i = b[k];
    for(it = a[i].b.begin(); it != a[i].b.end(); ++it)
      r.pb(-*it);
    s.erase(s.find(i));
  }
  ds(i), b.clear(), k = N;
  while(k != i) b.pb(k), k = a[k].p;
  for(k = b.size()-1; k >= 0; --k) r.pb(b[k]);

  printf("%d\n", r.size());
  for(i = 0; i < r.size(); ++i)
    printf("%d ", r[i]);
  printf("\n");
  return 0;
}
