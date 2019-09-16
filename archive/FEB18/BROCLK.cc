// BROCLK

#include <stdio.h>
#include <unordered_map>

using std::unordered_map;

#define ll long long
#define gc getchar
#define MOD 1000000007

int getn(){
  int n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}
ll getl(){
  ll n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

//! Might fail if n < 0 && -n % MOD == 0
int mod(ll n){ return (n < 0) ? MOD-((-n)%MOD) : n%MOD; }
int pow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1) r = r * n % MOD;
    n = n * n % MOD, e >>= 1;
  }
  return r % MOD;
}

struct R {
  ll n,d;
  R(): n(0), d(1) {}
  R(ll n0, ll d0): n(mod(n0)), d(mod(d0)) {}
  R rmod(){ return R(mod(n), mod(d)); }
  R operator+(R o) const { return R(mod(n*o.d) + mod(o.n*d), d*o.d); }
  R operator-(R o) const { return (*this + (o * R(-1, 1)).rmod()).rmod(); }
  R operator*(R o) const { return R(n*o.n, d*o.d); }
};

unordered_map<ll,R> m;
R cheb(ll n, R x){
  R r(1, 1);
  unordered_map<ll,R>::iterator it;
  if(!n) return r;
  else if(n == 1) return x;
  else if((it = m.find(n)) != m.end()) return m[n];
  else if(!(n&1)){
    r = cheb(n>>1, x);
    r = (r * r * R(2, 1) - R(1, 1)).rmod();
  }else r = (cheb((n-1)>>1, x) * cheb((n+1)>>1, x) * R(2, 1) - x).rmod();
  m[n] = r;
  return r;
}

int main(){
  int T,D,L, i;
  ll N;
  R r;

  T = getn();
  while(T--){
    L = getn(), D = getn(), N = getl(), m.clear();

    r = cheb(N, R(D, L)) * R(L, 1);
    printf("%d\n", mod((ll)mod(r.n) * pow(mod(r.d), MOD-2)));
  }
  return 0;
}
