// FAULT - WORST CASE

#include <stdio.h>

#define gc getchar//_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[1000][200] = {{0}};
int main(){
  int N=getn(),S=getn(),C, i,j;
  for(i = 0; i < S; i++){
    C = getn();
    for(j = 0; j < C; j++)
      a[i][j] = getn();
  }
  printf("%d\n",S);
  for(i = 0; i < S; i++)
    printf("%d\n",i);
  return 0;
}
