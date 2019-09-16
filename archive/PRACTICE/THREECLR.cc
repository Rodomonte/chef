// THREECLR

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int b[501];
vector<int> a[501];

void dfs(int i){
  int j,n,f;
  for(n = 1; 1; ++n){
    for(j = f = 0; j < a[i].size(); ++j)
      if(b[a[i][j]] == n){ f = 1; break; }
    if(!f) break;
  }
  b[i] = n;
  for(j = 0; j < a[i].size(); ++j)
    if(!b[a[i][j]]) dfs(a[i][j]);
}

int main(){
  int T,N,M,X,Y, i;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 1; i <= N; ++i)
      a[i].clear(), b[i] = 0;
    for(i = 0; i < M; ++i)
      X = getn(), Y = getn(), a[X].pb(Y), a[Y].pb(X);

    for(i = 1; i <= N; ++i)
      if(!b[i]) dfs(i);

    for(i = 1; i <= N; ++i)
      printf("%d ", b[i]);
    printf("\n");
  }
  return 0;
}
