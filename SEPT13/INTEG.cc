// INTEG

#include <stdio.h>
#include <algorithm>
using std::sort;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[100000],an;
int main(){
  int N,A,X, i;
  long long n, r;
  N = getn(), an = r = 0;
  for(i = 0; i < N; i++){
    A = getn();
    if(A < 0)
      a[an++] = A;
  }
  X = getn();
  sort(a, a+an);
  if(X < an){
    n = a[X];
    r += -n * X;
    for(i = 0; i < X; i++)
      r -= a[i] - n;
  }else
    for(i = 0; i < an; i++)
      r -= a[i];
  printf("%lld\n",r);
  return 0;
}

