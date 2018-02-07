// ANUCBC

#include <stdio.h>
#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

#define ll long long
#define MAX 100000
#define MOD 1000000009
int pow(ll n, int e){
  ll r = 1;
  while(e){
    if(e & 1)
      r = (r * n) % MOD;
    n = (n * n) % MOD;
    e >>= 1;
  }
  return (int)r;
}
int inv(int a){
  int b,b0,t,q,x0,x1;
  b0 = b = MOD, x0 = 0, x1 = 1;
  while(a > 1){
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  if(x1 < 0) x1 += b0;
  return x1;
}
int a[MAX], b[(MAX>>1)+1], f[MAX+1], ia[MAX+1];
int main(){
  int T,N,Q,M, i,j,k,x,y, c[100],t[100],p[100],r[100];
  ll t1,t2;
  f[0] = 1, ia[0] = -1;
  for(i = 1; i <= MAX; i++){
    t1 = f[i-1], t2 = i;
    f[i] = (int)(t1 * t2 % MOD);
    ia[i] = -1;
  }
  T = getn();
  while(T--){
    N = getn(), Q = getn();
    for(i = 0; i < N; i++)
      a[i] = getn();
    while(Q--){
      M = getn();
      memset(c, 0, M<<2);
      for(i = 0; i < N; i++){
        j = a[i] % M;
        j += (j < 0) ? M : 0;
        c[j]++;
      }
      memset(r, 0, M<<2);
      r[0] = pow(2, c[0]);
      for(i = 1; i < M; i++){
        if(!c[i])
          continue;
        memset(t, 0, M<<2);
        k = i, b[0] = 1, x = c[i], y = 0;
        for(j = 1; j <= c[i]>>1; j++){
          x--, y++;
          t1 = f[x], t2 = f[y];
          t1 = t1 * t2 % MOD;
          if(t1 <= MAX){
            if(ia[t1] == -1)
              ia[t1] = t2 = inv(t1);
            else
              t2 = ia[t1];
          }else
            t2 = inv(t1);
          t1 = f[c[i]];
          b[j] = (int)(t1 * t2 % MOD);
          t[k] = (t[k]+b[j] >= MOD) ? t[k]+b[j]-MOD : t[k]+b[j];
          k = (k+i >= M) ? k+i-M : k+i;
        }
        for(j = (c[i]>>1)-((c[i]&1)?0:1); j >= 0; j--){
          t[k] = (t[k]+b[j] >= MOD) ? t[k]+b[j]-MOD : t[k]+b[j];
          k = (k+i >= M) ? k+i-M : k+i;
        }
        memcpy(p, r, M<<2);
        for(j = 0; j < M; j++){
          if(!t[j])
            continue;
          for(k = 0; k < M; k++){
            if(!p[k])
              continue;
            x = (j+k >= M) ? j+k-M : j+k;
            t1 = t[j], t2 = p[k];
            y = (int)(t1 * t2 % MOD);
            r[x] = (r[x]+y >= MOD) ? r[x]+y-MOD : r[x]+y;
          }
        }
      }
      printf("%d\n",r[0]);
    }
  }
  return 0;
}
