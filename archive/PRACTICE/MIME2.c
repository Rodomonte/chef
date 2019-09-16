// MIME2

#include <stdio.h>
#include <string.h>

int main(){
  int N, Q, i,j;
  scanf("%d %d",&N,&Q);
  char e[N][11], m[N][51], f[51], *p;
  for(i=0; i < N; i++) scanf("%s %s",e[i],m[i]);
  for(i=0; i < Q; i++){
    scanf("%s",f);
    p = strrchr(f, '.');
    if(!p) printf("unknown\n");
    else{
      j=0;
      while(j < N && strcmp(&p[1], e[j])) j++;
      if(j == N) printf("unknown\n");
      else printf("%s\n",m[j]);
    }
  }
  return 0;
}
