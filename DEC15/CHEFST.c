//CHEFST

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

inline ll getll(){
  ll n = 0;
  char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  ll T,A,B,M, t,r;
  T = getll();
  while(T--){
    A = getll(), B = getll(), M = getll();
    t = (M*(M+1))>>1;
    if(A > t && B > t)
      r = A-t+B-t;
    else if(A > B)
      r = A-B;
    else
      r = B-A;
    printf("%lld\n", r);
  }
  return 0;
}
