// PLAYFIT

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N, G, mn,mx;
  while(T--){
    N = getn(), mn=1000000, mx=0;
    while(N--){
      G = getn();
      if(G < mn) mn = G;
      if(G - mn > mx) mx = G - mn;
    }
    if(mx > 0) printf("%d\n",mx);
    else printf("UNFIT\n");
  }
  return 0;
}
