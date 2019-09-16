// SAD

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int R = getn(),r, C = getn(),c, n, rmn[100],cmx[100]={0};
  for(r = 0; r < R; r++){
    rmn[r] = 100000000;
    for(c = 0; c < C; c++){
      n = getn();
      if(n < rmn[r]) rmn[r] = n;
      if(n > cmx[c]) cmx[c] = n;
    }
  }
  for(r = 0; r < R; r++){
    for(c = 0; c < C; c++){
      if(rmn[r] == cmx[c]){
        printf("%d\n",rmn[r]);
        return 0;
      }
    }
  }
  printf("GUESS\n");
  return 0;
}
