// MCHAIRS

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
  return (int)r;
}

int main(){
  int T,N;
  T = getn();
  while(T--){
    N = getn();
    printf("%d\n",pow(2,N)-1);
  }
  return 0;
}
