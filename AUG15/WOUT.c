// WOUT

#include <stdio.h>
#include <string.h>

#define ll long long
#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[1000001], N;
void update(int i, int v){
  for(; i <= N; i += (i&(-i)))
    a[i] += v;
}
int query(int i){
  int r = 0;
  for(; i; i -= (i&(-i)))
    r += a[i];
  return r;
}

int b[1000000];
int main(){
  int T,H,L,R, i;
  ll s,m;
  T = getn();
  while(T--){
    N = getn(), H = getn();

    memset(a, 0, 4000004);
    for(i = 0; i < N; ++i){
      L = getn()+1, R = getn()+1;
      update(L, 1);
      update(R+1, -1);
    }
    for(i = 0; i < N; ++i)
      b[i] = query(i+1);

    s = 0;
    for(i = 0; i < H; ++i)
      s += b[i];
    m = s;
    for(i = 1; i+H-1 < N; ++i){
      s += b[i+H-1] - b[i-1];
      if(s > m)
  m = s;
    }

    printf("%lld\n", (ll)H*N-m);
  }
  return 0;
}
