#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

inline int geti(){
  char c = gc(), f = 1; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f; }

int mmul(ll a, ll b){ return (int)(a * b % MOD); }
int mpow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1) r = (r * n) % MOD;
    n = (n * n) % MOD, e >>= 1; }
  return (int)r;
}

int main(){
  int T,N,K;
  T = geti();
  while(T--){
    N = geti(), K = geti();
    printf("%d\n", mmul(K, mpow(K-1, N-1)));
  }
  return 0;
}
