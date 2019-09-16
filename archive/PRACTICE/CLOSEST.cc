// CLOSEST

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked
#define INFD (double)(1LL<<50)
#define ITER 50000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P {
  int x,y,z;
};

double dist(P a, P b){
  return sqrt((double)(a.x-b.x)*(a.x-b.x) + (double)(a.y-b.y)*(a.y-b.y) +
              (double)(a.z-b.z)*(a.z-b.z));
}

P a[50000], b[50000];
int main(){
  int N,Q, i,j,c,r;
  double m,d;

  N = getn();
  for(i = 0; i < N; ++i)
    a[i].x = getn(), a[i].y = getn(), a[i].z = getn();
  Q = getn();
  for(i = 0; i < Q; ++i)
    b[i].x = getn(), b[i].y = getn(), b[i].z = getn();

  for(i = c = 0; i < Q; ++i){
    if(c >= ITER){
      printf("0\n");
      continue;
    }

    m = INFD;
    for(j = 0; j < N; ++j, ++c){
      d = dist(b[i], a[j]);
      if(d < m)
        m = d, r = j;
    }
    printf("%d\n", r);
  }

  return 0;
}
