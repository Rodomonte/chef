// CUBESUM

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[100][100][100];
int main(){
  int T = getn(),X,Y,Z, i,j,k, n;
  while(T--){
    X = getn(), Y = getn(), Z = getn();
    for(i = 0; i < X; i++)
      for(j = 0; j < Y; j++){
        a[i][j][0] = getn(), n = 0;
        if(i){
          n += a[i-1][j][0];
          if(j)
            n -= a[i-1][j-1][0];
        }
        if(j)
          n += a[i][j-1][0];
        printf("%d",a[i][j][0]-n);
        for(k = 1; k < Z; k++){
          a[i][j][k] = getn(), n = a[i][j][k-1];
          if(i){
            n += a[i-1][j][k];
            n -= a[i-1][j][k-1];
            if(j){
              n -= a[i-1][j-1][k];
              n += a[i-1][j-1][k-1];
            }
          }
          if(j){
            n += a[i][j-1][k];
            n -= a[i][j-1][k-1];
          }
          printf(" %d",a[i][j][k]-n);
        }
        printf("\n");
      }
  }
  return 0;
}
