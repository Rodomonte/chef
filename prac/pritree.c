// PRITREE

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[1000];
int main(){
  int N, i;

  N = getn();
  for(i = 0; i < N; ++i)
    a[i] = getn();

  for(i = 2; i <= N; ++i)
    printf("1 %d\n", i);

  return 0;
}
