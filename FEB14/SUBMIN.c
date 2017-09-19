// SUBMIN

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int N,Q,K,A[50], i,j, p,r;
  N = getn();
  for(i = 0; i < N; i++)
    A[i] = getn();
  Q = getn();
  while(Q--){
    K = getn(), p = r = 0;
    for(i = 0; i < N; i++){
      p = (A[i] >= K) ? p+1 : 0;
      if(A[i] == K){
        for(j = i; j < N && A[j] >= K; j++)
          r += p;
        p = 0;
      }
    }
    printf("%d\n",r);
  }
  return 0;
}
