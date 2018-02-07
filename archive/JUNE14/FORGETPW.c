// FORGETPW

#include <stdio.h>

#define gc getchar_unlocked

char s[1000001];
int main(){
  char C,P, f;
  int T,N, i, d[127];
  scanf("%d\n",&T);
  while(T--){
    scanf("%d\n",&N);
    for(i = 33; i <= 126; i++)
      d[i] = 0;
    for(i = 0; i < N; i++){
      C = gc(), gc(), P = gc(), gc();
      d[C] = P;
    }
    scanf("%s",s);
    for(i = f = 0; s[i] != 0; i++){
      if(d[s[i]])
        s[i] = d[s[i]];
      if(s[i] == '.')
        f = 1;
    }
    if(f)
      while(s[--i] == '0')
        s[i] = 0;
    if(s[i] == '.')
      s[i] = 0;
    for(i = 0; s[i] == '0'; i++);
    if(s[i] == 0){
      printf("0\n");
      continue;
    }
    for(; s[i] != 0; i++)
      printf("%c",s[i]);
    printf("\n");
  }
  return 0;
}