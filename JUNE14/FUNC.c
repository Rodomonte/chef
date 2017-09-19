// FUNC
 
#include <stdio.h>
#include <math.h>

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007
const ll MAX = 1000000000000000000L;

inline int getn(){
  char c = gc(), f = 0; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = 1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return (f) ? 0-n : n;
}
 
inline ll getl(){
  char c = gc(); ll n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}
 
char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}
 
int pmod(int n){
  if(n >= MOD)
    return n - MOD;
  return n;
}
 
int nmod(int n){
  if(n < 0)
    return n + MOD;
  return n;
}
 
ll p2cor(ll X, ll n){
  while(n*n > X)
    n--;
  while((n+1)*(n+1) <= X)
    n++;
  return n;
}
 
ll p3cor(ll X, ll n){
  while(n*n*n > X)
    n--;
  while((n+1)*(n+1)*(n+1) <= X)
    n++;
  return n;
}
 
char cprod(ll n, int e){
  if(n < 10000000000000000L)
    return 1;
  int i;
  ll r = n;
  for(i = 2, r = 0; i <= e; i++){
    r += n;
    if(r > MAX)
      return 0;
  }
  return 1;
}
 
int root(ll X, ll* c){
  int i = 1, j = c[0], t;
  while(j-i > 1){
    t = i+((j-i)>>1);
    if(X < c[t])
      j = t;
    else
      i = t;
  }
  return i;
}

ll cbrt1(ull x){
  int s;
  ui y;
  ull b;
  y = 0;
  for(s = 63; s >= 0; s -= 3){
    y += y;
    b = 3*y*((ull)y+1)+1;
    if((x>>s) >= b)
      x -= b << s, y++;
  }
  return (ll)y;
}

int min(int a, int b){
  return (a < b) ? a : b;
}
 
int a[10001], b[61];
ll c4[31624],c5[3983],c[60][1002];
int main(){
  int T,N,Q, i,j,k,t,r;
  ll X, l;
 
  // c[t][i]: i^t
  c4[0] = 31623, c5[0] = 3982, c[6][0] = 1001;
  c4[1] = c5[1] = c[6][1] = 1;
  for(i = 2; i <= 31623; i++)
    c4[i] = (ll)i*i, c4[i] *= c4[i];
  for(i = 2; i <= 3982; i++)
    c5[i] = c4[i]*i;
  for(i = 2; i <= 1001; i++)
    c[6][i] = c5[i]*i;
  for(t = 7; t <= 59; t++){
    c[t][1] = 1;
    for(i = 2; c[t][i-1] <= MAX; i++){
      if(!cprod(c[t-1][i],i))
        c[t][i] = MAX+1;
      else
        c[t][i] = c[t-1][i]*i;
    }
    c[t][0] = i-1;
  }
 
  T = getn();
  while(T--){
    N = getn(), Q = getn(), t = 0;
    for(i = 1; i <= N; i++)
      a[i] = nmod(getn());
 
    // b[i]: Sum(a[i]..a[N])
    for(i = N; i >= 60; i--)
      t = pmod(t + a[i]);
    if(N < 60)
      t = a[N];
    for(i = min(59,N-1), b[min(60,N)] = t; i >= 1; i--)
      b[i] = pmod(b[i+1] + a[i]);
 
    while(Q--){
      X = getl();
      r = ((X%MOD) * a[1])%MOD;
      // OPT: N=2,3 Newton to .1 prec
      // OPT: Quit once root < 2
      if(N >= 2)
        r = pmod(r + (p2cor(X,(ll)floor(sqrt(X)))*a[2])%MOD);
      if(N >= 3)
        r = pmod(r + (p3cor(X,cbrt1(X))*a[3])%MOD);
      if(N >= 4)
        r = pmod(r + ((ll)root(X,c4)*a[4])%MOD);
      if(N >= 5)
        r = pmod(r + ((ll)root(X,c5)*a[5])%MOD);
      for(k = 6; k <= min(59,N); k++){
        t = root(X,c[k]);
        if(t == 1)
          break;
        r = pmod(r + ((ll)t*a[k])%MOD);
      }
      if(N >= k)
        r = pmod(r + b[k]);
      putn(r); pc(' ');
    }
    pc('\n');
 
  }
  return 0;
}
