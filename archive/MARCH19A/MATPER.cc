// MATPER

#include <stdio.h>
#include <string.h>
#include <map>

using std::map;

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char s[100001], p[14][100001], u[200002];
int N,M, pl[14], f[14][100000], fr[100000],frn, y[14][100000], z[200001],
    c[5040][7], a[17297280][7], b[17297280][7], v[3432]={0}, h[16384];
map<int, int> g[3432];

// O(7P7)
void genp(int i, int j, int& n){
  if(j == M) return;
  char m[7]={0};
  int k,l;
  for(k = 0; k < j; ++k)
    m[c[i][k]] = 1;
  for(k = 0; m[k]; ++k);
  c[i][j] = k;
  genp(i, j+1, n);
  for(++k; k < M; ++k) if(!m[k]){
    for(l = 0; l < j; ++l)
      c[n][l] = c[i][l];
    l = n, c[l][j] = k, ++n;
    genp(l, j+1, n);
  }
}

// O(14P7)
void genp2(int i, int j, int& n){
  if(j == M-7) return;
  char m[14]={0};
  int k,l;
  for(k = 0; k < j; ++k)
    m[a[i][k]] = 1;
  for(k = 0; m[k]; ++k);
  a[i][j] = k;
  genp2(i, j+1, n);
  for(++k; k < M; ++k) if(!m[k]){
    for(l = 0; l < j; ++l)
      a[n][l] = a[i][l];
    l = n, a[l][j] = k, ++n;
    genp2(l, j+1, n);
  }
}

// O(14P7)
void genp3(int i, int j, int& n){
  if(j == 7) return;
  char m[14]={0};
  int k,l;
  for(k = 0; k < j; ++k)
    m[b[i][k]] = 1;
  for(k = 0; m[k]; ++k);
  b[i][j] = k;
  genp3(i, j+1, n);
  for(++k; k < M; ++k) if(!m[k]){
    for(l = 0; l < j; ++l)
      b[n][l] = b[i][l];
    l = n, b[l][j] = k, ++n;
    genp3(l, j+1, n);
  }
}

// O(14C7)
void hpop(int i, int j, int& n, int& t){
  if(j == 7){
    h[v[i]] = t++;
    return;
  }
  int k,l,m;
  m = v[i];
  for(k = M-1; k >= 0; --k)
    if(v[i] & (1 << k)){ v[i] |= (1 << (k+1)); break; }
  if(k == -1) v[i] = 1;
  hpop(i, j+1, n, t);
  for(k += 2; k < M-(6-j); ++k){
    v[l = n++] = (m | (1 << k));
    hpop(l, j+1, n, t);
  }
}

// O(10^5)
void find(int pi){
  int n,i,k,l,r;
  for(i = 0; i < pl[pi]; ++i)
    u[i] = p[pi][i];
  u[pl[pi]] = '$';
  for(i = pl[pi]+1, k = 0; k < N; ++i, ++k)
    u[i] = s[k];
  n = N + pl[pi] + 1, l = r = u[n] = 0;
  for(i = 1; i < n; ++i){
    if(i > r){
      l = r = i;
      while(r < n && u[r-l] == u[r])
        ++r;
      z[i] = r-l, --r;
    }else{
      k = i-l;
      if(z[k] < r-i+1) z[i] = z[k];
      else{
        l = i;
        while(r < n && u[r-l] == u[r])
          ++r;
        z[i] = r-l, --r;
      }
    }
  }
  for(k = 0; k < n; ++k)
    if(z[k] == pl[pi]) fr[frn++] = k - pl[pi] - 1;
}

int main(){
  int i,j,k, m,n,t;
  ll r;
  map<int, int>::iterator it;
  map<int, int>::reverse_iterator rt;

  N = getn(), M = getn();
  scanf("%s", s);
  for(i = 0; i < M; ++i)
    scanf("%s", p[i]);

  for(i = 0; i < M; ++i){
    pl[i] = strlen(p[i]);
    frn = 0;
    find(i);
    for(j = k = 0; j < frn; ++j)
      for(; k <= fr[j]; ++k)
        f[i][k] = fr[j];
    for(; k < N; ++k)
      f[i][k] = -1;
    for(j = frn-1, k = N-1; j >= 0; --j)
      for(; k >= fr[j]; --k)
        y[i][k] = fr[j];
    for(; k >= 0; --k)
      y[i][k] = -1;
  }

  if(M < 8){
    r = 0, n = 1;
    genp(0, 0, n);
    for(i = 0; i < n; ++i){
      for(j = 1, k = f[c[i][0]][0]; j < M && k != -1; ++j){
        if(k+pl[c[i][j-1]] == N){ k = -1; break; }
        k = f[c[i][j]][k+pl[c[i][j-1]]];
      }
      if(k != -1) ++r;
    }
    printf("%lld\n", r);
    return 0;
  }

  n = 1;
  genp2(0, 0, n);
  k = 1, t = 0;
  hpop(0, 0, k, t);
  for(i = 0; i < n; ++i){
    for(j = 0, m = (1 << M) - 1; j < M-7; ++j)
      m ^= (1 << a[i][j]);
    for(j = M-9, k = y[a[i][M-8]][N-1]; j >= 0 && k != -1; --j){
      if(k-pl[a[i][j]] < 0){ k = -1; break; }
      k = y[a[i][j]][k-pl[a[i][j]]];
    }
    if(k != -1){
      if((it = g[h[m]].find(k)) == g[h[m]].end()) g[h[m]][k] = 1;
      else ++it->second;
    }
  }
  for(i = 0; i < 3432; ++i){
    if(g[i].size() < 2) continue;
    for(rt = g[i].rbegin(), n = rt->second, ++rt; rt != g[i].rend(); ++rt)
      rt->second += n, n = rt->second;
  }

  n = 1;
  genp3(0, 0, n);
  for(r = i = 0; i < n; ++i){
    for(j = m = 0; j < 7; ++j)
      m |= (1 << b[i][j]);
    for(j = 1, k = f[b[i][0]][0]; j < 7 && k != -1; ++j){
      if(k+pl[b[i][j-1]] == N){ k = -1; break; }
      k = f[b[i][j]][k+pl[b[i][j-1]]];
    }
    if(k != -1){
      it = g[h[m]].lower_bound(k+pl[b[i][6]]);
      if(it != g[h[m]].end())
        r += it->second;
    }
  }

  printf("%lld\n", r);
  return 0;
}
