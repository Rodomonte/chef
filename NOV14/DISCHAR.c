// DISCHAR

#include <stdio.h>

#define gc getchar_unlocked

int main(){
  char c, a[123];
  int T, i,n;
  scanf("%d\n", &T);
  while(T--){
    for(i = 0; i < 123; i++)
      a[i] = 0;
    n = 0;
    while((c=gc()) != '\n'){
      if(!a[c]){
        a[c] = 1;
        ++n;
      }
    }
    printf("%d\n", n);
  }
  return 0;
}
