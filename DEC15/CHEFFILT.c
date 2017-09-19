// CHEFFILT

#include <stdio.h>

#define gc getchar_unlocked
#define MOD 1000000007

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int madd(int a, int b){
  a += b;
  if(a >= MOD)
    a -= MOD;
  return a;
}

int a[100000], d[100000][1024];
int main(){
  int T,S,N, i,j,e;

  T = getn();
  while(T--){
    for(S = 0, e = 9; e >= 0; --e)
      if(gc() == 'b')
  S += (1<<e);
    S ^= 1023;
    //printf("  S=%d\n", S);
    N = getn();
    for(i = 0; i < N; ++i){
      for(a[i] = 0, e = 9; e >= 0; --e)
  if(gc() == '+')
    a[i] += (1<<e);
      //printf("  a[%d]=%d\n", i, a[i]);
      gc();
    }

    d[0][0] = a[0] ? 1 : 2;
    for(i = 1; i < 1024; ++i)
      d[0][i] = (a[0] == i) ? 1 : 0;
    for(i = 1; i < N; ++i)
      for(j = 0; j < 1024; ++j){
        d[i][j] = madd(d[i-1][j], d[i-1][j^a[i]]);
  //if(d[i][j])
  //  printf("  d[%d][%d] = d[%d][%d]=%d + d[%d][%d]=%d = %d\n",
  //   i,j,i-1,j,d[i-1][j],i-1,j^a[i],d[i-1][j^a[i]],d[i][j]);
      }

    printf("%d\n", d[N-1][S]);
  }
  return 0;
}
