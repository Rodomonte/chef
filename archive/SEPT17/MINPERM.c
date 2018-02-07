// MINPERM

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[100001];
int main(){
  int T,N, i,t;

  T = getn();
  while(T--){
    N = getn();

    for(i = 1; i <= N; ++i) a[i] = i;
    for(i = 1; i <= ((N&1)?N-3:N); i += 2) t = a[i], a[i] = a[i+1], a[i+1] = t;
    if(N&1) t = a[N-2], a[N-2] = a[N-1], a[N-1] = a[N], a[N] = t;

    for(i = 1; i <= N; ++i) printf("%d ", a[i]);
    printf("\n");
  }
  return 0;
}
