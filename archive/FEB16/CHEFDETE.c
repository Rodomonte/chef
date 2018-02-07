// CHEFDETE

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char b[100001]={0};
int a[100001];
int main(){
  int N, i;
  N = getn();
  for(i = 1; i <= N; ++i)
    a[i] = getn(), b[a[i]] = 1;
  for(i = 1; i <= N; ++i)
    if(!b[i])
      printf("%d ", i);
  printf("\n");
  return 0;
}
