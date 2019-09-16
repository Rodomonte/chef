// PRIMES2

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char pr(int n){
  if(n < 2 || (!(n & 1) && n != 2))
    return 0;
  int i;
  for(i = 3; i*i <= n; i += 2)
    if(!(n % i))
      return 0;
  return 1;
}
int main(){
  int P, a,b,c;
  char f;
  while(P = getn()){
    f = 0;
    for(a = 100; a > 0; a--){
      if(a*a*a < P && pr(a)){
        for(b = 2; b*b+a*a*a < P; b++){
          c = P - a*a*a - b*b;
          if(pr(b) && pr(c)){
            f = 1;
            break;
          }
        }
        if(f)
          break;
      }
    }
    if(!f)
      a = b = c = 0;
    printf("%d %d %d\n",c,b,a);
  }
  return 0;
}
