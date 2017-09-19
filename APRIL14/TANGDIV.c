// TANGDIV

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
  char f,f2;
  int T,N,K,P,L,R, i,j, a[500],n;
  T = getn();
  while(T--){
    N = getn(), K = getn(), P = getn(), n = f2 = 0;
    for(i = 0; i < K; i++)
      a[n++] = getn(), R = getn();
    for(i = 0; i < P; i++){
      L = getn(), R = getn(), f = 0;
      if(!f2){
        for(j = 0; j < n; j++)
          if(L == a[j]){ f = 1; break; }
        if(!f) f2 = 1;
      }
    }
    printf(f2?"No\n":"Yes\n");
  }
  return 0;
}
