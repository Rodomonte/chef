// BURNCITY

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

char a[50][51], b[50][50], r[251];
int N, xd,yd;

void find(int x, int y){
  int i,j,k;
  for(k = 1; k < N; ++k){
    for(i = x-k; i <= x+k; ++i){
      for(j = y-k; j <= y+k; ++j){
        if(i > x-k && i < x+k && j == y-k+1){ j = y+k-1; continue; }
        if(i < 0 || i >= N || j < 0 || j >= N) continue;
        if(a[i][j] == 'b'){ xd = i, yd = j; return; }
      }
    }
  }
  xd = yd = -1;
}

int main(){
  int T,C,H, i,j,ti, h,x,y, rn;

  T = getn();
  for(ti = 1; ti <= T; ++ti){
    N = getn(), C = getn(), H = getn(), y = getn()-1, x = getn()-1;
    for(i = 0; i < N; ++i)
      scanf("%s", a[i]);

    for(rn = h = 0; h < H; ++h){
      if(h && !(h & 1)){
        for(i = 0; i < N; ++i)
          for(j = 0; j < N; ++j)
            b[i][j] = a[i][j];
        for(i = 0; i < N; ++i){
          for(j = 0; j < N; ++j){
            if(a[i][j] == 'f'){
              if(i > 0 && a[i-1][j] != 'w') b[i-1][j] = 'f';
              if(i < N-1 && a[i+1][j] != 'w') b[i+1][j] = 'f';
              if(j > 0 && a[i][j-1] != 'w') b[i][j-1] = 'f';
              if(j < N-1 && a[i][j+1] != 'w') b[i][j+1] = 'f';
            }
          }
        }
        for(i = 0; i < N; ++i)
          for(j = 0; j < N; ++j)
            a[i][j] = b[i][j];
      }

      if(!C){ r[rn++] = '-'; continue; }
      if(a[x][y] == 'b'){ r[rn++] = '+', a[x][y] = 'w', --C; continue; }
      find(x, y);
      if(xd == -1){ r[rn++] = '-'; continue; }
      if(x < xd) r[rn++] = 'S', ++x;
      else if(x > xd) r[rn++] = 'N', --x;
      else if(y < yd) r[rn++] = 'E', ++y;
      else if(y > yd) r[rn++] = 'W', --y;
    }

    r[rn] = 0;
    printf("city %d Y\n%s\n", ti, r);
  }
  return 0;
}
