// DOUBLE

#include <stdio.h>
#include <string.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int N = getn(), i;
  while(N--){
    i = getn();
    if(i % 2 == 1) i--;
    printf("%d\n", i);
  }
  return 0;
}
