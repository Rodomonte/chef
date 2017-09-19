// LCPESY

#include <stdio.h>

#define gc getchar_unlocked
int main(){
  char c;
  int T, i, a[123],b[123], r;
  scanf("%d\n",&T);
  while(T--){
    for(i = 48; i < 123; i++)
      a[i] = b[i] = 0;
    while((c=gc()) != '\n')
      a[c]++;
    while((c=gc()) != '\n')
      b[c]++;
    for(r = 0, i = 48; i < 123; i++)
      r += (a[i] < b[i]) ? a[i] : b[i];
    printf("%d\n",r);
  }
  return 0;
}
