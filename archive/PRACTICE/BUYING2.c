// BUYING2

#include <stdio.h>

/* INCOMPLETE */
#define getchar_unlocked getchar

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N,n, X, s, m, r;
  while(T--){
    N = getn(), X = getn(), s=0, m=100;
    int a[N];
    for(n = 0; n < N; n++){
      a[n] = getn();
      s += a[n];
      if(a[n] < m) m = a[n];
    }
    r = s % X;
    if(r >= m) printf("-1\n");
    else printf("%d\n",s/X);
  }
  return 0;
}
