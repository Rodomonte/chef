// PRPOTION

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
  int T,N[3],M,L, i,j,m[3];
  T = getn();
  while(T--){
    for(i = 0; i < 3; i++)
      N[i] = getn();
    M = getn();
    for(i = 0; i < 3; i++){
      m[i] = 0;
      for(j = 0; j < N[i]; j++){
        L = getn();
        if(L > m[i])
          m[i] = L;
      }
    }
    while(M--){
      if(m[0] >= m[1] && m[0] >= m[2])
        m[0] >>= 1;
      else if(m[1] >= m[0] && m[1] >= m[2])
        m[1] >>= 1;
      else
        m[2] >>= 1;
    }
    if(m[0] >= m[1] && m[0] >= m[2])
      printf("%d\n", m[0]);
    else if(m[1] >= m[0] && m[1] >= m[2])
      printf("%d\n", m[1]);
    else
      printf("%d\n", m[2]);
  }
  return 0;
}
