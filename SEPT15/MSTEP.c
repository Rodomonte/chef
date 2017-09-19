// MSTEP

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int abs(int n){
  return (n < 0) ? 0-n : n;
}
int a[250001][2];
int main(){
  int T,N,C, i,j,r;
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i){
      for(j = 0; j < N; ++j){
  C = getn();
  a[C][0] = i, a[C][1] = j;
      }
    }
    r = 0;
    for(i = 1; i < N*N; ++i){
      r += abs(a[i][0] - a[i+1][0]);
      r += abs(a[i][1] - a[i+1][1]);
    }
    printf("%d\n", r);
  }
  return 0;
}
