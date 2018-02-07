// ONEKING

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
  int l,r;
} B ;
void setB(B* d, B* s){
  d->l = s->l, d->r = s->r;
}
void sortB(B* a, int n){
  if(n < 2) return;
  int p = a[n/2].r;
  B *l = a, *r = a+n-1, t;
  while(l <= r){
    if(l->r < p){ l++; continue; }
    if(r->r > p){ r--; continue; }
    setB(&t, l); setB(l, r); setB(r, &t);
    l++; r--;
  }
  sortB(a, r-a+1);
  sortB(l, a+n-l);
}

B a[100000];
int main(){
  int T,N, i,p,r;
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      a[i].l = getn(), a[i].r = getn();
    sortB(a, N);
    p = -1, r = 0;
    for(i = 0; i < N; ++i)
      if(a[i].l > p)
        p = a[i].r, ++r;
    printf("%d\n", r);
  }
  return 0;
}
