// SANSKAR

#include <stdio.h>
#include <vector>
using std::vector;

#define ll long long
#define pb push_back

struct P {
  P(ll n0, int c0): n(n0), c(c0) {}
  ll n;
  int c;
};

int K;
ll d;
vector<P> a;
vector<vector<ll> > b;

void fn1(vector<P> c, int p, ll s){
  int i,j;
  if(s == d){
    vector<ll> bv;
    for(i = 0; i < c.size(); ++i)
      for(j = 0; j < c[i].c; ++j)
        bv.pb(c[i].n);
    b.pb(bv);
  }
  for(i = p; i < a.size(); ++i){
    if(c[i].c < a[i].c && s+c[i].n <= d){
      vector<P> c2 = c;
      ++c2[i].c;
      fn1(c2, i, s+c[i].n);
    }
  }
}

bool fn2(int k, vector<ll>& p){
  if(k == K)
    return p.empty() ? true : false;
  if(p.empty())
    return false;
  bool f;
  int i,j,n;
  vector<ll> p2;
  for(i = 0; i < b.size(); ++i){
    p2 = p;
    for(j = 0; j < b[i].size(); ++j){
      f = false;
      for(n = 0; n < p2.size(); ++n){
        if(b[i][j] == p2[n]){
          f = true;
          p2.erase(p2.begin() + n);
          break;
        }
      }
      if(!f)
        break;
    }
    if(!f)
      continue;
    if(fn2(k+1, p2))
      return true;
  }
  return false;
}

int main(){
  bool f;
  int T,N, i,j,z;
  ll s;
  vector<ll> p;
  vector<P> c;

  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &N, &K);
    a.clear();
    s = z = 0;
    for(i = 0; i < N; ++i){
      d = 0;
      scanf("%lld", &d);
      if(d == 0)
        ++z;
      s += d, f = false;
      for(j = 0; j < a.size(); ++j){
        if(a[j].n == d){
          f = true;
          ++a[j].c;
        }
      }
      if(!f)
        a.pb(P(d, 1));
    }

    if(K == 1){
      printf("yes\n");
      continue;
    }
    if(N < K || s % K){
      printf("no\n");
      continue;
    }

    d = s / K;
    c.clear();
    for(i = 0; i < a.size(); ++i)
      c.pb(P(a[i].n, 0));
    b.clear();
    fn1(c, 0, 0);

    p.clear();
    for(i = 0; i < a.size(); ++i)
      for(j = 0; j < a[i].c; ++j)
        p.pb(a[i].n);
    printf(fn2(0, p) ? "yes\n" : "no\n");
  }
  return 0;
}
