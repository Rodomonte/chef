// SEAWCU

#include <stdio.h>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

#define pb push_back
#define gc getchar_unlocked
#define INF 2000000000

inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}
int min(int a, int b){
  return (a < b) ? a : b;
}
int max(int a, int b){
  return (a > b) ? a : b;
}

struct P {
  int x,y,z;
  P(){}
  P(int x0, int y0, int z0): x(x0),y(y0),z(z0) {}
};
struct Q {
  int d;
  P p;
  Q(int d0, const P& p0): d(d0),p(p0) {}
};

int N;
vector<P> nbrs(const P& p){
  vector<P> r;
  if(p.z > 0) r.pb(P(p.x, p.y, p.z-1));
  if(p.y > 0) r.pb(P(p.x, p.y-1, p.z));
  if(p.x > 0) r.pb(P(p.x-1, p.y, p.z));
  if(p.z < N-1) r.pb(P(p.x, p.y, p.z+1));
  if(p.y < N-1) r.pb(P(p.x, p.y+1, p.z));
  if(p.x < N-1) r.pb(P(p.x+1, p.y, p.z));
  return r;
}

const int D = 8;
char b[50][50][50], v[50][50][50];
int dc(const P& p){ // O(D^3)
  int i,x,y,z,m;
  vector<P> n;
  queue<Q> q;
  if(b[p.z][p.y][p.x])
    return 0;
  for(z = max(0, p.z-D); z < min(N, p.z+D+1); ++z)
    for(y = max(0, p.y-D); y < min(N, p.y+D+1); ++y)
      for(x = max(0, p.x-D); x < min(N, p.x+D+1); ++x)
        v[z][y][x] = 0;
  q.push(Q(0, p)), v[p.z][p.y][p.x] = 1, m = 0;
  while(!q.empty() && m < D){
    n = nbrs(q.front().p);
    for(i = 0; i < n.size(); ++i)
      if(!b[n[i].z][n[i].y][n[i].x] && !v[n[i].z][n[i].y][n[i].x])
        q.push(Q(q.front().d+1, n[i])), v[n[i].z][n[i].y][n[i].x] = 1,
        m = max(m, q.front().d+1);
    q.pop();
  }
  return m;
}

int a[50][50][50];
P next(const P& p){
  int i,k,d,s,t,md,ms;
  P tp,mp(-1,-1,-1);
  vector<P> n;
  md = 0, ms = -INF;
  if(p.z > 0){
    tp = P(p.x, p.y, p.z-1), n = nbrs(tp), k = 0;
    for(i = 0; i < n.size(); ++i)
      if(b[n[i].z][n[i].y][n[i].x])
        ++k;
    if(k == 1){
      d = dc(tp), t = a[p.z-1][p.y][p.x], s = (t > 0) ? t*1000 : t/1000;
      if(d > md || (d == md && s > ms))
        md = d, ms = s, mp = tp;
    }
  }
  if(p.y > 0){
    tp = P(p.x, p.y-1, p.z), n = nbrs(tp), k = 0;
    for(i = 0; i < n.size(); ++i)
      if(b[n[i].z][n[i].y][n[i].x])
        ++k;
    if(k == 1){
      d = dc(tp), t = a[p.z][p.y-1][p.x], s = (t > 0) ? t*250 : t/250;
      if(d > md || (d == md && s > ms))
        md = d, ms = s, mp = tp;
    }
  }
  if(p.x > 0){
    tp = P(p.x-1, p.y, p.z), n = nbrs(tp), k = 0;
    for(i = 0; i < n.size(); ++i)
      if(b[n[i].z][n[i].y][n[i].x])
        ++k;
    if(k == 1){
      d = dc(tp), t = a[p.z][p.y][p.x-1];
      s = (t > 0) ? t*60 : t/60;
      if(d > md || (d == md && s > ms))
        md = d, ms = s, mp = tp;
    }
  }

  if(p.x < N-1){
    tp = P(p.x+1, p.y, p.z), n = nbrs(tp), k = 0;
    for(i = 0; i < n.size(); ++i)
      if(b[n[i].z][n[i].y][n[i].x])
        ++k;
    if(k == 1){
      d = dc(tp), t = a[p.z][p.y][p.x+1];
      s = (t > 0) ? t*15 : t/15;
      if(d > md || (d == md && s > ms))
        md = d, ms = s, mp = tp;
    }
  }
  if(p.y < N-1){
    tp = P(p.x, p.y+1, p.z), n = nbrs(tp), k = 0;
    for(i = 0; i < n.size(); ++i)
      if(b[n[i].z][n[i].y][n[i].x])
        ++k;
    if(k == 1){
      d = dc(tp), t = a[p.z][p.y+1][p.x];
      s = (t > 0) ? t*4 : t/4;
      if(d > md || (d == md && s > ms))
        md = d, ms = s, mp = tp;
    }
  }
  if(p.z < N-1){
    tp = P(p.x, p.y, p.z+1), n = nbrs(tp), k = 0;
    for(i = 0; i < n.size(); ++i)
      if(b[n[i].z][n[i].y][n[i].x])
        ++k;
    if(k == 1){
      d = dc(tp), s = a[p.z+1][p.y][p.x];
      if(d > md || (d == md && s > ms))
        md = d, ms = s, mp = tp;
    }
  }
  if(!md)
    mp.x = -1;
  return mp;
}

int main(){
  int T, i,x,y,z;
  P p;
  vector<P> r;
  T = getn();
  while(T--){
    N = getn(), r.clear();
    for(z = 0; z < N; ++z)
      for(y = 0; y < N; ++y)
        for(x = 0; x < N; ++x)
          a[z][y][x] = getn(), b[z][y][x] = 0;
    p = P(0,0,0);
    while(p.x != -1){
      r.pb(p);
      b[p.z][p.y][p.x] = 1;
      p = next(p);
    }
    printf("%d\n", r.size());
    for(i = 0; i < r.size(); ++i)
      printf("%d %d %d\n", r[i].x+1, r[i].y+1, r[i].z+1);
  }
  return 0;
}
