// CHSQARR

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

int a[1000][1000], b[1000][1000], c[10][10][1000][1000];
int main(){
  int N,M,Q,A,B, i,j,k,l, m,r,s;

  N = getn(), M = getn();
  for(i = 0; i < N; ++i) for(j = 0; j < M; ++j) a[i][j] = getn();

  b[0][0] = a[0][0];
  for(i = 1; i < N; ++i) b[i][0] = b[i-1][0] + a[i][0];
  for(j = 1; j < M; ++j) b[0][j] = b[0][j-1] + a[0][j];
  for(i = 1; i < N; ++i) for(j = 1; j < M; ++j)
    b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];

  for(i = 0; i < N; ++i) for(j = 0; j < M; ++j) c[0][0][i][j] = a[i][j];
  for(k = 1; (1<<k) <= N; ++k)
    for(i = 0; i+(1<<k) <= N; ++i) for(j = 0; j < M; ++j)
      c[k][0][i][j] = max(c[k-1][0][i][j], c[k-1][0][i+(1<<(k-1))][j]);
  for(l = 1; (1<<l) <= M; ++l)
    for(i = 0; i < N; ++i) for(j = 0; j+(1<<l) <= M; ++j)
      c[0][l][i][j] = max(c[0][l-1][i][j], c[0][l-1][i][j+(1<<(l-1))]);
  for(k = 1; (1<<k) <= N; ++k) for(l = 1; (1<<l) <= M; ++l)
    for(i = 0; i+(1<<k) <= N; ++i) for(j = 0; j+(1<<l) <= M; ++j)
      c[k][l][i][j] = max(max(max(
        c[k-1][l-1][i][j], c[k-1][l-1][i+(1<<(k-1))][j+(1<<(l-1))]),
        c[k-1][l-1][i+(1<<(k-1))][j]), c[k-1][l-1][i][j+(1<<(l-1))]);

  Q = getn();
  while(Q--){
    A = getn(), B = getn();

    k = (int)log2(A), l = (int)log2(B), r = INF;
    for(i = 0; i <= N-A; ++i){ for(j = 0; j <= M-B; ++j){
      s = b[i+A-1][j+B-1] - (i ? b[i-1][j+B-1] : 0) - (j ? b[i+A-1][j-1] : 0)
          + ((i&&j) ? b[i-1][j-1] : 0);
      m = max(max(max(c[k][l][i][j], c[k][l][i+A-(1<<k)][j+B-(1<<l)]),
                      c[k][l][i+A-(1<<k)][j]), c[k][l][i][j+B-(1<<l)]);
      r = min(r, m*A*B-s);
    }}

    printf("%d\n", r);
  }
  return 0;
}
