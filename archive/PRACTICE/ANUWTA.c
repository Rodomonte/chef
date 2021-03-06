// ANUWTA

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T;
  ll N;

  T = getn();
  while(T--){
    N = getn();
    printf("%lld\n", N+((N*(N+1))>>1));
  }
  return 0;
}
