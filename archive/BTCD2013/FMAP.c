// FMAP

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
  int T,N,S,G, i,j,t, a[20001];
  T = getn();
  while(T--){
    N = getn(), S = getn(), G = getn();
    for(i = 1; i < S; i++)
      a[i] = getn();
    a[S] = 0;
    for(i = S+1; i <= N; i++)
      a[i] = getn();
    i = G, j = a[G];
    while(j){
      t = a[j];
      a[j] = i;
      i = j;
      j = t;
    }
    for(i = 1; i < G; i++)
      printf("%d ",a[i]);
    for(i = G+1; i <= N; i++)
      printf("%d ",a[i]);
    printf("\n");
  }
  return 0;
}
