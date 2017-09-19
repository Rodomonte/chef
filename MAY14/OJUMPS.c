// OJUMPS

#include <stdio.h>

int main(){
  long long A;
  scanf("%lld",&A);
  printf((A%6==0||A%6==1||A%6==3)?"yes\n":"no\n");
  return 0;
}
