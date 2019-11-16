// DDART

#include <stdio.h>
#include <math.h>
#include <map>

#define ll long long
#define gc getchar_unlocked
#define map std::map
#define EP 0.00000001
#define MX 1000000

ll getl(){
  ll n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

double absd(double a){ return (a < 0.0) ? -a : a; }
bool eq0(double a){ return absd(a) < EP; }

struct P {
  double x,y;
  P(){}
  P(double _x, double _y): x(_x), y(_y) {}
  double dist(P& o){ return sqrt((x-o.x)*(x-o.x) + (y-o.y)*(y-o.y)); }
};

struct C {
  ll r2;
  double r;
  P c,i,j;
};

int circle_intersections(C& c0, C& c1, P& r0, P& r1){
  double d,e,f,r;
  P p;

  d = c0.c.dist(c1.c);
  if(eq0(d)) return (c0.r2 == c1.r2) ? -1 : 0;
  e = (d*d - c1.r2 + c0.r2) / d / 2.0;
  if(e - c0.r > EP) return 0;
  f = sqrt(absd(d*d*c0.r2*4.0 - (d*d-c1.r2+c0.r2)*(d*d-c1.r2+c0.r2))) / d;

  if(eq0(c1.c.x-c0.c.x)){ // vertical
    p.x = c0.c.x, p.y = c0.c.y + e * ((c1.c.y > c0.c.y) ? 1.0 : -1.0);
    if(eq0(f)){ r0 = p; return 1; }
    r0 = P(p.x - f / 2.0, p.y), r1 = P(p.x + f / 2.0, p.y);
    return 2;
  }

  if(eq0(c1.c.y-c0.c.y)){ // horizontal
    p.x = c0.c.x + e * ((c1.c.x > c0.c.x) ? 1.0 : -1.0), p.y = c0.c.y;
    printf("f=%lf\n", f);
    if(eq0(f)){ r0 = p; return 1; }
    r0 = P(p.x, p.y - f / 2.0), r1 = P(p.x, p.y + f / 2.0);
    return 2;
  }

  r = (c1.c.y-c0.c.y) / (c1.c.x-c0.c.x);
  p.y = c0.c.y + sqrt(d*d - r*(c1.c.x-c0.c.x))
               * ((c1.c.y > c0.c.y) ? 1.0 : -1.0);
  p.x = c0.c.x + (p.y - c0.c.y) / r;
  if(eq0(f)){ r0 = p; return 1; }

  r = 1.0 / r;
  d = sqrt(f*f / (4.0*(r*r+1)));
  if((c1.c.y-c0.c.y) / (c1.c.x-c0.c.x) > 0.0){ // SW <-> NE
    c0.i.x = c1.i.x = p.x - d;
    c0.i.y = c1.i.y = p.y + d*r;
    c0.j.x = c1.j.x = p.x + d;
    c0.j.y = c1.j.y = p.y - d*r;

  }else{ // NW <-> SE
    c0.i.x = c1.i.x = p.x + d;
    c0.i.y = c1.i.y = p.y + d*r;
    c0.j.x = c1.j.x = p.x - d;
    c0.j.y = c1.j.y = p.x - d*r;
  }
  return 2;
}

int b[MX], n;
C a[MX];
int main(){
  char d,g;
  int Q,O,X,Y, i, pn;
  P p,q;

  Q = getl(), d = -1, g = 1, pn = 0;
  for(i = 0; i < Q; ++i)
    b[i] = -1;
  while(Q--){
    O = getl();
    if(d == 1) Y = getl(), X = getl();
    else X = getl(), Y = getl();
    if(O == 1){
      C& c(a[n]);
      c.c.x = X, c.c.y = Y, c.r = sqrt(c.r2 = getl()), ++n;

      if(n == 1 || !g) continue;
      if(n == 2) pn = circle_intersections(a[0], a[1], p, q);
      else if(!eq0(c.c.dist(p) - c.r)) p = q, pn = 1;
      else if(pn == 2 && !eq0(c.c.dist(q) - c.r)) pn = 1;

      // find 1-3 intersections of c with b
      // if 1, g = 0
      // if 2, new segment at an end of b
      // if 3, new segment in middle of b

    }else{
      X = getl(), Y = getl();

      if(!g){
        printf("%d\n", d = (eq0(p.x - X) && eq0(p.y - Y)) ? 1 : 0); continue; }
      //! g == 1: X,Y in shape?

      printf("%d\n", d);
    }
  }
  return 0;
}
