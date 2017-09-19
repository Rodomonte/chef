// FLOORI4

#include <stdio.h>
#include <math.h>

#define ll long long

ll amod(ll a, ll b, ll M){
  a += b;
  return (a >= M) ? a-M : a;
}

ll cmod(ll n, ll M){
  return (n >= M) ? n%M : n;
}

ll i4(ll i, ll M){
  i = cmod(i, M);
  i = cmod(i*i, M);
  return cmod(i*i, M);
}

// sum(i^4 for i=[1,N]) = N(N+1)(2N+1)(3N^2+3N-1)/30
ll i4s(ll i, ll M){
  char f,u;
  int j,k;
  ll t[3] = {i, i+1, (i<<1)+1};
  ll d[3] = {2, 3, 5}, n,v,nw,nr,r5, r = 1;
  u = 0;
  for(k = 0; k < 3; k++){
    f = 0;
    for(j = 0; j < 3; j++){
      n = t[j] / d[k];
      if(t[j]-d[k]*n == 0){
        t[j] = n, f = 1;
        break;
      }
    }
    if(!f){
      ll nw,nr;
      u = 1;
      nw = i*3/5;
      nr = i*3-nw*5;
      v = cmod(amod(cmod(i,M),1,M) * cmod(nw,M), M);
      r5 = (i+1)*nr - 1;
      r5 /= 5;
      v = amod(v, cmod(r5,M), M);
    }
  }
  for(j = 0; j < 3; j++){
    t[j] = cmod(t[j], M);
    r = cmod(r * t[j], M);
  }
  if(!u){
    v = amod(cmod(cmod(i*3,M)*cmod(i,M),M), cmod(i*3,M), M);
    v = (!v) ? M-1 : v-1;
  }
  r = cmod(r * v, M);
  return r;
}

ll a[100001];
int main(){
  int T;
  ll N,M, i,j,k,s,r;
  scanf("%d", &T);
  while(T--){
    scanf("%lld %lld", &N, &M);
    s = (ll)sqrt((double)N), r = 0;
    for(i = 1; i <= s; i++){
      a[i] = N / i;
      r = amod(r, cmod(cmod(a[i],M) * i4(i,M), M), M);
    }
    if(s+1 < a[s])
      r = amod(r, cmod(N/(s+1) * i4(s+1,M), M), M);
    if(s != a[s])
      r = amod(r, cmod(s * i4(a[s],M), M), M);
    for(k = s; k > 1; k--){
      i = i4s(a[k], M), j = i4s(a[k-1], M);
      j = (j < i) ? j+M : j;
      r = amod(r, cmod((k-1)*(j-i),M), M);
    }
    printf("%lld\n", r);
  }
  return 0;
}
