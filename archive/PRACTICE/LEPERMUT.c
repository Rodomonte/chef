// LEPERMUT

#include <stdio.h>

#define getchar_unlocked getchar

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N,n,n2, i,li;
  while(T--){
    N = getn(), i=0, li=0;
    int a[N];
    for(n=0; n < N; n++){
      a[n] = getn();
      if(n && a[n] < a[n-1]) li++;
    }
    for(n = 0; n < N-1; n++)
      for(n2 = n+1; n2 < N; n2++)
        if(a[n] > a[n2])
          i++;
    printf(i==li?"YES\n":"NO\n");
  }
  return 0;
}
