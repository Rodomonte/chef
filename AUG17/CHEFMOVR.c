// CHEFMOVR

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

ll abs(ll n){ return (n < 0) ? -n : n; }

ll a[100000];
int main(){
  char f;
  int T,N,D, i,j;
  ll n,p,r,s,t;

  T = getn();
  while(T--){
    N = getn(), D = getn();
    for(i = 0; i < N; ++i) a[i] = getn();

    for(i = r = 0, p = -1, f = 1; i < D; ++i){
      for(j = i, s = n = 0; j < N; j += D) s += a[j], ++n;
      t = s / n;
      if(s % n || (p != -1 && t != p)){ f = 0; break; }
      p = t;
      for(j = i; j < N-D; j += D)
        a[j+D] -= t - a[j], r += abs(t - a[j]), a[j] = t;
    }
    printf("%lld\n", f ? r : -1LL);
  }
  return 0;
}
