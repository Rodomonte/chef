// CHEFCOUN

#include <stdio.h>

#define ui unsigned int
#define ll long long
#define gc getchar_unlocked
#define MOD (1LL << 32) // 4294967296

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int r[100000];
int main(){
  int T,N, i, n,x;
  ll s;

  T = getn();
  while(T--){
    N = getn();

    if(N == 99991) x = 60000;
    else if(N == 99992) x = 20000;
    else if(N == 99993) x = 70000;
    else if(N == 99994) x = 30000;
    else if(N == 99995) x = 90000;
    else if(N == 99996) x = 50000;
    else if(N == 99997) x = 97000;
    else if(N == 99998) x = 60000;
    else if(N == 99999) x = 20000;
    else if(N == 100000) x = 70000;

    n = MOD / N, s = 0;
    for(i = 0; i < x; ++i) r[i] = n+1, s += n+1;
    for(; i < N; ++i) r[i] = n, s += n;
    s -= r[23]-1, r[23] = 1;

    printf("%d", r[0]);
    for(i = 1; i < N; ++i) printf(" %d", r[i]);
    printf("\n");

    //printf("BIG = %u, SMALL = %u\n", (ui)(s%MOD), (ui)((s+n+1)%MOD));
  }
  return 0;
}
