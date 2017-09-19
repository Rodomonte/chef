// PPSUM

#include <stdio.h>

#define gc getchar_unlocked

inline int geti(){
  char c = gc(), f = 1; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f; }

int sum(int n){
  int i,r=0;
  for(i = 1; i <= n; ++i)
    r += i;
  return r;
}

int main(){
  int T,D,N, i,r;
  T = geti();
  while(T--){
    D = geti(), N = geti(), r = sum(N);
    for(i = 1; i < D; ++i)
      r = sum(r);
    printf("%d\n", r);
  }
  return 0;
}
