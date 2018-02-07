// SPOTWO

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

#define llu unsigned long long
#define MOD 1000000007
llu pow(llu n, llu e, char m){
  llu r = 1;
  while(e){
    if(e % 2){
      r *= n;
      if(m) r %= MOD;
    }
    n *= n;
    if(m) n %= MOD;
    e /= 2;
  }
  return r;
}

int main(){
  int T,N, i, dp[20] = { 524288, 262144, 131072, 65536, 32768, 16384, 8192,
      4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1 };
  llu b, bp[20] = { 10000000000000000000UL, 1000000000000000000UL,
      100000000000000000UL, 10000000000000000UL, 1000000000000000UL,
      100000000000000UL, 10000000000000UL, 1000000000000UL,
      100000000000UL, 10000000000UL, 1000000000UL, 100000000UL,
      10000000UL, 1000000UL, 100000UL, 10000UL, 1000UL, 100UL, 10UL,
      1UL };
  T = getn();
  while(T--){
    N = getn(), b = i = 0;
    while(N){
      if(N >= dp[i]){
        N -= dp[i];
        b += bp[i];
      }
      i++;
    }
    putn((int)pow(pow(2,b,1),2,1));
    pc('\n');
  }
  return 0;
}
