// L2GRAPH

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked
#define INF 2000000000
#define D 20

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

double dist(int* a, int* b){
  int i, t = 0;
  for(i = 0; i < D; ++i)
    t += (a[i]-b[i]) * (a[i]-b[i]);
  return sqrt(t);
}
void set(int* d, int* s){
  int i;
  for(i = 0; i < D; ++i) d[i] = s[i];
}
char eq(int* a, int* b){
  int i;
  for(i = 0; i < D; ++i) if(a[i] != b[i]) return 0;
  return 1;
}

int a[300][300], r[300][20];
int main(){
  char f;
  int T,N, i,j,k,ii, d, p[20], c[41][20];
  double m,t, m2,m3;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      for(j = 0; j < N; ++j)
        a[i][j] = getn();

    for(i = 0; i < D; ++i) r[0][i] = 0;
    for(i = 1; i < N; ++i){
      set(p, r[0]), d = a[0][i];
      while(d > (a[0][i]>>2)){
        for(j = 0; j < 41; ++j) set(c[j], p);
        for(j = 1; j < 41; j += 2) c[j][j>>1] -= d;
        for(j = 2; j < 41; j += 2) c[j][(j-1)>>1] += d;

        m = INF;
        for(j = 0; j < 41; ++j){
          m2 = 0, m3 = INF;
          for(k = 0; k < i; ++k){
            t = dist(c[j], r[k]) / a[i][k];
            if(t > m2) m2 = t;
            if(t < m3) m3 = t;
          }
          if(m2/m3 < m) m = m2/m3, ii = j;
        }
        set(p, c[ii]), d /= 2;
      }

      while(1){
        f = 1;
        for(j = 0; j < i; ++j)
          if(eq(p, r[j]))
            f = 0, p[0] += 1;
        if(f) break;
      }
      set(r[i], p);
    }

    printf("%d\n", D);
    for(i = 0; i < N; ++i){
      for(j = 0; j < D; ++j)
        printf("%d ", r[i][j]);
      printf("\n");
    }
  }
  return 0;
}
