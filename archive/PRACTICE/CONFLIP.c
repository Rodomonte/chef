// CONFLIP

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), G, I, N, Q;
  while(T--){
    G = getn();
    while(G--){
      I = getn(), N = getn(), Q = getn();
      printf("%d\n",I==Q?N/2:(N+1)/2);
    }
  }
  return 0;
}
