// LAND

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 0;
  while((c < '0' || c > '9') && c != '-') c = gc();
  if(c == '-') f = 1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return f ? -n : n;
}

int a[100][100];
bool b[100][100];
int main(){
  int T,N,M, i,j,k,kn,n,d;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N; ++i)
      for(j = 0; j < M; ++j)
        a[i][j] = getn(), b[i][j] = a[i][j] ? true : false;

    kn = 1000000 / (N*M);
    for(k = 0; k < kn; ++k){
      for(i = 0; i < N; ++i){
        for(j = 0; j < M; ++j){
          if(b[i][j])
            continue;
          n = d = 0;
          if(i > 0 && a[i-1][j]) n += a[i-1][j], ++d;
          if(i < N-1 && a[i+1][j]) n += a[i+1][j], ++d;
          if(j > 0 && a[i][j-1]) n += a[i][j-1], ++d;
          if(j < M-1 && a[i][j+1]) n += a[i][j+1], ++d;
          if(d)
            a[i][j] = n / d;
        }
      }
    }

    for(i = 0; i < N; ++i){
      for(j = 0; j < M; ++j)
        printf("%d ", a[i][j]);
      printf("\n");
    }
  }
  return 0;
}
