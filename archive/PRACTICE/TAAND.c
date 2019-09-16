// TAAND

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

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

int a[300000];
int main(){
  int N, i, m;

  N = getn();
  for(i = 0; i < N; ++i) a[i] = getn();

  sort(a, N);
  for(i = N-1, m = 0; i > 0; --i) if((a[i]&a[i-1]) > m) m = a[i]&a[i-1];

  printf("%d\n", m);
  return 0;
}
