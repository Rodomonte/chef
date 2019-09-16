// SPOON

#include <stdio.h>

#define gc getchar_unlocked

int main(){
  int T,R,C, i,j;
  char a[100][101], c, f;
  scanf("%d\n",&T);
  while(T--){
    scanf("%d %d\n",&R,&C);
    f = 0;
    for(i = 0; i < R; i++){
      for(j = 0; j < C; j++){
        c = gc();
        if(c < 97) c += 32;
        a[i][j] = c;
      }
      a[i][j] = '\0';
      gc();
    }
    for(i = 0; i < R; i++){
      for(j = 0; j < C; j++){
        if((j+4 < C && a[i][j] == 's' && a[i][j+1] == 'p'
            && a[i][j+2] == 'o' && a[i][j+3] == 'o'
            && a[i][j+4] == 'n') || (i+4 < R && a[i][j] == 's'
            && a[i+1][j] == 'p' && a[i+2][j] == 'o'
            && a[i+3][j] == 'o' && a[i+4][j] == 'n')){
          f = 1;
          break;
        }
      }
      if(f)
        break;
    }
    printf(f?"There is a spoon!\n":"There is indeed no spoon!\n");
  }
  return 0;
}
