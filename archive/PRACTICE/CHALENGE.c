// SORTROW

#include <stdio.h>
#include <stdlib.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,H,S, i,j,t;
  T = getn(), N = getn(), H = getn();
  while(T--){
    for(i = 0; i < N; ++i){
      t = rand()%5 + 8;
      for(j = 0; j < t; ++j)
        printf("%c", rand()&+'a');
      printf("\n");
    }
    fflush(stdout);
    S = getn();
  }
  return 0;
}
