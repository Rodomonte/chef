// DIRECTI

#include <stdio.h>

#define getcu getchar_unlocked

int main(){
  int T, N,n, i;
  char c;
  scanf("%d",&T);
  while(T--){
    scanf("%d\n",&N);
    for(i=0; i < 10; i++) c = getcu();
    char t[N-1], r[N][43];
    for(n=0; n < N; n++){
      i=0;
      while(c != '\n'){
        r[n][i++] = c;
        c = getcu();
      }
      r[n][i] = '\0';
      if(n != N - 1){
        t[n] = getcu();
        if(t[n] == 'L') i = 8;
        else i = 9;
        while(i--) c = getcu();
      }
    }
    printf("Begin on %s\n",r[N-1]);
    for(n = N-2; n >= 0; n--) printf("%s on %s\n",t[n]=='L'?"Right":"Left",r[n]);
  }
  return 0;
}
