// DBOY

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[1001],  // Distance counts
  b[1001];  // Min # of stations
int main(){
  int T = getn(),N, i,j, m,n,r;
  while(T--){
    N = getn(), m = r = 0;
    for(i = 2; i <= 1000; i += 2)
      a[i] = 0;
    for(i = 0; i < N; i++){
      n = getn()*2;
      a[n]++;
      if(n > m) m = n;
    }
    for(i = 0; i <= m; i++)
      b[i] = 1001;
    for(i = 0; i < N; i++){
      n = getn();
      b[n] = 1;
      if(a[n]){
        r += a[n];
        a[n] = 0;
      }
    }
    for(i = 1; i <= m; i++){
      if(b[i] < 1001)
        continue;
      for(j = 1; j <= i/2; j++){
        n = b[j] + b[i-j];
        if(n < b[i]){
          b[i] = n;
          if(b[i] == 2)
            break;
        }
      }
      if(a[i])
        r += b[i] * a[i];
    }
    printf("%d\n",r);
  }
  return 0;
}
