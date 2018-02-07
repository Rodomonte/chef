// CHEFGIRL

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
int min(int a, int b){
  return (a < b) ? a : b;
}
int max(int a, int b){
  return (a > b) ? a : b;
}

char il[100001], ir[100001];
int a[100000],an, b[100001]={0};
int main(){
  char l,r;
  int N,M,A,B, i,j, c[33][33], m[33][33];

  N = getn(), M = getn(), an = 0;
  for(i = 0; i < M; ++i){
    A = getn(), B = getn();
    il[B] = getn(), ir[B] = getn();
    if(A == 1)
      a[an++] = B;
    else
      b[A] = B;
  }

  memset(m, 1<<6, 4356);
  for(i = 0; i < an; ++i){
    memset(c, 0, 4356);
    for(j = a[i]; j; j = b[j]){
      for(l = 1; l < il[j]; ++l){
        for(r = l; r <= ir[j]; ++r)
          c[l][r] += il[j]-l;
        for(r = ir[j]+1; r <= 32; ++r)
          c[l][r] += il[j]-l+r-ir[j];
      }
      for(l = il[j]; l <= 32; ++l)
        for(r = max(l, ir[j]+1); r <= 32; ++r)
          c[l][r] += r-ir[j];
    }
    for(l = 1; l <= 32; ++l)
      for(r = l; r <= 32; ++r)
        m[l][r] = min(m[l][r], c[l][r]);
  }
  for(i = 2; i <= 32; ++i)
    for(l = 1, r = i; r <= 32; ++l, ++r)
      for(j = 1; j < i; ++j)
        m[l][r] = min(m[l][r], m[l][l+j-1] + m[l+j][r]);

  printf("%d\n", m[1][32]);
  return 0;
}
