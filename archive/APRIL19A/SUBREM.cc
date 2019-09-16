// SUBREM

#include <stdio.h>
#include <vector>

using std::vector;

#define ll long long
#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

ll max(ll a, ll b){ return (a > b) ? a : b; }

struct P {
  int p,v;
  vector<int> n;
} a[100001];
int X;

void dfsp(int i, int p){
  int j;
  a[i].p = p;
  for(j = 0; j < a[i].n.size(); ++j)
    if(a[i].n[j] != p) dfsp(a[i].n[j], i);
}

ll dfs(int i){
  ll j,r,t;
  r = a[i].v;
  for(j = 0; j < a[i].n.size(); ++j){
    if(a[i].n[j] == a[i].p) continue;
    r += max(-X, dfs(a[i].n[j]));
  }
  return max(-X, r);
}

int main(){
  int T,N,U,V, i;
  T = getn();
  while(T--){
    N = getn(), X = getn();
    for(i = 1; i <= N; ++i) a[i].v = getn(), a[i].n.clear();
    for(i = 0; i < N-1; ++i)
      U = getn(), V = getn(), a[U].n.pb(V), a[V].n.pb(U);
    dfsp(1, -1);
    printf("%lld\n", dfs(1));
  }
  return 0;
}
