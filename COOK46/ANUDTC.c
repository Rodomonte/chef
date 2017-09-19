// ANUDTC

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
  int T,N;
  T = getn();
  while(T--){
    N = getn();
    printf((360%N==0)?"y":"n");
    printf((N<=360)?" y":" n");
    printf((N<=26)?" y\n":" n\n");
  }
  return 0;
}
