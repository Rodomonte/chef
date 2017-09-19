// GOODSET

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char a[501];
  int T,N, i,j;

  for(i = 1; i <= 500; ++i)
    a[i] = 1;
  for(i = 2; i <= 500; ++i){
    if(!a[i]) continue;
    for(j = 1; j < i; ++j)
      if(a[j] && i+j <= 500)
        a[i+j] = 0;
  }

  T = getn();
  while(T--){
    N = getn();

    for(i = 1, j = 0; i <= 500 && j < N; ++i)
      if(a[i])
        printf("%d ", i), ++j;
    printf("\n");
  }
  return 0;
}
