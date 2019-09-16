// BYTEFOOD

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int n){ return (n < 0) ? -n : n; }
int min(int a, int b){ return (a < b) ? a : b; }

typedef struct {
  char v;
  int x,y,a,b,c;
} P;

P a[1000];
int r[1000][2];
int main(){
  int T,N,M,P,Q, i,j,k,ti, d,m,t,x,y, rn;

  T = getn();
  for(ti = 1; ti <= T; ++ti){
    N = getn(), M = getn(), rn = 0;
    for(i = 0; i < N; ++i)
      a[i].x = getn(), a[i].y = getn(), a[i].a = getn(),
      a[i].b = getn(), a[i].c = getn(), a[i].v = 0;
    x = P = getn(), y = Q = getn();

    while(1){
      for(m = i = 0; i < N; ++i){
        if(a[i].v || !a[i].b) continue;
        d = abs(x-a[i].x) + abs(y-a[i].y);
        t = min(a[i].b * a[i].c, a[i].a - (a[i].b * d));
        if(d + abs(a[i].x-P) + abs(a[i].y-Q) + t/a[i].b > M) continue;
        if(t > m) m = t, j = i, k = t/a[i].b;
      }
      if(!m) break;
      M -= (t = abs(x-a[j].x) + abs(y-a[j].y) + k);
      x = a[j].x, y = a[j].y, a[j].v = 1, r[rn][0] = j, r[rn][1] = k, ++rn;
      for(i = 0; i < N; ++i)
        a[i].a -= a[i].b * t;
    }

    printf("%d\n", ti);
    for(i = 0; i < rn; ++i)
      printf("%d %d\n", r[i][0]+1, r[i][1]);
    printf("0 0\n");
  }
  return 0;
}
