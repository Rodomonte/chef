// LVGFT

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

struct P {
  char b;
  int i,qi,qm,qm2,p,bp,e,l,m,m2,pm,pm2;
  vector<int> n;
  bool operator<(P& o) const { return i < o.i; }
};

int N, li[20],ln,an, q[100000];
P a[200000];

void build(){
  int i,j,s;
  li[0] = 0, s = N, ln = j = 1;
  for(i = 0; i < N*2; ++i) a[i].bp = -1;
  while(s > 1){
    li[ln] = li[ln-1] + s;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++)
      a[i].bp = a[i+1].bp = j,
      a[j].qm2 = max(max((a[i].qm == a[i+1].qm) ? -1 : min(a[i].qm, a[i+1].qm),
                         a[i].qm2), a[i+1].qm2),
      a[j].qm = max(a[i].qm, a[i+1].qm);
    s >>= 1, ln++;
  }
  an = j, a[an-1].bp = -1;
  for(i = 0; i < an; ++i) a[i].m = a[i].m2 = a[i].pm = a[i].pm2 = -1;
}

void push(int i){
  int p = a[i].bp;
  if(p == -1) return;
  a[p].m2 =
    max(max((a[p].m == a[i].m) ? -1 : min(a[p].m, a[i].m), a[p].m2), a[i].m2);
  a[p].m = max(a[p].m, a[i].m);
  push(p);
}

void updateRange(int i0, int i1, int m, int m2){
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
      a[i].m2 = max(max((a[i].m == m) ? -1 : min(a[i].m, m), a[i].m2), m2);
      a[i].pm2 = max(max((a[i].pm == m) ? -1 : min(a[i].pm, m), a[i].pm2), m2);
      a[i].m = max(a[i].m, m), a[i].pm = max(a[i].pm, m);
      push(i);
      i0 += e;
      if(i0 > i1) break;
    }
    if(i1 - i0 + 1 < e) e >>= 1, l--, i = li[l] + (ia >> l) + 1;
    else i++;
  }
}

void queryRange(int i0, int i1, int& m, int& m2){
  int i,j,l,e,ia,ib;
  l = 0, e = 1, i = i0, m = m2 = -1;
  while(i0 <= i1){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (i0 >> l+1);
      ia = (j - li[l+1]) << (l+1), ib = ia + (e << 1) - 1;
      if(ia == i0 && ib <= i1){ i = j, e <<= 1, l++; continue; }
    }
    ia = (i - li[l]) << l;
    if(ia == i0){
      m2 = max(max((a[i].qm == m) ? -1 : min(a[i].qm, m), a[i].qm2), m2);
      m = max(a[i].qm, m);
      i0 += e;
      if(i0 > i1) break;
    }
    if(i1 - i0 + 1 < e) e >>= 1, l--, i = li[l] + (ia >> l) + 1;
    else i++;
  }
}

void update(int i){
  int j,m,m2;
  if(a[i].b) return;
  a[i].b = 1;
  m = N-1, m2 = N-2, updateRange(i, i, m, m2);
  queryRange(i, a[i].e, m, m2);
  updateRange(0, i-1, m, m2), updateRange(a[i].e+1, N-1, m, m2);
  queryRange(0, i, m, m2), updateRange(i+1, a[i].e, m, m2);
  queryRange(a[i].e+1, N-1, m, m2), updateRange(i+1, a[i].e, m, m2);
  for(j = 0; j < a[i].n.size(); ++j)
    if(a[i].n[j] != a[i].p)
      queryRange(i+1, a[i].n[j]-1, m, m2),
      updateRange(a[i].n[j], a[a[i].n[j]].e, m, m2),
      queryRange(a[a[i].n[j]].e+1, a[i].e, m, m2),
      updateRange(a[i].n[j], a[a[i].n[j]].e, m, m2);
}

void pull(int i, int l){
  int p,j,k;
  if(l == ln-1 || a[i].bp == -1) return;
  p = a[i].bp;
  pull(p, l+1);
  j = li[l]+((p - li[l+1])<<1), k = j+1;

  a[j].pm2 = max(max((a[j].pm == a[p].pm) ? -1 : min(a[j].pm, a[p].pm),
                     a[j].pm2), a[p].pm2);
  a[j].pm = max(a[j].pm, a[p].pm);
  a[k].pm2 = max(max((a[k].pm == a[p].pm) ? -1 : min(a[k].pm, a[p].pm),
                     a[k].pm2), a[p].pm2);
  a[k].pm = max(a[k].pm, a[p].pm);

  a[j].m2 = max(max((a[j].m == a[p].pm) ? -1 : min(a[j].m, a[p].pm),
                    a[j].m2), a[p].pm2);
  a[j].m = max(a[j].m, a[p].pm);
  a[k].m2 = max(max((a[k].m == a[p].pm) ? -1 : min(a[k].m, a[p].pm),
                    a[k].m2), a[p].pm2);
  a[k].m = max(a[k].m, a[p].pm);
  a[p].pm = a[p].pm2 = -1;
}

void dfs(int i, int p, int l, int& k){
  int j;
  a[i].p = p, a[i].l = l, a[i].i = ++k;
  for(j = 0; j < a[i].n.size(); ++j)
    if(a[i].n[j] != p)
      dfs(a[i].n[j], i, l+1, k);
  a[i].e = k;
}

int main(){
  int T,M,O,C, i,j;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N; ++i)
      a[i].n.clear(), a[i].e = -1, a[i].b = 0, a[i].qi = a[i].qm = i,
      a[i].qm2 = -1;
    for(i = 0; i < N-1; ++i)
      O = getn()-1, C = getn()-1, a[O].n.pb(C), a[C].n.pb(O);

    i = -1;
    dfs(0, -1, 0, i);
    sort(a, a+N);
    for(i = 0; i < N; ++i) q[a[i].qi] = i;
    for(i = 0; i < N; ++i){
      a[i].p = q[a[i].p];
      for(j = 0; j < a[i].n.size(); ++j) a[i].n[j] = q[a[i].n[j]];
    }
    build();

    while(M--){
      O = getn(), C = getn()-1;
      if(O == 1) update(q[C]);
      else pull(q[C], 0),
           printf("%d\n", (a[q[C]].m2 == -1) ? -1 : a[q[C]].m2+1);
    }
  }
  return 0;
}
