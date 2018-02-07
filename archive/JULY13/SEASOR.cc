// SEASOR

#include <stdio.h>
#include <algorithm>
using std::sort;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char f;
  int T = getn(),N,K, i, a[1000],b[1000];
  while(T--){
    N = getn(), K = getn(), f = 1;
    for(i = 0; i < N; i++)
      a[i] = b[i] = getn();
    sort(b, b+N);
    for(i = 0; i < N; i++)
      if(a[i] != b[i]){
        f = 0;
        break;
      }
    if(f){
      printf("0\n");
      continue;
    }
    printf("%d\n",(N-K)*2+1);
    for(i = 1; i <= N-K+1; i++)
      printf("%d ",i);
    for(i = N-K; i >= 1; i--)
      printf("%d ",i);
    printf("\n");
  }
  return 0;
}

