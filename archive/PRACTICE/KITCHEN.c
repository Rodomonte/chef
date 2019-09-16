// KITCHEN

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char a[100][100];
  int T,N,M, i,j;

  T = getn();
  while(T--){
    N = getn(), M = getn();

    for(i = 0; i < N; i += 3)
      for(j = 0; j < M; ++j)
        a[i][j] = '#';
    for(i = 1; i < N; i += 3)
      for(j = 0; j < M; ++j)
        a[i][j] = (j&1) ? '.' : '#';
    for(i = 2; i < N; i += 3){
      if(i == N-1){
        for(j = 0; j < M; ++j)
          a[i][j] = (j&1) ? '.' : '#';
      }else{
        a[i][0] = '#', a[i][1] = '.';
        for(j = 2; j < M; ++j)
          a[i][j] = (j&1) ? '#' : '.';
      }
    }

    for(i = 0; i < N; ++i){
      for(j = 0; j < M; ++j)
        printf("%c", a[i][j]);
      printf("\n");
    }
  }
  return 0;
}
