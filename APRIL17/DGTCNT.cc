// DGTCNT

#include <stdio.h>
#include <unordered_map>

using std::unordered_map;

#define ll long long
#define gc getchar//_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

ll pow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1)
      r *= n;
    n *= n, e >>= 1;
  }
  return (ll)r;
}

int a[10],b[10],c[10],bn;
ll fac[20];
unordered_map<ll,int> xm;

ll fn(ll n, ll d){
  int j,f,xn,cs;
  ll t;
  unordered_map<ll,int>::iterator it;

  for(j = 0; j < 10; ++j)
    c[j] = b[j];
  it = xm.find(d);
  if(it == xm.end()){
    t = d, xn = 0;
    while(t > 1)
      t /= 10, ++xn;
    xm[d] = xn;
  }else
    xn = it->second;
  t = d, f = 0;
  while(t <= n){
    j = n/t%10;
    if(!c[j]){
      f = 1;
      break;
    }else if(c[j] > 0)
      --c[j];
    t *= 10;
  }
  if(f)
    return 0;

  cs = 0;
  for(j = 0; j < 10; ++j)
    if(c[j] > 0)
      cs += c[j];
  if(cs > xn)
    return 0;
  xn -= cs, t = 1;
  for(j = 0; j < 10; ++j)
    if(c[j] > 1)
      t *= fac[c[j]];

  return pow(10-bn, xn) * (fac[cs+xn] / (fac[cs]*fac[xn])) *
         (fac[cs] / t);
}

int main(){
  char f;
  int T, i,j;
  ll L,R, r,rt,n,d;

  fac[0] = 1;
  for(i = 1; i < 20; ++i)
    fac[i] = fac[i-1] * i;

  T = getn();
  while(T--){
    scanf("%lld %lld", &L, &R);
    for(i = 0; i < 10; ++i)
      a[i] = getn();

    r = R-L+1;
    for(i = 1; i < (1<<10); ++i){
      for(j = 0; j < 10; ++j)
        b[j] = -1;
      bn = 0;
      for(j = 0; j < 10; ++j)
        if((i>>j)&1)
          b[j] = a[j], ++bn;

      rt = f = 0;
      for(n = L, d = 1; n <= R; n += d){
        while(!f && n+d < R && !(n/d%10))
          d *= 10;
        if(!f && d > 1 && n+d > R)
          f = 1;
        while(f && n < R && n/d%10 == R/d%10)
          d /= 10;
        while(f && d > 1 && n == R)
          d /= 10;

        rt += fn(n, d);
      }
      r += rt * ((bn&1) ? -1 : 1);
    }
    printf("%lld\n", r);
  }
  return 0;
}
