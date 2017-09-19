// ROTATION

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[100000];
int main(){
  char Q;
  int N,M,D, i;
  N = getn(), M = getn();
  for(i = 0; i < N; i++)
    a[i] = getn();
  i = 0;
  while(M--){
    Q = gc(), D = getn();
    if(Q == 'C')
      i = (i+D >= N) ? i+D-N : i+D;
    else if(Q == 'A')
      i = (i-D < 0) ? N+(i-D) : i-D;
    else
      printf("%d\n", (i+D-1 >= N) ? a[i+D-1-N] : a[i+D-1]);
  }
  return 0;
}
