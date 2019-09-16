// GARDENSQ

#include <stdio.h>

#define gc getchar_unlocked
int main(){
  int T, N, M, i,j, s, e;
  char a[50][51],c;
  scanf("%d\n",&T);
  while(T--){
    scanf("%d %d\n",&N,&M);
    for(i = 0; i < N; i++)
      gets(a[i]);
    if(N == 1 || M == 1){
      printf("0\n");
      continue;
    }
    e = 0;
    for(s = 1; s < (N<M?N:M); s++){
      for(i = 0; i < N-s; i++){
        for(j = 0; j < M-s; j++){
          c = a[i][j];
          if(a[i+s][j] == c && a[i+s][j+s] == c && a[i][j+s] == c)
            e++;
        }
      }
    }
    printf("%d\n",e);
  }
  return 0;
}
