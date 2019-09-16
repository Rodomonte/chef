// CHEFRRUN

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int MOD;
int madd(int a, int b){ return ((a += b) >= MOD) ? a-MOD : a; }

char r[100000];
int a[100000], v[100000];
int main(){
  int T,N, i,j,k, n;

  T = getn();
  while(T--){
    N = MOD = getn();
    for(i = 0; i < N; ++i) a[i] = getn()%N, v[i] = -1, r[i] = 0;

    for(i = 0; i < N; ++i){
      if(v[i] != -1) continue;
      for(j = i; v[j] == -1; j = madd(j, a[j]+1)) v[j] = i;
      if(v[j] == i){
        k = j, r[j] = 1;
        for(j = madd(j, a[j]+1); j != k; j = madd(j, a[j]+1)) r[j] = 1;
      }
    }

    for(i = n = 0; i < N; ++i) if(r[i]) ++n;
    printf("%d\n", n);
  }
  return 0;
}
