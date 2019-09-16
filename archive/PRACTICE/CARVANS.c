// CARVANS

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N, c, s, m;
  while(T--){
    N = getn(), m = getn(), c=1;
    while(N---1){
      s = getn();
      if(s <= m){
        m = s;
        c++;
      }
    }
    printf("%d\n",c);
  }
  return 0;
}
