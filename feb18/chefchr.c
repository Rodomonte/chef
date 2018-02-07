// CHEFCHR

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char s[500001];
int main(){
  char c,h,e,f;
  int T, i,j,k, r;

  T = getn();
  while(T--){
    scanf("%s", s);

    for(i = r = 0, k = strlen(s)-3; i < k; ++i){
      for(j = i, c = h = e = f = 0; j < i+4; ++j){
        if(s[j] == 'c') c = 1;
        else if(s[j] == 'h') h = 1;
        else if(s[j] == 'e') e = 1;
        else if(s[j] == 'f') f = 1;
      }
      if(c && h && e && f) ++r;
    }

    if(r) printf("lovely %d\n", r);
    else printf("normal\n");
  }
  return 0;
}
