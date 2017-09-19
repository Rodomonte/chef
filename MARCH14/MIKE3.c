// MIKE3

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[20001][21]={0}, b[21][21]={0};
int main(){
  int N,M,K,A, i,j,k,m,o,s;
  N = getn(), M = getn();
  for(i = 1; i <= M; i++){
    K = getn();
    for(j = 0; j < K; j++){
      A = getn();
      a[A][++a[A][0]] = i;
      for(k = 1; k < a[A][0]; k++){
        if(!b[i][a[A][k]]){
          b[i][a[A][k]] = 1;
          b[i][0]++;
          b[a[A][k]][i] = 1;
          b[a[A][k]][0]++;
        }
      }
    }
  }
  m = 0;
  for(s = 0; s < (1 << M); s++){
    o = 0;
    for(i = 0; i < M; i++)
      if((s >> i) & 1)
        o++;
    if(o <= m)
      continue;
    for(i = 0; i < M; i++){
      if((s >> i) & 1){
        for(j = i+1; j < M; j++){
          if((s >> j) & 1){
            if(b[i+1][j+1]){
              o = -1;
              break;
            }
          }
        }
        if(o == -1)
          break;
      }
    }
    if(o > m)
      m = o;
  }
  printf("%d\n",m);
  return 0;
}
