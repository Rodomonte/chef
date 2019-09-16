// STRMRG

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

char a[5001], b[5001];
int d[5000][5000];
int main(){
  int T,N,M, i,j;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N; ++i) a[i] = gc();
    for(i = 0, gc(); i < M; ++i) b[i] = gc();
    gc();

    for(i = j = 1; j < N; ++j) if(a[j] != a[j-1]) a[i++] = a[j];
    N = i;
    for(i = j = 1; j < M; ++j) if(b[j] != b[j-1]) b[i++] = b[j];
    M = i;

    for(i = 0; i < N; ++i) for(j = 0; j < M; ++j)
      d[i][j] = (a[i] == b[j]) ? ((i > 0 && j > 0) ? d[i-1][j-1]+1 : 1) :
                max((i > 0) ? d[i-1][j] : 0, (j > 0) ? d[i][j-1] : 0);

    printf("%d\n", d[N-1][M-1] + (N-d[N-1][M-1]) + (M-d[N-1][M-1]));
  }
  return 0;
}
