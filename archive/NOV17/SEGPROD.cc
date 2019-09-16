// SEGPROD

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

int madd(int a, int b, int m){ return ((a += b) >= m) ? a-m : a; }
int mmul(int a, int b, int m){ return (ll)a * b % m; }

int N,P, a[1000000], b[312502], d[1000000], h[1000001];
vector<vector<int> > c[20];
vector<int> e[20], g[20];

void init(int i, int l, int r, int pi, int pj){
  int j, m;
  vector<int> n,v,w;
  if(r-l+1 < 2) return;
  m = l+((r-l+1)>>1), d[m] = 1;
  for(j = m+1; j <= r; ++j) d[j] = mmul(d[j-1], a[j], P);
  for(j = m-1; j >= l; --j) d[j] = mmul(d[j+1], a[j], P);
  d[m] = a[m];
  for(j = l; j <= r; ++j) n.pb(d[j]);
  c[i].pb(n), e[i].pb(l), g[i].pb(m);
  v.pb(-1), v.pb(i), v.pb(c[i].size()-1);
  init(i+1, l, m-1, i, c[i].size()-1);
  c[i+1].pb(v), e[i+1].pb(m), g[i+1].pb(-1);
  init(i+1, m+1, r, pi, pj);
  if(pi != -1)
    w.pb(-1), w.pb(pi), w.pb(pj), c[i+1].pb(w), e[i+1].pb(r+1), g[i+1].pb(-1);
}

int query(int l, int r){
  int i,j,jl,jr,kl,km,kr, f,t,rr;
  if(r-l+1 < 4){
    for(i = l, j = 1; i <= r; ++i) j = mmul(j, a[i], P); return j; }

  i = h[r-l+1];
  jl = 2 * l / (N / (1<<i)), jr = 2 * r / (N / (1<<i));
  while(jl >= e[i].size() || l < e[i][jl]) --jl;
  while(jl < 0 || (jl < e[i].size()-1 && l >= e[i][jl+1])) ++jl;
  while(jr >= e[i].size() || r < e[i][jr]) --jr;
  while(jr < 0 || (jr < e[i].size()-1 && r >= e[i][jr+1])) ++jr;

  if(jr-jl == 2) j = jr-1;
  else if(jr-jl == 1 && c[i][jl][0] == -1) j = jl;
  else if(jr-jl == 1 && c[i][jr][0] == -1) j = jr;
  else j = jl;

  if(c[i][j][0] == -1) t = i, i = c[t][j][1], j = c[t][j][2];
  kl = l - e[i][j], km = g[i][j] - e[i][j], kr = r - e[i][j];
  rr = c[i][j][km];
  if(kl < km) rr = mmul(rr, c[i][j][kl], P);
  if(kr > km) rr = mmul(rr, c[i][j][kr], P);
  return rr;
}

int main(){
  int T,Q, i,j,k, l,q,r,t,x;

  T = getn();
  while(T--){
    N = getn(), P = getn(), Q = getn(), q = Q/64+2;
    for(i = 0; i < N; ++i) a[i] = getn();
    for(i = 0; i < q; ++i) b[i] = getn();

    for(i = N, t = 1; i > 0; --i){ if(i == N/(1<<t)) ++t; h[i] = t-1; }
    for(i = 0; i < 20; ++i) c[i].clear(), e[i].clear(), g[i].clear();
    init(0, 0, N-1, -1, -1);

    for(q = x = 0; q < Q; ++q){
      t = x % N;
      if(qd) l = madd(l, t, N), r = madd(r, t, N);
      else l = madd(b[q/64], t, N), r = madd(b[q/64+1], t, N);
      if(l > r) t = l, l = r, r = t;
      x = madd(query(l, r), 1, P);
    }
    printf("%d\n", x%P);
  }
  return 0;
}
