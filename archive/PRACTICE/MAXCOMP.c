// MAXCOMP

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
  int T,N,S,E,C, i,j, a[49][49],b[49], m,n;
  T = getn();
  while(T--){
    N = getn(), m = 0;
    for(i = 0; i < 49; i++){
      for(j = 0; j < 49; j++)
        a[i][j] = 0;
      b[i] = 0;
    }
    for(i = 0; i < N; i++){
      S = getn(), E = getn(), C = getn();
      if(E > m)
        m = E;
      if(C > a[S][E])
        a[S][E] = C;
    }
    for(j = 1; j <= m; j++){
      n = 0;
      for(i = 0; i < j; i++)
        if(a[i][j] + b[i] > n)
          n = a[i][j] + b[i];
      b[i] = n;
    }
    printf("%d\n",b[m]);
  }
  return 0;
}
