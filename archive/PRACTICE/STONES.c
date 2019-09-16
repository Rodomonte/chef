// STONES

#include <stdio.h>

int main(){
  int T, n;
  scanf("%d\n",&T);
  while(T--){
    char m[58] = {0}, c;
    c = getchar(), n = 0;
    while(c != '\n'){
      m[c-65] = 1;
      c = getchar();
    }
    c = getchar();
    while(c != '\n'){
      if(m[c-65] == 1) n++;
      c = getchar();
    }
    printf("%d\n",n);
  }
  return 0;
}
