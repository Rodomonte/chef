// MANYCHEF

#include <stdio.h>

int main(){
  int T, l, i;
  char s[2014];
  scanf("%d\n",&T);
  while(T--){
    gets(s);
    l = strlen(s);
    for(i = l - 1; i >= 0; i--){
      if(i >= 3 && (s[i-3] == 'C' || s[i-3] == '?') && (s[i-2] == 'H' || s[i-2] == '?')
          && (s[i-1] == 'E' || s[i-1] == '?') && (s[i] == 'F' || s[i] == '?')){
        s[i-3] = 'C', s[i-2] = 'H', s[i-1] = 'E', s[i] = 'F';
        i -= 3;
      }else if(s[i] == '?')
        s[i] = 'A';
    }
    puts(s);
  }
  return 0;
}
