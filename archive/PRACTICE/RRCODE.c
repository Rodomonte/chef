// RRCODE

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
  char C;
  int T,N,K,A, i, a[1000], n;
  T = getn();
  while(T--){
    N = getn(), K = getn(), A = getn();
    for(i = 0; i < N; i++)
      a[i] = getn();
    if(!K){
      printf("%d\n",A);
      continue;
    }
    C = gc();
    while(C != 'A' && C != 'O' && C != 'X')
      C = gc();
    n = a[0];
    if(C == 'A'){
      for(i = 1; i < N; i++)
        n &= a[i];
      A &= n;
    }else if(C == 'O'){
      for(i = 1; i < N; i++)
        n |= a[i];
      A |= n;
    }else{
      for(i = 1; i < N; i++)
        n ^= a[i];
      A ^= (K % 2) ? n^0 : 0;
    }
    printf("%d\n",A);
  }
  return 0;
}
