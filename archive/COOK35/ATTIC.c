// ATTIC

#include <stdio.h>

#define gc getchar_unlocked

int main(){
  char c, p;
  int T, j,n,r;
  scanf("%d\n",&T);
  while(T--){
    p = gc(), j = n = r = 0;
    while((c = gc()) != '\n'){
      if(c == '.')
        n++;
      else if(p == '.'){
        if(n > j){
          j = n;
          r++;
        }
        n = 0;
      }
      p = c;
    }
    printf("%d\n",r);
  }
  return 0;
}
