// MEX

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

int max(int a, int b){ return (a > b) ? a : b; }

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int a[100000];
int main(){
  int T,N,K, i, p;

  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = 0; i < N; ++i) a[i] = getn();

    sort(a, N), p = -1;
    for(i = 0; i < N && a[i] - p < K+2; ++i)
      K -= max(0, a[i] - p - 1), p = a[i];

    printf("%d\n", p + K + 1);
  }
  return 0;
}
