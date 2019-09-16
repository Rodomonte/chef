// KS1

#include <stdio.h>
#include <vector>

#define ll long long
#define vec std::vector
#define pb push_back
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[100000];
vec<int> b[1048576];
int main(){
  int T,N, i,j,k,n;
  ll r,t;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      a[i] = getn();
    for(i = 0; i < 1048576; ++i)
      b[i].clear();

    b[0].pb(-1);
    for(n = i = 0; i < N; ++i)
      n ^= a[i], b[n].pb(i);
    for(i = 0, r = 0; i < 1048576; ++i){
      if(b[i].size() < 2) continue;
      t = (b[i][1] - b[i][0] - 1) * (b[i].size() - 1);
      for(j = 2; j < b[i].size(); ++j)
        t += ((b[i][j] - b[i][j-1]) * j - 1) * (b[i].size() - j);
      r += t;
    }

    printf("%lld\n", r);
  }
  return 0;
}
