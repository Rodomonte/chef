// ANUMLA

#include <stdlib.h> //!
#include <stdio.h>

#define gc getchar_unlocked
#define MX 32768

int getn(){
  int n = 0; char c = gc(), f = 1;
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
  sort(a, r-a+1), sort(l, a+n-l);
}

char v[MX];
int a[MX];
int main(){
  int T,N, i,j,k, r[15],rn;

  T = 0; //getn();
  while(++T){ //--){
    N = rand()%4+1; //getn();
    printf("\nT%d: N=%d\n", T,N);
    for(i = 0; i < (1 << N); ++i)
      /*a[i] = getn(),*/ v[i] = 0;
    int b[N];
    for(i = 0; i < N; ++i)
      b[i] = rand() % 1000000;
    sort(b, N);
    for(i = 0; i < N; ++i)
      printf("%d ", b[i]);
    printf("\n");
    for(i = 0; i < (1 << N); ++i){
      for(k = j = 0; j < N; ++j)
        if(i & (1 << j)) k += b[j];
      a[i] = k;
    }

    sort(a, 1 << N);
    for(rn = 0, i = 1; rn < N; ++i){
      if(v[i]) continue;
      r[rn++] = a[i], v[i] = 1;
      printf("\n%d:\n", a[i]);
      for(j = 1, k = i+1; j < (1 << N) && k < (1 << N);){
        if(i == j || !v[j]){ ++j; continue; }
        printf("%d\n", a[i]+a[j]);
        if(a[k] < a[i]+a[j]){ ++k; continue; }
        printf("v[%d] %d\n", k, a[k]);
        v[k] = 1, ++j, ++k;
      }
    }

    for(i = 0; i < rn; ++i)
      printf("%d ", r[i]);
    printf("\n");

    for(i = 0; i < N; ++i)
      if(b[i] != r[i]) gc();
  }
  return 0;
}
