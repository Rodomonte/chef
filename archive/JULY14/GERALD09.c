// GERALD09

#include <stdio.h>
#include <stdlib.h>

int main(){
  char a[15][15],c;
  int T,N,M,K, i,j,s,n,m;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d",&N,&M,&K);
    for(i = 0; i < N; i++)
      for(j = 0; j < M; j++)
        a[i][j] = 'A';
    s = N*M, m = 0;
    while(s < K && m < N*M*3/4){
      n = rand()%3;
      if(n == 0) c = 'C';
      else if(n == 1) c = 'G';
      else c = 'T';
      i = j = 0;
      while(a[i][j] != 'A')
        i = rand()%N, j = rand()%M;
      a[i][j] = c;
      s += N*M;
      m++;
    }
    for(i = 0; i < N; i++){
      for(j = 0; j < M; j++)
        printf("%c",a[i][j]);
      printf("\n");
    }
  }
  return 0;
}
