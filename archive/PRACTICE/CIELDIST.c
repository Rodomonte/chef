// CIELDIST

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), A,B,D, d;
  while(T--){
    A = getn(), B = getn(), D = getn();
    if(A >= B + D) d = A - B - D;
    else if(B >= A + D) d = B - A - D;
    else if(D >= A + B) d = D - A - B;
    else d = 0;
    printf("%d\n",d);
  }
  return 0;
}
