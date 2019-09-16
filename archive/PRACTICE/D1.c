// D1

#include <stdio.h>

//#define getchar_unlocked getchar

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
#define MAX 500001
#define MOD 10000
int a[MAX];
char f[MAX];
int main(){
  int T = getn(), N, i, t;
  for(i = 0; i < MAX; i++)
    a[i] = 1, f[i] = 0;
  for(i = 2; (t=i*i) < MAX; i++){
    a[t] *= i;
    if(a[t] >= MOD){
      f[t] = 1;
      a[t] %= MOD;
    }
    t += i;
    for(; t < MOD; t += i){
      a[t] *= t;
      if(a[t] >= MOD){
        f[t] = 1;
        a[t] %= MOD;
      }
    }
    for(; t < MAX; t += i){
      a[t] *= t % MOD;
      f[t] = 1;
      a[t] %= MOD;
    }
  }
  while(T--){
    N = getn();
    if(!f[N])
      printf("%d\n",a[N]);
    else{
      if(a[N] < 1000){
        putchar('0');
        if(a[N] < 100){
          putchar('0');
          if(a[N] < 10)
            putchar('0');
        }
      }
      printf("%d\n",a[N]);
    }
  }
  return 0;
}
