// NUMFACT

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char s[1000]={0};
int c[1000000];
int main(){
  int T,N,X, i,j, r;

  for(i = 2; i < 1000; ++i) if(!s[i]) for(j = i*i; j < 1000; j += i) s[j] = 1;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < 1000000; ++i) c[i] = 0;
    for(i = 0; i < N; ++i){
      X = getn();
      for(j = 2; j < 1000; ++j) if(!s[j]) while(!(X % j)) X /= j, ++c[j];
      ++c[X];
    }

    for(i = 2, r = 1; i < 1000000; ++i) if(c[i]) r *= c[i] + 1;
    printf("%d\n", r);
  }
  return 0;
}
