// GRANAMA

#include <stdio.h>

#define gc getchar_unlocked
int main(){
  int T, i;
  char a[26],b[26], c, f;
  scanf("%d\n",&T);
  while(T--){
    for(i = 0; i < 26; i++)
      a[i] = 0, b[i] = 0;
    while((c = gc()) != ' ')
      a[c-97]++;
    while((c = gc()) != '\n')
      b[c-97]++;
    f = 0;
    for(i = 0; i < 26; i++){
      if((a[i] && !b[i]) || (!a[i] && b[i])){
        f = 0;
        break;
      }
      if(a[i] && b[i] && a[i] != b[i])
        f = 1;
    }
    printf(f?"NO\n":"YES\n");
  }
  return 0;
}
