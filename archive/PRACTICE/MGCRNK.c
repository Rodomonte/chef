// MGCRNK

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-'){
    f = -1;
    c = gc();
  }
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T = getn(), N, i,j, a[100][100];
  float m;
  while(T--){
    N = getn();
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        a[i][j] = getn();
        if(i && !j)
          a[i][j] += a[i-1][j];
        else if(!i && j)
          a[i][j] += a[i][j-1];
        else if(i && j)
          a[i][j] += a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
      }
    }
    m = (float)a[N-1][N-1] / (N*2-3);
    if(m < 0)
      printf("Bad Judges\n");
    else
      printf("%f\n",m);
  }
  return 0;
}
