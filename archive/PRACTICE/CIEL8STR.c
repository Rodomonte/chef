// CIEL8STR

#include <stdio.h>

char s[1000001];
int main(){
  unsigned long long r = 0;
  int i = 0, j, n, d = 0;
  char c;
  gets(s);
  while((c=s[i]) != '\0'){
    if(c == '8' || c == '0')
      r++;
    if(i > 0){
      n = (c-48) + (s[i-1]-48)*10;
      if(n >= 10 && !(n % 8))
        r++;
      if(i > 1){
        if(i > 2 && s[i-3] != '0')
          d++;
        n += (s[i-2]-48)*100;
        if(!(n % 8)){
          if(n >= 100)
            r++;
          r += d;
        }
      }
    }
    i++;
  }
  printf("%llu\n",r);
  return 0;
}
