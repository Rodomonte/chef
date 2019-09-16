// KCON

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[200000];
int main(){
  int T,N,K, i, f;
  ll h,m,n,s;

  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = s = f = 0, n = -INF; i < N; ++i){
      s += (a[i] = a[i+N] = getn());
      if(a[i] >= 0) f = 1;
      if(a[i] > n) n = a[i];
    }

    for(i = h = m = 0; i < ((K == 1) ? N : (N<<1)); ++i)
      h = (h+a[i] < 0) ? 0 : h+a[i], m = (h > m) ? h : m;
    printf("%lld\n",
           (K == 1) ? (f ? m : n) : ((s > 0) ? s*(K-2)+m : (f ? m : n)));
  }
  return 0;
}
