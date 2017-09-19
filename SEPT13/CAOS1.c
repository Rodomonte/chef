// CAOS1

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  char a[50][50];
  int T,R,C, i,j, r;
  T = getn();
  while(T--){
    R = getn(), C = getn(), r = 0;
    for(i = 0; i < R; i++){
      for(j = 0; j < C; j++)
        a[i][j] = (gc()=='^'?1:0);
      gc();
    }
    if(R < 5 || C < 5){
      printf("0\n");
      continue;
    }
    for(i = 2; i < R-2; i++)
      for(j = 2; j < C-2; j++)
        if(a[i][j] && a[i-1][j] && a[i-2][j]
            && a[i][j+1] && a[i][j+2] && a[i+1][j]
            && a[i+2][j] && a[i][j-1] && a[i][j-2])
          r++;
    printf("%d\n",r);
  }
  return 0;
}
