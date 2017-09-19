// LEMOVIE

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n/2], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

#define MOD 1000000007
#define ll long long
int N,P[200], a[200][201],f[201],c[201][201]={{0}};

ll nc2(ll a, ll k){
  ll r = 1, n = a;
  while(k){
    if(k&1)
      r = (r * n) % MOD;
    k >>= 1;
    n = (n * n) % MOD;
  }
  return r;
}
int nc1(ll n){
  int d = 0;
  ll u = MOD;
  while(u <= n){
    d += n / u;
    u *= MOD;
  }
  return d;
}
int nc(int n, int k){
  if(nc1(n) - nc1(n-k) > nc1(k))
    return 0;
  ll i, t, r = 1;
  for(i = n; i > n-k; --i){
    t = i;
    while(t % MOD == 0)
      t /= MOD;
    r = (r * t) % MOD;
  }
  ll d = 1;
  for(i = 1; i <= k; ++i){
    t = i;
    while(t % MOD == 0)
      t /= MOD;
    d = (d * t) % MOD;
  }
  r = (r * nc2(d, MOD-2)) % MOD;
  return r;
}

int mp(int i, int k, int np){
  if(!np) return 1;
  if(!k || np < k) return 0;
  if(a[i][k] != -1) return a[i][k];
  int n = N-i, r = 1;
  while(i+r < N && P[i+r] == P[i]) r++;
  if(!c[n][r]) c[n][r] = nc(n,r);
  if(!c[n-1][r-1]) c[n-1][r-1] = nc(n-1,r-1);
  a[i][k] = ((((ll)((c[n][r] - c[n-1][r-1] + MOD) % MOD) * mp(i+r,k,np-1)) % MOD
      + ((ll)c[n-1][r-1] * mp(i+r,k-1,np-1)) % MOD) % MOD * f[r]) % MOD;
  return a[i][k];
}

int main(){
  int T,K, i,j, t,r;
  for(f[1] = 1, i = 2; i <= 200; i++)
    f[i] = ((ll)f[i-1] * i) % MOD;
  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = 0; i < N; i++)
      P[i] = getn();
    sort(P, N);
    for(i = 0; i < N; i++)
      for(j = 1; j <= K; j++)
        a[i][j] = -1;
    for(t = j = i = 0; i < N; i++)
      if(P[i] != t)
        t = P[i], j++;
    for(r = 0, i = 1; i <= K; i++)
      r = (r + mp(0, i, j)) % MOD;
    printf("%d\n",r);
  }
  return 0;
}
