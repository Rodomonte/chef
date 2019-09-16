// TWTCLOSE

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  char a[1000], s[9];
  int N,K,X, i, r;

  N = getn(), K = getn();

  for(r = i = 0; i < N; ++i) a[i] = 0;
  while(K--){
    scanf("%s", s);
    if(s[2] == 'I') X = getn()-1, r += (a[X] ? -1 : 1), a[X] = (a[X] ? 0 : 1);
    else for(r = i = 0; i < N; ++i) a[i] = 0;
    printf("%d\n", r);
  }

  return 0;
}
