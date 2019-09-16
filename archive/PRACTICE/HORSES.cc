// HORSES

#include <stdio.h>
#include <algorithm>
using std::sort;

#define gc getchar_unlocked
inline int getn(){
  int n=0, c=gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
int main(){
  int T = getn(), N,n, m, i,j;
  while(T--){
    N = getn(), m=1000000000;
    int a[N];
    for(n=0; n < N; n++) a[n] = getn();
    sort(a, a+N);
    for(n=0; n < N-1; n++){
      i = a[n], j = a[n+1];
      if(i == j){
        m = 0;
        break;
      }else if(i < j && j - i < m) m = j - i;
      else if(i > j && i - j < m) m = i - j;
    }
    printf("%d\n",m);
  }
  return 0;
}

