// HOMDEL

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
  int N = getn(),M,S,G,D, a[250][250], i,j,k;
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      a[i][j] = getn();
  for(k = 0; k < N; k++)
    for(i = 0; i < N; i++)
      for(j = 0; j < N; j++)
        if(i != k && j != k && a[i][k] + a[k][j] < a[i][j])
          a[i][j] = a[i][k] + a[k][j];
  M = getn();
  while(M--){
    S = getn(), G = getn(), D = getn();
    G = a[S][G] + a[G][D];
    printf("%d %d\n",G,G-a[S][D]);
  }
  return 0;
}
