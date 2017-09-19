// PERSHFT

#include <stdio.h>

#define gc getchar_unlocked
#define MOD 1000000007

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

int madd(int a, int b){
  a += b;
  if(a >= MOD)
    a -= MOD;
  return a;
}

int mmul(int a, int b){
  long long r = a;
  r = r * b % MOD;
  return (int)r;
}

struct P {
  int v,h,lc;
  struct P* c[2];
} leaf = {0, 0, 0, {&leaf, &leaf}}, *pl = &leaf;
struct P p[100000];
int pn;

struct P* init(int v){
  p[pn].v = v;
  p[pn].h = 1;
  p[pn].lc = 0;
  p[pn].c[0] = p[pn].c[1] = pl;
  return p+(pn++);
}

struct P* rot(struct P** r, int d){
  struct P* ro = *r;
  struct P* rn = ro->c[d];
  if(pl != (*r = rn)){
    if(d)
      rn->lc += ro->lc + 1;
    else
      ro->lc -= rn->lc + 1;
    ro->c[d] = rn->c[!d];
    ro->h = 1 + max(ro->c[0]->h, ro->c[1]->h);
    rn->c[!d] = ro;
  }
  return rn;
}

void bal(struct P** rp){
  struct P* r = *rp;
  int b = (r->c[0]->h - r->c[1]->h)>>1;
  if(b){
    int d = (1-b)>>1;
    if(r->c[d]->c[0]->h - r->c[d]->c[1]->h == -b)
      rot(&r->c[d], !d);
    r = rot(rp, d);
  }
  if(r != pl)
    r->h = 1 + max(r->c[0]->h, r->c[1]->h);
}

void ins(struct P** rp, int v){
  struct P* r = *rp;
  if(r == pl){
    *rp = init(v);
  }else{
    if(v < r->v)
      ++r->lc;
    ins(&r->c[v > r->v], v);
    bal(rp);
  }
}

int lt(struct P* r, int v){
  if(r == pl)
    return 0;
  if(v < r->v)
    return lt(r->c[0], v);
  else
    return 1 + r->lc + lt(r->c[1], v);
}

int a[100000], b[100000], d[100001], e[100000], f[100000], f2[100000];

int inv(int l, int r){
  if(l >= r)
    return 0;
  int m,c,i,j,k;
  m = (l+r)>>1;
  c = inv(l, m) + inv(m+1, r);
  ++m;
  i = k = l, j = m;
  while(i <= m-1 && j <= r){
    if(e[i] <= e[j]){
      d[k++] = e[i++];
    }else{
      d[k++] = e[j++];
      c += m - i;
    }
  }
  while(i <= m-1)
    d[k++] = e[i++];
  while(j <= r)
    d[k++] = e[j++];
  for(i = l; i <= r; ++i)
    e[i] = d[i];
  return c;
}

int main(){
  char c;
  int T,N,K, i,j,r,t;
  struct P* pr;

  f[0] = 1;
  for(i = 1; i < 100000; ++i)
    f[i] = mmul(i, f[i-1]);
  f2[0] = f2[1] = 0, f2[2] = 1;
  for(i = 3; i < 100000; ++i)
    f2[i] = mmul(i, f2[i-1]);

  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = 0; i < N; ++i)
      a[i] = getn();
    for(i = 0; i < N; ++i)
      b[i] = getn();

    if(K == N){
      for(j = 0; b[j] != a[0]; ++j);
      c = 1;
      for(i = 0; i < N; ++i, ++j){
        if(j == N)
    j = 0;
  if(a[i] != b[j]){
    c = 0;
    break;
  }
      }
      printf("%d\n", c ? b[0] : -1);
      continue;
    }

    for(i = 0; i < N; ++i)
      d[a[i]] = i+1;
    for(i = 0; i < N; ++i)
      e[i] = d[b[i]];

    if(K&1){
      i = inv(0, N-1);
      if(i&1){
  printf("-1\n");
  continue;
      }
    }

    pn = r = 0;
    pr = pl;
    for(i = 0; i < N; ++i){
      r = madd(r, mmul(b[i]-lt(pr, b[i])-1, ((K&1) ? f2[N-i-1] : f[N-i-1])));
      ins(&pr, b[i]);
      /*
      for(j = 0; j < pn; ++j)
        printf("%d: l=%d r=%d lc=%d h=%d\n", p[j].v, p[j].c[0]->v,
               p[j].c[1]->v, p[j].lc, p[j].h);
      printf("\n");
      */
    }

    printf("%d\n", madd(r, 1));
  }
  return 0;
}
