// CHEFDIV

#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

#define ll long long
#define gc getchar_unlocked
#define pb push_back
#define MAX 1000000

inline ll getn(){
  ll n = 0; char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char sv[MAX+1]={0};
vector<int> a[100001];
int main(){
  int i,j,k,m;
  ll A,B, n,r,t;
  vector<int> p;
  map<ll,int> f;
  map<ll,int>::iterator it,it2;

  for(i = 2; i <= MAX; ++i){
    if(sv[i])
      continue;
    for(j = i+i; j <= MAX; j += i)
      sv[j] = 1;
    p.pb(i);
  }

  A = getn(), B = getn();
  for(i = 0; i < p.size(); ++i){
    if(p[i] > B)
      break;
    j = (int)(ceil((double)A / (double)p[i]) * p[i] - A);
    for(; j <= B-A; j += p[i])
      a[j].pb(p[i]);
  }

  r = 0;
  for(n = A; n <= B; ++n){
    t = n, f.clear();
    for(i = 0; i < a[n-A].size(); ++i){
      k = a[n-A][i];
      while(!(t % k)){
        it = f.find(k);
        if(it == f.end())
          f[k] = 1;
        else
          ++it->second;
        t /= k;
      }
    }
    if(t > 1)
      f[t] = 1;

    while(!f.empty()){
      m = 0, t = 1;
      for(it = f.begin(); it != f.end(); ++it){
        t *= it->second + 1;
        if(it->second > m)
          m = it->second, it2 = it;
      }
      r += t;
      --it2->second;
      if(!it2->second)
        f.erase(it2);
    }
  }

  printf("%lld\n", r);
  return 0;
}
