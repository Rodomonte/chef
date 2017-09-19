// PLAYNUM

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int comp(int* a, int* b){
  return *b - *a;
}
int a[100],b[100];
int main(){
  int T,N,Q,A,B, i, r;
  T = getn();
  while(T--){
    N = getn(), Q = getn(), r = 0;
    for(i = 0; i < N; i++)
      a[i] = getn(), b[i] = 0;
    while(Q--){
      A = getn()-1, B = getn()-1;
      for(i = A; i <= B; i++)
        b[i]++;
    }
    qsort(a, N, 4, comp);
    qsort(b, N, 4, comp);
    for(i = 0; i < N; i++)
      r += a[i] * b[i];
    printf("%d\n",r);
  }
  return 0;
}
