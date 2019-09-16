// LADDU

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

int main(){
  char O[16], A[16];
  int T,N,X, i, r;

  T = getn();
  while(T--){
    N = getn(), scanf("%s", O);
    for(i = r = 0; i < N; ++i){
      scanf("%s", A);
      if(A[0] == 'B') r += getn();
      else if(A[0] == 'T') r += 300;
      else if(A[8] == 'W') r += 300 + max(0, 20-getn());
      else r += 50;
    }
    printf("%d\n", r/((O[0] == 'I') ? 200 : 400));
  }
  return 0;
}
