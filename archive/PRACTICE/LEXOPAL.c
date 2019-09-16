// LEXOPAL

#include <stdio.h>
#include <string.h>

char a[12346];
int main(){
  int T,N, i,j, f;

  scanf("%d", &T);
  while(T--){
    scanf("%s", a), N = strlen(a);
    for(i = 0, j = N-1, f = 1; i <= N/2; ++i, --j){
      if(a[i] == '.' && a[j] == '.') a[i] = a[j] = 'a';
      else if(a[i] == '.') a[i] = a[j];
      else if(a[j] == '.') a[j] = a[i];
      else if(a[i] != a[j]){ f = 0; break; }
    }
    if(!f){ printf("-1\n"); continue; }
    if((N&1) && a[N/2] == '.') a[N/2] = 'a';
    printf("%s\n", a);
  }
  return 0;
}
