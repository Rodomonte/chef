// FLAGS

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

ll nck[10001][5];
int main(){
  int T,N, n,k;
  ll r;
  for(n = 0; n <= 10000; n++)
    nck[n][0] = 1;
  nck[0][1] = nck[0][2] = nck[0][3] = nck[0][4] = 0;
  for(n = 1; n <= 10000; n++)
    for(k = 1; k <= 4; k++)
      nck[n][k] = nck[n-1][k-1] + nck[n-1][k];
  T = getn();
  while(T--){
    N = getn(), r = 0;
    r += nck[N][2]*4;
    r += nck[N][3]*30;
    r += nck[N][4]*48;
    printf("%lld\n",r);
  }
  return 0;
}
