// PALINGAM

#include <stdio.h>
#include <string.h>

char a[501], b[501];
int main(){
  char f;
  int T, i, an, c[26],d[26];

  scanf("%d", &T);
  while(T--){
    scanf("%s%s", a, b), an = strlen(a);

    for(i = 0; i < 26; ++i) c[i] = d[i] = 0;
    for(i = 0; i < an; ++i) ++c[a[i]-'a'];
    for(i = 0; i < an; ++i) ++d[b[i]-'a'];

    /* If P1 has 2+ of any char that P2 doesn't have, he wins
       Else if P1 doesn't have any char that P2 doesn't have, he loses
       * P1 plays 'a'
       If P2 doesn't have any char that P1 doesn't have, he loses
       * P2 plays 'b' -> 'ab'
       Now it can never be a palindrome: P2 win
    */

    for(i = f = 0; i < 26; ++i)
      if(c[i] > 1 && !d[i]) f = 1;
    if(f){ printf("A\n"); continue; }
    for(i = f = 0; i < 26; ++i)
      if(c[i] > 0 && !d[i]) f = 1;
    if(!f){ printf("B\n"); continue; }
    for(i = f = 0; i < 26; ++i)
      if(d[i] > 0 && !c[i]) f = 1;
    if(!f){ printf("A\n"); continue; }
    printf("B\n");
  }
  return 0;
}
