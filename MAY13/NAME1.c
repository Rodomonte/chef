// NAME1

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char c,f;
  int T = getn(),N, i, a[26],b[26];
  while(T--){
    for(i = 0; i < 26; i++)
      a[i] = b[i] = 0;
    while((c=gc()) != ' ')
      a[c-97]++;
    while((c=gc()) != '\n')
      a[c-97]++;
    N = getn(), f = 1;
    while(N--){
      while((c=gc()) != '\n'){
        if(f){
          i = c - 97;
          b[i]++;
          if(b[i] > a[i]){
            f = 0;
            while((c=gc()) != '\n');
            break;
          }
        }
      }
    }
    printf(f?"YES\n":"NO\n");
  }
  return 0;
}
