// MISINTER

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define MAX 100001
#define MOD 1000000007
int a[MAX], b[MAX];
int main(){
  int T = getn(), N, i,j, c, p;
  long long d;
  while(T--){
    N = getn();
    if(N == 1){
      printf("26\n");
      continue;
    }
    if(N % 2){
      c = 1;
      N--;
    }else
      c = 0;
    for(i = 1; i <= N/2; i += 2){
      j = i * 2;
      while(j <= N)
        j *= 2;
      j /= 2;
      a[i] = j;
      b[N+1-i] = N + 1 - j;
    }
    for(i = 1; i <= N/2; i += 2){
      if(a[i] > N / 2)
        c++;
      else
        continue;
      for(j = b[a[i]]; j != i;){
        p = b[a[j]];
        a[j] = i;
        j = p;
      }
    }
    d = 1;
    while(c--){
      d *= 26;
      d %= MOD;
    }
    printf("%lld\n",d);
  }
  return 0;
}
