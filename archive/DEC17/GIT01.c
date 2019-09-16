// GIT01

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }

char a[100][101];
int main(){
  char c,d;
  int T,N,M, i,j, x,y;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N; ++i) scanf("%s", a[i]);

    for(i = x = y = 0, c = 'R', d = 'G'; i < N; ++i){
      for(j = 0; j < M; ++j){
        if(a[i][j] == 'R' && c == 'G') x += 5;
        if(a[i][j] == 'G' && c == 'R') x += 3;
        if(a[i][j] == 'R' && d == 'G') y += 5;
        if(a[i][j] == 'G' && d == 'R') y += 3;
        if(j != M-1 || (M&1))
          c = (c == 'R') ? 'G' : 'R', d = (d == 'R') ? 'G' : 'R';
      }
    }

    printf("%d\n", min(x, y));
  }
  return 0;
}
