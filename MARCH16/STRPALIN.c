// STRPALIN

#include <stdio.h>

char a[1001],b[1001];
int main(){
  int T, i,c[26];
  scanf("%d", &T);
  while(T--){
    scanf("%s%s", a,b);
    for(i = 0; i < 26; ++i) c[i] = 0;
    for(i = 0; a[i]; ++i) ++c[a[i]-'a'];
    for(i = 0; b[i]; ++i) if(c[b[i]-'a']){ c[0] = -1; break; }
    printf((c[0] == -1) ? "Yes\n" : "No\n");
  }
  return 0;
}
