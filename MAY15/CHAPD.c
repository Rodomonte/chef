// CHAPD

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

ll min(ll a, ll b){
  return (a < b) ? a : b;
}
ll max(ll a, ll b){
  return (a > b) ? a : b;
}
ll gcd(ll a, ll b){
  return b ? gcd(b,a%b) : a;
}

int main(){
  char r;
  ll T,A,B, g,n,t;
  T = getll();
  while(T--){
    A = getll(), B = getll();
    if(B == 1){
      printf("Yes\n");
      continue;
    }
    g = gcd(max(A,B), min(A,B));
    n = B / g;
    if(g == 1){
      r = 0;
    }else if(n == 1){
      r = 1;
    }else{
      r = 0;
      while(1){
        t = gcd(max(g,n), min(g,n));
        if(t == 1)
          break;
        n /= t;
        if(A % n == 0){
          r = 1;
          break;
        }
      }
    }
    printf(r ? "Yes\n" : "No\n");
  }
  return 0;
}
