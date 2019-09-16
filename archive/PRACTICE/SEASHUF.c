// SEASHUF

#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define gc getchar_unlocked
#define SS 500
#define BS 300

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

ll absl(ll n){ return (n < 0) ? -n : n; }
int min(int a, int b){ return (a < b) ? a : b; }

int N, f,k, a[100000], r[10000][2],rn;
ll d;

void shift(int L, int R){
  int i, t;
  if(R-L+1 > k) return;
  for(i = L, t = a[L]; i < R; ++i) a[i] = a[i+1];
  a[R] = t, k -= R-L+1, f = 1;
  if(L < N/2 && R >= N/2) d += 2*a[N/2-1] - 2*a[R];
  r[rn][0] = L, r[rn][1] = R, ++rn;
}

int main(){
  int i,j;
  ll m,t;

  N = getn();
  for(i = 0; i < N; ++i) a[i] = getn();

  for(i = d = 0; i < N/2; ++i) d += a[i];
  for(i = N/2, m = 0; i < N; ++i) m += a[i];
  d -= m, k = N*2, rn = 0;
  while(1){
    if(!d) break;
    for(i = N/2-1, m = absl(d); i >= N/2-min(N/2, SS); --i){
      t = absl(d - 2*a[i] + 2*a[N/2]);
      if(t < m) m = t, j = i;
    }
    f = 0;
    if(m == absl(d)) shift(N/2, N/2+min(N/2-1, BS));
    else shift(j, N/2+min(N/2-1, BS));
    if(!f) break;
  }

  printf("%d\n", rn);
  for(i = 0; i < rn; ++i) printf("%d %d\n", r[i][0]+1, r[i][1]+1);
  return 0;
}
