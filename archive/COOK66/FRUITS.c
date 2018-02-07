// FRUITS

#include <stdio.h>

#define gc getchar_unlocked

inline int gi(){
  char c; int n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int abs(int n){
  return (n < 0) ? -n : n;
}

int main(){
  int T,N,M,K;
  T = gi();
  while(T--){
    N = gi(), M = gi(), K = gi();
    if(abs(N-M) <= K)
      printf("0\n");
    else
      printf("%d\n", abs(N-M)-K);
  }
  return 0;
}
