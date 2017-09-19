// CSEQ

#include <stdio.h>

#define ll long long
#define MOD 1000003

ll invm(ll k){
  k %= MOD;
  int neg = 1;
  long long p1 = 1, p2 = 0, k1 = k, m1 = MOD, q, r, temp;
  while(k1 > 0) {
    q = m1 / k1;
    r = m1 % k1;
    temp = q*p1 + p2;
    p2 = p1;
    p1 = temp;
    m1 = k1;
    k1 = r;
    neg = !neg;
  }
  return neg ? MOD - p2 : p2;
}
ll nck2(ll n, ll k){
  n %= MOD;
  if(n < k) return 0;
  if(k == 0 || k == n) return 1;
  if(k > n/2)
    k = n-k;
  ll num = n, den = 1;
  for(n = n-1; k > 1; --n, --k){
    num = (num * n) % MOD;
    den = (den * k) % MOD;
  }
  den = invm(den);
  return (num * den) % MOD;
}
ll nck1(ll n, ll k){
  if(k < MOD)
    return nck2(n, k);
  ll q_n, r_n, q_k, r_k, c;
  q_n = n / MOD;
  r_n = n % MOD;
  q_k = k / MOD;
  r_k = k % MOD;
  c = nck2(r_n, r_k) * nck1(q_n, q_k);
  return c % MOD;
}
ll fe(ll n){
  ll ex = 0;
  do{
    n /= MOD;
    ex += n;
  }while(n > 0);
  return ex;
}
int nck(ll n, ll k){
  if(k < 0 || n < k) return 0;
  if(k == 0 || k == n) return 1;
  if(fe(n) > fe(k) + fe(n-k)) return 0;
  return (int)nck1(n, k);
}
int msub(int a, int b){
  a -= b;
  return (a < 0) ? a+MOD : a;
}

int main(){
  int T,N,L,R;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d %d", &N, &L, &R);
    printf("%d\n", msub(nck(R-L+N+1, N), 1));
  }
  return 0;
}
