// MAXSC

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[700][700];
int main(){
  int T,N, i,j, m,p;
  ll r;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i) for(j = 0; j < N; ++j) a[i][j] = getn();

    for(i = N-1, p = INF, r = 0; i >= 0; --i){
      for(j = m = 0; j < N; ++j) if(a[i][j] < p && a[i][j] > m) m = a[i][j];
      if(!m){ r = -1; break; }
      p = m, r += m;
    }
    printf("%lld\n", r);
  }
  return 0;
}
