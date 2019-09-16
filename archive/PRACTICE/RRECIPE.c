// RRECIPE

#include <stdio.h>
#include <string.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), l, i, n;
  char s[1000001];
  while(T--){
    n = 1;
    gets(s);
    l = strlen(s);
    for(i = 0; i < (l+1)/2; i++){
      if(s[i] == s[l-1-i]){
        if(s[i] == '?')
          n = (n*26) % 10000009L;
      }else{
        if(s[i] != '?' && s[l-1-i] != '?'){
          n = 0;
          break;
        }
      }
    }
    printf("%d\n",n);
  }
  return 0;
}
