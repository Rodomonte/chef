// PERPALIN

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N,P, i,j;

  T = getn();
  while(T--){
    N = getn(), P = getn();

    if(N < 3 || P < 3){ printf("impossible\n"); continue; }
    for(i = 0; i < N; i += P){
      printf("a");
      for(j = 0; j < P-2; ++j) printf("b");
      printf("a");
    }
    printf("\n");
  }
  return 0;
}
