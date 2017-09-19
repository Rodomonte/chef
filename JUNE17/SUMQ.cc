// SUMQ

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using std::sort;
using std::vector;
using std::map;

#define ll long long
#define gc getchar_unlocked
#define pb push_back
#define MOD 1000000007

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int madd(int a, int b){
  return (a+b >= MOD) ? a+b-MOD : a+b;
}
int mmul(int a, int b){
  return (ll)a * b % MOD;
}

struct S {
  int i,n;
  S(){}
  S(int i0, int n0): i(i0), n(n0) {}
};

int main(){
  int T,P,Q,R, i,n,r;
  vector<int> a,b,c;
  map<int,S> x,z;
  map<int,S>::iterator it,jt;

  T = getn();
  while(T--){
    a.clear(), b.clear(), c.clear(), x.clear(), z.clear();
    P = getn(), Q = getn(), R = getn();
    for(i = 0; i < P; ++i) a.pb(getn());
    for(i = 0; i < Q; ++i) b.pb(getn());
    for(i = 0; i < R; ++i) c.pb(getn());

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for(n = i = 0; i < P; ++i)
      n = madd(n, a[i]), x[a[i]] = S(i+1, n);
    for(n = i = 0; i < R; ++i)
      n = madd(n, c[i]), z[c[i]] = S(i+1, n);

    for(r = i = 0; i < Q; ++i){
      it = x.upper_bound(b[i]);
      if(it == x.begin()) continue;
      --it;
      jt = z.upper_bound(b[i]);
      if(jt == z.begin()) continue;
      --jt;
      r = madd(r, madd(mmul(mmul(mmul(b[i], b[i]), it->second.i), jt->second.i),
                  madd(mmul(mmul(b[i], it->second.n), jt->second.i),
                  madd(mmul(mmul(b[i], jt->second.n), it->second.i),
                       mmul(it->second.n, jt->second.n)))));
    }

    printf("%d\n", r);
  }
  return 0;
}
