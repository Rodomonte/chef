// MAXDIFF

#include <stdio.h>
#include <stdlib.h>

#define gc getchar//_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int qcomp(const void *e1, const void *e2){
  int f = *((int*)e1), s = *((int*)e2);
  if(f > s) return 1;
  if(f < s) return -1;
  return 0;
}

int main(){
  int T = getn(),N,K, i, a[100], s,t;
  while(T--){
    N = getn(), K = getn(), s=0, t=0;
    for(i = 0; i < N; i++)
      t += (a[i] = getn());
    qsort(a, N, 4, qcomp);
    for(i = 0; i < ((K<=N-K)?K:N-K); i++)
      s += a[i];
    printf("%d\n",t-s-s);
  }
  return 0;
}
