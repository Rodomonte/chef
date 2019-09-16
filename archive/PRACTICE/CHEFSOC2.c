// CHEFSOC2

#include <stdio.h>

#define gc getchar_unlocked
#define MOD 1000000007

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int madd(int a, int b){ return (a+b>=MOD) ? a+b-MOD : a+b; }

int a[1001], b[1001][1001];
int main(){
  int T,N,M,S, i,j;

  T = getn();
  while(T--){
    N = getn(), M = getn(), S = getn();
    for(i = 1; i <= M; ++i) a[i] = getn();
    for(i = 1; i <= N; ++i) for(j = 0; j <= M; ++j) b[i][j] = 0;

    b[S][0] = 1;
    for(i = 1; i <= M; ++i){
      for(j = 1; j <= N; ++j){
        if(!b[j][i-1]) continue;
        if(j-a[i] >= 1) b[j-a[i]][i] = madd(b[j-a[i]][i], b[j][i-1]);
        if(j+a[i] <= N) b[j+a[i]][i] = madd(b[j+a[i]][i], b[j][i-1]);
      }
    }

    for(i = 1; i <= N; ++i) printf("%d ", b[i][M]);
    printf("\n");
  }
  return 0;
}
