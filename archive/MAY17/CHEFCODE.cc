// CHEFCODE

#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

#define ll long long
#define gc getchar_unlocked
#define pb push_back

ll getn(){
  ll n = 0; char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct P {
  int c,n;
  P(): c(0), n(1) {}
};

int main(){
  int N, i,j,k;
  ll K, n,r;
  vector<ll> a,b,c;
  map<ll,P> m;
  map<ll,P>::iterator it;

  N = getn(), K = getn();
  for(i = 0; i < N; ++i)
    a.pb(getn());

  for(i = 0; i < N/2; ++i){
    if(a[i] > K)
      continue;
    k = b.size();
    for(j = 0; j < k; ++j)
      if((double)a[i] * (double)b[j] <= (double)K*2)
        if(a[i] * b[j] <= K)
          b.pb(a[i] * b[j]);
    b.pb(a[i]);
  }

  for(i = N/2; i < N; ++i){
    if(a[i] > K)
      continue;
    k = c.size();
    for(j = 0; j < k; ++j)
      if((double)a[i] * (double)c[j] <= (double)K*2)
        if(a[i] * c[j] <= K)
          c.pb(a[i] * c[j]);
    c.pb(a[i]);
  }

  for(i = 0; i < c.size(); ++i){
    n = K / c[i];
    it = m.find(n);
    if(it == m.end())
      m[n] = P();
    else
      ++it->second.n;
  }
  for(i = 0; i < b.size(); ++i){
    it = m.lower_bound(b[i]);
    if(it == m.end())
      continue;
    ++it->second.c;
  }

  r = b.size()+c.size(), n = 0;
  for(it = m.begin(); it != m.end(); ++it){
    n += it->second.c;
    r += n * it->second.n;
  }
  printf("%lld\n", r);

  return 0;
}
