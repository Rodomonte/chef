// SEABIL

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

int N, a[101][101], a0[101][101], r[4000][5],rn, rf[4000][5],rfn;

int hit(int i, int j, int vi, int vj, int e){
  int k,t;
  r[rn][0] = i, r[rn][1] = j, r[rn][2] = vi, r[rn][3] = vj, r[rn][4] = e, ++rn;
  for(k = 0; k < e; ++k){
    t = a[i][j], a[i][j] = 0, i += vi, j += vj;
    if((i == -1 && j == -1) || (i == -1 && j == N+1) ||
       (i == N+1 && j == -1) || (i == N+1 && j == N+1))
      return t-1;
    if(i == -1)
      i = 1, vi = 1;
    if(i == N+1)
      i = N-1, vi = -1;
    if(j == -1)
      j = 1, vj = 1;
    if(j == N+1)
      j = N-1, vj = -1;
    a[i][j] += t;
  }
  return -1;
}

int d[8][2] =
  {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int main(){
  int T,M,X,Y,Z, i,j,k,i0,m,mk,ms,s,c,n,x,y,t,u,vi,vj,e,me;

  T = getn();
  while(T--){
    N = getn(), M = getn(), rfn = 0;
    for(i = 0; i <= N; ++i)
      for(j = 0; j <= N; ++j)
        a[i][j] = 0;
    for(i = 0; i < M; ++i)
      X = getn(), Y = getn(), Z = getn(), a[X][Y] = Z;
    for(i = 0; i <= N; ++i)
      for(j = 0; j <= N; ++j)
        a0[i][j] = a[i][j];

    ms = 0;
    for(i0 = 1; i0 < (N>>1); ++i0){
      rn = s = c = 0;
      for(i = 0; i <= N; ++i)
        for(j = 0; j <= N; ++j)
          a[i][j] = a0[i][j];

      for(i = i0; c < N-2; ++i, ++c){
        if(i == N)
          i = 1;
        for(j = 1; j < N; ++j){
          if(a[i][j] < 2)
            continue;
          m = -1000;
          for(k = 0; k < 8; ++k){
            n = 0, vi = d[k][0], vj = d[k][1];
            for(x = i+vi, y = j+vj, e = 1; e <= N*4; x += vi, y += vj, ++e){
              if(x == -1)
                x = 1, vi = 1;
              if(x == N+1)
                x = N-1, vi = -1;
              if(y == -1)
                y = 1, vj = 1;
              if(y == N+1)
                y = N-1, vj = -1;
              if(a[x][y] > 1)
                ++n;
              else if(a[x][y] < -1)
                n -= 8;
              if(n > m && (!x || x == N || !y || y == N))
                m = n, mk = k, me = e;
            }
          }

          vi = d[mk][0], vj = d[mk][1];
          for(x = i+vi, y = j+vj, e = 1; e <= me; x += vi, y += vj, ++e){
            if(x == -1)
              x = 1, vi = 1;
            if(x == N+1)
              x = N-1, vi = -1;
            if(y == -1)
              y = 1, vj = 1;
            if(y == N+1)
              y = N-1, vj = -1;
            if(a[x][y] > -2)
              continue;
            if(!mk || mk == 4){
              if(!y)
                s += hit(x, y, 0, 1, 1);
              else
                s += hit(x, y, 0, -1, 1);
            }else if(!x)
              s += hit(x, y, 1, 0, 1);
            else
              s += hit(x, y, -1, 0, 1);
          }
          s += hit(i, j, d[mk][0], d[mk][1], me);
        }
      }

      for(i = 1; i < N; ++i){
        if(a[i][0] < -1)
          s += hit(i, 0, 0, 1, 1);
        if(a[i][N] < -1)
          s += hit(i, N, 0, -1, 1);
      }
      for(j = 1; j < N; ++j){
        if(a[0][j] < -1)
          s += hit(0, j, 1, 0, 1);
        if(a[N][j] < -1)
          s += hit(N, j, -1, 0, 1);
      }

      for(i = N; i >= 0 && a[i][0] < 2; --i);
      if(i > 0)
        s += hit(i, 0, -1, 0, i);
      for(j = N; j >= 0 && a[0][j] < 2; --j);
      if(j > 0)
        s += hit(0, j, 0, -1, j);
      if(a[0][0] > 1)
        s += hit(0, 0, -1, -1, 1);
      for(i = 0; i <= N && a[i][N] < 2; ++i);
      if(i < N)
        s += hit(i, N, 1, 0, N-i);
      for(j = 0; j <= N && a[N][j] < 2; ++j);
      if(j < N)
        s += hit(N, j, 0, 1, N-j);
      if(a[N][N] > 1)
        s += hit(N, N, 1, 1, 1);

      if(s > ms){
        for(i = 0; i < rn; ++i)
          for(j = 0; j < 5; ++j)
            rf[i][j] = r[i][j];
        rfn = rn;
      }
    }

    printf("%d\n", rfn);
    for(i = 0; i < rfn; ++i)
      printf("%d %d %d %d %d\n", rf[i][0], rf[i][1], rf[i][2], rf[i][3],
                                 rf[i][4]);
  }
  return 0;
}
