// STFM

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

int M;
int madd(int a, int b){
  a += b;
  if(a >= M)
    return a-M;
  if(a < 0)
    return a+M;
  return a;
}
int mmul(ll a, ll b){
  return (int)((a%M)*(b%M)%M);
}

int f[10000001];
ll a[100000];
int main(){
  int N, i,t,r;
  N = (int)getll(), M = (int)getll();
  for(i = 0; i < N; ++i)
    a[i] = getll();
  for(f[0] = i = 1; i <= M; ++i)
    f[i] = mmul(f[i-1], i);
  r = 0;
  // f(x) = x*x*(x+1)/2 + (x+1)! - 1
  for(i = 0; i < N; ++i){
    if(a[i]&1)
      r = madd(r, mmul(mmul(a[i], a[i]), (a[i]+1)>>1));
    else
      r = madd(r, mmul(mmul(a[i], a[i]>>1), a[i]+1));
    if(a[i]+1 < M)
      r = madd(r, f[a[i]+1]);
    r = madd(r, -1);
  }
  printf("%d\n",r);
}
