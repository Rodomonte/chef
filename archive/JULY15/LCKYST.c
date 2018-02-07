// LCKYST

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

inline int getn(){
  int n = 0;
  char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T, i,m,c;
  ll n,t,r;
  T = getn();
  while(T--){
    r = n = getn(), m = -1;
    while(1){
      t = n, c = 0;
      while(t % 10 == 0)
        t /= 10, ++c;
      if(c > m)
  m = c, r = n;
      else
  break;
      n <<= 2;
    }
    printf("%lld\n", r);
  }
  return 0;
}

