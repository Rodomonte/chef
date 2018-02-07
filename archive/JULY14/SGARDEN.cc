// SGARDEN

#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
using std::vector;
using std::map;

#define gc getchar_unlocked
#define pb push_back
#define ll long long
#define MAX 100001
#define MOD 1000000007

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[MAX];
vector<int> b[MAX];
char v[MAX]={0};
int main(){
  int T,N, i,j,k,n,p,t;
  ll r;
  map<int,int> c;
  map<int,int>::iterator it;
  for(i = 2; i < MAX; i++){
    if(v[i]) continue;
    b[i].pb(i);
    for(j = i+i; j < MAX; j += i)
      b[j].pb(i), v[j] = 1;
  }
  T = getn();
  while(T--){
    N = getn(), r = 1;
    c.clear();
    memset(v, 0, N+1);
    for(i = 1; i <= N; i++)
      a[i] = getn();
    for(i = 1; i <= N; i++){
      if(v[i])
        continue;
      j = a[i], n = 1, v[i] = 1;
      while(!v[j]){
        n++;
        v[j] = 1;
        j = a[j];
      }
      t = n;
      for(j = 0; j < b[n].size(); j++){
        k = 0, p = b[n][j];
        while(t && t%p==0)
          t /= p, k++;
        if(c.find(p) == c.end() || c[p] < k)
          c[p] = k;
      }
    }
    for(it = c.begin(); it != c.end(); it++){
      n = it->second;
      for(j = 0; j < n; j++){
        r *= it->first;
        if(r >= MOD)
          r %= MOD;
      }
    }
    printf("%lld\n",r);
  }
  return 0;
}
