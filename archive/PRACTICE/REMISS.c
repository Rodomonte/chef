// REMISS

#include <stdio.h>

int max(int a, int b){
  return (a > b) ? a : b;
}

int main(){
  int T,A,B;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &A, &B);
    printf("%d %d\n", max(A,B), A+B);
  }
  return 0;
}
