// EFFPAINT

#include <stdio.h>

char a[50][50], b[50][51], r[2500][5];
int main(){
  int N, i,j,k,l,mi,mj, c,m,n,t, rn;

  scanf("%d", &N);
  for(i = 0; i < N; ++i)
    scanf("%s", b[i]);

  n = rn = 0;
  for(i = 0; i < N; ++i){
    for(j = 0; j < N; ++j){
      if(b[i][j] == 'B') ++n;
      a[i][j] = 'W';
    }
  }
  if(n > N*N/2){
    for(i = 0; i < N; ++i) for(j = 0; j < N; ++j) a[i][j] = 'B';
    r[0][0] = r[0][1] = 0, r[0][2] = r[0][3] = N-1, r[0][4] = 'B', ++rn;
  }

  for(i = 0; i < N; ++i){
    for(j = 0; j < N; ++j){
      for(k = i, c = 50, m = 0; k < N; ++k){
        for(l = j, n = 0; l < N; ++l){
          if(a[k][l] != b[k][l]) ++n;
          else break;
        }
        if(n < c) c = n;
        t = (k-i+1) * c;
        if(t > m) m = t, mi = k, mj = j+n-1;
        if(!n) break;
      }

      if(m){
        for(k = i; k <= mi; ++k) for(l = j; l <= mj; ++l)
          a[k][l] = (a[k][l] == 'B') ? 'W' : 'B';
        r[rn][0] = i, r[rn][1] = j, r[rn][2] = mi, r[rn][3] = mj,
        r[rn][4] = 'F', ++rn;
      }
    }
  }

  printf("%d\n", rn);
  for(i = 0; i < rn; ++i)
    printf("%d %d %d %d %c\n", r[i][0], r[i][1], r[i][2], r[i][3], r[i][4]);
  return 0;
}
