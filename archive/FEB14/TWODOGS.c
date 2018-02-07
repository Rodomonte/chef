// TWODOGS

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int min(int a, int b){
  return a < b ? a : b;
}
int max(int a, int b){
  return a > b ? a : b;
}
int a[1000001][2]={{0}};
int main(){
  int N,K,T, i, m;
  N = getn(), K = getn();
  for(i = 1; i <= N; i++){
    T = getn();
    if(!a[T][0])
      a[T][0] = i;
    a[T][1] = N-i+1;
  }
  if(!(K&1))
    a[K>>1][0] = a[K>>1][1] = 0;
  m = N;
  for(i = 1; i <= K>>1; i++){
    if(a[i][0] && a[K-i][0]){
      m = min(m, max(a[i][0], a[K-i][0]));
      m = min(m, max(a[i][0], a[K-i][1]));
      m = min(m, max(a[i][1], a[K-i][0]));
      m = min(m, max(a[i][1], a[K-i][1]));
    }
  }
  if(m == N)
    m = -1;
  printf("%d\n",m);
  return 0;
}
