// ALEXTASK

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
ll min(ll a, ll b){
  return (a < b) ? a : b;
}
ll gcd(ll a, ll b){
  return b ? gcd(b,a%b) : a;
}
ll lcm(ll a, ll b){
  return a / gcd(a,b) * b;
}

int main(){
  int T,N, i,j, a[500];
  ll m;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      a[i] = getn();

    m = (ll)INF * INF;
    for(i = 0; i < N-1; ++i)
      for(j = i+1; j < N; ++j)
        m = min(m, lcm(a[i], a[j]));

    printf("%lld\n", m);
  }
  return 0;
}
