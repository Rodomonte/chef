// CHFING

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

ll getl(){
  ll n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int mmul(int a, int b){ return (ll)a * b % MOD; }

int main(){
  int T;
  ll N,K, a,n;

  T = getl();
  while(T--){
    N = getl(), K = getl();

    n = (K+N-3) / (N-1);
    a = ((K-1 - (n-1) * (N-1)) << 1) + (n-1) * (N-1);
    if(n & 1) a >>= 1;
    else n >>= 1;

    printf("%d\n", mmul(n % MOD, a % MOD));
  }
  return 0;
}
