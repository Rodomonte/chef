// CHEFGAME

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

#define ll long long
#define MOD 747474747
int a[6666][5], b[6666], D;
ll c[6666];
ll dist(int p, int q){
  int i, n;
  ll r = 0;
  for(i = 0; i < D; i++){
    n = a[p][i] - a[q][i];
    r += (ll)n * n;
  }
  return r;
}
int main(){
  int T = getn(),N, i,j, n,n2;
  ll d,m,r;
  while(T--){
    N = getn(), D = getn(), n = 0, r = 1;
    for(i = 0; i < N; i++){
      b[i] = 0, c[i] = -1;
      for(j = 0; j < D; j++)
        a[i][j] = getn();
    }
    while(1){
      b[n] = 1, m = -1;
      for(i = 0; i < N; i++)
        if(!b[i]){
          d = dist(n, i);
          if(d > c[i]) c[i] = d;
          if(c[i] > m){
            m = c[i];
            n2 = i;
          }
        }
      if(m == -1) break;
      n = n2;
      if(m > 1)
        r = (r * (m % MOD)) % MOD;
    }
    printf("%lld\n",r);
  }
  return 0;
}
