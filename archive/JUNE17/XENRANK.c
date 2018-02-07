// XENRANK

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,U,V;

  T = getn();
  while(T--){
    U = getn(), V = getn();
    printf("%lld\n", (ll)(U+V)*(U+V+1)/2+U+1);
  }
  return 0;
}
