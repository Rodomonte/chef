// RRCOPY

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

char a[100001];
int main(){
  int T,N,A, i,r;
  T = getn();
  while(T--){
    for(i = 1; i <= 100000; ++i) a[i] = 0;
    N = getn(), r = 0;
    for(i = 0; i < N; ++i){
      A = getn();
      if(!a[A]) ++r;
      a[A] = 1;
    }
    printf("%d\n", r);
  }
  return 0;
}
