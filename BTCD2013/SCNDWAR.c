// SCNDWAR

#include <stdio.h>
#include <string.h>
#include <math.h>

#define ull unsigned long long
int main(){
  char s[61],c;
  int T, i, a[36],an, l,n;
  ull p,r;
  scanf("%d\n",&T);
  while(T--){
    an = r = 0;
    for(i = 0; i < 36; i++)
      a[i] = -1;
    scanf("%s",s);
    l = strlen(s);
    for(i = 0; i < l; i++){
      c = s[i];
      n = (c>=48&&c<=57) ? c-48 : c-87;
      if(a[n] < 0){
        if(!an) a[n] = 1;
        else if(an == 1) a[n] = 0;
        else a[n] = an;
        an++;
      }
    }
    if(an == 1){
      printf("%llu\n",(ull)pow(2,l)-1);
      continue;
    }
    p = 1;
    for(i = l-1; i >= 0; i--){
      c = s[i];
      n = (c>=48&&c<=57) ? c-48 : c-87;
      r += a[n] * p;
      p *= an;
    }
    printf("%llu\n",r);
  }
  return 0;
}
