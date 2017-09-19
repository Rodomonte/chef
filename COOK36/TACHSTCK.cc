// TACHSTCK

#include <stdio.h>
#include <algorithm>
using std::sort;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[100000];
int main(){
  int N,D, i, r;
  N = getn(), D = getn(), r = 0;
  for(i = 0; i < N; i++)
    a[i] = getn();
  sort(a, a+N);
  for(i = 0; i < N-1; i++)
    if(a[i+1] - a[i] <= D)
      r++, i++;
  printf("%d\n",r);
  return 0;
}
