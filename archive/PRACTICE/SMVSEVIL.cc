// SMVSEVIL

#include <stdio.h>
#include <utility>
#include <vector>
#include <set>

using std::pair;
using std::make_pair;
using std::vector;
using std::set;

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

struct C {
  int i,j;
  C(){}
  C(int i0, int j0): i(i0), j(j0) {}
  bool operator==(const C& o) const { return i == o.i && j == o.j; }
  bool operator!=(const C& o) const { return i != o.i || j != o.j; }
  bool operator<(const C& o) const { return i < o.i || (i == o.i && j < o.j); }
};
struct P {
  char c;
  int d;
  C p;
  vector<C> n;
};

int K, M[25], N[25];
char s[50];
P a[25][50][50];
C b[25], c[25], e[25];
vector<char> r;

void ds(int k, C s){
  int i,j, c,t,w;
  C u,v;
  set<pair<int, C> > q;
  for(i = 0; i < M[k]; ++i)
    for(j = 0; j < N[k]; ++j)
      a[k][i][j].d = INF;
  a[k][s.i][s.j].d = 0, q.insert(make_pair(a[k][s.i][s.j].d, s));
  while(!q.empty()){
    c = q.begin()->first, u = q.begin()->second, q.erase(q.begin());
    for(i = 0; i < a[k][u.i][u.j].n.size(); ++i){
      v = a[k][u.i][u.j].n[i], w = 1, t = c+w;
      if(t < a[k][v.i][v.j].d){
        if(a[k][v.i][v.j].d != INF)
          q.erase(q.find(make_pair(a[k][v.i][v.j].d, v)));
        a[k][v.i][v.j].d = t, a[k][v.i][v.j].p = u;
        q.insert(make_pair(a[k][v.i][v.j].d, v));
      }
    }
  }
}

int move(char ch){
  int i,j,k,n;
  n = 0;
  for(k = 0; k < K; ++k){
    if(ch == 'N') i = c[k].i-1, j = c[k].j;
    else if(ch == 'E') i = c[k].i, j = c[k].j+1;
    else if(ch == 'S') i = c[k].i+1, j = c[k].j;
    else if(ch == 'W') i = c[k].i, j = c[k].j-1;
    if(i < 0 || i >= M[k] || j < 0 || j >= N[k] || c[k] == e[k] ||
       a[k][i][j].c == '#') continue;
    c[k].i = i, c[k].j = j;
    if(c[k] == e[k]) ++n;
  }
  r.pb(ch);
  return n;
}

int main(){
  int T, i,j,k, m,n;
  C t;
  vector<C> p;

  T = getn();
  while(T--){
    K = getn();
    for(k = 0; k < K; ++k){
      M[k] = getn(), N[k] = getn();
      for(i = 0; i < M[k]; ++i){
        scanf("%s", s);
        for(j = 0; j < N[k]; ++j){
          a[k][i][j].c = s[j], a[k][i][j].n.clear();
          if(s[j] == 'S') b[k].i = i, b[k].j = j, c[k] = b[k];
          if(s[j] == 'E') e[k].i = i, e[k].j = j;
        }
      }
    }

    for(k = 0; k < K; ++k){
      for(i = 0; i < M[k]; ++i){
        for(j = 0; j < N[k]; ++j){
          if(a[k][i][j].c == '#') continue;
          if(i > 0 && a[k][i-1][j].c != '#')
            a[k][i][j].n.pb(C(i-1, j)), a[k][i-1][j].n.pb(C(i, j));
          if(j > 0 && a[k][i][j-1].c != '#')
            a[k][i][j].n.pb(C(i, j-1)), a[k][i][j-1].n.pb(C(i, j));
        }
      }
    }

    n = 0, r.clear();
    while(n < K){
      m = INF;
      for(k = 0; k < K; ++k){
        if(c[k] == e[k]) continue;
        ds(k, c[k]);
        if(a[k][e[k].i][e[k].j].d < m)
          m = a[k][e[k].i][e[k].j].d, i = k;
      }

      p.clear(), t = e[i], p.pb(t);
      while(t != c[i])
        t = a[i][t.i][t.j].p, p.pb(t);
      for(j = p.size()-2; j >= 0; --j){
        if(p[j].i < p[j+1].i) n += move('N');
        else if(p[j].j > p[j+1].j) n += move('E');
        else if(p[j].i > p[j+1].i) n += move('S');
        else if(p[j].j < p[j+1].j) n += move('W');
      }
    }

    for(i = 0; i < r.size(); ++i)
      printf("%c", r[i]);
    printf("\n");
  }
  return 0;
}
