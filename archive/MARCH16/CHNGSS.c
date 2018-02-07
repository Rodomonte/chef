// CHNGSS

#include <stdio.h>

#define gc getchar_unlocked

inline int geti(){
  char c = gc(), f = 1; int n = 0;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f; }

int a[501][25001];
int main(){
  int N,M,C, i,j,it;

  N = geti(), M = geti(), C = geti(), it = 0;
  for(i = 1; i <= N; ++i){
    for(j = 1; j <= M; ++j, ++it){
      if(C){
        printf("2 %d %d %d %d\n", i,i,j,j); fflush(stdout);
        a[i][j] = geti(), --C;
        continue;
      }
      if(it < 120000){
        printf("1 %d %d %d %d 1 12\n", i,i,j,j); fflush(stdout);
        if(geti()){ a[i][j] = 6; continue; }
        printf("1 %d %d %d %d 13 25\n", i,i,j,j); fflush(stdout);
        if(geti()){ a[i][j] = 18; continue; }
        printf("1 %d %d %d %d 26 37\n", i,i,j,j); fflush(stdout);
        a[i][j] = geti() ? 31 : 44;
        continue;
      }
      printf("1 %d %d %d %d 1 16\n", i,i,j,j), fflush(stdout);
      if(geti()){ a[i][j] = 8; continue; }
      printf("1 %d %d %d %d 17 32\n", i,i,j,j), fflush(stdout);
      a[i][j] = geti() ? 25 : 42;
    }
  }

  printf("3\n");
  for(i = 1; i <= N; ++i){
    for(j = 1; j <= M; ++j) printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}
