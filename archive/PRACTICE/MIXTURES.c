// MIXTURES

#include <stdio.h>

#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[100][100], b[100][100];
int main(){
  int N, i,j,k, m,t;

  while(scanf("%d", &N) != EOF){
    for(i = 0; i < N; ++i) a[i][i] = getn();

    for(k = 2; k <= N; ++k){
      for(i = 0; i <= N-k; ++i){
        for(j = i, m = INF; j < i+k-1; ++j){
          t = b[i][j] + b[j+1][i+k-1] + a[i][j]*a[j+1][i+k-1];
          if(t < m)
            a[i][i+k-1] = (a[i][j] + a[j+1][i+k-1]) % 100, b[i][i+k-1] = m = t;
        }
      }
    }

    printf("%d\n", b[0][N-1]);
  }
  return 0;
}
