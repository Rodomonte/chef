// GCAC

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

char q[1000][1001];
int ms[1000], os[1000], mo[1000], jo[1000];
int main(){
  int T,N,M, i,j,k, m, r1,r3;
  ll r2;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N; ++i) ms[i] = getn();
    for(i = 0; i < M; ++i) os[i] = getn(), mo[i] = getn(), jo[i] = 0;
    for(i = 0; i < N; ++i) scanf("%s", q[i]);

    r1 = r2 = r3 = 0;
    for(i = 0; i < N; ++i){
      for(j = m = 0; j < M; ++j)
        if(q[i][j] == '1' && jo[j] < mo[j] && os[j] >= ms[i] && os[j] > m)
          m = os[j], k = j;
      if(!m) continue;
      ++jo[k], ++r1, r2 += os[k];
    }
    for(i = 0; i < M; ++i) if(!jo[i]) ++r3;

    printf("%d %lld %d\n", r1, r2, r3);
  }
  return 0;
}
