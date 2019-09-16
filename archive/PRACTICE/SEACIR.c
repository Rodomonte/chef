// SEACIR

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define gc getchar_unlocked
#define INF 2000000000
#define RN 1000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

double dist(double x1, double y1, double x2, double y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int a[400], b[200][3];
int main(){
  int N,S,K,R, i,j,k, s,x,y, bn,mx,my;
  double m,t, m2;

  N = getn(), S = getn(), K = getn();
  for(i = 0; i < N*2; ++i)
    a[i] = getn();

  sort(a, N*2);
  s = a[N*2-K*2], bn = 0;
  for(i = 0; i < N; ++i){
    R = getn();
    if(K && R >= s){
      printf("-1 -1\n"), fflush(stdout), --K;
      continue;
    }

    m = -INF;
    for(j = 0; j < RN; ++j){
      x = rand()%(S-R*2)+R, y = rand()%(S-R*2)+R, m2 = INF;
      for(k = 0; k < bn; ++k){
        t = dist(x, y, b[k][1], b[k][2]) - R - b[k][0];
        if(t < m2) m2 = t;
      }
      if(m2 > m) m = m2, mx = x, my = y;
    }

    b[bn][0] = R, b[bn][1] = mx, b[bn][2] = my, ++bn;
    printf("%d %d\n", mx, my), fflush(stdout);
  }

  return 0;
}
