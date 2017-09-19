// CHINSM

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

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

struct P {
  P(int i0, int j0): i(i0), j(j0) {}
  int i,j;
};

int a[100000], g[100000];
vector<int> f[100001];
queue<int> q[100001];
int main(){
  int N,K, i,j,n,m,s,e;
  ll r;
  vector<int> b;
  vector<P> p;

  for(i = 1; i <= 316; ++i){
    n = i*i;
    f[n].pb(i);
    n += i;
    for(j = i+1; n <= 100000; ++j){
      f[n].pb(i);
      f[n].pb(j);
      n += i;
    }
  }
  for(i = 1; i <= 100000; ++i)
    std::sort(f[i].rbegin(), f[i].rend());

  N = getn(), K = getn();
  for(i = 0; i < N; ++i){
    a[i] = getn();
    q[a[i]].push(i);
  }

  for(i = 0; i < N; ++i){
    while(b.size() && a[b.back()] < a[i]){
      g[b.back()] = i;
      b.pop_back();
    }
    b.pb(i);
  }
  for(i = b.size()-1; i >= 0; --i)
    g[b[i]] = N;

  for(i = 0; i < N-1; ++i){
    q[a[i]].pop();
    if(a[i] < K)
      continue;
    m = N;
    if(a[i] == K){
      m = g[i];
    }else{
      for(j = 0; j < f[a[i]-K].size(); ++j){
  n = f[a[i]-K][j];
  if(n <= K)
    break;
  if(!q[n].empty() && q[n].front() < m)
    m = q[n].front();
      }
    }
    if(m == N)
      continue;
    while(!p.empty() && p.back().j >= m)
      p.pop_back();
    p.pb(P(i, m));
  }

  if(p.empty()){
    printf("%lld\n", ((ll)N*(N+1))>>1);
    return 0;
  }
  s = p[0].i, e = p[0].j;
  r = ((ll)e*(e+1))>>1;
  for(i = 1; i < p.size(); ++i){
    n = p[i].j - e;
    r += (((ll)n*(n+1))>>1) + (ll)n*(e-s-1);
    s = p[i].i, e = p[i].j;
  }
  n = N - e;
  r += (((ll)n*(n+1))>>1) + (ll)n*(e-s-1);
  printf("%lld\n", r);

  return 0;
}
