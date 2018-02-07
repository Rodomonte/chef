// COLARR

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

typedef struct {
  int o,p;
} A ;
void setA(A* d, A* s){
  d->o = s->o, d->p = s->p;
}
void sortA(A* a, int n){
  if(n < 2) return;
  int p = a[n/2].p;
  A *l = a, *r = a+n-1, t;
  while(l <= r){
    if(l->p > p){ l++; continue; }
    if(r->p < p){ r--; continue; }
    setA(&t, l); setA(l, r); setA(r, &t);
    l++; r--;
  }
  sortA(a, r-a+1);
  sortA(l, a+n-l);
}
int B[1000][1000];
int main(){
  int T,N,M,K,C, i,j,p;
  A a[1000];
  T = getn();
  while(T--){
    N = getn(), M = getn(), K = getn();
    for(i = 0; i < N; i++)
      a[i].o = getn()-1, a[i].p = 0;
    for(i = 0; i < N; i++)
      for(j = 0; j < M; j++)
        B[i][j] = getn();
    for(i = 0; i < N; i++)
      a[i].o = B[i][a[i].o];
    for(i = 0; i < N; i++){
      for(j = 0; j < M; j++){
        C = getn();
        p = B[i][j] - C - a[i].o;
        if(p > a[i].p)
          a[i].p = p;
      }
    }
    sortA(a, N);
    for(p = i = 0; i < K; i++){
      if(i >= N || a[i].p < 1)
        break;
      p += a[i].p + a[i].o;
    }
    for(; i < N; i++)
      p += a[i].o;
    printf("%d\n",p);
  }
  return 0;
}
