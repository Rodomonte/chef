// BIAS

#include <stdio.h>
#include <stdlib.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

typedef struct { int i; double s; } P ;
char lt(P a, P b){ return a.s > b.s; }
void sort(P* a, int n){
  if(n < 2) return;
  P p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(lt(*l, p)){ l++; continue; }
    if(lt(p, *r)){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int N,M, a[1000][1000], l[1000], u[1000], r[1000];
P s[1000];

int inv(){
  int i,j, t;
  for(i = 0; i < N; ++i) for(s[i].s = j = 0, s[i].i = i; j < M; ++j)
    s[i].s += (double)a[i][j] * r[j] / 1000000;
  sort(s, N);
  for(i = t = 0; i < N-1; ++i) if(s[i].i > s[i+1].i) ++t;
  return t;
}

int main(){
  int T, i,j,k,ii, g;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < M; ++i) l[i] = r[i] = getn(), u[i] = getn();
    for(i = 0; i < N; ++i) for(j = 0; j < M; ++j) a[i][j] = getn();

    inv(), ii = 0;
    while(ii < 1000000){
      for(i = 0; i < N-3; ++i){
        if(s[i+1].i > s[i+2].i && s[i+1].i < s[i+3].i &&
           (s[i].i < s[i+2].i || (s[i].i > s[i+2].i && s[i].i > s[i+1].i))){
          while(1){
            for(j = 1, k = 0; j < M; ++j){
              if(r[j] < u[j] &&
                 a[s[i+2].i][j] - a[s[i+1].i][j] >
                 a[s[i+2].i][k] - a[s[i+1].i][k]) k = j;
              ++ii;
            }
            if(!k && r[k] == u[k]) break;
            g = (int)((s[i+2].s - s[i+1].s) / (a[s[i+1].i][k] - a[s[i+2].i][k]))
                + r[k];

            //printf("i=%d k=%d g=%d\n", i,k,g);

            if(g >= u[k]){ r[k] = u[k]; continue; }
            r[k] = g+1;
            break;
          }
          inv();
        }
      }
      ++ii;
    }

    for(i = 0; i < M; ++i) printf("%d ", r[i]);
    printf("\n");

    //!
    for(i = 0; i < M; ++i) printf("%d ", s[i].i);
    printf("\n");

  }
  return 0;
}
