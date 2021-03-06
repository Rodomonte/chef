// FLIPCOIN

#include <stdio.h>

#define gc getchar_unlocked
#define MOD 2

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int madd(int a, int b){ return ((a += b) >= MOD) ? a-MOD : a; }

typedef struct {
  int f,l,n,p,s;
} P ;

int N, li[20],ln,an;
P a[200000];

void build(){
  int i,j,s,t;
  li[0] = 0, s = N, ln = j = 1, t = 2;
  for(i = 0; i < N*2; ++i) a[i].n = a[i].f = a[i].l = 0, a[i].s = 1, a[i].p = -1;
  while(s > 1){
    li[ln] = li[ln-1] + s;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++)
      a[i].p = a[i+1].p = j, a[j].s = t, a[j].l = ln;
    s >>= 1, t <<= 1, ln++;
  }
  an = j;
}

void push(int i, int v){
  if(a[i].p == -1) return;
  a[a[i].p].n += v;
  push(a[i].p, v);
}

void pull(int i){
  int j,k,p;
  p = a[i].p;
  if(p == -1) return;
  pull(p);
  j = li[a[i].l]+((p - li[a[i].l+1])<<1), k = j+1;
  a[j].f = madd(a[j].f, a[p].f), a[k].f = madd(a[k].f, a[p].f);
  if(a[p].f) a[j].n = a[j].s - a[j].n, a[k].n = a[k].s - a[k].n;
  a[p].f = 0;
}

void updateRange(int i0, int i1){
  int i,j,l,e,ia,ib;
  l = 0, e = 1, i = i0;
  while(i0 <= i1){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (i0 >> l+1);
      ia = (j - li[l+1]) << (l+1), ib = ia + (e << 1) - 1;
      if(ia == i0 && ib <= i1){ i = j, e <<= 1, l++; continue; }
    }
    ia = (i - li[l]) << l;
    if(ia == i0){
      pull(i);
      a[i].f = madd(a[i].f, 1), push(i, a[i].s-a[i].n-a[i].n);
      a[i].n = a[i].s - a[i].n, i0 += e;
      if(i0 > i1) break;
    }
    if(i1 - i0 + 1 < e) e >>= 1, l--, i = li[l] + (ia >> l) + 1;
    else i++;
  }
}

int queryRange(int i0, int i1){
  int i,j,l,e,ia,ib,r;
  l = 0, e = 1, i = i0, r = 0;
  while(i0 <= i1){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (i0 >> l+1);
      ia = (j - li[l+1]) << (l+1), ib = ia + (e << 1) - 1;
      if(ia == i0 && ib <= i1){ i = j, e <<= 1, l++; continue; }
    }
    ia = (i - li[l]) << l;
    if(ia == i0){
      pull(i), r += a[i].n, i0 += e;
      if(i0 > i1) break;
    }
    if(i1 - i0 + 1 < e) e >>= 1, l--, i = li[l] + (ia >> l) + 1;
    else i++;
  }
  return r;
}

int main(){
  int Q,O,L,R;
  N = getn(), Q = getn();
  build();
  while(Q--){
    O = getn(), L = getn(), R = getn();
    if(O) printf("%d\n", queryRange(L, R));
    else updateRange(L, R);
  }
  return 0;
}
