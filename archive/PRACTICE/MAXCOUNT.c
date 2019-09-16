// MAXCOUNT

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N,n, i;
  while(T--){
    N = getn();
    int a[10001]={0}, v, c=0;
    for(n = 0; n < N; n++){
      i = getn();
      a[i]++;
      if(a[i] > c) v = i, c = a[i];
      if(a[i] == c && i < v) v = i;
    }
    printf("%d %d\n",v,c);
  }
  return 0;
}
