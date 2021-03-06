// FATCHEF

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked
#define ll long long
#define MOD 1000000009

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char a[100001];
int main(){
  char X;
  int T,N,M,Y, i,j;
  ll r;
  T = getn();
  while(T--){
    N = getn(), M = getn();
    memset(a, 0, N+1);
    for(i = 0; i < M; i++){
      X = gc(), Y = getn();
      a[Y] = X;
    }
    for(i = 1; !a[i]; i++);
    j = i++;
    for(r = 1; i <= N; i++){
      if(a[i]){
        if(a[i] != a[j])
          r = r * (i-j) % MOD;
        j = i;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
