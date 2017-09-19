// PRLADDU

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int n){
  return (n < 0) ? 0-n : n;
}
int min(int a, int b){
  return (a < b) ? a : b;
}

int a[100000];
int main(){
  int T,N, i,j,m;
  ll r;
  T = getn();
  while(T--){
    N = getn(), r = 0;
    for(i = 0; i < N; i++)
      a[i] = getn();
    for(i = j = 0; i < N;){
      if(a[i] <= 0){
        i++;
        continue;
      }
      if(a[j] >= 0){
        j++;
        continue;
      }
      m = min(a[i], 0-a[j]);
      a[i] -= m, a[j] += m;
      r += (ll)m * abs(i-j);
    }
    printf("%lld\n", r);
  }
  return 0;
}
