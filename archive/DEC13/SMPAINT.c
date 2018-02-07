// SMPAINT

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
  char a[1000][1000], v[1000][1000]={{0}};
  int N, i,j, ni,nj,i0,j0,j1,c, r[4000][5],rn,rn2;
  N = getn();
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++){
      a[i][j] = getn();
      if(!a[i][j])
        v[i][j] = 1;
    }
  // 0,0 -> N,N
  ni = nj = rn = 0;
  while(ni < N && v[ni][nj])
    if(++nj == N)
      ni++, nj = 0;
  while(ni < N){
    c = a[ni][nj];
    v[ni][nj] = 1;
    i0 = ni, j0 = nj;
    while(++nj < N && a[ni][nj] == c && !v[ni][nj])
      v[ni][nj] = 1;
    j1 = nj-1;
    while(++j1 < N && !v[ni][j1])
      if(a[ni][j1] == c)
        v[ni][j1] = 1;
    i = i0+1, j = j0;
    while(i < N && !v[i][j])
      if(++j == j1){
        for(j = j0; j < j1; j++)
          if(a[i][j] == c)
            v[i][j] = 1;
        i++, j = j0;
      }
    r[rn][0] = c;
    r[rn][1] = i0+1, r[rn][2] = i;
    r[rn][3] = j0+1, r[rn][4] = j1;
    rn++;
    if(nj == N)
      ni++, nj = 0;
    while(ni < N && v[ni][nj])
      if(++nj == N)
        ni++, nj = 0;
  }
  // N,N -> 0,0
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
    v[i][j] = a[i][j] ? 0 : 1;
  ni = nj = N-1, rn2 = 2000;
  while(ni >= 0 && v[ni][nj])
    if(--nj < 0)
      ni--, nj = N-1;
  while(ni >= 0){
    c = a[ni][nj];
    v[ni][nj] = 1;
    i0 = ni, j0 = nj;
    while(--nj >= 0 && a[ni][nj] == c && !v[ni][nj])
      v[ni][nj] = 1;
    j1 = nj+1;
    while(--j1 >= 0 && !v[ni][j1])
      if(a[ni][j1] == c)
        v[ni][j1] = 1;
    i = i0-1, j = j0;
    while(i >= 0 && !v[i][j])
      if(--j == j1){
        for(j = j0; j > j1; j--)
          if(a[i][j] == c)
            v[i][j] = 1;
        i--, j = j0;
      }
    r[rn2][0] = c;
    r[rn2][1] = i+2, r[rn2][2] = i0+1;
    r[rn2][3] = j1+2, r[rn2][4] = j0+1;
    rn2++;
    if(nj < 0)
      ni--, nj = N-1;
    while(ni >= 0 && v[ni][nj])
      if(--nj < 0)
        ni--, nj = N-1;
  }
  if(rn < rn2){
    printf("%d\n",rn);
    for(i = 0; i < rn; i++)
      printf("%d %d %d %d %d\n",r[i][0],r[i][1],r[i][2],r[i][3],r[i][4]);
  }else{
    printf("%d\n",rn2);
    for(i = 2000; i < rn2; i++)
      printf("%d %d %d %d %d\n",r[i][0],r[i][1],r[i][2],r[i][3],r[i][4]);
  }
  return 0;
}
