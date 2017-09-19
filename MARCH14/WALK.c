// WALK

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
  int T,N, i, a[100000], r;
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; i++)
      a[i] = getn();
    r = a[N-1];
    for(i = N-2; i >= 0; i--)
      r = (r+1 < a[i]) ? a[i] : r+1;
    printf("%d\n",r);
  }
  return 0;
}
