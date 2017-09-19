#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

inline ll getl(){
  char c = gc(); ll f = 1, n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f; }

int main(){
  ll T,N,M, r;
  T = getl();
  while(T--){
    N = getl(), M = getl();
    if(N > M) r = N, N = M, M = r;
    if(N == 1)
      r = (M == 2) ? 1 : 0;
    else if((N&1) && (M&1))
      r = 0;
    else
      r = 1;
    printf(r ? "Yes\n" : "No\n");
  }
  return 0;
}
