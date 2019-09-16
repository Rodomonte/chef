// COINS

#include <stdio.h>

#define uint unsigned int
#define an 1000000
int a[an]={0};
uint fn(int n){
  //printf("%d\n",n);
  if(n < an && a[n] >= 0) return a[n];
  int n2 = fn(n/2), n3 = fn(n/3), n4 = fn(n/4);
  uint s = n2 + n3 + n4;
  uint r = s > (uint)n ? s : (uint)n;
  if(n < an)
    a[n] = (int)r;
  return r;
}
int main(){
  int N, i;
  a[0] = 0;
  for(i = 1; i < an; i++)
    a[i] = -1;
  while(scanf("%d",&N) != EOF)
    printf("%u\n",fn(N));
  return 0;
}
