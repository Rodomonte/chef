// TREEROOT

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[1001];
int main(){
  int T,N,I,S, i, sn,sc;

  T = getn();
  while(T--){
    N = getn();
    if(N == 1){ I = getn(), S = getn(), printf("%d\n", I); continue; }
    for(i = 1; i <= 1000; ++i) a[i] = -1;
    for(i = sn = sc = 0; i < N; ++i)
      sn += (I = getn()), sc += (S = getn()), a[I] = S;
    for(i = 1; i <= 1000; ++i)
      if(sn - i == sc && a[i] >= 0) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
