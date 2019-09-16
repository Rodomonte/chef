// VILTRIBE

#include <stdio.h>
#include <string.h>

char s[100002];
int main(){
  int T,N, i, a,b,t;

  scanf("%d", &T);
  while(T--){
    scanf("%s", s+1), N = strlen(s+1);

    a = b = t = 0;
    for(i = 1; i <= N; ++i){
      if(s[i] == 'A' && t < 0) a += i+t-1, t = -i;
      if(s[i] == 'B' && t > 0) b += i-t-1, t = i;
      if(s[i] == 'A') ++a, t = -i;
      if(s[i] == 'B') ++b, t = i;
    }
    printf("%d %d\n", a, b);
  }
  return 0;
}
