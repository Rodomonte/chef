// TAPALIN

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
int pow(long long n, int e){
  long long r = 1;
  while(e){
    if(e % 2)
      r = (r * n) % MOD;
    n = (n * n) % MOD;
    e /= 2;
  }
  return r;
}
int main(){
  int T = getn(),N;
  long long r, m = pow(25, MOD-2);
  while(T--){
    N = getn();
    r = ((((pow(26, N/2) - 1) * m) % MOD) * 52) % MOD;
    if(N % 2)
      r = (r + pow(26, N/2 + 1)) % MOD;
    printf("%lld\n",r);
  }
  return 0;
}
