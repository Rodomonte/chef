// CHEFPAR

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ll long long
#define time() (double)clock()/CLOCKS_PER_SEC
#define gc getchar_unlocked
#define MX 10000
#define IT 200000000

int getn(){
  int n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int madd(int a, int b, int m){ return ((a += b) >= m) ? a-m : a; }
int mmul(int a, int b, int m){ return (int)((ll)a * b % m); }

int A[MX], P[MX], a[MX]={0}, b[MX], c[MX];
int main(){
  int N,M,K, i,j,k,mi, it;
  ll m,n,s;

  N = rand()%9900+100, M = 1000000/N, K = 1000000;
  for(i = 0; i < N; ++i)
    A[i] = rand()%2000000000;
  for(i = 0; i < M; ++i)
    P[i] = 1000000001 + (i << 1);

  m = n = 0;
  while(time() < 3.95){
    i = rand() % N;
    for(j = 0; j < M; ++j)
      for(b[j] = 1, k = 0; k < N; ++k)
        if(i != k) b[j] = mmul(b[j], A[k]+a[k], P[j]);
    for(j = 0; j < M; ++j)
      c[j] = mmul(b[j], A[i]+a[i], P[j]);

    for(it = min(K-a[i], IT/M), j = 0; j <= it && time() < 3.95; ++j){
      for(s = k = 0; k < M; ++k)
        s += c[k], c[k] = madd(c[k], b[k], P[k]);
      if(s > m) m = s, mi = j;
    }
    if(m > n) a[i] += mi;
    n = m;
  }

  for(i = 0; i < N; ++i)
    printf("%d ", A[i]+a[i]);
  printf("\n");
  return 0;
}
