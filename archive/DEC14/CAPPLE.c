// CAPPLE

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char a[100001];
int main(){
  int T,N,X, i,d;
  T = getn();
  while(T--){
    N = getn(), d = 0;
    memset(a, 0, 100001);
    for(i = 0; i < N; i++){
      X = getn();
      if(!a[X])
        a[X] = 1, ++d;
    }
    printf("%d\n", d);
  }
  return 0;
}