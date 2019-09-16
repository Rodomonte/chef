// TLCS

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

int min(int a, int b){ return (a < b) ? a : b; }

char a[1001], b[1001];
int main(){
  int T,N,M, i,ti, f;

  T = getn();
  for(ti = 1; ti <= T; ++ti){
    N = getn(), scanf("%s", a), M = getn(), scanf("%s", b);

    printf("case %d %c\n", ti, 'N');
  }
  return 0;
}
