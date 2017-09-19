// NEO01

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define INF 1000000000000000000LL

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int a[100000];
int main(){
  int T,N, i,k,n;
  ll m,r,s;

  T = getn();
  while(T--){
    N = getn();
    for(r = s = n = i = 0; i < N; ++i)
      a[i] = getn();

    sort(a, N);
    m = -INF, s = n = 0;
    for(i = N-1; i >= 0; --i){
      s += a[i], ++n;
      if(s*n > m)
        m = s*n, k = i;
    }
    r = m;
    for(i = k-1; i >= 0; --i)
      r += a[i];

    printf("%lld\n", r);
  }
  return 0;
}
