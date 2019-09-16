// BIAS

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MAR 500

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

typedef struct { int i; ll s; } P ;
char ltp(P a, P b){ return a.s > b.s; }
void sortp(P* a, int n){
  if(n < 2) return;
  P p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(ltp(*l, p)){ l++; continue; }
    if(ltp(p, *r)){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sortp(a, r-a+1);
  sortp(l, a+n-l);
}

typedef struct { int j,r; } R ;
char ltr(R a, R b){ return a.r > b.r; }
void sortr(R* a, int n){
  if(n < 2) return;
  R p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(ltr(*l, p)){ l++; continue; }
    if(ltr(p, *r)){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sortr(a, r-a+1);
  sortr(l, a+n-l);
}

int N,M, IT, a[1000][1000], l[1000], u[1000], r[1000], b[1000];
P s[1000];
R ra[1000];

int inv(){
  int i,j, t;
  for(i = 0; i < N; ++i) for(s[i].s = j = 0, s[i].i = i; j < M; ++j)
    s[i].s += (ll)a[i][j] * r[j];
  sortp(s, N);
  for(i = 0; i < N; ++i) b[s[i].i] = i;
  for(i = t = 0; i < N-1; ++i) for(j = i+1; j < N; ++j) if(s[i].i > s[j].i) ++t;
  IT += ((N*N)>>1);
  return t;
}

int main(){
  int T, i,j;
  ll x;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < M; ++i) l[i] = r[i] = getn(), u[i] = getn();
    for(i = 0; i < N; ++i) for(j = 0; j < M; ++j) a[i][j] = getn();

    IT = 0, inv();
    for(i = N-2; i >= 0; --i){
      for(j = 0; j < M; ++j) ra[j].j = j, ra[j].r = a[i][j];
      sortr(ra, M);
      for(j = 0; j < M; ++j){
        if(ra[j].r == a[i+1][ra[j].j]) continue;
        else
          x = (s[b[i+1]].s - s[b[i]].s + MAR) / (ra[j].r - a[i+1][ra[j].j])
              + r[ra[j].j];
          /* printf("x=%lld s[i+1]=%d s[i]=%d r[i]=%d r[i+1]=%d\n", */
          /*        x, s[b[i+1]].s, s[b[i]].s, ra[j].r, a[i+1][ra[j].j]); */
        if(x >= u[ra[j].j]) r[ra[j].j] = u[ra[j].j], inv();
        else if(x >= l[ra[j].j]){ r[ra[j].j] = x; inv(); break; }
        else continue;
      }
      if(IT > 40000000) break;
    }

    for(i = 0; i < M; ++i) printf("%d ", r[i]);
    printf("\n");

    //!
    /* for(i = 0; i < N; ++i) printf("%d ", s[i].i); */
    /* printf("\n"); */
  }
  return 0;
}
