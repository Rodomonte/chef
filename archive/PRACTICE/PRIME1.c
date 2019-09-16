// PRIME1

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,L,R, d,f,n,s;

  T = getn();
  while(T--){
    L = getn(), R = getn();
    for(n = L; n <= R; ++n){
      s = sqrt(n), f = 1;
      for(d = 2; d <= s; ++d) if(!(n % d)){ f = 0; break; }
      if(f && n != 1) printf("%d\n", n);
    }
    printf("\n");
  }
  return 0;
}
