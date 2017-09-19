// CLIQUED

#include <stdio.h>
#include <math.h>
#include <utility>
#include <vector>
#include <set>

using std::pair;
using std::make_pair;
using std::vector;
using std::set;

#define ll long long
#define gc getchar_unlocked
#define pb push_back
#define INF 1000000000000000000LL

inline int getn(){
  int n = 0; char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct E {
  int i;
  double c;
  E(int i0, double c0): i(i0), c(c0) {}
  bool operator<(const E& o) const{
    return (c < o.c || (c == o.c && i < o.i));
  }
};

int N;
vector<E> a[100002];
double d[100002];

void ds(int s){
  int i,u,v;
  double c,w,t;
  set<pair<double, int> > q;
  for(i = 1; i <= N+1; ++i)
    d[i] = INF;
  d[s] = 0;
  q.insert(make_pair(d[s], s));
  while(!q.empty()){
    c = q.begin()->first, u = q.begin()->second;
    q.erase(q.begin());
    for(i = 0; i < a[u].size(); ++i){
      v = a[u][i].i, w = a[u][i].c, t = c+w;
      if(t < d[v]){
        if(d[v] != INF)
          q.erase(q.find(make_pair(d[v], v)));
        d[v] = t;
        q.insert(make_pair(d[v], v));
      }
    }
  }
}

int main(){
  int T,K,X,M,S,A,B,C, i;

  T = getn();
  while(T--){
    N = getn(), K = getn(), X = getn(), M = getn(), S = getn();
    for(i = 1; i <= N+1; ++i)
      a[i].clear();
    for(i = 0; i < M; ++i)
      A = getn(), B = getn(), C = getn(), a[A].pb(E(B, C)), a[B].pb(E(A, C));

    for(i = 1; i <= K; ++i)
      a[i].pb(E(N+1, (double)X/2.0)), a[N+1].pb(E(i, (double)X/2.0));
    ds(S);
    for(i = 1; i <= N; ++i)
      printf("%lld ", (ll)round(d[i]));
    printf("\n");
  }
  return 0;
}
