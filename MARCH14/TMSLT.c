// TMSLT

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

#define ll long long
#define MAX 1000000
ll abs(ll a){
  return a >= 0 ? a : -a;
}
int a[MAX], b[MAX],bn;
int main(){
  int T,N,A,B,C,D, i,t,s,d,m;
  ll p,r1,r2;
  T = getn();
  while(T--){
    N = getn(), A = getn(), B = getn(), C = getn(), D = getn();
    memset(a, 0, MAX*4);
    r1 = r2 = 0, a[D] = 1, b[0] = D, bn = 1, p = D, t = 0;
    for(i = 1; i < N; i++){
      p = (p*p*A + p*B + C) % MAX;
      if(a[p])
        break;
      b[bn++] = p;
      a[p]++;
    }
    for(i = 0; i < MAX; i++){
      if(b[i] == p)
        break;
      t += a[b[i]];
    }
    s = i;
    d = (N-t+bn-s-1)/(bn-s), m = (N-t)%(bn-s);
    m = (!m) ? bn-s : m, t = 0;
    for(i = s; i < s+m; i++)
      a[b[i]] += d-1;
    for(i = s+m; i < bn; i++)
      a[b[i]] += d-2;
    if(bn < 10000){
      sort(b, bn);
      for(i = 0; i < bn; i++){
        if(!a[b[i]])
          continue;
        if(t){
          r1 += ((a[b[i]]+1)>>1) * b[i];
          r2 += (a[b[i]]>>1) * b[i];
        }else{
          r1 += (a[b[i]]>>1) * b[i];
          r2 += ((a[b[i]]+1)>>1) * b[i];
        }
        t = (t + a[b[i]]) & 1;
      }
      printf("%lld\n",abs(r1-r2));
      continue;
    }
    for(i = 0; i < MAX; i++){
      if(!a[i])
        continue;
      if(t){
        r1 += ((a[i]+1)>>1) * i;
        r2 += (a[i]>>1) * i;
      }else{
        r1 += (a[i]>>1) * i;
        r2 += ((a[i]+1)>>1) * i;
      }
      t = (t + a[i]) & 1;
    }
    printf("%lld\n",abs(r1-r2));
  }
  return 0;
}
