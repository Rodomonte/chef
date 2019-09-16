// NOTATRI

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
  int N = getn();
  while(N){
    int a[N], t=0, n,i,j;
    for(n = 0; n < N; n++) a[n] = getn();
    sort(a, a+N);
    for(n = N-1; n >= 2; n--){
      i = 0, j = n-1;
      while(i < j){
        if(a[i] + a[j] < a[n]){
          t += j - i;
          i++;
        }else j--;
      }
    }
    printf("%d\n",t);
    N = getn();
  }
  return 0;
}

