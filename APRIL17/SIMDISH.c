// SIMDISH

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

int main(){
  int T, i,j,n;
  char a[4][11], b[4][11];

  T = getn();
  while(T--){
    for(i = 0; i < 4; ++i)
      scanf("%s", a[i]);
    for(i = 0; i < 4; ++i)
      scanf("%s", b[i]);

    n = 0;
    for(i = 0; i < 4; ++i)
      for(j = 0; j < 4; ++j)
        if(!strcmp(a[i], b[j])){
          ++n;
          break;
        }

    printf((n >= 2) ? "similar\n" : "dissimilar\n");
  }
  return 0;
}
