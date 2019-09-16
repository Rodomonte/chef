// MONTRANS

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), A,B,C, p, t, i, r, z;
  while(T--){
    A = getn(), B = getn(), C = getn();
    t=r=0;
    i = A * 100 + B;
    p = i;
    while(t < 10000 && C <= p){
      t++;
      if(C > B){
        A--;
        B += 100;
      }
      B -= C;
      z = B, B = A, A = z;
      p = A * 100 + B;
      if(p > i) i = p, r = t;
    }
    printf("%d\n",r);
  }
  return 0;
}
