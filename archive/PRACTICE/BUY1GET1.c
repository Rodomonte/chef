// BUY1GET1

#include <stdio.h>

#define gc getchar_unlocked
int main(){
  char c;
  int T, a[52], i, n;
  scanf("%d\n",&T);
  while(T--){
    for(i = 0; i < 52; i++)
      a[i] = 0;
    while((c = gc()) != '\n')
      a[c<97?c-65:c-71]++;
    n = 0;
    for(i = 0; i < 52; i++)
      n += a[i]/2 + (a[i]%2?1:0);
    printf("%d\n",n);
  }
  return 0;
}
