// CHEFPNT

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char a[101][101];
int r[5000][3],rn;
int main(){
  int N,M,K, i,j,n, mi,mj,md,m,t;
  N = getn(), M = getn(), K = getn();
  rn = 0, n = N*M-K;
  for(i = 1; i <= N; i++)
    for(j = 1; j <= M; j++)
      a[i][j] = 'w';
  while(K--){
    i = getn(), j = getn();
    a[i][j] = 'b';
  }

  while(n){
    // Consider each line, score by most nonwhite touching (later try least white segments?)
    m = 0;
    for(i = 1; i <= N; i++){
      t = 0;
      for(j = 1; j <= M; j++){
        if(a[i][j] != 'w'){
          t = 0;
          continue;
        }
        if(i == 1 || a[i-1][j] != 'w')
          t++;
        if(i == N || a[i+1][j] != 'w')
          t++;
        if(t > m)
          m = t, mi = i, mj = j, md = 0;
      }
    }

    for(j = 1; j <= M; j++){
      t = 0;
      for(i = 1; i <= N; i++){
        if(a[i][j] != 'w'){
          t = 0;
          continue;
        }
        if(j == 1 || a[i][j-1] != 'w')
          t++;
        if(j == N || a[i][j+1] != 'w')
          t++;
        if(t > m)
          m = t, mi = i, mj = j, md = 1;
      }
    }

    i = mi, j = mj;
    if(md == 0){
      for(; j <= M && a[i][j] == 'w'; j++)
        a[i][j] = 'r', n--;
      for(j = mj-1; j >= 1 && a[i][j] == 'w'; j--)
        a[i][j] = 'r', n--;
    }else{
      for(; i <= N && a[i][j] == 'w'; i++)
        a[i][j] = 'r', n--;
      for(i = mi-1; i >= 1 && a[i][j] == 'w'; i--)
        a[i][j] = 'r', n--;
    }
    r[rn][0] = mi, r[rn][1] = mj, r[rn][2] = md, rn++;
  }
  printf("%d\n", rn);
  for(i = 0; i < rn; i++)
    printf("%d %d %d\n", r[i][0], r[i][1], r[i][2]);
  return 0;
}