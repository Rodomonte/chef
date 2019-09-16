// CHEFCCYL

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int a){ return (a < 0) ? -a : a; }
int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

struct P {
  int l,r,x,y;
};
struct C {
  int s,x,y,cx,cy,dx,dy,ex,ey;
  vector<P> a;
};

C a[100000];
int main(){
  int T,N,Q,A,D,U,V,W,X, i,j, n,p,t,u,v;

  T = getn();
  while(T--){
    N = getn(), Q = getn();
    for(i = 0; i < N; ++i){
      A = getn(), a[i].s = 0, a[i].a.clear(), a[i].a.pb(P());
      for(j = 1; j < A; ++j)
        a[i].s += (D = getn()), a[i].a.back().r = D,
        a[i].a.pb(P()), a[i].a.back().l = D;
      a[i].s += (D = getn()), a[i].a.back().r = a[i].a[0].l = D;
    }
    for(i = 0; i < N; ++i){
      U = getn()-1, V = getn()-1, D = getn();
      a[i].x = U, a[(i+1)%N].y = V;
      a[i].ex = V, a[(i+1)%N].ey = U;
      a[i].dx = a[(i+1)%N].dy = D;
    }

    for(i = 0; i < N; ++i){
      n = 0, t = a[i].s;
      for(j = a[i].x; j < a[i].a.size(); ++j)
        a[i].a[j].x = min(n, t), n += a[i].a[j].r, t -= a[i].a[j].r;
      for(j = 0; j < a[i].x; ++j)
        a[i].a[j].x = min(n, t), n += a[i].a[j].r, t -= a[i].a[j].r;
      n = 0, t = a[i].s;
      for(j = a[i].y; j < a[i].a.size(); ++j)
        a[i].a[j].y = min(n, t), n += a[i].a[j].r, t -= a[i].a[j].r;
      for(j = 0; j < a[i].y; ++j)
        a[i].a[j].y = min(n, t), n += a[i].a[j].r, t -= a[i].a[j].r;
    }

    for(n = i = 0; i < N; ++i)
      a[i].cy = n, n += a[i].a[a[i].y].x,
      a[i].cx = n, n += a[i].dx, p = a[i].ex;

    while(Q--){
      U = getn()-1, V = getn()-1, W = getn()-1, X = getn()-1;
      p = a[V].a[U].x + a[X].a[W].x + min(abs(a[V].cx - a[X].cx),
            n - max(a[V].cx, a[X].cx) + min(a[V].cx, a[X].cx));
      t = a[V].a[U].x + a[X].a[W].y + min(abs(a[V].cx - a[X].cy),
            n - max(a[V].cx, a[X].cy) + min(a[V].cx, a[X].cy));
      u = a[V].a[U].y + a[X].a[W].x + min(abs(a[V].cy - a[X].cx),
            n - max(a[V].cy, a[X].cx) + min(a[V].cy, a[X].cx));
      v = a[V].a[U].y + a[X].a[W].y + min(abs(a[V].cy - a[X].cy),
            n - max(a[V].cy, a[X].cy) + min(a[V].cy, a[X].cy));
      // printf("aVUxy = %d %d, aXWxy = %d %d\n", a[V].a[U].x, a[V].a[U].y,
      //        a[X].a[W].x, a[X].a[W].y);
      // printf("aVcxy = %d %d, aXcxy = %d %d\n", a[V].cx, a[V].cy,
      //        a[X].cx, a[X].cy);
      // printf("ptuv = %d %d %d %d\n", p, t, u, v);
      printf("%d\n", min(min(min(p, t), u), v));
    }
  }
  return 0;
}
