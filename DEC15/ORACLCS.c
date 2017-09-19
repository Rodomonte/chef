// ORACLCS

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
int min(int a, int b){
  return (a < b) ? a : b;
}

int main(){
  char c;
  int T,N, i,j,a,b,m;
  T = getn();
  while(T--){
    N = getn(), m = 100;
    for(i = 0; i < N; ++i){
      a = b = 0;
      while((c=gc()) != '\n')
        if(c == 'a') ++a; else ++b;
      m = min(min(m, a), b);
    }
    printf("%d\n", m);
  }
  return 0;
}
