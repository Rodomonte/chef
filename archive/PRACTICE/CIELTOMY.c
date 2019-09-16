// CIELTOMY

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T = getn(),N,M, i,j,k, a[11][11],b[11][11];
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N; i++)
      for(j = 0; j < N; j++){
        if(i == j)
          a[i][j] = 0, b[i][j] = 1;
        else
          a[i][j] = 1000, b[i][j] = 0;
      }
    for(k = 0; k < M; k++){
      i = getn()-1, j = getn()-1;
      a[i][j] = a[j][i] = getn();
      b[i][j] = b[j][i] = 1;
    }
    for(k = 0; k < N; k++){
      for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
          if(i == k || j == k)
            continue;
          if(a[i][k] + a[k][j] < a[i][j]){
            a[i][j] = a[i][k] + a[k][j];
            b[i][j] = b[i][k] * b[k][j];
          }else if(a[i][k] + a[k][j] == a[i][j])
            b[i][j] += b[i][k] * b[k][j];
        }
      }
    }
    printf("%d\n",b[0][N-1]);
  }
  return 0;
}
