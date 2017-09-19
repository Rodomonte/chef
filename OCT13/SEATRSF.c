// SEATRSF

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define pc putchar_unlocked
inline void putn(int n){
  if(!n) pc('0');
  char pb[10];
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

#define ll long long
#define MOD 1000000007
ll pow(ll n, int e){
  ll r = 1;
  while(e){
    if(e % 2)
      r = (r * n) % MOD;
    n = (n * n) % MOD;
    e /= 2;
  }
  return r;
}
int main(){
  int T,N,M,Q,K, r;
  T = getn();
  while(T--){
    N = getn(), M = getn(), Q = getn(), K = getn();
    if(Q >= M){
      putn(0);
      pc('\n');
      continue;
    }
    r = ((pow(Q+1,N) - ((pow(Q,N)*2)%MOD) + pow(Q-1,N)) * (ll)(M-Q)) % MOD;
    if(r < 0)
      r += MOD;
    putn(r);
    pc('\n');
  }
  return 0;
}
