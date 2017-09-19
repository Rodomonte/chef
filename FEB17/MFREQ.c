// MFREQ

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

typedef struct {
  int n,b,l,r;
} S ;

S a[100000];
int main(){
  int N,M,L,R,K, i,j,m,n,p,l;

  N = getn(), M = getn(), p = -1;
  for(i = 0; i < N; ++i){
    a[i].n = getn();

    if(a[i].n == p){
      ++n;
    }else{
      for(j = i-1; j >= 0 && a[j].n == a[i-1].n; --j)
        a[j].b = n, a[j].l = l, a[j].r = i-1;
      n = 1, l = i;
    }
    p = a[i].n;
  }
  for(j = i-1; j >= 0 && a[j].n == a[i-1].n; --j)
    a[j].b = n, a[j].l = l, a[j].r = i-1;

  //for(i = 0; i < N; ++i)
  //  printf("a[%d] = %d,%d,%d,%d\n", i,a[i].n,a[i].b,a[i].l,a[i].r);

  while(M--){
    L = getn()-1, R = getn()-1, K = getn();
    p = (R-L > 50) ? (int)sqrt(R-L) : 1;
    for(i = L, m = 0; i <= R; i += p){
      n = a[i].b;
      if(a[i].l < L)
        n -= L - a[i].l;
      if(a[i].r > R)
        n -= a[i].r - R;
      if(n > m)
        m = n, j = i;
    }

    printf("%d\n", (m >= K) ? a[j].n : -1);
  }
  return 0;
}
