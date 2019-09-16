// PERFCONT

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N,P,X, i, c,h;

  T = getn();
  while(T--){
    N = getn(), P = getn(), c = h = 0;
    for(i = 0; i < N; ++i){
      X = getn();
      if(X >= P/2) ++c;
      if(X <= P/10) ++h;
    }

    printf((c == 1 && h == 2) ? "yes\n" : "no\n");
  }
  return 0;
}
