// CNPIIM

#include <stdio.h>
#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define ll long long
#define MAX 1562500
int a[MAX]={0}, b[MAX+1];
int main(){
  int T,N, i,j;
  ll r;
  for(i = 1; i < MAX; i++)
    for(j = i; j < MAX; j += i)
      a[j]++;
  b[0] = 0;
  for(i = 0; i < MAX; i++)
    b[i+1] = b[i] + a[i];
  T = getn();
  while(T--){
    N = getn(), r = 0;
    for(i = 1; i < N; i++)
      r += b[i*(N-i)];
    printf("%lld\n",r);
  }
  return 0;
}
