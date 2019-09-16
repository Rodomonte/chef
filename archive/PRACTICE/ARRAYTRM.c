// ARRAYTRM

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
  int T,N,K, i,k, b;

  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = 0; i <= 1000; ++i) a[i] = 0;
    for(i = 0; i < N; ++i) ++a[getn()];

    for(i = 0; !a[i]; ++i);
    for(b = k = 0; i <= 1000; ++i){
      if(k && a[i]) ++b;
      k = (k+1 == K+1) ? 0 : k+1;
    }
    if(b < 2){ printf("YES\n"); continue; }

    for(i = 0; !a[i]; ++i);
    for(++i; !a[i]; ++i);
    for(b = k = 0; i <= 1000; ++i){
      if(k && a[i]) ++b;
      k = (k+1 == K+1) ? 0 : k+1;
    }
    printf(b ? "NO\n" : "YES\n");
  }
  return 0;
}
