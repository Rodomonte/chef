// TOTR

#include <stdio.h>
#include <string.h>

int main(){
  int T, i, l;
  char a[27], s[101],c, d;
  scanf("%d ",&T);
  gets(a);
  while(T--){
    gets(s);
    l = strlen(s);
    for(i = 0; i < l; i++){
      c = s[i];
      if(c == '_') d = ' ';
      else if(c >= 65 && c <= 90) d = a[c-65]-32;
      else if(c >= 97 && c <= 122) d = a[c-97];
      else d = c;
      printf("%c",d);
    }
    printf("\n");
  }
  return 0;
}
