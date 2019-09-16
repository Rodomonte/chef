// INTRPATH

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define vec std::vector
#define llu unsigned long long
#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P {
  bool e;
  int d,p,s,t[20],u[20],c[20];
  vec<int> n;
};

struct C {
  int i,j;
  llu n;
  C(int _i, int _j): i(_i), j(_j), n(0) {}
};

int N, d[300001], e[300001];
llu g[300001];
P a[300001];
vec<C> c[20];
vec<llu> b[300001];

int dfs(int i, int p, int d){
  int j,k,ii,n,f;
  a[i].p = p, a[i].d = d, a[i].s = 1;
  if(d && !(d & 3)){
    for(ii = 2, n = 4; n <= N; ++ii, n <<= 1){
      if(d & (n-1)) break;
      for(k = f = 0, j = i; k < n; ++k){
        if(a[j].p == -1){ f = 1; break; }
        a[i].u[ii] = j, j = a[j].p;
      }
      if(f) break;
      c[ii].pb(C(j, i));
      a[i].e = true, a[i].c[ii] = c[ii].size()-1, a[i].t[ii] = j;
    }
  }
  for(j = 0; j < a[i].n.size(); ++j)
    if(a[i].n[j] != p) a[i].s += dfs(a[i].n[j], i, d+1);
  return a[i].s;
}

llu score(int i, int k, int p){
  int j,s;
  llu n,t,u;
  n = 0, t = g[i];
  if(k != -1) t -= (k == a[i].p) ? (N - a[i].s) : a[k].s;
  if(p != -1) t -= (p == a[i].p) ? (N - a[i].s) : a[p].s;
  for(j = 0; j < a[i].n.size(); ++j)
    if(a[i].n[j] != p && a[i].n[j] != k)
      u = (a[i].n[j] == a[i].p) ? (N - a[i].s) : a[a[i].n[j]].s,
      n += u * (t - u);
  n >>= 1;
  return n + t + 1;
}

int main(){
  int T,Q,U,V, i,j,k,ii,jj, t;
  llu n;

  T = getn();
  while(T--){
    N = getn(), Q = getn();
    for(i = 1; i <= N; ++i)
      a[i].n.clear(), a[i].e = false, b[i].clear();
    for(i = 0; i < N-1; ++i)
      U = getn(), V = getn(), a[U].n.pb(V), a[V].n.pb(U);

    for(ii = 2, n = 4; n <= N; ++ii, n <<= 1)
      c[ii].clear();
    for(i = 1; i <= N; ++i)
      for(ii = 0; ii < 20; ++ii)
        a[i].t[ii] = -1;

    dfs(1, -1, 0);
    for(i = 1; i <= N; ++i)
      for(g[i] = j = 0; j < a[i].n.size(); ++j)
        g[i] += (a[i].n[j] == a[i].p) ? (N - a[i].s) : a[a[i].n[j]].s;

    for(i = 1; i <= N; ++i){
      for(j = 0; j < a[i].n.size(); ++j){
        k = a[i].n[j];
        if(k == a[i].p) b[i].pb(score(i, a[i].p, -1)), e[i] = j;
        else b[i].pb(score(i, a[i].p, k)), d[k] = j;
      }
    }

    for(ii = 2, n = 4; n <= N; ++ii, n <<= 1){
      for(i = 0; i < c[ii].size(); ++i){
        j = c[ii][i].j;
        while(1){
          k = j, j = a[j].p;
          if(j == c[ii][i].i) break;
          c[ii][i].n += b[j][d[k]];
        }
      }
    }

    while(Q--){
      U = i = getn(), V = j = getn(), n = 0, k = ii = -1;

      while(a[i].d > a[j].d){
        n += (k == -1) ? b[i][e[i]] : b[i][d[k]];
        if(a[i].e && a[i].d - a[j].d > 4){
          jj = 2, t = 4;
          while(!(a[i].d & ((t << 1)-1)) && (t << 1) < a[i].d - a[j].d)
            ++jj, t <<= 1;
          n += c[jj][a[i].c[jj]].n, k = a[i].u[jj], i = a[i].t[jj];
        }
        else k = i, i = a[i].p;
      }

      if(i == j){
        n += score(i, k, -1);
        printf("%llu\n", n);
        continue;
      }

      while(a[j].d > a[i].d){
        n += (ii == -1) ? b[j][e[j]] : b[j][d[ii]];
        if(a[j].e && a[j].d - a[i].d > 4){
          jj = 2, t = 4;
          while(!(a[j].d & ((t << 1)-1)) && (t << 1) < a[j].d - a[i].d)
            ++jj, t <<= 1;
          n += c[jj][a[j].c[jj]].n, ii = a[j].u[jj], j = a[j].t[jj];
        }
        else ii = j, j = a[j].p;
      }

      if(i == j){
        n += score(j, ii, -1);
        printf("%llu\n", n);
        continue;
      }

      while(i != j){
        n += (k == -1) ? b[i][e[i]] : b[i][d[k]];
        n += (ii == -1) ? b[j][e[j]] : b[j][d[ii]];
        if(a[i].e && a[i].t[2] != a[j].t[2]){
          jj = 2;
          while(a[i].t[jj] != -1 && a[i].t[jj] != a[j].t[jj])
            ++jj;
          --jj;
          n += c[jj][a[i].c[jj]].n + c[jj][a[j].c[jj]].n;
          k = a[i].u[jj], i = a[i].t[jj], ii = a[j].u[jj], j = a[j].t[jj];
        }else k = i, i = a[i].p, ii = j, j = a[j].p;
      }
      n += score(i, k, ii);

      printf("%llu\n", n);
    }
  }
  return 0;
}
