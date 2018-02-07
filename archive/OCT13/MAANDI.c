// MAANDI

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

int fn1(int n){
  while(n){
    if(n % 10 == 4 || n % 10 == 7)
      return 1;
    n /= 10;
  }
  return 0;
}
int main(){
  int T,N, i, r;
  T = getn();
  while(T--){
    N = getn(), r = 0;
    for(i = 1; i <= (int)sqrt(N); i++)
      if(N%i == 0){
        r += fn1(i);
        r += fn1(N/i);
      }
    printf("%d\n",r);
  }
  return 0;
}
