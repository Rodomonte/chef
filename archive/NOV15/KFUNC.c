// KFUNC

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

inline int getn(){
  int n = 0;
  char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
inline ll getll(){
  ll n = 0;
  char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[200]={0};
int fn(ll n){
  if(n < 200)
    return a[n];
  int s = n % 10;
  while(n >= 10){
    n /= 10;
    s += n % 10;
  }
  return fn(s);
}

int main(){
  int T,A,D, i,n0,n,s,p;
  ll L,R, t,r;

  n = 1;
  for(i = 1; i < 200; ++i){
    a[i] = n++;
    if(n == 10)
      n = 1;
  }

  T = getn();
  while(T--){
    A = getn(), D = getn(), L = getll(), R = getll();

    t = A;
    s = n0 = fn(t);
    t += D;
    n = fn(t);
    p = 1;
    while(n != n0){
      s += n;
      ++p;
      t += D;
      n = fn(t);
    }
    r = (R-L+1) / p * s;
    t = ((L-1)%s)*D + A;
    for(i = 0; i < (R-L+1)%p; ++i){
      r += fn(t);
      t += D;
    }

    printf("%lld\n", r);
  }
  return 0;
}
