// SEAFUNC

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[100][100], r[10000][9];
int main(){
  char s[101];
  int T,N, i,j, t, rn;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i){
      scanf("%s", s);
      for(j = 0; j < N; ++j) a[i][j] = s[j]-'0';
    }

    for(i = rn = 0; i < N; ++i){
      for(j = 0; j < N; ++j){
        if(a[i][j] == 1){
          r[rn][0] = 0, r[rn][1] = 1, r[rn][2] = 0, r[rn][3] = 1;
          r[rn][4] = 0, r[rn][5] = 1, r[rn][6] = j+1, r[rn][7] = i+1;
          r[rn][8] = i+1, ++rn;
        }
      }

      /* for(j = t = 0; j < N; ++j){ */
      /*   if(a[i][j] == 1){ ++t; */
      /*   }else if(t){ */
      /*     r[rn][0] = 0, r[rn][1] = 1, r[rn][2] = 0, r[rn][3] = 1; */
      /*     r[rn][4] = 0, r[rn][5] = 1, r[rn][6] = i+1, r[rn][7] = j-t+1; */
      /*     r[rn][8] = j, ++rn, t = 0; */
      /*   } */
      /* } */
      /* if(t){ */
      /*   r[rn][0] = 0, r[rn][1] = 1, r[rn][2] = 0, r[rn][3] = 1; */
      /*   r[rn][4] = 0, r[rn][5] = 1, r[rn][6] = i+1, r[rn][7] = N-t+1; */
      /*   r[rn][8] = N, ++rn; */
      /* } */
    }

    printf("%d\n", rn);
    for(i = 0; i < rn; ++i)
      printf("%d %d %d %d %d %d %d %d %d\n", r[i][0], r[i][1], r[i][2],
             r[i][3], r[i][4], r[i][5], r[i][6], r[i][7], r[i][8]);
  }
  return 0;
}
