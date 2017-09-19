// CHEFCH

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char s[100000];
int main(){
  char c;
  int T, i,n,m,t;
  T = getn();
  while(T--){
    scanf("%s", s);
    n = strlen(s), m = 100000, t = 0, c = '+';
    for(i = 0; i < n; ++i){
      t = (s[i] != c) ? t+1 : t;
      c = (c == '+') ? '-' : '+';
    }
    m = (t < m) ? t : m;
    t = 0, c = '-';
    for(i = 0; i < n; ++i){
      t = (s[i] != c) ? t+1 : t;
      c = (c == '+') ? '-' : '+';
    }
    m = (t < m) ? t : m;
    printf("%d\n", m);
  }
  return 0;
}
