// DEVARRAY

#include <stdio.h>

#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

int main(){
  int N,Q,X, i, n,x;
  N = getn(), Q = getn(), n = INF, x = -INF;
  for(i = 0; i < N; ++i) X = getn(), n = min(n, X), x = max(x, X);
  while(Q--) X = getn(), printf((X >= n && X <= x) ? "Yes\n" : "No\n");
  return 0;
}
