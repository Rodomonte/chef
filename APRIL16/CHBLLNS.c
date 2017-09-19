#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

inline int geti(){
  char c = gc(), f = 1; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f; }

ll min(int a, int b){ return (a < b) ? a : b; }

int main(){
  int T,R,G,B,K;
  ll r;
  T = geti();
  while(T--){
    R = geti(), G = geti(), B = geti(), K = geti(), r = 0;
    if(R >= K) r = K + min(G, K-1) + min(B, K-1);
    else if(G >= K) r = K + min(R, K-1) + min(B, K-1);
    else r = K + min(R, K-1) + min(G, K-1);
    printf("%lld\n", r);
  }
  return 0;
}
