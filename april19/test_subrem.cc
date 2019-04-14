// SUBREM TEST

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>

using std::set;
using std::map;

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P {
  bool x;
  int p,v;
  set<int> n;
} a[100001];
int X;

ll dfs(int i, int p){
  ll n,t;
  set<int>::iterator it;
  a[i].p = p, n = a[i].v;
  for(it = a[i].n.begin(); it != a[i].n.end(); ++it){
    if(*it == p) continue;
    t = dfs(*it, i);
    if(t > -X) n += t;
  }
  if(n <= -X) a[i].x = true;
  return n;
}

ll dfs2(int i){
  if(a[i].x) return -X;
  ll r;
  set<int>::iterator it;
  r = a[i].v;
  for(it = a[i].n.begin(); it != a[i].n.end(); ++it){
    if(*it == a[i].p) continue;
    r += dfs2(*it);
  }
  return r;
}

ll max(ll a, ll b){ return (a > b) ? a : b; }

ll dfs3(int i){
  ll r,t;
  set<int>::iterator it;
  r = a[i].v;
  for(it = a[i].n.begin(); it != a[i].n.end(); ++it){
    if(*it == a[i].p) continue;
    r += max(-X, dfs3(*it));
  }
  return max(-X, r);
}

int main(){
  int T,N,U,V, i,j;
  ll r,r2;

  T = 0;
  while(++T){
    N = 100000, X = rand() % 1000000000 + 1;
    for(i = 1; i <= N; ++i)
      a[i].v = rand() % 1000000001 - 1000000000, a[i].n.clear(), a[i].x = false;
    for(i = 2; i <= N; ++i){
      j = rand() % (i-1) + 1;
      a[i].n.insert(j), a[j].n.insert(i);
    }

    dfs(1, -1);
    r = dfs2(1);

    r2 = dfs3(1);
    printf("%lld -- %lld\n", r, r2);
    if(r != r2) gc();
  }
  return 0;
}
