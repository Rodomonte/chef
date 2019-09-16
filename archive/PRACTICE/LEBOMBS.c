// LEBOMBS

#include <stdio.h>
#include <string.h>

int main(){
  int T, N, n, i;
  char s[1001];
  scanf("%d",&T);
  while(T--){
    n=0;
    scanf("%d",&N);
    scanf("%s",s);
    if(s[0] == '0'){
      if(N > 1){
        if(s[1] == '0') n++;
      }else n++;
    }
    for(i=1; i <= N-2; i++)
      if(s[i] == '0' && s[i-1] == '0' && s[i+1] == '0')
        n++;
    if(s[N-2] == '0' && s[N-1] == '0') n++;
    printf("%d\n",n);
  }
  return 0;
}
