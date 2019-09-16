// POINPOLY

#include <stdio.h>
#include <math.h>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

#define ll long long
#define gc getchar
#define pb push_back
//#define PI2 6.283185307179586476925286766559005768394338798750211641949
#define ERR 0.0000000001
#define DIV 10

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

double dabs(double d){ return (d < 0) ? -d : d; }

struct P {
  int x,y;
  P(){}
  P(int x0, int y0): x(x0), y(y0) {}
  //P operator-(const P& p) const { return P(x-p.x, y-p.y); }
  ll hash(){ return ((ll)x << 32) | y; }
  //double vlen(){ return sqrt((double)x*x + (double)y*y); }
  //double vdp(P p){ return (double)x*p.x + (double)y*p.y; }
  //double vang(P p){ return acos(vdp(p) / (vlen()*p.vlen())); }
  char onseg(P p, P q){
    ll n,t;
    n = (ll)(y-p.y)*(q.x-p.x) - (ll)(x-p.x)*(q.y-p.y);
    if(n) return 0;
    n = (ll)(x-p.x)*(q.x-p.x) + (ll)(y-p.y)*(q.y-p.y);
    if(n < 0) return 0;
    t = (ll)(q.x-p.x)*(q.x-p.x) + (ll)(q.y-p.y)*(q.y-p.y);
    return n <= t;
  }
};

struct Tri {
  P a,b,c;
  Tri(P a0, P b0, P c0): a(a0), b(b0), c(c0) {}
  double area(){ return dabs(((ll)a.x*(b.y-c.y) + (ll)b.x*(c.y-a.y) +
                              (ll)c.x*(a.y-b.y)) / 2.0); }
  char contains(P p){
    // printf("%lf %lf %lf == %lf ?\n", Tri(p,a,b).area(), Tri(p,a,c).area(),
    //        Tri(p,b,c).area(), area());
    return !p.onseg(a, b) && !p.onseg(b, c) && !p.onseg(c, a) &&
           dabs(area() - (Tri(p,a,b).area() + Tri(p,a,c).area() +
                          Tri(p,b,c).area())) < ERR;
  }
};

int N;
P a[100000];
unordered_map<ll,P> r;

vector<P> adj(P p){
  vector<P> r;
  r.pb(P(p.x-1, p.y)), r.pb(P(p.x+1, p.y)), r.pb(P(p.x, p.y-1));
  r.pb(P(p.x, p.y+1)), r.pb(P(p.x+1, p.y+1)), r.pb(P(p.x+1, p.y-1));
  r.pb(P(p.x-1, p.y+1)), r.pb(P(p.x-1, p.y-1));
  return r;
}

void dfs(P p, Tri t){
  int i;
  vector<P> n = adj(p);
  if(r.size() >= N/DIV) return;
  for(i = 0; i < n.size(); ++i){
    //printf("  (%d,%d)\n", n[i].x, n[i].y);
    if(r.find(n[i].hash()) == r.end() && t.contains(n[i]))
      /*printf("  yes\n"),*/ r[n[i].hash()] = n[i], dfs(n[i], t);
  }
}

int main(){
  int T, i;
  unordered_map<ll,P>::iterator it;

  // !
  // Tri t(P(-1000000000,0), P(1000000000, 0), P(1000000000, 2));
  // printf("%d\n", t.contains(P(999999999, 1)));
  // Tri t(P(0,0), P(4,0), P(4,4));
  // printf("%d\n", t.contains(P(3,2)));
  // return 0;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i) a[i].x = getn(), a[i].y = getn();

    r.clear();
    if(N == 3){
      dfs(a[0], Tri(a[0], a[1], a[2]));
      dfs(a[1], Tri(a[0], a[1], a[2]));
      dfs(a[2], Tri(a[0], a[1], a[2]));
    }

    for(i = 1; i < N-2; ++i){
      dfs(a[0], Tri(a[0], a[i], a[i+2]));
      dfs(a[i], Tri(a[0], a[i], a[i+2]));
      dfs(a[i+2], Tri(a[0], a[i], a[i+2]));
      if(r.size() >= N/DIV) break;
    }

    //printf("|r|=%d\n", r.size());
    if(r.size() < N/DIV) printf("-1\n");
    else for(i = 0, it = r.begin(); i < N/DIV; ++i, ++it)
      printf("%d %d\n", it->second.x, it->second.y);
  }
  return 0;
}
