// IPCTRAIN

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using std::vector;
using std::set;

#define ll long long
#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

struct P {
  int d,t,s;
  P(int _d, int _t, int _s): d(_d), t(_t), s(_s) {}
};
struct R {
  int i,j;
  R(int _i, int _j): i(_i), j(_j) {}
  bool operator<(const R& o) const { return i < o.i; }
};

bool cmp(P& a, P& b){ return a.s > b.s; }

int main(){
  int T,N,D,X,Y,Z, i, d,p,s,t;
  ll r;
  vector<P> a;
  set<R> b;
  set<R>::iterator it,jt;

  T = getn();
  while(T--){
    N = getn(), D = getn(), a.clear(), b.clear();
    for(i = 0; i < N; ++i)
      X = getn(), Y = getn(), Z = getn(), a.pb(P(X, Y, Z));

    sort(a.begin(), a.end(), cmp), r = 0;
    for(i = 0; i < N; ++i){
      d = a[i].d-1, t = a[i].t;
      it = b.lower_bound(R(d+1, 0));
      if(b.empty() || it == b.begin()){ s = d+1;
      }else{
        --it, d = max(it->j, d);
        if(d == it->j) s = it->i, jt = it, ++it, b.erase(jt);
        else s = d+1, ++it;
      }

      while(1){
        if(it == b.end()){
          //printf("1 d=%d->%d t-=%d\n", d,min(D,d+t),min(D,d+t)-d);
          p = d, d = min(D, d+t), t -= d-p; break; }
        if(it->i > d+t){ //printf("2 d+=%d=%d\n", t,d+t);
          d += t, t = 0; break; }
        //printf("3 d=%d t-=%d=%d\n", it->j,it->i-d-1,t-(it->i-d-1));
        t -= it->i-d-1, d = it->j;
        //printf("  About to lower_bound %d\n", d);
        b.erase(it), it = b.lower_bound(R(d, 0));
        //if(it == b.end()) printf("  it = END\n");
        //else printf("  it = %d,%d\n", it->i, it->j);
      }
      b.insert(R(s, d));

      //printf("b:");
      //for(it = b.begin(); it != b.end(); ++it)
      //  printf(" %d,%d", it->i, it->j);
      //printf("\n");
      r += (ll)t * a[i].s;
    }
    printf("%lld\n", r);
  }
  return 0;
}
