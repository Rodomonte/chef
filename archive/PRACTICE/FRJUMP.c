// FRJUMP

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

int mmul(int a, int b){ return (ll)a * b % MOD; }

int mpow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1) r = r * n % MOD;
    n = n * n % MOD, e >>= 1;
  }
  return (int)r;
}

int a[100000], b[100000][256], bn[100000], p[100001];
double s[100001];
int main(){
  int N,Q,O,P,F,R, i,j, u;
  double t;

  N = getn();
  for(i = 0; i < N; ++i) a[i] = getn(), bn[i] = 0;

  for(i = 1; i <= N; ++i) for(j = i, s[i] = 0, p[i] = 1; j < N; j += i)
    p[i] = mmul(p[i], a[j]), s[i] += log10(a[j]), b[j][bn[j]++] = i;

  Q = getn();
  while(Q--){
    O = getn();
    if(O == 1){
      P = getn()-1, F = getn();
      if(!P){ a[0] = F; continue; }
      for(i = 0; i < bn[P]; ++i)
        p[b[P][i]] = mmul(mmul(p[b[P][i]], mpow(a[P], MOD-2)), F),
        s[b[P][i]] += log10(F) - log10(a[P]);
      a[P] = F;
    }else{
      R = getn();
      t = s[R] + log10(a[0]);
      u = (int)(pow(10, t-(int)t)+0.000000001);
      while(u > 9) u /= 10;
      printf("%d %d\n", u, mmul(p[R], a[0]));
    }
  }
  return 0;
}
