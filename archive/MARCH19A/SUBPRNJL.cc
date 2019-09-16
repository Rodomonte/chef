// SUBPRNJL

#include <stdio.h>
#include <math.h>
#include <vector>

#define gc getchar_unlocked
#define vec std::vector
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
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

struct P {
  int v,p,n;
};

int a[2000], b[2000];
P c[2000];
vec<int> d[2001];
int main(){
  char f;
  int T,N,K, i,j,k, l,m,n,t,r;
  P* p;

  T = getn();
  while(T--){
    N = getn(), K = getn(), r = 0;
    for(i = 0; i < N; ++i) a[i] = getn();

    for(i = 0; i < N; ++i){
      for(k = i; k < N; ++k) b[k-i] = a[k];
      sort(b, N-i);
      c[0].v = b[0], c[0].p = -1, c[N-i-1].n = -1, d[b[0]].pb(0);
      for(k = 1; k < N-i; ++k)
        c[k].v = b[k], c[k].p = k-1, c[k-1].n = k, d[b[k]].pb(k);
      l = m = (int)ceil((double)K / (double)(N-i));
      k = (int)ceil((double)K / (double)m) - 1;
      p = c + k;

      for(j = N-1; j >= i; --j){
        if(!d[d[p->v].size()].empty()) ++r;
        n = d[a[j]].back(), f = 0;
        if(n == p-c){
          f = 1;
          if(p->n == -1) p = c + p->p;
          else p = c + p->n;
        }

        if(c[n].p == -1)
          c[c[n].n].p = -1;
        else
          c[c[n].p].n = c[n].n;
        if(c[n].n == -1)
          c[c[n].p].n = -1;
        else
          c[c[n].n].p = c[n].p;
        d[a[j]].pop_back();
        if(i == j) break;

        l = m, m = (int)ceil((double)K / (double)(j-i)), t = 0;
        if(a[j] < p->v && !f) ++t;
        if(l < m){
          t -= (int)ceil((double)K / (double)l) -
               (int)ceil((double)K / (double)m);
          if(f) ++t;
        }
        if(t > 0) for(k = 0; k < t; ++k) p = c + p->n;
        else if(t < 0) for(k = 0; k < -t; ++k) p = c + p->p;
      }
    }

    printf("%d\n", r);
  }
  return 0;
}
