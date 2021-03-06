// BANDMATR

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N, i,j,n,z;

  T = getn();
  while(T--){
    N = getn(), n = z = 0;
    for(i = 0; i < N; ++i)
      for(j = 0; j < N; ++j)
        if(!getn())
          ++z;

    for(i = 1; i < N; ++i){
      n += (i<<1);
      if(n > z)
        break;
    }
    printf("%d\n", N-i);
  }
  return 0;
}
