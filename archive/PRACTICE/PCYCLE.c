// PCYCLE

#include <stdio.h>

int main(){
  int N,n, nc=0, nv=0, ai=1, ci=0, csi=1;
  scanf("%d", &N);
  int a[N+1], c[2*N];
  char v[N+1];
  for(n = 1; n <= N; n++){
    scanf("%d",a+n);
    v[n] = 0;
  }
  while(nv < N){
    c[ci++] = ai;
    v[ai] = 1;
    nv++;
    ai = a[ai];
    if(ai == csi){
      c[ci++] = ai;
      while(v[++ai]);
      csi = ai;
      nc++;
    }
  }
  printf("%d\n",nc);
  c[ci] = 0;
  ci = 0;
  csi = 1;
  while(c[ci]){
    printf("%d",c[ci++]);
    if(c[ci] == csi){
      printf(" %d\n",c[ci++]);
      csi = c[ci];
    }else printf(" ");
  }
  return 0;
}
