// CARPTUN

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

int max(int a, int b){ return (a > b) ? a : b; }

int a[100000];
int main(){
  int T,N,C,D,S, i, m;
  ll r;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i) a[i] = getn();
    C = getn(), D = getn(), S = getn();

    r = m = a[0];
    for(i = 1; i < N; ++i)
      r += max(0, a[i] - max(m, a[i-1])), m = max(m, a[i]);
    r *= C-1;
    printf("%lld\n", r);
  }
  return 0;
}
