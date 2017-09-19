// CHEFKEY

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked

static inline int gi(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,M,C, i,r,s,d;
  T = gi();

  while(T--){
    N = gi(), M = gi(), C = gi();
    s = (int)floor(sqrt(C)), r = 0;
    for(i = 1; i <= s; ++i){
      d = C / i;
      if(d*i != C)
        continue;
      if(d <= N && i <= M)
        ++r;
      if(d != i && d <= M && i <= N)
        ++r;
    }
    printf("%d\n", r);
  }
  return 0;
}
