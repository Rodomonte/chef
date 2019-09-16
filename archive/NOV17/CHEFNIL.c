// CHEFNIL 3

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

typedef struct { int i,j; } P ;
typedef struct { P a,b; } S ;

double dist(P a, P b){ return sqrt((a.i-b.i)*(a.i-b.i) + (a.j-b.j)*(a.j-b.j)); }
char onseg(P a, P b, P c){
  return (b.i <= max(a.i, c.i) && b.i >= min(a.i, c.i) &&
          b.j <= max(a.j, c.j) && b.j >= min(a.j, c.j)) ? 1 : 0;
}
char orient(P a, P b, P c){
  int t = (b.j - a.j) * (c.i - b.i) - (b.i - a.i) * (c.j - b.j);
  return t ? ((t > 0) ? 1 : 2) : 0;
}
char intersect(S a, S b){
  char o1,o2,o3,o4;
  o1 = orient(a.a, a.b, b.a), o2 = orient(a.a, a.b, b.b);
  o3 = orient(b.a, b.b, a.a), o4 = orient(b.a, b.b, a.b);
  return ((o1 != o2 && o3 != o4) || (!o1 && onseg(a.a, b.a, a.b)) ||
          (!o2 && onseg(a.a, b.b, a.b)) || (!o3 && onseg(b.a, a.a, b.b)) ||
          (!o4 && onseg(b.a, a.b, b.b))) ? 1 : 0;
}

int N, a[500][50][50];
S b[100][500];

P move(int bi, int k){
  int i,j,l, f;
  double d,m,t;
  P p,q;
  S s;
  p.i = p.j = -2, m = 0;
  for(i = 0; i < N; ++i){ for(j = 0; j < N; ++j){
    q.i = i, q.j = j;
    for(l = 0, f = 1; l < k-1; ++l){
      s.a = b[bi][k-1].b, s.b = q;
      if(intersect(s, b[bi][l])){ f = 0; break; }
    }
    if(!orient(b[bi][k-1].a, q, b[bi][k-1].b) &&
       onseg(b[bi][k-1].a, q, b[bi][k-1].b)) f = 0;
    if(!f) continue;
    for(l = d = 0; l < k; ++l)
      d += dist(b[bi][l].b, q);// * dist(b[bi][l].b, q);
    t = (double)a[k][i][j] / d;
    if(t > m) m = t, p = q;
  }}
  return p;
}

int main(){
  int M, i,j,k,l,ii,jj,im,jm,mi, s,ms;
  P m,p;
  S t;

  N = getn(), M = getn();
  for(k = 0; k < M; ++k) for(i = 0; i < N; ++i) for(j = 0; j < N; ++j)
    a[k][i][j] = getn();

  for(i = l = ms = 0; i < N; i += 6){ for(j = 0; j < N; j += 6, ++l){
    for(ii = i, s = 0; ii < N && ii < i+6; ++ii)
      for(jj = j; jj < N && jj < j+6; ++jj)
        if(a[0][ii][jj] > s) s = a[0][ii][jj], im = ii, jm = jj;
    s = a[0][im][jm], p.i = im, p.j = jm, t.a = t.b = p, b[l][0] = t;
    for(k = 1; k < M; ++k){
      m = move(l, k), s += a[k][m.i][m.j];
      t.a = b[l][k-1].b, t.b = m, b[l][k] = t;
      if(m.i == -2) break;
    }
    if(s > ms) ms = s, mi = l;
  }}

  for(k = 0; k < M; ++k){
    printf("%d %d\n", b[mi][k].b.i+1, b[mi][k].b.j+1);
    if(b[mi][k].b.i == -2) break;
  }
  return 0;
}
