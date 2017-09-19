// CPERM

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int msub(int a, int b){
  return ((a-=b)<0) ? a+MOD : a;
}
int mpow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1)
      r = (r * n) % MOD;
    n = (n * n) % MOD;
    e >>= 1;
  }
  return (int)r;
}

int main(){
  int T,N;
  T = getn();
  while(T--){
    N = getn();
    printf("%d\n", (N < 3) ? 0 : msub(mpow(2,N-1),2));
  }
  return 0;
}
