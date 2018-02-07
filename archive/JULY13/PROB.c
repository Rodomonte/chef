// PROB

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T = getn(),T1,T2,T3,T4;
  while(T--){
    T1 = getn(), T2 = getn(), T3 = getn(), T4 = getn();
    printf("%f\n",(double)T1/(double)(T1+T2));
  }
  return 0;
}
