// CKISSHUG

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
inline long long comb(int n){
  long long r = 1, e = 2;
  while(n){
    if(n % 2)
      r = (r * e) % MOD;
    e = (e * e) % MOD;
    n /= 2;
  }
  return r;
}
int main(){
  int T = getn(),N;
  long long c, s;
  while(T--){
    N = getn();
    if(N == 1){
      printf("2\n");
      continue;
    }
    c = comb(N / 2);
    s = (c * 2 - 1) * 2;
    if(!(N % 2))
      s -= c;
    s %= MOD;
    printf("%lld\n",s);
  }
  return 0;
}
