// KPRIME

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char a[100001]={0};
int b[100001][5];
int main(){
  int T = getn(),A,B,K, i,j, f[6], n,p,z;
  for(i = 0; i < 5; i++)
    b[1][i] = 0;
  for(i = 2; i <= 100000; i++){
    z = 2, n = i, p = 0;
    while(z * z <= n){
      if(n % z == 0){
        if(!a[z]){
          a[z] = 1;
          f[p++] = z;
        }
        n /= z;
      }else
        z++;
    }
    z = p;
    if(!a[n])
      p++;
    for(j = 0; j < 5; j++)
      b[i][j] = b[i-1][j];
    if(p <= 5)
      b[i][p-1]++;
    for(j = 0; j < z; j++)
      a[f[j]] = 0;
  }
  while(T--){
    A = getn(), B = getn(), K = getn();
    printf("%d\n",b[B][K-1]-b[A-1][K-1]);
  }
  return 0;
}
