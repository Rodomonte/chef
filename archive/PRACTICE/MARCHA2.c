// MARCHA2

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int N = getn(), K, L;
  while(N--){
    K = getn();
    int f=0, s=1;
    while(K--){
      L = getn();
      if(L > s){
        f = 1;
        break;
      }
      s = (s - L) * 2;
    }
    printf(f||s?"No\n":"Yes\n");
  }
  return 0;
}
