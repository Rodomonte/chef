// NSUDOKU

#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
inline void putn(int n){
  int t;
  if(n >= 100){
    t = n / 100;
    pc(t + '0');
    n -= t * 100;
    t = n / 10;
    pc(t + '0');
    n -= t * 10;
    pc(n + '0');
  }else if(n >= 10){
    t = n / 10;
    pc(t + '0');
    n -= t * 10;
    pc(n + '0');
  }else{
    pc(n + '0');
  }
}

char r[900][901]={{0}}, c[900][901]={{0}}, b[30][30][901]={{0}};
int a[900][900]={{0}};
int main(){
  int N=getn(),N2, K=getn(), i,j,k, bi,bj, n=0,cf,n1,n2,nn;
  N2 = N * N;
  srand(time(NULL));
  while(K--){
    i=getn()-1, j=getn()-1, n=getn();
    a[i][j] = n, r[i][n] = 1, c[j][n] = 1, b[i/N][j/N][n] = 1;
  }
  for(i = 0; i < N2; i++){
    bi = i / N;
    for(j = 0; j < N2; j++){
      if(!a[i][j]){
        bj = j / N, n1 = 0, n2 = 0;
        for(k = 0; k < N2; k++){
          n++; if(n > N2) n = 1;
          cf = 0;
          if(r[i][n]) cf++;
          if(c[j][n]) cf++;
          if(b[bi][bj][n]) cf++;
          if(!cf){
            a[i][j] = n, r[i][n] = 1, c[j][n] = 1, b[bi][bj][n] = 1;
            break;
          }
          if(!n1 && cf == 1)
            n1 = n;
          else if(!n2 && cf == 2)
            n2 = n;
        }
        if(!a[i][j]){
          if(n1) nn = n1;
          else if(n2) nn = n2;
          else nn = n==N2 ? 1 : n+1;
          a[i][j] = nn, r[i][nn] = 1, c[j][nn] = 1, b[bi][bj][nn] = 1;
          n++; if(n > N2) n = 1;
        }
      }
      putn(a[i][j]);
      pc(' ');
    }
    pc('\n');
  }
  return 0;
}
