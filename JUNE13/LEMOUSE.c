// LEMOUSE

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

typedef struct {
  char d;
  int v;
} S;

int main(){
  char a[100][100];
  int T = getn(),N,M, i,j, v,h;
  S b[100][100];
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N; i++){
      for(j = 0; j < M; j++)
        a[i][j] = (gc()=='1'?1:0), b[i][j].v = 0;
      gc();
    }
    b[0][0].v = a[0][0] + a[0][1] + a[1][0];
    for(i = 1; i < N; i++){
      b[i][0].v = b[i-1][0].v + a[i][1];
      if(i < N-1)
        b[i][0].v += a[i+1][0];
      b[i][0].d = 'V';
    }
    for(j = 1; j < M; j++){
      b[0][j].v = b[0][j-1].v + a[1][j];
      if(j < M-1)
        b[0][j].v += a[0][j+1];
      b[0][j].d = 'H';
    }
    for(i = 1; i < N; i++){
      for(j = 1; j < M; j++){
        v = b[i-1][j].v, h = b[i][j-1].v;
        if(b[i-1][j].d == 'V')
          v += a[i][j-1];
        if(b[i][j-1].d == 'H')
          h += a[i-1][j];
        if(v < h){
           b[i][j].v = v;
           b[i][j].d = 'V';
        }else if(v > h){
          b[i][j].v = h;
          b[i][j].d = 'H';
        }else{
          b[i][j].v = v;
          b[i][j].d = 'E';
        }
        if(i < N-1)
          b[i][j].v += a[i+1][j];
        if(j < M-1)
          b[i][j].v += a[i][j+1];
      }
    }
    printf("%d\n",b[N-1][M-1].v);
  }
  return 0;
}
