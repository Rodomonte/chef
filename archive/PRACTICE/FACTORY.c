// FACTORY

#include <stdio.h>

#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int ra[100], rb[100];
double a[100], b[100][100];
int main(){
  int T,F,S, i,j,k;
  double m,t;

  T = getn();
  while(T--){
    F = getn(), S = getn();
    for(i = 0; i < F; ++i)
      scanf("%lf", a+i);
    for(i = 0; i < S; ++i)
      for(j = 0; j < F; ++j)
        scanf("%lf", b[i]+j);

    for(i = 0; i < F; ++i)
      ra[i] = 0;
    for(i = 0; i < S; ++i){
      for(j = 0, m = INF; j < F; ++j)
        if(a[j] + b[i][j] < m)
          m = a[j] + b[i][j], k = j;
      ra[k] = 1, rb[i] = k;
    }

    for(i = 0; i < F; ++i){
      if(!ra[i]) continue;
      // For all stores using fac i:
      //   Add savings of best swap to n
      //   If n < 0, swap all
    }

    for(i = 0; i < S; ++i){
      for(m = j = 0; j < F; ++j){
        if(!ra[j]) continue;
        t = b[i][rb[i]] - b[i][j];
        if(t > m) m = t, k = j;
      }
      if(m != 0) rb[i] = k;
    }

    for(i = 0; i < F; ++i)
      printf("%d ", ra[i]);
    printf("\n");
    for(i = 0; i < S; ++i)
      printf("%d ", rb[i]+1);
    printf("\n");
  }
  return 0;
}
