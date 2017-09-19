// MXMEDIAN

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
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

int a[100000];
int main(){
  int T,N, i,m;

  T = getn();
  while(T--){
    N = getn()<<1;
    for(i = 0; i < N; ++i)
      a[i] = getn();

    sort(a, N);
    if((N>>1)&1)
      m = a[(N>>1)+(N>>2)];
    else
      m = (a[(N>>1)+(N>>2)-1] + a[(N>>1)+(N>>2)]) >> 1;
    printf("%d\n", m);
    for(i = 0; i < (N>>1); ++i)
      printf("%d %d ", a[i], a[i+(N>>1)]);
    printf("\n");
  }
  return 0;
}
