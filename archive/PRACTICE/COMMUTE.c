// COMMUTE

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N, X,L,F, t, w;
  while(T--){
    N = getn(), t = 0;
    while(N--){
      X = getn(), L = getn(), F = getn();
      if(t <= X) t = X + L;
      else{
        w = F - ((t - X - 1) % F) - 1;
        t += w + L;
      }
    }
    printf("%d\n",t);
  }
  return 0;
}
