// MARRAYS

#include <stdio.h>
#include <vector>

using std::vector;

#define ll long long
#define gc getchar_unlocked
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

int abs(int a){ return (a < 0) ? -a : a; }
int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }
ll maxl(ll a, ll b){ return (a > b) ? a : b; }

typedef struct {
  int v;
  ll b;
} P;

vector<P> a[1000000];
int main(){
  int T,N,M, i,j,k, t,u;
  ll m;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i){
      M = getn(), a[i].clear();
      for(j = 0; j < M; ++j){
        P pn;
        pn.v = getn(), pn.b = 0;
        a[i].pb(pn);
      }
    }

    if(N == 2){
      t = INF, u = 0;
      for(i = 0; i < a[0].size(); ++i){
        if(a[0][i].v < t) t = a[0][i].v;
        if(a[0][i].v > u) u = a[0][i].v;
      }
      for(i = 0; i < a[1].size(); ++i)
        a[1][i].b = max(abs(a[1][i].v - t), abs(a[1][i].v - u));

    }else
      for(i = 1; i < N; ++i)
        for(j = 0; j < a[i].size(); ++j)
          for(k = 0; k < a[i-1].size(); ++k)
            a[i][j].b = maxl(a[i][j].b, a[i-1][k].b + (ll)i *
                abs(a[i][j].v - a[i-1][k?k-1:a[i-1].size()-1].v));

    m = 0;
    for(i = 0; i < a[N-1].size(); ++i)
      if(a[N-1][i].b > m) m = a[N-1][i].b;
    printf("%lld\n", m);
  }
  return 0;
}
