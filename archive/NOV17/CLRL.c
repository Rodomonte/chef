// CLRL

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N,R,X, i, f,l,p,r;

  T = getn();
  while(T--){
    N = getn(), R = getn(), f = l = 1, r = 1000000000, p = getn();
    for(i = 1; i < N; ++i){
      X = getn();

      if(X < l || X > r) f = 0;
      if(X < p && p < r) r = p;
      if(X > p && p > l) l = p;
      p = X;
    }
    printf(f ? "YES\n" : "NO\n");
  }
  return 0;
}
