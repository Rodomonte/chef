// MAKETRI

#include <stdio.h>
#include <vector>
#include <algorithm>

#define ll long long
#define gc getchar_unlocked
#define pb push_back

using std::vector;
using std::sort;

ll getn(){
  ll n = 0; char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
ll abs(ll n){
  return (n < 0) ? -n : n;
}
ll max(ll a, ll b){
  return (a > b) ? a : b;
}

struct S {
  S(ll a, ll b){
    l = abs(a - b) + 1;
    r = a + b - 1;
  }
  ll l,r;
};
bool scmp(const S& a, const S& b){
  return a.l < b.l;
}

int main(){
  ll N,L,R, i,m,n,r;
  vector<ll> a;
  vector<S> s;

  N = getn(), L = getn(), R = getn();
  for(i = 0; i < N; ++i)
    a.pb(getn());
  sort(a.begin(), a.end());
  for(i = 1; i < N; ++i)
    s.pb(S(a[i-1], a[i]));
  sort(s.begin(), s.end(), scmp);
  for(i = m = r = 0; i < s.size(); ++i){
    //printf("s[%lld] = %lld,%lld\n", i,s[i].l,s[i].r);
    if(m < s[i].l){
      if(m && m >= L && n <= R){
        if(L > n) n = L;
        if(R < m) m = R;
        r += m - n + 1;
      }
      n = s[i].l;
    }
    m = max(m, s[i].r);
  }
  if(m >= L && n <= R){
    if(L > n) n = L;
    if(R < m) m = R;
    r += m - n + 1;
  }

  printf("%lld\n", r);
  return 0;
}
