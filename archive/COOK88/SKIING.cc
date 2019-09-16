// SKIING

#include <stdio.h>
#include <algorithm>

using std::sort;

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P {
  int i,j,h;
  bool operator<(P& o){ return h > o.h; }
};

char v[1000][1000];
int N,M, a[1000][1000];
P b[1000000];

int dfs(int i, int j){
  int r = 0;
  if(v[i][j]) return r;
  //printf("  dfs(%d,%d):\n", i,j);
  v[i][j] = 1, ++r;
  if(i > 0 && a[i-1][j] <= a[i][j]) r += dfs(i-1, j);
  if(i < N-1 && a[i+1][j] <= a[i][j]) r += dfs(i+1, j);
  if(j > 0 && a[i][j-1] <= a[i][j]) r += dfs(i, j-1);
  if(j < M-1 && a[i][j+1] <= a[i][j]) r += dfs(i, j+1);
  //printf("  %d,%d = %d\n", i,j, r);
  return r;
}

int main(){
  int T, i,j,k, c,n,t;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = k = 0; i < N; ++i)
      for(j = 0; j < M; ++j, ++k)
        a[i][j] = getn(), b[k].i = i, b[k].j = j, b[k].h = a[i][j], v[i][j] = 0;

    sort(b, b+k);
    // for(i = 0; i < k; ++i) printf("b[%d]: i=%d j=%d h=%d\n", i,b[i].i,b[i].j,
    //                               b[i].h);
    for(i = n = c = 0; i < k; ++i){
      n += (t = dfs(b[i].i, b[i].j));
      if(t > 0) ++c;
      if(n == k) break;
    }
    printf("%d\n", c);
  }
  return 0;
}
