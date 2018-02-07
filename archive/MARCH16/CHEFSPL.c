// CHEFSPL

#include <stdio.h>
#include <string.h>

char s[1000001];
int main(){
  int D, i,j,f,l;
  scanf("%d", &D);
  while(D--){
    scanf("%s", s);
    l = strlen(s);
    if((l&1) == 0){
      for(i = f = 0, j = l>>1; j < l; ++i, ++j)
        if(s[i] != s[j]){ f = 1; break; }
      printf(f ? "NO\n" : "YES\n");
      continue;
    }
    if(l == 1){ printf("NO\n"); continue; }
    for(i = f = 0, j = (l>>1)+1; j < l; ++i, ++j)
      if(s[i] != s[j]) break;
    if(j == l){ printf("YES\n"); continue; }
    for(++i; j < l; ++i, ++j)
      if(s[i] != s[j]){ f = 1; break; }
    if(!f){ printf("YES\n"); continue; }
    for(i = f = 0, j = l>>1; i < l>>1; ++i, ++j)
      if(s[i] != s[j]) break;
    if(i == l>>1){ printf("YES\n"); continue; }
    for(++j; j < l; ++i, ++j)
      if(s[i] != s[j]){ f = 1; break; }
    printf(f ? "NO\n" : "YES\n");
  }
  return 0;
}
