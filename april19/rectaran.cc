// RECTARAN

#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int n){ return (n < 0) ? -n : n; }

struct P {
  int x,y;
  P(int _x, int _y): x(_x), y(_y) {}
  P(P o): x(o.x), y(o.y) {}
  int dist(){ return abs(x) + abs(y); }
};

struct R {
  int w,h,d;
  P p;
  vector<P> c; // x=time y={-1=left, 0=back, 1=right}
  P eval(){
    int i,x,y,e,t;
    x = p.x, y = p.y, e = d, t = 0;
    c.pb(P(N, 0));
    for(i = 0; i < c.size(); ++i){
      if(!e)          y += c[i].x - t, e = ((!n) ? 2 : ((n == -1) ? 3 : 1));
      else if(e == 1) x += c[i].x - t, e = ((!n) ? 3 : ((n == -1) ? 0 : 2));
      else if(e == 2) y -= c[i].x - t, e = ((!n) ? 0 : ((n == -1) ? 1 : 3));
      else            x -= c[i].x - t, e = ((!n) ? 1 : ((n == -1) ? 2 : 0));
      t = c[i].x;
    }
    c.pop_back();
    return P(x, y);
  }
};

int N;
R a[1001];
map<int, int> m;

int rev(){
  int i,t;
  map<int, int>::iterator it;
  it = m.end(), --it, i = it->second, m.erase(it);
  if(
  printf("%d %d\n", i, t);
  m[a[i].eval().dist()] = i;
  return i;
}

int rot(){
  int i;
  map<int, int>::iterator it;
  it = m.end(), --it, i = it->second;

  return i;
}

int main(){
  char C[8];
  int T,Q, i;
  P p;

  T = getn();
  while(T--){
    Q = N = getn();
    for(i = 1; i <= N; ++i)
      a[i].p.x = getn(), a[i].p.y = getn(), a[i].w = getn(), a[i].h = getn(),
      a[i].d = getn();

    while(Q--){
      scanf("%s", C);
      i = (C[1] == 'E') ? rev() : rot();
      fflush(stdout);
    }
  }
  return 0;
}
