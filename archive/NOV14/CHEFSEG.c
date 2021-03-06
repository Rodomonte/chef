// CHEFSEG

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

inline ll getll(){
  char c = gc();
  ll n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  ll T,X,K, s,k;
  double i;
  T = getll();
  while(T--){
    X = getll(), K = getll(), s = 1, k = 0, i = (double)X / 2.0;
    while(1){
      if(k + s >= K)
        break;
      k += s;
      s <<= 1;
      i /= 2;
    }
    printf("%lf\n", i+2.0*i*(K-k-1));
  }
  return 0;
}
