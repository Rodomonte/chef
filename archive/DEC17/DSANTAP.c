// DSANTAP

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked
#define PI 3.14159265358979323846264338327950288
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

void assert(char c){ if(!c) ++c, c /= 0; }

typedef struct { int x,y,h,n, d,s, g[51]; double a; } P ;
typedef struct { int s,d; } Q ;

double dist(P* a, P* b){
  return sqrt((a->x-b->x)*(a->x-b->x) + (a->y-b->y)*(a->y-b->y));
}

const double PID2 = PI / 2.0, PI3D2 = PI * 3.0 / 2.0, PI2 = PI * 2.0;
double ang(P* a, P* b){
  if(a->x == b->x) return (a->y > b->y) ? PID2 : PI3D2;
  if(a->y == b->y) return (a->x < b->x) ? 0.001 : PI;
  if(a->x < b->x){
    if(a->y < b->y) return PI2 + atan((double)(a->y-b->y) / (b->x-a->x));
    else return atan((double)(a->y-b->y) / (b->x-a->x));
  }else if(a->y < b->y) return PI + atan((double)(a->y-b->y) / (b->x-a->x));
  return PI + atan((double)(a->y-b->y) / (b->x-a->x));
}

void sort(Q* a, int n, char lt(Q, Q)){
  if(n < 2) return;
  Q p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(lt(*l, p)){ l++; continue; }
    if(lt(p, *r)){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1, lt);
  sort(l, a+n-l, lt);
}

char f[501];
int G,B, v[51], e[500],en, qn;
double d[501][501]={{0}};
P a[501];
Q q[250000];

char lt(Q i, Q j){ return d[i.s][i.d] < d[j.s][j.d]; }

char good(int i, int s){
  int s0 = s;
  if(s > B) return 0;
  s -= v[a[i].n];
  if(a[i].d == -1 || a[i].h != a[a[i].d].n) s += v[a[i].h];
  if(s > B) return 0;
  while((i = a[i].d) != -1){
    if(a[i].n == a[a[i].s].h && s + v[a[i].n] > B) return 0;
    if(a[i].n != a[a[i].s].h) s -= v[a[i].n];
    if(a[i].d == -1 || a[i].h != a[a[i].d].n) s += v[a[i].h];
    if(s > B) return 0;
  }
  return 1;
}

char cycle(int i, int j){
  while(1){
    i = a[i].d;
    if(i == -1) return 0;
    if(i == j) return 1;
  }
}

int main(){
  int T,N, i,j,k,ii, s;
  double m;

  T = getn();
  while(T--){
    N = getn(), G = getn(), B = getn();
    a[0].x = getn(), a[0].y = getn(), a[0].h = a[0].n = -1;
    for(i = 1; i <= G; ++i) v[i] = getn();
    for(i = 1; i <= N; ++i){
      a[i].x = getn(), a[i].y = getn(), a[i].h = getn(), a[i].n = getn();
      a[i].d = a[i].s = -1, a[i].a = ang(a+i, a), f[i] = 0;
      for(j = 1; j <= 50; ++j) a[i].g[j] = 0;
    }

    // Link best source
    for(i = 0; i < N; ++i) for(j = i+1; j <= N; ++j)
      d[i][j] = d[j][i] = dist(&a[i], &a[j]);
    for(i = 1, qn = 0; i <= N; ++i) for(j = 1; j <= N; ++j)
      if(i != j && a[i].h == a[j].n &&
         d[i][j]*3 < d[i][0] && d[i][j]*3 < d[j][0])
        q[qn].s = i, q[qn++].d = j;
    sort(q, qn, lt);
    for(i = 0; i < qn; ++i)
      if(a[q[i].s].d == -1 && a[q[i].d].s == -1 && !cycle(q[i].d, q[i].s))
        a[q[i].s].d = q[i].d, a[q[i].d].s = q[i].s;

    // Connect remaining
    while(1){
      for(i = 1, m = INF; i <= N; ++i) if(a[i].s == -1 && d[i][0] < m)
        m = d[i][0], k = i;
      if(m == INF) break;

      a[k].s = s = 0, ii = k;
      while(1){
        s += v[a[k].n], ++a[ii].g[a[k].n];
        while(a[k].d != -1) k = a[k].d;
        for(i = 1, m = INF; i <= N; ++i){
          if(i != k && a[i].s == -1 && a[i].n != a[k].h && d[i][k] < m &&
             d[i][k] < d[k][0] && d[i][k] < d[i][0]){
            a[k].d = i;
            if(good(ii, s + v[a[i].n])) m = d[i][k], j = i;
            a[k].d = -1;
          }
        }

        if(m == INF) break;
        a[k].d = j, a[j].s = k, k = j;
      }
      a[k].d = 0;
    }

    // Write commands
    for(i = 1; i <= N; ++i){
      if(a[i].s) continue;
      for(j = 1, s = 0; j <= 50; ++j) for(k = 0; k < a[i].g[j]; ++k)
        printf("2 %d\n", j), s += v[j];
      assert(s <= B);

      j = i, en = 0;
      while(j){
        printf("1 %d\n3 %d\n", j, a[j].n), s -= v[a[j].n], ++f[j];
        assert(s >= 0);
        printf("2 %d\n", a[j].h), s += v[a[j].h];
        if(a[j].h != a[a[j].d].n) e[en++] = a[j].h;
        assert(s <= B);
        j = a[j].d;
      }
      printf("1 0\n");
      for(j = 0; j < en; ++j) printf("3 %d\n", e[j]), s -= v[e[j]];
      assert(!s);
    }
    for(i = 1; i <= N; ++i) assert(f[i] == 1);
    printf("0\n");
  }
  return 0;
}
