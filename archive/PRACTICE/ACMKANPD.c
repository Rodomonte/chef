// ACMKANPD

#include <stdio.h>
#include <string.h>

int main(){
  int n, l;
  char a[35], f;
  scanf("%s",a);
  while(a[0] != '~'){
    n = 0;
    while(a[0] != '#'){
      l = strlen(a);
      if(l == 1)
        f = 1;
      else if(l == 2)
        f = 0;
      else{
        l -= 2;
        if(!f)
          n <<= l;
        else
          n = (n << l) | ((1 << l) - 1);
      }
      scanf("%s",a);
    }
    printf("%d\n",n);
    scanf("%s",a);
  }
  return 0;
}
