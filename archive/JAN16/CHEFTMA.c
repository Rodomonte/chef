// CHEFTMA

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ ++l; continue; }
    if(*r > p){ --r; continue; }
    t = *l; *l = *r; *r = t, ++l, --r;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int a[100000], b[200000];
int main(){
  int T,N,K, i,j,r;
  T = getn();
  while(T--){
    N = getn(), K = getn()+getn();
    for(i = 0; i < N; ++i)
      a[i] = getn();
    for(i = 0; i < N; ++i)
      a[i] -= getn();
    for(i = 0; i < K; ++i)
      b[i] = getn();
    sort(a, N);
    sort(b, K);

    r = 0;
    for(i = N-1, j = K-1; i >= 0; --j){
      if(j < 0){
  r += a[i--];
  continue;
      }
      if(a[i] < b[j])
  continue;
      r += a[i]-b[j], --i;
    }
    printf("%d\n", r);
  }
  return 0;
}
