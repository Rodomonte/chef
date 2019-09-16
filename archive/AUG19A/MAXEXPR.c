// MAXEXPR

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked
#define MIN 0.000000001

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

double absd(double d){ return (d < 0.0) ? -d : d; }
double fix(double d){ return (d < 0.0 && d > -MIN) ? 0.0 : d; }

double a[100000], b[100000], c[100000], d[100000];

int main(){
  int T,N, i,j;
  double f,m,t;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      scanf("%lf", b+i);
    for(i = 0; i < N; ++i)
      scanf("%lf", c+i);

    for(i = 0; i < N; ++i)
      a[i] = -c[i];
    for(f = i = 0; i < N; ++i)
      f += a[i] * b[i];

    if(f > MIN){
      printf("-1\n");
      continue;
    }else if(absd(f) < MIN){
      printf("%lf", 0.0);
      for(i = 0; i < N; ++i)
        printf(" %lf", a[i]);
      printf("\n");
      continue;
    }

    m = 2000.0;
    for(i = 0; i < N; ++i)
      if(b[i] < m) m = b[i], j = i;
    a[j] += -f / b[j];
    for(t = i = 0; i < N; ++i)
      t += 1.0 / b[i];
    for(i = 0; i < N; ++i)
      d[i] = 1.0 / b[i] / t * (a[j] + c[j]);
    for(i = 0; i < N; ++i){
      if(i == j) continue;
      a[i] += d[i] * b[j] / b[i];
      a[j] -= d[i];
    }

    for(f = i = 0; i < N; ++i)
      f += sqrt(a[i] + c[i]);
    printf("%lf", f);
    for(i = 0; i < N; ++i)
      printf(" %lf", a[i]);
    printf("\n");
  }
  return 0;
}
