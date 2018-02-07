// DELISH

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

#define ll long long
ll absll(ll a){
  return a < 0 ? -a : a;
}
ll minll(ll a, ll b){
  return a < b ? a : b;
}
ll maxll(ll a, ll b){
  return a < b ? b : a;
}
int main(){
  int T = getn(),N, i, a[10000];
  long long mn[10000], mx[10000], n,pmn,pmx,rmn,rmx,r;
  while(T--){
    N = getn(), a[0] = mn[0] = mx[0] = pmn = pmx = getn();
    for(i = 1; i < N; i++){
      n = a[i] = getn();
      pmn = minll(n, pmn+n);
      mn[i] = minll(mn[i-1], pmn);
      pmx = maxll(n, pmx+n);
      mx[i] = maxll(mx[i-1], pmx);
    }
    pmn = pmx = rmn = rmx = a[N-1];
    r = maxll(absll(mx[N-2]-rmn), absll(rmx-mn[N-2]));
    for(i = N-2; i > 0; i--){
      n = a[i];
      pmn = minll(n, pmn+n);
      rmn = minll(rmn, pmn);
      pmx = maxll(n, pmx+n);
      rmx = maxll(rmx, pmx);
      r = maxll(r, maxll(absll(mx[i-1]-rmn), absll(rmx-mn[i-1])));
    }
    printf("%lld\n",r);
  }
  return 0;
}
