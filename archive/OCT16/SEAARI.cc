// SEAARI

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define vec std::vector
#define pb push_back
#define gc getchar_unlocked
#define INF 2000000000

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int min(int a, int b){
  return (a < b) ? a : b;
}
int max(int a, int b){
  return (a > b) ? a : b;
}
int abs(int d){
  return (d < 0) ? -d : d;
}

struct P {
  bool v;
  int x,y,d;
  P(int x0, int y0): x(x0), y(y0), v(false) {}
};
bool cmp(const P& a, const P& b){
  return abs(a.d) > abs(b.d);
}
struct R {
  int t,i,j;
  R(int t0, int i0, int j0): t(t0), i(i0), j(j0) {}
};

vec<P> a,s;
vec<R> r;
int main(){
  int N,K,D, i,j,k,x,y,xy,x2,m,b,d,n,t,u;

  N = getn(), K = getn(), D = getn();
  n = max(10000000/N,(int)round(sqrt(N))), x = y = xy = x2 = u = 0;
  for(i = 0; i < N; ++i){
    P p(i, getn());
    a.pb(p), s.pb(p), x += i, y += p.y, xy += i*p.y, x2 += i*i;
  }
  m = (int)round((double)(N*xy - x*y) / (N*x2 - x*x));
  b = (int)round((double)(y*x2 - x*xy) / (N*x2 - x*x));
  for(i = 0; i < N; ++i)
    s[i].d = s[i].y - (m*i+b);

  std::sort(s.begin(), s.end(), cmp);
  for(i = 0; i < N && u < K; ++i){
    if(a[s[i].x].v) continue;
    x = (int)round((double)(s[i].y - b) / m), d = INF;
    for(j = max(0,x-(n>>1)-1); j < min(N,x+(n>>1)+1); ++j){
      if(a[j].v || j == s[i].x) continue;
      t = abs(s[i].y-(m*j+b)) + abs(a[j].y-(m*s[i].x+b));
      if(t < d)
        d = t, k = j;
    }
    if(d == INF || d >= s[i].d+a[k].d) continue;
    a[s[i].x].v = a[k].v = true, ++u;
    r.pb(R(1, s[i].x+1, k+1));
  }

  for(i = 0; i < min(D,N); ++i)
    r.pb(R(2, N-i, -1));

  printf("%d %d\n", b, m);
  for(i = 0; i < r.size(); ++i)
    if(r[i].t == 1)
      printf("1 %d %d\n", r[i].i, r[i].j);
    else
      printf("2 %d\n", r[i].i);
  printf("-1\n");

  return 0;
}
