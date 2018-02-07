// XENTASK

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
  int T,N,A, i,x,y;
  T = getn();
  while(T--){
    N = getn(), x = y = 0;
    for(i = 0; i < N; ++i){
      A = getn();
      if(i&1) y += A;
      else x += A;
    }
    for(i = 0; i < N; ++i){
      A = getn();
      if(i&1) x += A;
      else y += A;
    }
    printf("%d\n", (x < y) ? x : y);
  }
  return 0;
}
