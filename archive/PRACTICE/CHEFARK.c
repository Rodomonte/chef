// CHEFARK

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int madd(int a, int b){ return ((a += b) >= MOD) ? a-MOD : a; }
int msub(int a, int b){ return ((a -= b) < 0) ? a+MOD : a; }
int mmul(int a, int b){ return (ll)a * b % MOD; }

int pow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1) r = r * n % MOD;
    n = n * n % MOD, e >>= 1;
  }
  return (int)r;
}

int f[100001], g[100001];

int nck(int n, int k){
  if(n < k) return 0;
  if(!k || n == 1 || n == k) return 1;
  return mmul(g[n-k], pow(f[k], MOD-2));
}

int main(){
  int T,N,K,X, i, r,t,z;

  for(i = f[0] = 1; i <= 100000; ++i) f[i] = mmul(i, f[i-1]);

  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = z = 0; i < N; ++i) if(!(X = getn())) ++z;

    for(i = N-z, t = 1; i >= 0; --i) g[i] = t, t = mmul(t, i);
    for(i = K, r = 0; i >= 0; i -= (z ? 1 : 2)) r = madd(r, nck(N-z, i));

    printf("%d\n", r);
  }
  return 0;
}
