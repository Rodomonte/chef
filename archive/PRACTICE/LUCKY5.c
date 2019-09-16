// LUCKY5

#include <stdio.h>

#define getcu getchar_unlocked

int main(){
  int T, i,ni, c;
  char N[100002];
  scanf("%d\n",&T);
  while(T--){
    c=0, ni=0, i = getcu();
    while(i != '\n'){
      N[ni++] = i;
      i = getcu();
    }
    N[ni] == '\0';
    for(i=0; N[i] >= '0'; i++)
      if(N[i] == '4' || N[i] == '7')
        c++;
    printf("%d\n",i-c);
  }
  return 0;
}
