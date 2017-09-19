// SEAGCD

#include <stdio.h>
#include <math.h>

#define ll long long
#define MOD 1000000007

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

int mmul(int n, int m){
  ll p = (ll)n * m % MOD;
  return (int)p;
}

int madd(int n, int a){
  return (n + a >= MOD) ? n+a-MOD : n+a;
}

int msub(int n, int s){
  return (n < s) ? n-s+MOD : n-s;
}

int min(int a, int b){
  return (a < b) ? a : b;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

typedef struct {
  int l,r,v;
} S ;

int main(){
  int T,N,M,L,R, i,j,s,d,n,p,an,r;
  S a[6324];
  scanf("%d", &T);
  while(T--){
    scanf("%d %d %d %d", &N, &M, &L, &R);
    s = (int)sqrt((double)M);
    for(i = 1; i < s; ++i)
      a[i].l = a[i].r = i;
    p = --i;
    for(d = s; d <= M; d++){
      n = M / d;
      if(n != p)
        ++i, a[i].l = a[i].r = d;
      else
        ++a[i].r;
      p = n;
    }
    a[(an = i)].v = 1;
    for(i = an-1; i >= 1; --i){
      a[i].v = mpow(M / a[i].r, N), j = i;
      for(d = a[i].r << 1; d <= M; d += a[i].r){
        while(a[j].r < d)
          ++j;
        a[i].v = msub(a[i].v, a[j].v);
      }
    }
    r = 0;
    for(i = 1; a[i].r < L; ++i);
    for(; i <= an; ++i){
      n = min(a[i].r, R) - max(a[i].l, L) + 1;
      r = madd(r, mmul(a[i].v, n));
      if(a[i].r >= R)
        break;
    }
    printf("%d\n", r);
  }
  return 0;
}
