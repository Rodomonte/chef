// CBALLS

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[10000]={0}, p[1229], s[1229][10001];
int main(){
  int T,N, i,j,k,m,r;

  for(i = 2, k = 0; i <= 9973; ++i){
    if(a[i])
      continue;
    p[k++] = i;
    for(j = i+i; j <= 9973; j += i)
      a[j] = 1;
  }
  for(i = 0; i < 1229; ++i)
    for(j = 1; j <= 10000;)
      for(k = 1; j <= 10000 && k <= p[i]; ++j, ++k)
        s[i][j] = p[i]-k;

  T = getn();
  while(T--){
    N = getn(), a[0] = getn(), r = 0;
    for(i = 1; i < N; ++i){
      a[i] = getn();
      if(a[i] < a[i-1])
  r += a[i-1]-a[i], a[i] = a[i-1];
    }

    m = 1000000000;
    for(i = 0; i < 1229; ++i){
      for(j = k = 0; j < N; ++j)
        k += s[i][a[j]];
      if(k < m)
  m = k;
    }
    printf("%d\n", r+m);
  }
  return 0;
}
