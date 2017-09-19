// MAXISUM

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define INF 2000000000

inline int geti(){
  char c = gc(), f = 1; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f; }

ll a[100000], b[100000];
int main(){
  int T,N,K, i,j,k,n,x;
  ll r;

  T = geti();
  while(T--){
    N = geti(), K = geti(), n = INF, x = -INF, r = 0;
    for(i = 0; i < N; ++i) a[i] = geti();
    for(i = 0; i < N; ++i){
      b[i] = geti();
      if(b[i] < n) n = b[i], j = i;
      if(b[i] > x) x = b[i], k = i; }
    if(-n > x) a[j] -= K;
    else a[k] += K;
    for(i = 0; i < N; ++i) r += a[i] * b[i];
    printf("%lld\n", r);
  }
  return 0;
}
