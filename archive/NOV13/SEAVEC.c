// SEAVEC

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
  int i;
  float r;
} P ;
void setP(P* d, P* s){
  d->i = s->i, d->r = s->r;
}
void sortP(P* a, int n){
  if(n < 2) return;
  float p = a[n/2].r;
  P *l = a, *r = a+n-1, t;
  while(l <= r){
    if(l->r < p){ l++; continue; }
    if(r->r > p){ r--; continue; }
    setP(&t, l); setP(l, r); setP(r, &t);
    l++; r--;
  }
  sortP(a, r-a+1);
  sortP(l, a+n-l);
}
void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n/2], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

#define ll long long
int a[100000], b[100000], r[100000];
P c[100000];
int main(){
  char f;
  int T,N,K,NK, i,j,k, ri;
  float t;
  T = getn();
  while(T--){
    N = getn(), K = getn();
    NK = N*K;
    for(i = 0; i < NK; i++)
      a[i] = getn();
    for(i = 0; i < K; i++)
      b[i] = getn();
    for(i = k = 0; i < N; i++){
      c[i].i = i, c[i].r = 0;
      for(j = 0; j < K; j++, k++){
        t = (float)a[k] / (float)b[j];
        if(t > c[i].r)
          c[i].r = t;
      }
    }
    sortP(c, N);
    for(ri = f = 0; ri < N && ri < N/10+1; ri++){
      for(j = 0, k = c[ri].i*K; j < K; j++, k++){
        b[j] -= a[k];
        if(b[j] < 0)
          f = 1;
      }
      if(f){
        for(j = 0, k = c[ri].i*K; j < K; j++, k++)
          b[j] += a[k];
        break;
      }
      r[ri] = c[ri].i+1;
    }
    for(i = ri; i < N; i++){
      c[i].r = 0;
      for(j = 0, k = c[i].i*K; j < K; j++, k++){
        t = (float)a[k] / (float)b[j];
        if(t > c[i].r)
          c[i].r = t;
      }
    }
    sortP(&c[ri], N-ri);
    for(f = 0; ri < N; ri++){
      for(j = 0, k = c[ri].i*K; j < K; j++, k++){
        b[j] -= a[k];
        if(b[j] < 0)
          f = 1;
      }
      if(f){
        for(j = 0, k = c[ri].i*K; j < K; j++, k++)
          b[j] += a[k];
        break;
      }
      r[ri] = c[ri].i+1;
    }
    for(i = ri; i < N; i++){
      f = 1;
      for(j = 0, k = c[i].i*K; j < K; j++, k++)
        if(b[j] - a[k] < 0){ f = 0; break; }
      if(f){
        for(j = 0, k = c[i].i*K; j < K; j++, k++)
          b[j] -= a[k];
        r[ri++] = c[i].i+1;
      }
    }
    sort(r, ri);
    printf("%d\n",ri);
    for(i = 0; i < ri; i++)
      printf("%d ",r[i]);
    if(i) printf("\n");
  }
  return 0;
}
