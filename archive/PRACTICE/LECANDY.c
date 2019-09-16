// LECANDY

#include <stdio.h>
#include <stdlib.h>

inline int getn(){
  int n=0;
  int c=getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T, N, C, s;
  T = getn();
  while(T--){
    N = getn();
    C = getn();
    s = 0;
    while(N--) s += getn();
    puts(s>C?"No":"Yes");
  }
  return 0;
}
