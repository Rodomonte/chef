// RESIST

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N, M, a, b;
  while(T--){
    N = getn() - 1, M = getn();
    a=b=1;
    while(N--){
      a += b;
      if(a >= M) a -= M;
      b += a;
      if(b >= M) b -= M;
    }
    printf("%d/%d\n",a,b);
  }
  return 0;
}
