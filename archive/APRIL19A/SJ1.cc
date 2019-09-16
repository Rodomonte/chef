// SJ1

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

ll getl(){
  char c = gc(), f = 1;
  ll n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

ll gcd(ll a, ll b){
  return b ? gcd(b,a%b) : a;
}

struct P {
  int p;
  ll v,m,r;
  vector<int> n;
};

P a[100001];
vector<int> p;

void dfsp(int i, int p){
  int j;
  a[i].p = p;
  for(j = 0; j < a[i].n.size(); ++j)
    if(a[i].n[j] != p) dfsp(a[i].n[j], i);
}

void dfs(int i, ll g){
  int j;
  p.pb(i);
  g = gcd(g, a[i].v);
  for(j = 0; j < a[i].n.size(); ++j){
    if(a[i].n[j] == a[i].p) continue;
    dfs(a[i].n[j], g);
  }
  if(i != 1 && a[i].n.size() == 1)
    a[i].r = a[i].m - gcd(g, a[i].m);
  p.pop_back();
}

int main(){
  int T,N,X,Y, i;

  T = getn();
  while(T--){
    N = getn();
    for(i = 1; i <= N; ++i) a[i].n.clear();
    for(i = 0; i < N-1; ++i) X = getn(), Y = getn(), a[X].n.pb(Y), a[Y].n.pb(X);
    for(i = 1; i <= N; ++i) a[i].v = getl();
    for(i = 1; i <= N; ++i) a[i].m = getl();

    dfsp(1, -1);
    dfs(1, a[1].v);
    for(i = 2; i <= N; ++i)
      if(a[i].n.size() == 1) printf("%lld ", a[i].r);
    printf("\n");
  }
  return 0;
}
