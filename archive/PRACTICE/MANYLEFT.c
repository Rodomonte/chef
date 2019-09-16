// MANYLEFT

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char f, a[30][31];
  int N, i,j,rn, r[900][4];

  N = getn();
  for(i = 0; i < N; ++i)
    scanf("%s", a[i]);

  rn = 0, f = 1;
  while(f){
    f = 0;
    for(i = 0; i < N; ++i){
      for(j = 0; j < N; ++j){
        if(a[i][j] == '.' || ((i+j)&1)) continue;
        if(i > 1 && a[i-1][j] == '*' && a[i-2][j] == '.')
          a[i][j] = '.', a[i-1][j] = '.', a[i-2][j] = '*', r[rn][0] = i,
          r[rn][1] = j, r[rn][2] = i-2, r[rn][3] = j, ++rn, f = 1;
        else if(j > 1 && a[i][j-1] == '*' && a[i][j-2] == '.')
          a[i][j] = '.', a[i][j-1] = '.', a[i][j-2] = '*', r[rn][0] = i,
          r[rn][1] = j, r[rn][2] = i, r[rn][3] = j-2, ++rn, f = 1;
        else if(i < N-2 && a[i+1][j] == '*' && a[i+2][j] == '.')
          a[i][j] = '.', a[i+1][j] = '.', a[i+2][j] = '*', r[rn][0] = i,
          r[rn][1] = j, r[rn][2] = i+2, r[rn][3] = j, ++rn, f = 1;
        else if(j < N-2 && a[i][j+1] == '*' && a[i][j+2] == '.')
          a[i][j] = '.', a[i][j+1] = '.', a[i][j+2] = '*', r[rn][0] = i,
          r[rn][1] = j, r[rn][2] = i, r[rn][3] = j+2, ++rn, f = 1;
        if(f) break;
      }
      if(f) break;
    }
    if(f) continue;

    for(i = 0; i < N; ++i){
      for(j = 0; j < N; ++j){
        if(a[i][j] == '.') continue;
        if(i > 1 && a[i-1][j] == '*' && a[i-2][j] == '.')
          a[i][j] = '.', a[i-1][j] = '.', a[i-2][j] = '*', r[rn][0] = i,
          r[rn][1] = j, r[rn][2] = i-2, r[rn][3] = j, ++rn, f = 1;
        else if(j > 1 && a[i][j-1] == '*' && a[i][j-2] == '.')
          a[i][j] = '.', a[i][j-1] = '.', a[i][j-2] = '*', r[rn][0] = i,
          r[rn][1] = j, r[rn][2] = i, r[rn][3] = j-2, ++rn, f = 1;
        else if(i < N-2 && a[i+1][j] == '*' && a[i+2][j] == '.')
          a[i][j] = '.', a[i+1][j] = '.', a[i+2][j] = '*', r[rn][0] = i,
          r[rn][1] = j, r[rn][2] = i+2, r[rn][3] = j, ++rn, f = 1;
        else if(j < N-2 && a[i][j+1] == '*' && a[i][j+2] == '.')
          a[i][j] = '.', a[i][j+1] = '.', a[i][j+2] = '*', r[rn][0] = i,
          r[rn][1] = j, r[rn][2] = i, r[rn][3] = j+2, ++rn, f = 1;
        if(f) break;
      }
      if(f) break;
    }
  }

  printf("%d\n", rn);
  for(i = 0; i < rn; ++i)
    printf("%d %d %d %d\n", r[i][1], r[i][0], r[i][3], r[i][2]);

  return 0;
}
