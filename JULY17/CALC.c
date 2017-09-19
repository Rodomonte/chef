// CALC

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

int main(){
  int T,N,B, n,x,y;
  ll r,t;

  T = getn();
  while(T--){
    N = getn(), B = getn();

    y = N/B/2, n = max(1, N/B/4), r = 0;
    while(1){
      x = N-B*y, t = (ll)x*y;
      if(t > r) r = t;
      if(!n) break;
      if((ll)(y+1)*(N-B*(y+1)) > t) y += n;
      else y -= n;
      n = (n==1) ? 0 : ((n&1) ? (n>>1)+1 : (n>>1));
    }

    printf("%lld\n", r);
  }
  return 0;
}
