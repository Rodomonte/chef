// CHEFGR

#include <stdio.h>

#define gc getchar//_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,M, i,m,r, a[100];
  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(m = i = 0; i < N; i++){
      a[i] = getn();
      if(a[i] > m)
        m = a[i];
    }
    for(r = i = 0; i < N; i++)
      r += m - a[i];
    printf((M >= r && (M-r)%N == 0) ? "Yes\n" : "No\n");
  }
  return 0;
}
