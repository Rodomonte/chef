// FORESTGA

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked
#define E18 1000000000000000000LL

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}
ll getl(){
  ll n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int h[100000], r[100000];
int main(){
  int N, i, f,q;
  ll W,L, m,p,s,t,u;

  N = getn(), W = getl(), L = getl();
  for(i = 0; i < N; ++i) h[i] = getn(), r[i] = getn();

  m = E18, s = E18>>1, p = q = -1;
  while(1){
    for(i = t = f = 0; i < N; ++i){
      if(E18 / r[i] < m){ f = 1; break; }
      u = m * r[i] + h[i];
      if(u >= L) t += u;
      if(t >= W){ f = 1; break; }
    }

    if(f){
      if(!m || m == p+1 && !q) break;
      p = m, q = f, m -= s;
    }else{
      if(m == p-1 && q){ ++m; break; }
      p = m, q = f, m += s;
    }
    if(s > 1) s >>= 1;
  }

  printf("%lld\n", m);
  return 0;
}
