// DIGROT

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

inline int sl(int n){
  int e = 1;
  while(n / (e * 10))
    e *= 10;
  return ((n % e) * 10 + n / e);
}
inline int sr(int n){
  int e = 1;
  while(n / (e * 10))
    e *= 10;
  return ((n % 10) * e + n / 10);
}
int main(){
  int T = getn(),N, l,r,m;
  while(T--){
    N = l = r = getn();
    m = sl(sr(N))>sr(sl(N))?sl(sr(N)):sr(sl(N));
    while(N / 10){
      l = sl(l), r = sr(r);
      if(l > m) m = l;
      if(r > m) m = r;
      N /= 10;
    }
    printf("%d\n",m);
  }
  return 0;
}
