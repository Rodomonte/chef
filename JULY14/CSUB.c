// CSUB

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char c;
  int T,N, i;
  ll r;
  T = getn();
  while(T--){
    N = getn(), r = 0;
    for(i = 0; i < N; i++)
      if((c=gc()) == '1')
        r++;
    r += (r*(r-1))>>1;
    printf("%lld\n",r);
  }
  return 0;
}
