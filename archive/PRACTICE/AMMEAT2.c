// AMMEAT2

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
  int T = getn(),N,K, i;
  while(T--){
    N = getn(), K = getn();
    if(K == 1)
      printf("1");
    else if(K > N/2)
      printf("-1");
    else
      for(i = 1; i <= K; i++)
        printf("%d ",i*2);
    printf("\n");
  }
  return 0;
}

