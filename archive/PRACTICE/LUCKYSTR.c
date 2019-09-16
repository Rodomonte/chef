// LUCKYSTR

#include <stdio.h>
#include <string.h>

int main(){
  int K,k, N, f;
  char a[51][51], b[51];
  scanf("%d %d\n",&K,&N);
  for(k = 0; k < K; k++) scanf("%s",a+k);
  while(N--){
    scanf("%s",b);
    if(strlen(b) >= 47){
      printf("Good\n");
      continue;
    }
    f = 0;
    for(k = 0; k < K; k++){
      if(strstr(b, a[k])){
        f = 1;
        break;
      }
    }
    printf(f?"Good\n":"Bad\n");
  }
  return 0;
}
