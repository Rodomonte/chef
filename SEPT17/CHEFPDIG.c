// CHEFPDIG

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char a[100001], b[26];
int main(){
  int T, i, n,o,t, d[10];

  T = getn();
  while(T--){
    scanf("%s", a);

    for(i = 0; i < 10; ++i) d[i] = 0;
    for(i = 0; a[i]; ++i) ++d[a[i]-'0'];
    for(i = 0; i < 26; ++i) b[i] = 0;

    for(i = 0, t = 6, o = 5; i < 26; ++i){
      if(t == o && d[t] > 1) b[i] = 1;
      else if(t != o && d[t] > 0 && d[o] > 0) b[i] = 1;
      ++o;
      if(o == 10) ++t, o = 0;
    }

    for(i = 0; i < 26; ++i) if(b[i]) printf("%c", i+65);
    printf("\n");
  }
  return 0;
}
