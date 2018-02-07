// HELLO

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
  int T,U,N,M,C, i, mi;
  double D,R, mc,pc;
  T = getn();
  while(T--){
    scanf("%lf",&D);
    U = getn(), N = getn(), mc = 101000.0;
    for(i = 1; i <= N; i++){
      M = getn();
      scanf("%lf",&R);
      C = getn();
      pc = R * (double)U + (double)C / (double)M;
      if(pc < mc)
        mc = pc, mi = i;
    }
    printf("%d\n",mc<D*(double)U?mi:0);
  }
  return 0;
}
