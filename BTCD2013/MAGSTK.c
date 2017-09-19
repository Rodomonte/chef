// MAGSTK

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N,X,L, i, a[220],b[105], r;
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < 220; i++)
      a[i] = 0;
    for(i = 0; i < N; i++){
      X = getn()+108, L = getn();
      a[X] = L, b[i] = X;
    }
    for(i = 0; i < N; i++){
      X = b[i], r = 1;
      L = a[X] - 1;
      while(L && X < 219){
        if(a[++X] > --L)
          L = a[X] - 1;
        if(a[X])
          r++;
      }
      printf("%d ",r);
    }
    printf("\n");
  }
  return 0;
}
