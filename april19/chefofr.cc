// CHEFOFR

//!
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <map>

using std::map;

#define llu unsigned long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

void rsort(llu* a, int n){
  if(n < 2) return;
  llu p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l > p){ l++; continue; }
    if(*r < p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  rsort(a, r-a+1), rsort(l, a+n-l);
}

//!
llu z[34000000];

int t[100000];
llu a[100000];
map<llu, llu> g,h;
int main(){
  char u[50];
  int Q,N,K, i,j,k, bn,dn,en;
  llu c,m,r,s,v,w,x,y, b[50], d[25], e[25];
  map<llu, llu>::iterator it;
  map<llu, llu>::reverse_iterator rt;

  // N = getn();
  // for(i = 0; i < N; ++i)
  //   a[i] = getn();
  // Q = getn();

  // while(Q--){
  //   K = getn();
  //   if(K > 50){ printf("0\n"); continue; }
  //   for(bn = i = 0; i < N; ++i)
  //     if(t[i] = getn()) b[bn++] = a[i] * t[i];

  N = 50;
  for(i = 0; i < N; ++i)
    a[i] = (llu)rand() * (llu)rand() % (1LLU << 50);
  Q = 1;

  while(Q--){
    K = 2;
    for(bn = i = 0; i < N; ++i)
      if(t[i] = (rand()%10+1)) b[bn++] = a[i] * t[i];
    g.clear(), h.clear();

    // if(K == 1){
    //   //!
    //   continue;
    // }

    rsort(b, bn);
    for(v = i = 0; i < bn; ++i)
      v += b[i], u[i] = false;
    v /= K;

    // Greedy approximation
    w = 0LLU - 1;
    for(i = k = 0; i < bn; ++i){
      if(u[i]) continue;
      s = b[i], ++k;
      for(j = i+1; j < bn; ++j)
        if(s + b[j] <= v || k == K) s += b[j], u[j] = true;
      w &= s;
    }

    printf("%llu\n", w);

    printf("w=%llu\n", w);
    printf("v=%llu\n", v);
    printf("-=%llu\n", v-w);

    // for(i = 62, r = 0; i >= 0; --i){
    //   while(clusters not all formed){

      for(y = en = 0; en < (bn >> 1); ++en)
        y += (e[en] = b[en]);
      for(j = en, x = dn = 0; j < bn; ++j, ++dn)
        x += (d[dn] = b[j]);
      printf("x=%llu\ny=%llu\n", x, y);

      llu t0,t1,t2;
      t0 = t1 = t2 = 0;

      for(c = 0; c < (1LLU << dn); ++c){
        llu tt = clock();
        for(s = j = 0; j < dn && s <= v; ++j)
          if(c & (1 << j)) s += d[j];
        t0 += clock() - tt;
        // printf("%d -- %llu < %llu || %llu < %llu\n",
        //        ((v < s) ? 1 : 2), v,s,s+y,w);
        if(s + y < w || s > v) continue;
        tt = clock();
        //g[s] = c;
        t1 += clock() - tt;
        tt = clock();
        if(g.size()%100000==0) printf("|g|=%lu\n", g.size());
        t2 += clock() - tt;
        printf("t0: %llu\nt1: %llu\nt2: %llu\n", t0,t1,t2);
      }

      for(c = 0; c < (1LLU << en); ++c){
        for(s = j = 0; j < en && s <= v; ++j)
          if(c & (1 << j)) s += e[j];
        if(s + x < w || s > v) continue;
        h[s] = c;
        if(h.size()%100000==0) printf("|h|=%lu\n", h.size());
      }

      //!
      printf("|g|=%lu\n", g.size());
      printf("|h|=%lu\n", h.size());

      // m = (1 << 63);
      // for(rt = g.rbegin(), it = h.begin(); rt != g.rend() && it != h.end();){
      //   s = rt->first + it->first;
      //   if(s >= (1 << i) && s < m) m = s,
      //   if(s > (1 << i)) ++rt;
      //   else if(rt->first + it->first < (1 << i)) ++it;
      //   else break;
      // }
      // if(rt == g.rend() || it == h.end()) continue;
    // }

    // printf("%llu\n", r);
  }
  return 0;
}
