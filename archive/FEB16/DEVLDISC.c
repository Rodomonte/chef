// DEVLDISC

#include <stdio.h>

int main(){
  int T,N, i,a,b,c;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    if(N < 7){
      printf("-1\n");
      continue;
    }
    printf("%d\n1 6\n5 7\n2 4\n6 7\n4 7\n3 6\n3 4\n", N);
    if(N % 3 == 1)
      i = 7;
    else if(N % 3 == 2)
      i = 8, printf("7 8\n");
    else
      i = 9, printf("7 8\n4 9\n");
    a = 1, b = 5, c = 2;
    for(; i < N; i += 3){
      printf("%d %d\n%d %d\n%d %d\n", a,i+1,b,i+2,c,i+3);
      a = i+1, b = i+2, c = i+3;
    }
    printf("3\n");
  }
  return 0;
}
