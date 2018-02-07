// MATDW

#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

#define gc getchar_unlocked
#define pb push_back
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct D {
  int d,i,n;
};

int main(){
  int N,H,Q,R,W,C,P,O,I,X, i,j, c,n,r,w, dt,mc, h[10][4];
  double m,t,u,v;
  D d;
  vector<int> dn,dc;
  map<int,D> a;
  map<int,D>::iterator it;

  N = getn(), H = getn(), m = INF;
  for(i = 0; i < H; ++i){
    Q = h[i][0] = getn(), R = h[i][1] = getn();
    W = h[i][2] = getn(), C = h[i][3] = getn();
    t = (double)((R+W)*100 + Q) / C;
    if(t < m) m = t, c = C, dt = i;
  }
  P = getn();

  mc = r = w = 0;
  while(N--){
    if(r+w == 1000){
      ++r, ++w, u = (double)r / w, v = (double)w / r, m = INF;
      for(i = 0; i < H; ++i){
        t = ((u*h[i][1] + v*h[i][2])*100 + h[i][0]) / h[i][3];
        if(t < m) m = t, c = h[i][3], dt = i;
      }
    }

    for(n = i = 0; i < dn.size(); ++i) if(!dn[i]) ++n;
    if(dn.size() < 1050 && !n)
      printf("p b %d\n", dt), fflush(stdout), ++mc, dn.pb(0), dc.pb(c);

    printf("g\n"), fflush(stdout);
    O = getn(), I = getn();
    if(!O){
      X = getn(), n = INF, ++w;
      if(X > c){ printf("p s -1 -1\n"), fflush(stdout), ++mc; continue; }
      for(i = 0; i < dn.size(); ++i)
        if(dc[i] - dn[i] >= X && dc[i] - dn[i] < n)
          n = dc[i] - dn[i], j = i;
      if(n == INF){ printf("p s -1 -1\n"), fflush(stdout), ++mc; continue; }
      d.d = j, d.i = dn[j], dn[j] += X, d.n = X, a[I] = d;
      printf("p s %d %d\n", j, dn[j]-X), fflush(stdout), ++mc;

    }else if(O == 1){
      X = getn(), ++r;
      if(a.find(I) == a.end()) printf("p i -1 -1\n");
      else{
        d = a[I];
        if(d.d != -1) printf("p i %d %d\n", d.d, d.i+X);
        else printf("p i -1 -1\n");
      }
      fflush(stdout), ++mc;

    }else{
      dn[I] = 0;
      for(it = a.begin(); it != a.end(); ++it)
        if(it->second.d == I) it->second.d = -1;
    }
  }

  printf("end\n"), fflush(stdout);
  return 0;
}
