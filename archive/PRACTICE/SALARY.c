// SALARY

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define MAX 1000000
int main(){
  int T = getn(),N,W, i, m,s;
  while(T--){
    N = getn(), m = MAX, s = 0;
    for(i = 0; i < N; i++){
      W = getn();
      if(W < m)
        m = W;
      s += W;
    }
    printf("%d\n",s-m*N);
  }
  return 0;
}
