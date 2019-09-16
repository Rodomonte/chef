// AMBIDEX

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

int a[1000][2], g[1000];
bool v[101];
int main(){
  int T,N,M, i,gi, n;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < M; ++i) a[i][0] = getn(), g[i] = 0;
    for(i = 0; i < M; ++i) a[i][1] = getn();

    gi = 0;
    while(1){
      n = 0, ++gi;
      for(i = 1; i <= N; ++i) v[i] = false;
      for(i = 0; i < M; ++i)
        if(!g[i] && !v[a[i][0]] && !v[a[i][1]])
          g[i] = gi, n += 2, v[a[i][0]] = v[a[i][1]] = true;
      for(i = 0; i < M; ++i){
        if(g[i]) continue;
        if(!v[a[i][0]])
          g[i] = gi, ++n, v[a[i][0]] = true;
        if(!v[a[i][1]])
          g[i] = gi, ++n, v[a[i][1]] = true;
      }
      if(n < N) break;
    }
    if(n) for(i = 0; i < M; ++i) if(g[i] == gi) g[i] = 0;

    for(i = 0; i < M; ++i)
      printf("%d ", g[i]);
    printf("\n");
  }
  return 0;
}
