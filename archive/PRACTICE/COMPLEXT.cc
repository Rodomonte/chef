// COMPLEXT

#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>

using std::vector;
using std::multiset;

#define gc getchar_unlocked
#define pb push_back
#define INF 2000000000

int MODE;

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P;

struct E {
  int x,y;
  P *a,*b;
  E(){}
  E(int x0, int y0, P* a0, P* b0): x(x0), y(y0), a(a0), b(b0) {}
  bool operator<(const E& o) const {
    if(MODE == 1) return x < o.x;
    if(MODE == 2) return x > o.x;
    if(MODE == 3) return y < o.y;
    if(MODE == 4) return y > o.y;
  }
};

struct P {
  int i,j,g;
  E e[4];
};

int N;
P a[20][20];
vector<E> r,rt;

double span(int M){
  int i,j,k;
  double dx,dy;
  P *t,*u,*v;
  vector<vector<P*> > g;
  multiset<E> e;
  multiset<E>::iterator it;

  MODE = M, rt.clear(), dx = dy = 0;
  for(i = 0; i < N; ++i) for(j = 0; j < N; ++j)
    a[i][j].g = -1, a[i][j].i = i, a[i][j].j = j;
  for(i = 0; i < N; ++i) for(j = 0; j < N; ++j) for(k = 0; k < 4; ++k)
    if(a[i][j].e[k].x != INF) e.insert(a[i][j].e[k]);

  for(it = e.begin(); it != e.end(); ++it){
    u = it->a, v = it->b;
    if(u->g == -1 && v->g == -1){
      vector<P*> n;
      n.pb(u), n.pb(v), u->g = v->g = g.size(), g.pb(n);
    }else if(u->g == -1) g[v->g].pb(u), u->g = v->g;
    else if(v->g == -1) g[u->g].pb(v), v->g = u->g;
    else if(u->g != v->g){
      if(g[u->g].size() < g[v->g].size()) t = u, u = v, v = t;
      for(i = 0, k = v->g; i < g[k].size(); ++i)
        g[u->g].pb(g[k][i]), g[k][i]->g = u->g;
      g[k].clear();
    }else continue;
    rt.pb(*it), dx += it->x, dy += it->y;
  }
  return sqrt(dx*dx + dy*dy);
}

int main(){
  int A,B, i,j,k;
  double m,t;

  N = getn();
  for(i = 0; i < N; ++i) for(j = 0; j < N; ++j) for(k = 0; k < 4; ++k)
    a[i][j].e[k].x = INF;
  for(i = 0; i < N; ++i) for(j = 0; j < N-1; ++j)
    A = getn(), B = getn(),
    a[i][j].e[1] = a[i][j+1].e[3] = E(A, B, &a[i][j], &a[i][j+1]);
  for(j = 0; j < N; ++j) for(i = 0; i < N-1; ++i)
    A = getn(), B = getn(),
    a[i][j].e[2] = a[i+1][j].e[0] = E(A, B, &a[i][j], &a[i+1][j]);

  for(i = 1, m = 0; i <= 4; ++i)
    if((t = span(i)) > m) m = t, r = rt;

  for(i = 0; i < r.size(); ++i)
    printf("%d %d %d %d\n", r[i].a->i+1, r[i].a->j+1, r[i].b->i+1, r[i].b->j+1);
  return 0;
}
