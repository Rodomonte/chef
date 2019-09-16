// FUZZYLIN

#include <stdio.h>
#include <math.h>
#include <vector>

#define ll long long
#define vec std::vector
#define pb push_back
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int gcd(int a, int b){ return b ? gcd(b,a%b) : a; }

ll b[1000001];
vec<int> a[17];
int main(){
  int N,Q,K, i,j,k, e,g,s;
  ll r;

  N = getn();
  for(i = 0; i < N; ++i)
    a[0].pb(getn());

  for(i = 0; a[i].size() > 1; ++i)
    for(j = 0; j < a[i].size()-1; j += 2)
      a[i+1].pb(gcd(a[i][j], a[i][j+1]));
  for(i = 1; i <= 1000000; ++i)
    b[i] = 0;
  for(i = 0; i < N; ++i){
    j = i, g = a[0][i];
    while(j < N){
      for(k = 0, e = 1; j+e-1 < N && j % e == 0 && a[k][j/e] % g == 0;
          ++k, e <<= 1);
      --k, e >>= 1;
      if(k == -1){
        g = gcd(g, a[0][j++]);
        if(g <= 1000000)
          ++b[g];
      }else{
        if(g <= 1000000)
          b[g] += e;
        j += e;
      }
    }
  }

  Q = getn();
  while(Q--){
    K = getn();

    s = sqrt(K), r = 0;
    for(i = 1; i <= s; ++i){
      if(K % i) continue;
      r += b[i];
      if(i != s || K / i != i) r += b[K / i];
    }
    printf("%lld\n", r);
  }
  return 0;
}
