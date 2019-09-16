// AND

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[100000];
int main(){
  int N, i,j,k;
  ll r;

  N = getn();
  for(i = 0; i < N; ++i) a[i] = getn();

  for(i = r = 0; i < 32; ++i){
    for(j = k = 0; j < N; ++j) if(a[j] & (1 << i)) ++k;
    r += (1LL<<i) * (((ll)k*(k-1))>>1);
  }

  printf("%lld\n", r);
  return 0;
}
