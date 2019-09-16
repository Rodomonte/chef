// CLEANUP

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
    int T, N,n, M;
  T = getn();
  while(T--){
    int h=1, s=0, a[1000]={0},b[1000]={0},c[1000]={0};
    N = getn(), M = getn();
    while(M--) a[getn()-1] = 1;
    for(n = 0; n < N; n++){
      if(!a[n]){
        if(h == 1) b[n] = 1, h = 0, s = 1;
        else c[n] = 1, h = 1, s = 0;
      }
    }
    for(n = 0; n < N; n++) if(b[n] == 1) printf("%d ",n+1);
    printf("\n");
    for(n = 0; n < N; n++) if(c[n] == 1) printf("%d ",n+1);
    printf("\n");
  }
  return 0;
}
