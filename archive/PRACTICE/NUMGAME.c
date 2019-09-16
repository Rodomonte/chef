// NUMGAME

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
    int T = getn(), N;
    while(T--)
    printf(getn()&1?"BOB\n":"ALICE\n");
    return 0;
}
