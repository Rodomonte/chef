// HOTEL

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N,n,i;
  while(T--){
    N = getn();
    int a[N],d[N], c, m=0;
    for(n = 0; n < N; n++) a[n] = getn();
    for(n = 0; n < N; n++) d[n] = getn();
    for(n = 0; n < N; n++){
      c = 1;
      for(i = 0; i < N; i++){
        if(n == i) continue;
        if(d[n] - a[i] > 0 && d[n] - d[i] <= 0) c++;
      }
      if(c > m) m = c;
    }
    printf("%d\n",m);
  }
  return 0;
}
