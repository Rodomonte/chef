// SCLUSTER

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,K, i,j,k,m,s, a[60][60],b[2001];

  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = 0; i < N; ++i)
      for(j = 0; j < N; ++j)
  a[i][j] = getn();
    for(k = 1; k <= K; ++k)
      b[i] = getn();

    s = 0;
    for(i = 0; i < N; ++i)
      for(j = 0; j < N; ++j)
        if(a[i][j])
    s += i;
    m = s / K;
    for(i = m-1; i >= 0; --i){
      for(j = 0; j < N; ++j){
  if(!a[i][j])
    continue;
  for(k = i+1; k <= m; ++k){
    if(a[k][j])
      break;
    a[k][j] = a[k-1][j];
    a[k-1][j] = 0;
  }
      }
    }
    for(i = m+1; i < N; ++i){
      for(j = 0; j < N; ++j){
  if(!a[i][j])
    continue;
  for(k = i-1; k >= m; --k){
    if(a[k][j])
      break;
    a[k][j] = a[k+1][j];
    a[k+1][j] = 0;
  }
      }
    }

    s = 0;
    for(i = 0; i < N; ++i)
      for(j = 0; j < N; ++j)
        if(a[i][j])
    s += j;
    m = s / K;
    for(j = m-1; j >= 0; --j){
      for(i = 0; i < N; ++i){
  if(!a[i][j])
    continue;
  for(k = j+1; k <= m; ++k){
    if(a[i][k])
      break;
    a[i][k] = a[i][k-1];
    a[i][k-1] = 0;
  }
      }
    }
    for(j = m+1; j < N; ++j){
      for(i = 0; i < N; ++i){
  if(!a[i][j])
    continue;
  for(k = j-1; k >= m; --k){
    if(a[i][k])
      break;
    a[i][k] = a[i][k+1];
    a[i][k+1] = 0;
  }
      }
    }

    for(i = 0; i < N; ++i){
      for(j = 0; j < N; ++j)
  printf("%d ", a[i][j]);
      printf("\n");
    }
  }
  return 0;
}
