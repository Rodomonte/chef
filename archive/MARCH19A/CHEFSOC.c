// CHEFSOC

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int madd(int a, int b){ return ((a += b) >= MOD) ? a-MOD : a; }
int mmul(int a, int b){ return (int)((ll)a * (ll)b % (ll)MOD); }

int a[100000], b[100000], c[100000], d[100000], e[100000];
int main(){
  int T,N, i,j,k, r,t;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i) a[i] = getn(), b[i] = c[i] = d[i] = e[i] = 0;

    for(i = 1; i < N; ++i){
      if(a[i] == 1 && a[i-1] == 2){
        e[i-1] = 0;
        for(j = i-2, k = 1; a[j] == 2; --j, ++k)
          e[j] = k;
        if(a[j+1] == 2)
          e[j] = k;
      }
    }
    for(j = N-1, k = 0; a[j] == 2; --j, ++k)
      e[j] = k;
    if(j < N-1 && a[j+1] == 2)
      e[j] = k;

    b[0] = 1;
    for(i = 1; i < N; ++i){
      // 1
      b[i] = madd(b[i], b[i-1]);
      // 2
      if(i > 1 && a[i-2] == 2)
        b[i] = madd(b[i], madd(b[i-2], c[i-2]));
      // 3
      if(a[i-1] == 2 && i < N-1)
        c[i] = madd(c[i], b[i-1]);
      // 4
      if(a[i-1] == 2 && i < N-2 && a[i+2] == 2)
        d[i] = madd(d[i], b[i-1]);
      if(a[i-1] == 2){
        // 5
        t = ((e[i] - ((e[i] == N-i-1) ? 1 : 0)) >> 1);
        if(t > 0)
          d[i] = madd(d[i], mmul(b[i-1], t));
        // 6
        if(e[i] >= 2 && (e[i]&1) == 0 && i+e[i]+2 < N && a[i+e[i]+2] == 2)
          d[i] = madd(d[i], b[i-1]);
        if(e[i] >= 4)
          d[i] = madd(d[i], mmul(b[i-1], (e[i]>>1)-1));
      }
    }

    for(i = r = 0; i < N; ++i)
      r = madd(r, madd(madd(b[i], c[i]), d[i]));
    printf("%d\n", r);
  }
  return 0;
}
