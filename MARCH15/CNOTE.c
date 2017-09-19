// CNOTE

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(int argc, char** argv) {
  char r;
  int T,X,Y,K,N,P,C;
  T = getn();
  while(T--){
    X = getn(), Y = getn(), K = getn(), N = getn(), r = 0;
    while(N--){
      P = getn(), C = getn();
      if(r)
  continue;
      if(P+Y >= X && C <= K)
        r = 1;
    }
    printf(r ? "LuckyChef\n" : "UnluckyChef\n");
  }
  return 0;
}
