// CHCUBE

#include <stdio.h>
#include <string.h>

int main(){
  char s[6][7], f;
  int T, i,j,k;
  scanf("%d", &T);
  while(T--){
    for(i = 0; i < 6; ++i)
      scanf("%s", s[i]);
    f = 0;
    for(i = 0; i < 2; ++i)
      for(j = 2; j < 4; ++j)
  for(k = 4; k < 6; ++k)
    if(!strcmp(s[i], s[j]) && !strcmp(s[j], s[k]))
      f = 1;
    printf(f ? "YES\n" : "NO\n"); 
  }
  return 0;
}
