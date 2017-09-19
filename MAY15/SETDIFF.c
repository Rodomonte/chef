// SETDIFF

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

int madd(int a, int b){
  if((a += b) >= MOD)
    return a - MOD;
  return a;
}

int msub(int a, int b){
  if((a -= b) < 0)
    return a + MOD;
  return a;
}

int mmul(ll a, ll b){
  return a * b % MOD;
}

int mpow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1)
      r = (r * n) % MOD;
    n = (n * n) % MOD;
    e >>= 1;
  }
  return (int)r;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ ++l; continue; }
    if(*r > p){ --r; continue; }
    t = *l; *l = *r; *r = t;
    ++l, --r;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int a[100000];
int main(){
  int T,N, i,r;
  T = getn();
  while(T--){
    N = getn(), r = 0;
    for(i = 0; i < N; ++i)
      a[i] = getn();
    sort(a, N);
    for(i = N-1; i >= 0; --i){
      r = madd(r, mmul(a[i], mpow(2, i)));
      r = msub(r, mmul(a[i], mpow(2, N-i-1)));
    }
    printf("%d\n", r);
  }
  return 0;
}
