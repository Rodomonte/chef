// CYCLRACE

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;

#define ll long long
#define gc getchar_unlocked
#define pb push_back

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
int max(int a, int b){
  return (a > b) ? a : b;
}

struct L {
  ll m,b;
  double x;
  L(ll m0, ll b0): m(m0), b(b0) {}
};

bool cmp(const L& a, const L& b){
  return (a.m > b.m || (a.m == b.m && a.b > b.b));
}

int a[50001]={0};
int main(){
  int N,Q,O,T,C,S, i,j,t;
  vector<int> q;
  vector<L> b,h;

  N = getn(), Q = getn();
  b.pb(L(0,0));
  while(Q--){
    O = getn(), T = getn();
    if(O == 1){
      C = getn(), S = getn();
      b.pb(L(S, b[a[C]].m * T + b[a[C]].b - (ll)S * T));
      a[C] = b.size()-1;
    }else
      q.pb(T);
  }
  if(b.size() == 1){
    for(i = 0; i < q.size(); ++i)
      printf("0\n");
    return 0;
  }

  std::sort(b.begin(), b.end(), cmp);
  b[0].x = 1000000000;
  h.pb(b[0]);
  for(i = 1; i < b.size(); ++i){
    if(b[i].m == b[i-1].m)
      continue;
    if(h.size() > 1 &&
       (double)(b[i].b-h[h.size()-2].b) / (h[h.size()-2].m-b[i].m) >=
       (double)(h.back().b-h[h.size()-2].b) / (h[h.size()-2].m-h.back().m)){
      h.pop_back();
      --i;
      continue;
    }
    b[i].x = h.empty() ? 1000000000 :
                         (double)(b[i].b-h.back().b) / (h.back().m-b[i].m);
    h.pb(b[i]);
  }

  for(i = 0; i < q.size(); ++i){
    j = h.size()>>1, t = max(h.size()>>2,1);
    while(1){
      if(j && q[i] > h[j].x){
  j -= t;
  if(t > 1)
    t >>= 1;
  continue;
      }
      if(j < h.size()-1 && q[i] < h[j+1].x){
  j += t;
  if(t > 1)
    t >>= 1;
  continue;
      }
      break;
    }
    printf("%lld\n", h[j].m * q[i] + h[j].b);
  }
  return 0;
}
