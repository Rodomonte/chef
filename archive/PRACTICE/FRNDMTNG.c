// FRNDMTNG

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
  int T;
  double E,F,W,X;

  T = getn();
  while(T--){
    E = getn(), F = getn(), W = getn(), X = getn();
    printf("%.7lf\n", 1 - (((W < F) ? (F-W)*(F-W) : 0) +
                           ((X < E) ? (E-X)*(E-X) : 0) -
                           ((F-W > E) ? (F-W-E)*(F-W-E) : 0) -
                           ((E-X > F) ? (E-X-F)*(E-X-F) : 0)) /
                          (E*F*2));
  }
  return 0;
}
