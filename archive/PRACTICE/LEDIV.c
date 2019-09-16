// LEDIV

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
inline int gcd(int a, int b){
  return (!a || !b) ? a+b : gcd(b, a % b);
}
int main(){
  int T = getn(), N, i,j, d, p[100001];
  for(i=2; i <= 100000; i++) p[i] = i;
  for(i=2; i <= 50000; i++){
    if(p[i] == i)
      for(j = i<<1; j <= 100000; j += i)
        p[j] = i < p[j] ? i : p[j];
  }
  while(T--){
    N = getn() - 1, d = getn();
    while(N--) d = gcd(d, getn());
    if(d == 1) printf("-1\n");
    else printf("%d\n",p[d]);
  }
  return 0;
}
