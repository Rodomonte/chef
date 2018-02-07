// FCBARCA

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define MOD 1000000007
int main(){
  int T = getn(),N,K, i,j, p,r;
  while(T--){
    N = getn(), K = getn(), r = K;
    for(i = 2; i < N; i++){
      r += i%2?1:-1;
      p = r;
      for(j = 1; j < K; j++){
        r += p;
        if(r >= MOD)
          r -= MOD;
      }
    }
    printf("%d\n",r);
  }
  return 0;
}
