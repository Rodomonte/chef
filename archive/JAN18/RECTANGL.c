// RECTANGL

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
  int T,A,B,C,D, t;
  T = getn();
  while(T--){
    A = getn(), B = getn(), C = getn(), D = getn();
    if(A == C) t = B, B = C, C = t;
    if(A == D) t = B, B = D, D = t;
    printf((A == B && C == D) ? "YES\n" : "NO\n");
  }
  return 0;
}
