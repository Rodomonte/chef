// SIMGRAPH

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int min(int a, int b){ return (a < b) ? a : b; }

char a[76][76], b[76][76], ra[76], rb[76];
int main(){
  int T,N, i,j,mi,mj, m,n,s,t,u;

  T = getn();
  while(T--){
    N = getn();
    for(i = 1; i <= N; ++i) for(j = 1; j <= N; ++j) a[i][j] = getn();
    for(i = 1; i <= N; ++i) for(j = 1; j <= N; ++j) b[i][j] = getn();

    for(i = 1; i <= N; ++i) ra[i] = rb[i] = 0;
    for(n = 1; n <= N;){
      for(i = 1, m = 0; i <= N; ++i){
        if(ra[i]) continue;
        for(t = j = 1; j <= N; ++j)
          if(a[i][j] && !ra[j]) ++t;
        if(t > m) m = t, mi = i;
      }
      for(i = 1, m = 0; i <= N; ++i){
        if(rb[i]) continue;
        for(t = j = 1; j <= N; ++j)
          if(b[i][j] && !rb[j]) ++t;
        if(t > m) m = t, mj = i;
      }

      ra[mi] = rb[mj] = n++, t = u = 0;
      for(i = 1; i <= N; ++i) if(a[mi][i] && !ra[i]) ++t;
      for(i = 1; i <= N; ++i) if(b[mj][i] && !rb[i]) ++u;
      m = min(t, u), s = n;
      for(i = 1; m > 0; ++i) if(a[mi][i] && !ra[i]) ra[i] = n++, --m;
      m = min(t, u);
      for(i = 1; m > 0; ++i) if(b[mj][i] && !rb[i]) rb[i] = s++, --m;
    }

    for(i = 1; i <= N; ++i) printf("%d ", ra[i]);
    printf("\n");
    for(i = 1; i <= N; ++i) printf("%d ", rb[i]);
    printf("\n");
  }
  return 0;
}
