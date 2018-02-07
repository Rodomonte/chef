// CHEFROUT

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char a[100001];
int main(){
  char e,s,r;
  int T,N, i;

  T = getn();
  while(T--){
    scanf("%s", a);

    N = strlen(a), e = s = 0, r = 1;
    for(i = 0; i < N; ++i){
      if(a[i] == 'C'){
        if(e || s)
          r = 0;
      }else if(a[i] == 'E'){
        e = 1;
        if(s)
          r = 0;
      }else
        s = 1;
    }

    printf(r ? "yes\n" : "no\n");
  }
  return 0;
}
