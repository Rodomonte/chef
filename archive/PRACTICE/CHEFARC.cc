// CHEFARC

#include <stdio.h>
#include <map>

using std::pair;
using std::multimap;

#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int a){ return (a < 0) ? -a : a; }
int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

struct P { int i,j; P(int _i, int _j): i(_i), j(_j) {} };

char a[100][100];
int N,M, d[100][100], e[100][100];

void eval(int b[][100], int k, P p){
  int i,j, t;
  multimap<int,P> m;
  multimap<int,P>::iterator it;
  pair<multimap<int,P>::iterator, multimap<int,P>::iterator> ir;

  b[p.i][p.j] = 0, m.insert(pair<int,P>(0, p));
  while(!m.empty()){
    p = m.begin()->second, m.erase(m.begin());
    for(i = max(0, p.i-k); i <= min(N-1, p.i+k); ++i){
      for(j = max(0, p.j-k); j <= min(M-1, p.j+k); ++j){
        t = abs(i - p.i) + abs(j - p.j);
        if(t <= k && !a[i][j] && b[p.i][p.j]+1 < b[i][j]){
          ir = m.equal_range(b[i][j]), b[i][j] = b[p.i][p.j]+1;
          //printf("b[%d][%d] = %d\n", i,j,b[i][j]);
          for(it = ir.first; it != ir.second; ++it)
            if(it->second.i == p.i && it->second.j == p.j){
              m.erase(it); break; }
          m.insert(pair<int,P>(b[i][j], P(i, j)));
        }
      }
    }
  }
}

int main(){
  int T,D,E, i,j, r;

  T = getn();
  while(T--){
    N = getn(), M = getn(), D = getn(), E = getn();
    for(i = 0; i < N; ++i) for(j = 0; j < M; ++j)
      a[i][j] = getn(), d[i][j] = e[i][j] = INF;

    eval(d, D, P(0, 0)), eval(e, E, P(0, M-1));
    for(i = 0, r = INF; i < N; ++i) for(j = 0; j < M; ++j)
      if(d[i][j] < INF && e[i][j] < INF) r = min(r, max(d[i][j], e[i][j]));

    printf("%d\n", (r == INF) ? -1 : r);
  }
  return 0;
}
