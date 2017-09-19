// RAINBOWA

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

int a[100],b[8],c[8];
int main(){
  char f;
  int T,N, i;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i) a[i] = getn();

    if(a[0] != 1){ printf("no\n"); continue; }
    for(i = 1; i <= 7; ++i) b[i] = c[i] = 0;
    b[1] = 1;
    for(i = 1; i < N && a[i]-a[i-1] >= 0 && a[i]-a[i-1] <= 1; ++i) ++b[a[i]];
    for(; i < N && a[i]-a[i-1] >= -1 && a[i]-a[i-1] <= 0; ++i) ++c[a[i]];
    for(i = 1, f = 0; i < 7; ++i)
      if(b[i] != c[i]){ f = 1; break; }
    printf((f || !b[7]) ? "no\n" : "yes\n");
  }
  return 0;
}
