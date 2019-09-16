// SUBANAGR

#include <stdio.h>

int main(){
  int N, i,j, a[26], w[26];
  char c, f;
  scanf("%d\n",&N);
  for(i = 0; i < 26; i++)
    a[i] = 100;
  while(N--){
    for(i = 0; i < 26; i++)
      w[i] = 0;
    c = getchar_unlocked();
    while(c != '\n'){
      w[c-'a']++;
      c = getchar_unlocked();
    }
    for(i = 0; i < 26; i++)
      if(w[i] < a[i])
        a[i] = w[i];
  }
  f = 0;
  for(i = 0; i < 26; i++){
    if(a[i]){
      f = 1;
      for(j = 0; j < a[i]; j++)
        putchar_unlocked(i+'a');
    }
  }
  if(!f) printf("no such string");
  putchar('\n');
  return 0;
}
