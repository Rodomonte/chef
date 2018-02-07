// NAME2

#include <stdio.h>

char M[25001], W[25001], *c,*d,f;
char eval(char *a, char *b){
  c = a, d = b;
  while(*c){
    while(*d && *d != *c)
      d++;
    d++;
    c++;
    if(!(*d) && *c)
      return 0;
  }
  return 1;
}
int main(){
  int T;
  scanf("%d\n",&T);
  while(T--){
    scanf("%s %s",M,W);
    f = eval(M, W);
    if(!f)
      f = eval(W, M);
    printf(f?"YES\n":"NO\n");
  }
  return 0;
}
