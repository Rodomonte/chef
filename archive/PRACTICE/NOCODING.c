// NOCODING

#include <stdio.h>

int main(){
  int T, i, p;
  char s[1001],*cp,c;
  scanf("%d",&T);
  while(T--){
    scanf("%s",s);
    c = s[1], cp = s+1, i=1, p = s[0];
    while(c){
      if(c < p) i += 26 - p + c;
      else i += c - p;
      p = c;
      cp++;
      c = *cp;
    }
    i += cp - s;
    printf(i<=11*(cp-s)?"YES\n":"NO\n");
  }
  return 0;
}
