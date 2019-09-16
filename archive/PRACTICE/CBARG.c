// CBARG

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N,X, i, p;
  ll r;

  T = getn();
  while(T--){
    N = getn(), r = p = 0;
    for(i = 0; i < N; ++i){
      X = getn();
      if(X-p > 0) r += X-p;
      p = X;
    }
    printf("%lld\n", r);
  }
  return 0;
}
