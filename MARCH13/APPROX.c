// APPROX

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), K,k, dd, ds, a;
  while(T--){
    K = getn();
    if(!K) printf("3\n");
    else{
      printf("3.");
      dd = 46870, ds = 33102;
      for(k = 0; k < K; k++){
        a = dd / ds;
        printf("%d",a);
        dd -= a * ds;
        if(dd < ds) dd *= 10;
      }
      printf("\n");
    }
  }
  return 0;
}
