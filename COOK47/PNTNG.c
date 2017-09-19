// PNTNG

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

inline ll getl(){
  ll n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

typedef struct {
  ll t; int c;
} B ;
void setB(B* d, B* s){
  d->t = s->t, d->c = s->c;
}
void sort(B* a, int n){
  if(n < 2) return;
  int p = a[n/2].c;
  B *l = a, *r = a+n-1, t;
  while(l <= r){
    if(l->c < p){ l++; continue; }
    if(r->c > p){ r--; continue; }
    setB(&t, l); setB(l, r); setB(r, &t);
    l++; r--;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

B a[100000];
int main(){
  int H, i;
  ll N, p,r;
  N = getl(), N *= getl(), H = getn();
  for(i = 0; i < H; i++)
    a[i].t = getl(), a[i].c = getn();
  sort(a, H);
  p = r = 0;
  for(i = 0; i < H; i++){
    if(p + a[i].t <= N)
      p += a[i].t, r += a[i].t*a[i].c;
    else
      r += (N-p)*a[i].c, p = N;
    if(p == N)
      break;
  }
  if(p < N)
    printf("Impossible\n");
  else
    printf("%lld\n",r);
  return 0;
}
