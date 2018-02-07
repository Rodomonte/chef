// CRAWA

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  char c = gc(), f = 0; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = 1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return (f) ? 0-n : n;
}

int abs(int n){
  return (n < 0) ? 0-n : n;
}

int main(){
  int T,X,Y;
  T = getn();
  while(T--){
    X = getn(), Y = getn();
    if(X >= 0){
      Y = abs(Y-1);
      if(X >= Y)
        printf((X&1)?"YES\n":"NO\n");
      else
        printf((Y&1)?"YES\n":"NO\n");
    }else{
      X = abs(X), Y = abs(Y);
      if(X >= Y)
        printf((X&1)?"NO\n":"YES\n");
      else
        printf((Y&1)?"NO\n":"YES\n");
    }
  }
  return 0;
}
