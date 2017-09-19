// CHSQR

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[400][400];
int main(){
  int T,K, i,j,n,s;

  T = getn();
  while(T--){
    K = getn();

    if(K == 1)
      a[0][0] = 1;
    else
      for(i = (K>>1)-1, s = 1; s <= K; i = (i==K-1)?0:i+1, ++s)
        for(j = 0, n = s; j < K; ++j, n = (n==K)?1:n+1)
          a[i][j] = n;

    for(i = 0; i < K; ++i){
      for(j = 0; j < K; ++j)
        printf("%d ", a[i][j]);
      printf("\n");
    }
  }
  return 0;
}
