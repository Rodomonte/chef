// DEVPERF

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

int main(){
  char c;
  int T,N,M, i,j,i0,i1,j0,j1;
  T = getn();
  while(T--){
    N = getn(), M = getn(), i0 = j0 = 1000, i1 = j1 = -1;
    for(i = 0; i < N; ++i){
      for(j = 0; j < M; ++j){
  c = gc();
  if(c == '*'){
    if(i < i0) i0 = i;
    if(i > i1) i1 = i;
    if(j < j0) j0 = j;
    if(j > j1) j1 = j;
  }
      }
      gc();
    }
    if(i1 == -1 || j1 == -1)
      printf("0\n");
    else
      printf("%d\n", (max(i1-i0+1, j1-j0+1)>>1)+1);
  }
  return 0;
}
