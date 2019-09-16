// LENTMO

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

ll max(ll a, ll b){ return (a > b) ? a : b; }

int a[10000];
int main(){
  int T,N,K,X, i,j, m,n;
  ll r,s;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      a[i] = getn();
    K = getn(), X = getn();

    for(n = i = 0; i < N; ++i)
      if((a[i] ^ X) > a[i]) ++n;
    r = s = 0;

    if(K == 1){
      for(i = 0; i < N; ++i)
        r += max(a[i], a[i] ^ X);

    }else if(K == N){
      for(i = 0; i < N; ++i)
        r += a[i], s += (a[i] ^ X);
      r = max(r, s);

    }else if((n & 1) && n % K && !((K & 1) && (n & 1))){
      for(i = 0; i < N; ++i)
        s += a[i];
      for(i = 0; i < N; ++i)
        a[i] = max(a[i], a[i] ^ X);
      for(i = 0, m = INF; i < N; ++i)
        if(a[i] - (a[i] ^ X) < m) m = a[i] - (a[i] ^ X), j = i;
      a[j] ^= X;
      for(i = 0; i < N; ++i)
        r += a[i];
      r = max(r, s);

    }else{
      for(i = 0; i < N; ++i)
        r += max(a[i], a[i] ^ X);
    }

    printf("%lld\n", r);
  }
  return 0;
}
