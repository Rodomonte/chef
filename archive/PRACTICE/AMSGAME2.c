// AMSGAME2

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define ll long long
#define MAX 10001
int gcd(int a, int b){
  return b ? gcd(b,a%b) : a;
}
ll a[MAX], b[MAX], c[MAX], d[MAX];
int main(){
  int T,N,A, i, g,t,n;
  T = getn();
  while(T--){
    N = getn(), g = 0;
    for(i = 0; i < MAX; i++)
      b[i] = 0;
    while(N--){
      A = getn(), t = g, n = 0;
      for(i = 0; i < g; i++){
        c[n] = gcd(A, a[i]);
        d[n++] = b[a[i]];
      }
      g = t;
      if(!b[A])
        a[g++] = A;
      b[A]++;
      for(i = 0; i < n; i++){
        if(!b[c[i]])
          a[g++] = c[i];
        b[c[i]] += d[i];
      }
    }
    printf("%lld\n",b[1]);
  }
  return 0;
}
