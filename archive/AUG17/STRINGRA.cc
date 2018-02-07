// STRINGRA

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

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

int min(int a, int b){ return (a < b) ? a : b; }

int f[100001], r[100001];
vector<int> a[100001];
int main(){
  bool b;
  int T,N,M,X,Y, i,j, t;
  vector<int> z;

  T = getn();
  while(T--){
    N = getn(), M = getn(), z.clear();
    for(i = 1; i <= N; ++i) f[i] = INF, r[i] = -1, a[i].clear();
    for(i = 0; i < M; ++i){
      X = getn(), Y = getn();
      if(X > Y) t = X, X = Y, Y = t;
      if(!X) z.pb(Y);
      f[Y] = min(f[Y], X), a[Y].pb(X);
    }

    for(i = 1; i <= N; ++i){
      sort(a[i].begin(), a[i].end()), b = true;
      for(j = 1; j < a[i].size(); ++j)
        if(a[i][j] - a[i][j-1] != 1){ b = false; break; }
      if(a[i].back() != i-1) b = false;
      if(!b) break;
    }
    if(!b){ printf("-1\n"); continue; }

    sort(z.begin(), z.end());
    for(i = 0; i < z.size(); ++i) r[z[i]] = i+1;
    for(i = 1, b = true; i <= N; ++i){
      if(r[i] != -1) continue;
      if(f[i] == INF){ b = false; break; }
      r[i] = r[f[i]];
      for(j = f[i]+1; j < i; ++j)
        if(r[j] == r[i]){ b = false; break; }
    }
    if(!b){ printf("-1\n"); continue; }

    for(i = 1; i <= N; ++i) printf("%d ", r[i]);
    printf("\n");
  }
  return 0;
}
