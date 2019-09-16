// STDYTAB

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int madd(int a, int b){ return (a+b>=MOD) ? a+b-MOD : a+b; }
int mmul(int a, int b){ return (ll)a * b % MOD; }

int nck[4000][2001]={{0}}, r[2001][2001];
int main(){
  int T,N,M, i,j;

  for(i = nck[0][0] = 1; i < 4000; i++)
    for(j = nck[i][0] = 1; j <= min(2000, i); j++)
      nck[i][j] = madd(nck[i-1][j-1], nck[i-1][j]);
  for(i = 0; i <= 2000; ++i) r[0][i] = r[i][0] = 1;

  T = getn();
  while(T--){
    N = getn(), M = getn();

    for(i = 1; i <= N; ++i) for(j = 1; j <= M; ++j)
      r[i][j] = madd(r[i][j-1], mmul(nck[M+j-1][j], r[i-1][j]));

    printf("%d\n", r[N][M]);
  }
  return 0;
}
