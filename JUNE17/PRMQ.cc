// PRMQ

#include <stdio.h>
#include <math.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char sv[1000000]={0};
int a[100000], p[78498], b[317][78498]={{0}}, pm[1000001]={0};
vector<int> d[100000];
int main(){
  int N,Q,L,R,X,Y, i,j,k,r,s,t, pn;

  for(i = 2, pn = 0; i < 1000000; ++i){
    if(sv[i]) continue;
    for(j = i+i; j < 1000000; j += i)
      sv[j] = 1;
    p[pn] = i, pm[i] = pn, ++pn;
  }
  for(i = 4, t = 3; i <= 1000000; ++i){
    if(pm[i]) t = i;
    else pm[i] = pm[t];
  }

  N = getn();
  for(i = 0; i < N; ++i){
    a[i] = t = getn(), s = (int)sqrt(a[i]);
    for(j = 0; p[j] <= s; ++j)
      while(t % p[j] == 0)
        d[i].pb(p[j]), t /= p[j];
    if(t > 1) d[i].pb(t);
  }

  s = (int)sqrt(N);
  for(i = 0, j = -1; i < N; ++i){
    if(i % s == 0) ++j;
    for(k = 0; k < d[i].size(); ++k)
      ++b[j][pm[d[i][k]]];
  }

  s = N / s;
  for(i = 0; i < s; ++i)
    for(j = 1; j < 78498; ++j)
      b[i][j] += b[i][j-1];

  Q = getn(), s = N / s;
  while(Q--){
    L = getn()-1, R = getn()-1, X = getn(), Y = getn(), r = 0;
    for(i = L; i <= R && i % s; ++i){
      for(j = 0; j < d[i].size(); ++j)
        if(d[i][j] >= X && d[i][j] <= Y)
          ++r;
      //printf("1  i=%d r=%d\n", i,r);
    }

    for(k = i/s; i+s-1 <= R; ++k, i += s){
      r += b[k][pm[Y]] - ((X-1 < 2) ? 0 : b[k][pm[X-1]]);
      //printf("2  i=%d k=%d r=%d\n", i,k,r);
    }

    for(; i <= R; ++i){
      for(j = 0; j < d[i].size(); ++j)
        if(d[i][j] >= X && d[i][j] <= Y)
          ++r;
      //printf("3  i=%d r=%d\n", i,r);
    }

    printf("%d\n", r);
  }

  return 0;
}
