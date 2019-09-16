// LASTDIG

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
const int v[] = {0, 1, 4, 3, 8, 5, 12, 7, 16, 9};
inline int s(int i){
  int o=0;
  while(i > 0){
    o += v[i];
    i /= 10;
  }
  return o;
}
int main(){
  int T = getn(), A, B, d;
  while(T--){
    A = getn(), B = getn(), d=0;
    while(A % 10 && A < B)
      d += s(A++) % 10;
    while(B % 10 && A < B)
      d += s(B--) % 10;
    d += ((B - A) / 10) * 45 + s(B) % 10;
    printf("%d\n",d);
  }
  return 0;
}
