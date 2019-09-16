// RESQ

#include <stdio.h>
#include <math.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N, r,ri, d, i;
  while(T--){
    N = getn();
    r = sqrt(N);
    if(r * r == N) d = 0;
    else{
      if(!(N % 2)) i = 1;
      else{
        if(!(r % 2)) r += 1;
        i = 2;
      }
      for(ri = r; ri; ri -= i){
        if(!(N % ri)){
          d = N / ri - ri;
          break;
        }
      }
    }
    printf("%d\n",d);
  }
  return 0;
}
