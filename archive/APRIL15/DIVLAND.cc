// DIVLAND

#include <stdio.h>
#include <algorithm>
#include <vector>
using std::vector;

#define ll long long
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

struct R {
  int a,b,c;
};
bool cmp(const R& a, const R& b){
  return a.c > b.c;
}

R a[1000000];
char v[1000000]={0};
vector<int> n[1000000];

int main(){
  int N,M, i,j,k,t,mi,it;
  ll m,c;
  vector<int> r;
  const int itmax = 11000000;
  N = getn(), M = getn();
  for(i = 0; i < M; ++i){
    a[i].a = getn(), a[i].b = getn(), a[i].c = getn();
    n[a[i].a].pb(i);
    n[a[i].b].pb(i);
  }

  it = 0;
  t = (N>>1) - r.size();
  for(i = 0; i < t; ++i){
    m = (1LL<<62), mi = -1;
    for(j = 0; j < N; ++j){
      if(v[j])
        continue;
      c = 0;
      for(k = 0; k < n[j].size(); k++){
        if(a[n[j][k]].a == a[n[j][k]].b)
          continue;
        if(v[(a[n[j][k]].a==j)?a[n[j][k]].b:a[n[j][k]].a])
          c -= a[n[j][k]].c;
        else
          c += a[n[j][k]].c;
      }
      if(c < m)
        m = c, mi = j;
      it += n[j].size();
      if(it > itmax)
        break;
    }
    if(mi == -1 || it > itmax)
      break;
    r.pb(mi);
    v[mi] = 1;
  }

  if(r.size() < (N>>1)){
    std::sort(a, a+M, cmp);
    t = (N-1 < M) ? N-1 : M;
    for(i = 0; i < t; ++i){
      if(!v[a[i].a])
        r.pb(a[i].a), v[a[i].a] = 1;
      if(r.size() == (N>>1))
        break;
      if(!v[a[i].b])
        r.pb(a[i].b), v[a[i].b] = 1;
      if(r.size() == (N>>1))
        break;
    }
    for(i = 0; r.size() < (N>>1); ++i)
      if(!v[i])
        r.pb(i);
  }

  for(i = 0; i < r.size(); ++i)
    putn(r[i]), pc(' ');
  pc('\n');
  return 0;
}
