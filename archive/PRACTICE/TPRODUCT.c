// TPRODUCT

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define MAX 32768
#define MOD 1000000007
long long a[MAX];
double b[MAX];
int main(){
  int H, i;
  while(H=(1<<getn())-1){
    for(i = 1; i <= H; i++)
      b[i] = a[i] = getn();
    for(i = H/2; i >= 1; i--){
      if(b[i*2] > b[i*2+1])
        a[i] *= a[i*2], b[i] *= b[i*2];
      else
        a[i] *= a[i*2+1], b[i] *= b[i*2+1];
      a[i] %= MOD;
    }
    printf("%lld\n",a[1]);
  }
  return 0;
}
