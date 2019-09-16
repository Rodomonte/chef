// DECSTR

#include <stdio.h>

int main(){
  int T, K;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&K);
    char a[105], c = 'a';
    int ai = 0, k = 0;
    while(k < K){
      if(c > 'a') k++;
      a[ai++] = c++;
      if(c > 'z') c = 'a';
    }
    while(ai > 0){
      printf("%c",a[--ai]);
    }
    printf("\n");
  }
  return 0;
}
