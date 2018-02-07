// SNAPE

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,B,L;
  double n,x;
  T = getn();
  while(T--){
    B = getn(), L = getn();
    n = sqrt(L*L-B*B);
    x = sqrt(L*L+B*B);
    printf("%f %f\n",n,x);
  }
  return 0;
}
