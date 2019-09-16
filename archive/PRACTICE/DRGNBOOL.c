// DRGNBOOL

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
  int T = getn(),N,M, i, a[101], n,r;
  while(T--){
    for(i = 1; i <= 100; i++)
      a[i] = 0;
    N = getn(), M = getn(), r = 0;
    for(i = 0; i < N; i++){
      n = getn();
      a[getn()] += n;
    }
    for(i = 0; i < M; i++){
      n = getn();
      a[getn()] -= n;
    }
    for(i = 1; i <= 100; i++)
      if(a[i] < 0)
        r -= a[i];
    printf("%d\n",r);
  }
  return 0;
}
