// MAXPR

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked
#define MOD 1000000007

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

int msub(int n, int s){
  n -= s;
  if(n < 0)
    n += MOD;
  return n;
}

int a[200001], b[101][101], c[101];
int main(){
  int T,N, i,j,k,r;
  T = getn();
  while(T--){
    memset(b, 0, 101*101*4);
    memset(c, 0, 101*4);
    N = getn(), r = 1;
    for(i = 1; i <= N; i++){
      a[i] = getn();
      r <<= 1;
      if(r >= MOD)
        r -= MOD;
    }
    r = msub(r, 1);
    for(i = N; i >= 1; i--){
      r = msub(r, 1);
      for(j = 1; j <= 100; j++)
        if(c[j])
          r = msub(r, c[j]);
      for(j = (a[i]>>1)+1, k = 0; k < 50; j++, k++){
        if(a[i] > j)
          r = msub(r, b[j][j-(a[i]-j)]);
        else if(a[i] == j)
          r = msub(r, b[j][j]);
        else
          r = msub(r, b[j][j+(j-a[i])]);
      }
      for(j = (a[i]>>1)+1, k = 0; k < 50; j++, k++){
        if(a[i] > j)
          b[a[i]][j] += b[j][j-(a[i]-j)];
        else if(j == a[i])
          b[a[i]][j] += b[j][j];
        else
          b[a[i]][j] += b[j][j+(j-a[i])];
        if(b[a[i]][j] >= MOD)
          b[a[i]][j] -= MOD;
      }
      for(j = 1; j <= 100; j++)
        if(c[j]){
          b[a[i]][j] += c[j];
          if(b[a[i]][j] >= MOD)
            b[a[i]][j] -= MOD;
        }
      c[a[i]]++;
    }
    printf("%d\n",r);
  }
  return 0;
}
