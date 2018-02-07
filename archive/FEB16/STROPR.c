// STROPR

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
inline ll getll(){
  char c = gc(); ll n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int madd(ll a, ll b){
  a %= MOD, b %= MOD;
  return ((a+=b)>=MOD) ? a-MOD : a;
}
int mmul(ll a, ll b){
  return (a%MOD)*(b%MOD)%MOD;
}
int mpow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1)
      r = r * n % MOD;
    n = n * n % MOD;
    e >>= 1;
  }
  return (int)r;
}

int a[100001];
int main(){
  int T,N,X,M, i,n,d,c,r;
  T = getn();
  while(T--){
    N = getn(), X = getn(), M = getll() % MOD, r = 0;
    for(i = 1; i <= N; ++i)
      a[i] = getll() % MOD;
    n = M-1, d = 0, c = 1, r = 0;
    for(i = X; i > 0; --i){
      r = madd(r, mmul(a[i], c));
      ++n, ++d;
      c = mmul(c, n);
      c = mmul(c, mpow(d, MOD-2));
    }
    printf("%d\n", r);
  }
  return 0;
}
