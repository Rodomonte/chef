// RRPLAYER

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N, i;
  double d;

  T = getn();
  while(T--){
    N = getn();
    for(i = 1, d = 0; i <= N; ++i) d += (double)N / i;
    printf("%.1lf\n", d);
  }
  return 0;
}
