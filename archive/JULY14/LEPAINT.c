// LEPAINT

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
  int T,N,C,K,L,R, i,j,k;
  double a[51][100], a0[51][100], t,u,v,r;
  T = getn();
  while(T--){
    N = getn(), C = getn(), K = getn();
    for(i = 1; i <= N; i++){
      a[i][0] = 0.0, a[i][1] = 1.0;
      for(j = 2; j < C; j++)
        a[i][j] = 0.0;
    }
    t = 1.0 / C;
    while(K--){
      L = getn(), R = getn();
      for(i = 1; i <= N; i++)
        for(j = 0; j < C; j++)
          a0[i][j] = a[i][j];
      for(i = L; i <= R; i++)
        for(j = 0; j < C; j++)
          a[i][j] = 0.0;
      u = (double)(1LL<<(R-L)) / (1LL<<(R-L+1));
      v = (double)((1LL<<(R-L+1))-(1LL<<(R-L))) / (1LL<<(R-L+1));
      for(i = L; i <= R; i++)
        for(j = 0; j < C; j++){
          a[i][j] += a0[i][j] * u;
          for(k = 0; k < C; k++)
            a[i][j*k%C] += a0[i][j] * t * v;
        }
    }
    r = 0.0;
    for(i = 1; i <= N; i++)
      for(j = 0; j < C; j++)
        r += a[i][j] * j;
    printf("%.7lf\n",r);
  }
  return 0;
}
