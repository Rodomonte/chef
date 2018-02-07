// COADIES2

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T = getn(),N, a,b, r;
  while(T--){
    N = getn(), r = 0;
    for(a = 1; a < N; a++)
      for(b = a+1; b <= N; b++)
        if(!((a*b)%(a+b)))
          r++;
    printf("%d\n",r);
  }
  return 0;
}
