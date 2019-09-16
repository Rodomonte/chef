// TIDRICE

#include <stdio.h>
#include <string.h>

char a[100][21], v[100];
int decf(char* ap, int n){
  while(n >= 0){
    if(!strcmp(ap, a[n])) return n;
    n--;
  }
  return -1;
}
int main(){
  int T, N,n;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    int s=0, i, p;
    for(n = 0; n < N; n++){
      scanf("%s %c",a[n],v+n);
      p = decf(a[n], n - 1);
      if(p >= 0) s -= v[p]=='+' ? 1 : -1;
      s += v[n]=='+' ? 1 : -1;
    }
    printf("%d\n",s);
  }
  return 0;
}
