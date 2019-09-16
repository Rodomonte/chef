// EXPGCD

#include <stdio.h>
#include <math.h>

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
int mmul(int a, int b){ return (int)((ll)a * b % MOD); }
int gcde(int a, int b, int* x, int* y){
  if(!a){ *x = 0, *y = 1; return b; }
  int g,x1,y1;
  g = gcde(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1, *y = x1;
  return g;
}
int minv(int a){
  int x,y;
  if(gcde(a, MOD, &x, &y) != 1)
    return -1;
  return (x % MOD + MOD) % MOD;
}
int mdiv(int a, int b){
  int inv = minv(b);
  if(inv == -1) inv /= 0;
  return mmul(inv, a);
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1), sort(l, a+n-l);
}

int c[200], d[200], f[200001], s[200001], t[200001];

int npk(int n, int k){ return mdiv(f[n], f[n-k]); }

int main(){
  int N,Q,K, i,j,k, n,n2,dn;

  for(f[0] = i = 1; i <= 200000; ++i)
    f[i] = mmul(f[i-1], i);

  Q = getn(), K = getn();
  s[1] = 0, t[1] = 0;
  for(i = 2; i <= 200000; ++i){
    s[i] = s[i-1], t[i] = t[i-1], dn = 0;
    for(j = 1, n = sqrt(i); j <= n; ++j){
      if(i % j) continue;
      d[dn++] = j;
      if(j != (n2 = i / j)) d[dn++] = n2;
    }

    sort(d, dn);
    for(j = 0; j < dn; ++j)
      c[j] = 0;
    for(j = dn-1; j >= 0; --j){
      if(d[j] == i || i/d[j] < K) continue;
      n = npk(i/d[j]-1, K-1);
      c[j] = madd(c[j], n);
      for(k = j-1; k >= 0; --k)
        if(d[j] % d[k] == 0) c[k] = msub(c[k], c[j]);
    }
    for(j = 0; j < dn; ++j)
      s[i] = madd(s[i], mmul(c[j], d[j])), t[i] = madd(t[i], c[j]);
  }
  for(i = 1; i <= 200000; ++i)
    if(!s[i]) t[i] = 1;

  while(Q--){
    N = getn();
    printf("%d\n", mdiv(s[N], t[N]));
  }
  return 0;
}
