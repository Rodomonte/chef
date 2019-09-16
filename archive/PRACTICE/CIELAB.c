// CIELAB

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int a = getn(), b = getn();
  int c = a - b;
  if(c % 10 == 9) c--;
  else c++;
  printf("%d\n",c);
  return 0;
}
