// CLMBSTRS

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define MOD 1000000007
#define MAX 1000001
#define C1 033333333333
#define C2 011111111111
#define C3 030707070707
int a[MAX];
int main(){
  int T,N,G, i, m,n,c,r;
  T = getn(), a[1] = 1, a[2] = m = 2;
  while(T--){
    N = getn(), G = getn();
    for(i = m+1; i <= N; i++)
      a[i] = (a[i-1] + a[i-2]) % MOD;
    if(N > m)
      m = N;
    n = a[N];
    c = n - ((n >> 1) & C1) - ((n >> 2) & C2);
    r = ((c + (c >> 3)) & C3) % 63;
    printf(r==G?"CORRECT\n":"INCORRECT\n");
  }
  return 0;
}
