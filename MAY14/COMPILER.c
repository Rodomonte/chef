// COMPILER

#include <stdio.h>
#define gc getchar_unlocked

int main(){
  char c;
  int T,n,l,r;
  scanf("%d\n",&T);
  while(T--){
    n = l = r = 0;
    while((c=gc()) != '\n'){
      if(c == '<') n++;
      else n--;
      if(n < 0)
        break;
      l++;
      if(!n)
        r = l;
    }
    if(c != '\n')
      while((c=gc()) != '\n');
    printf("%d\n",r);
  }
  return 0;
}
