// PIANO1

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
  int T,N, i,j,n,r;
  char s[101];
  T = getn();
  while(T--){
    scanf("%s", s);
    N = getn()*12, n = i = 0;
    while(s[i]){
      n += (s[i] == 'T') ? 2 : 1;
      ++i;
    }
    r = 0;
    for(i = 0; i < N-n; ++i)
      for(j = 1; i+j*n < N; ++j)
        ++r;
    printf("%d\n", r);
  }
  return 0;
}
