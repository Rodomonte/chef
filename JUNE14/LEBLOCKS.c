// LEBLOCKS

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked
#define ull unsigned long long
const ull MAX = 18446744073709551615ULL;

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

int min(int a, int b){
  return (a < b) ? a : b;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

ull r; int ri;
void ra(ull n){
  if(MAX-n < r){
    r -= MAX-n;
    ri++;
  }else
    r += n;
}
double rd(ull t){
  int i;
  double d = (double)r/(double)t;
  for(i = 0; i < ri; i++)
    d += (double)MAX/(double)t;
  return d;
}

typedef struct {
  int h, c;
} B ;

ull a[201][19], a2[201][19];
int main(){
  char f, c[21];
  int T,N,K, i,j,k,l,h1,h2,ht;
  B b[20];
  ull t, fac[21];

  for(fac[0] = i = 1; i <= 20; i++)
    fac[i] = fac[i-1]*i;
  T = getn();
  while(T--){
    N = getn(), K = getn(), r = ri = ht = 0;
    t = fac[N];
    for(i = 0; i < N; i++)
      ht += (b[i].h = getn()), b[i].c = getn();
    for(i = 0; i < N; i++)
      if(K < b[i].h)
        for(j = 0; j < b[i].h-K; j++)
          ra(t);
    memset(c, 0, 21);
    for(i = 0; i < N; i++){
      if(c[b[i].c])
        continue;
      h1 = b[i].h;
      for(j = i+1, f = 0; j < N; j++)
        if(b[j].c == b[i].c)
          h2 = b[j].h, f = 1;
      if(!f)
        continue;
      memset(a, 0, 30552);
      a[0][0] = 1;
      for(j = 0; j < N; j++){
        if(b[j].c == b[i].c)
          continue;
        memset(a2, 0, 30552);
        for(k = 0; k <= ht-b[j].h; k++)
          for(l = 0; l <= N-3; l++)
            if(a[k][l])
              a2[k+b[j].h][l+1] += a[k][l];
        for(k = 0; k <= ht; k++)
          for(l = 0; l <= N-2; l++)
            a[k][l] += a2[k][l];
      }
      for(j = max(0,K-h1-h2+1); j < K; j++)
        for(k = 0; k <= N-2; k++)
          if(a[j][k])
            // Out perms * mid pos * mid swap * in perms * in freq * cfn
            ra(fac[N-k-2]*(N-k-1)*2*fac[k]*a[j][k]*
               min(min(min(K-j,j-K+h1+h2),h1),h2));
      c[b[i].c] = 1;
    }
    printf("%.8lf\n",rd(t));
  }
  return 0;
}
