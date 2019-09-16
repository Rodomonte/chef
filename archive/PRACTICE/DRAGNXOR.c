// DRAGNXOR

#include <stdio.h>
#include <math.h>

int ones(int n){
  int c=0, o = n;
  while(n){
    n = n >> 1 << 1;
    if(o - n == 1) c++;
    o = n >> 1;
    n = o;
  }
  return c;
}
int main(){
  int T, N, A, B;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d",&N,&A,&B);
    int v=0, e = N-1, o = ones(A) + ones(B);
    if(o > N) o = N - (o - N);
    while(o--) v += pow(2,e--);
    printf("%d\n",v);
  }
  return 0;
}
