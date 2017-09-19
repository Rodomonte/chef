// PROSUM

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define ll long long
int main(){
  int T,N,A, i,t,g;
  ll r;
  T = getn();
  while(T--){
    N = getn(), t = g = 0, r = 0;
    for(i = 0; i < N; i++){
      A = getn();
      if(A == 0 || A == 1)
        r += N-i-1 + g;
      else if(A == 2)
        r += t++, g++;
      else
        g++;
    }
    printf("%lld\n",(((ll)N*(N-1))>>1)-r);
  }
  return 0;
}

