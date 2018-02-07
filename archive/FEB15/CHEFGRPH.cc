// CHEFGRPH

#include <stdio.h>
#include <map>
using std::map;

#define ll long long
#define gc getchar_unlocked
#define MOD 1000000007

inline ll getll(){
  ll n = 0;
  char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

ll madd(ll a, ll b){
  a += b;
  if(a >= MOD)
    return a-MOD;
  return a;
}

ll mpow(ll n, ll e){
  ll r = 1;
  n %= MOD;
  while(e){
    if(e & 1)
      r = (r * n) % MOD;
    n = (n * n) % MOD;
    e >>= 1;
  }
  return r;
}

struct E {
  ll n0,m0,n1,m1,pp;
};

struct P {
  E* e;
  char s;
};

char plt(P* a, P* b){
  if(a->s){
    if(b->s)
      return (a->e->n0 < b->e->n0) ? 1 : 0;
    else
      return (a->e->n0 < b->e->n1 || a->e->n0 == b->e->n1) ? 1 : 0;
  }else{
    if(b->s)
      return (a->e->n1 < b->e->n0) ? 1 : 0;
    else
      return (a->e->n1 < b->e->n1) ? 1 : 0;
  }
}

void sort(P* a, int n){
  if(n < 2) return;
  P *l = a, *r = a+n-1, p = a[n/2], t;
  while(l <= r){
    if(plt(l, &p)){ ++l; continue; }
    if(plt(&p, r)){ --r; continue; }
    t = *l, *l = *r, *r = t;
    ++l, --r;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

E e[50000];
P ep[100000];

map<ll,map<ll,ll> > pm;
map<ll,map<ll,ll> >::iterator it;
map<ll,ll>::iterator it2;

void mins(ll n, ll m, ll p){
  it = pm.find(n);
  if(it == pm.end()){
    map<ll,ll> pm2;
    pm2[m] = p;
    pm[n] = pm2;
  }else{
    it2 = it->second.find(m);
    if(it2 == it->second.end())
      it->second[m] = p;
    else
      it->second[m] = madd(it->second[m], p);
  }
}

ll mget(ll n, ll m){
  it = pm.find(n);
  if(it == pm.end())
    return 0;
  it2 = it->second.find(m);
  if(it2 == it->second.end())
    return 0;
  return it2->second;
}

int main(){
  ll N,M, n,r,t;
  int K, i,j;
  N = getll(), M = getll(), K = (int)getll();
  for(i = j = 0; i < K; ++i, j+=2){
    e[i].n0 = getll(), e[i].m0 = getll(), e[i].n1 = getll(), e[i].m1 = getll();
    ep[j].e = ep[j+1].e = e+i, ep[j].s = 1, ep[j+1].s = 0;
  }
  sort(ep, K<<1);
  for(i = 0; ep[i].s && !ep[i].e->n0; ++i){
    ep[i].e->pp = 1;
    mins(ep[i].e->n1, ep[i].e->m1, 1);
  }
  n = 0, r = 1;
  for(; i < (K<<1); ++i){
    if(ep[i].s){
      t = ep[i].e->n0-1 - n;
      if(t)
        r = r * mpow(M,t) % MOD, n += t;
      ep[i].e->pp = madd(r, mget(ep[i].e->n0, ep[i].e->m0));
      mins(ep[i].e->n1, ep[i].e->m1, ep[i].e->pp);
    }else{
      t = ep[i].e->n1 - n;
      if(ep[i].e->n1 == N+1)
        --t;
      if(t)
        r = r * mpow(M,t) % MOD, n += t;
      r = madd(r, ep[i].e->pp);
    }
  }
  if(n < N)
    r = r * mpow(M,N-n) % MOD;
  printf("%lld\n", r);
  return 0;
}
