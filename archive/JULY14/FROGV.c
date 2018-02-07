// FROGV

#include <stdio.h>
#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

typedef struct {
  int i,x,g;
} F ;
F a[100001];
int b[100001];

void sort(F* a, int n){
  if(n < 2) return;
  int p = a[n/2].x;
  F *l = a, *r = a+n-1, t;
  while(l <= r){
    if(l->x < p){ l++; continue; }
    if(r->x > p){ r--; continue; }
    t.x = l->x, t.i = l->i;
    l->x = r->x, l->i = r->i;
    r->x = t.x, r->i = t.i;
    l++; r--;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int main(){
  int N,K,P,A,B, i,g;
  N = getn(), K = getn(), P = getn();
  for(i = 1; i <= N; i++)
    a[i].i = i, a[i].x = getn();
  sort(a+1, N);
  a[1].g = g = 1, b[a[1].i] = 1;
  for(i = 2; i <= N; i++){
    a[i].g = (a[i-1].x+K<a[i].x) ? ++g : g;
    b[a[i].i] = i;
  }
  for(i = 0; i < P; i++){
    A = getn(), B = getn();
    printf((a[b[A]].g==a[b[B]].g)?"Yes\n":"No\n");
  }
  return 0;
}

