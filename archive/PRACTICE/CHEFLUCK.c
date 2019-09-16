// CHEFLUCK

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N, n4;
  while(T--){
    N = getn(), n4 = N;
    if(N < 4) n4 = -1;
    else if(N % 7){
      while(1){
        N -= 4;
        n4 -= 4;
        if(!(N % 7)) break;
        if(N < 4){
          n4 = -1;
          break;
        }
      }
    }
    printf("%d\n",n4);
  }
  return 0;
}
