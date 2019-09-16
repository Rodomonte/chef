// COOLCHEF

#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>

using std::vector;
using std::map;
using std::unordered_map;

#define ll long long
#define gc getchar_unlocked
#define pb push_back
#define MOD 1000000007
#define MAP 300

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int madd(int a, int b, int m){ return ((a += b) >= m) ? a-m : a; }
int mmul(int a, int b, int m){ return (int)((ll)a * (ll)b % m); }
int gcde(int a, int b, int& x, int& y){
  if(!a){ x = 0, y = 1; return b; }
  int g,x1,y1;
  g = gcde(b % a, a, x1, y1);
  x = y1 - (b / a) * x1, y = x1;
  return g;
}
int minv(int a, int m){
  int x,y;
  if(gcde(a, m, x, y) != 1)
    return -1;
  return (x % m + m) % m;
}
int mdiv(int a, int b, int m){
  int inv = minv(b, m);
  if(inv == -1) inv /= 0;
  return mmul(inv, a, m);
}

struct P {
  int n;
  vector<int> i;
  P(){}
  P(int _i, int _n): n(_n) { i.pb(_i); }
};

int s[300000], f[300001], N, li[20],ln,an;
map<int, vector<int> > a[600000];
map<int, int> b[600000];
unordered_map<int, map<int, int> > d;

void build(){
  int i,j,k,t;
  map<int, vector<int> >::iterator it,jt;
  unordered_map<int, int>::iterator kt;
  li[0] = 0, t = N, ln = 1;
  while(t > 1){
    li[ln] = li[ln-1] + t;
    for(i = li[ln-1], j = li[ln]; i < li[ln]-1; i += 2, j++){
      for(it = a[i].begin(); it != a[i].end(); ++it)
        a[j][it->first] = it->second;
      for(it = a[i+1].begin(); it != a[i+1].end(); ++it){
        if((jt = a[j].find(it->first)) == a[j].end())
          a[j][it->first] = it->second;
        else for(k = 0; k < it->second.size(); ++k)
          jt->second.pb(it->second[k]);
      }
    }
    t >>= 1, ++ln;
  }
  an = j;
}

int query(int L, int R){
  int i,j,l,e,ia,ib,r;
  unordered_map<int, int> m;
  map<int, int>::iterator it;
  l = 0, r = e = 1, i = L;
  while(L <= R){
    if(i != an-1 && i != li[l+1]-1){
      j = li[l+1] + (L >> l+1);
      ia = (j - li[l+1]) << (l+1), ib = ia + (e << 1) - 1;
      if(ia == L && ib <= R){ i = j, e <<= 1, l++; continue; }
    }

    ia = (i - li[l]) << l;
    if(ia == L){
      if(!a[i].empty()){
        it = b[i].upper_bound(R);
        if(it != b[i].begin()) --it, r = mmul(r, it->second, MOD);
      }
      L += e;
      if(L > R) break;
    }

    if(R - L + 1 < e) e >>= 1, l--, i = li[l] + (ia >> l) + 1;
    else i++;
  }
  return r;
}

int main(){
  int Q,L,R,L1,L2,R1,R2, i,j, n,r;
  unordered_map<int, int> m;
  unordered_map<int, P> u;
  unordered_map<int, int>::iterator mt,nt;
  unordered_map<int, P>::iterator it;
  map<int, vector<int> >::iterator jt;
  unordered_map<int, map<int, int> >::iterator kt;
  map<int, int>::iterator yt,zt;

  N = getn(), Q = getn();
  for(i = 0; i < N; ++i)
    s[i] = getn();

  for(f[0] = 1, i = 1; i <= N; ++i)
    f[i] = mmul(f[i-1], i, MOD);
  for(i = 0; i < N; ++i){
    if((mt = m.find(s[i])) == m.end()) m[s[i]] = 1;
    else ++mt->second;
  }
  mt = m.begin();
  while(mt != m.end()){
    if(mt->second < MAP) nt = mt, ++nt, m.erase(mt), mt = nt;
    else ++mt;
  }
  for(i = 0; i < N; ++i)
    if((mt = m.find(s[i])) != m.end()){
      if((kt = d.find(s[i])) == d.end()){
        map<int, int> mn;
        mn[i] = 0, d[s[i]] = mn;
      }else n = kt->second.size(), kt->second[i] = n;
    }

  for(i = 0; i < N; ++i){
    if(m.find(s[i]) != m.end()) continue;
    if((it = u.find(s[i])) == u.end()) u[s[i]] = P(i, 1);
    else{
      for(j = 0, n = ++it->second.n; j < it->second.i.size(); ++j, --n){
        if((jt = a[it->second.i[j]].find(i)) == a[it->second.i[j]].end()){
          vector<int> v;
          v.pb(n), a[it->second.i[j]][i] = v;
        }else jt->second.pb(n);
      }
      it->second.i.pb(i);
    }
  }

  build();
  for(i = 0; i < an; ++i)
    for(jt = a[i].begin(), n = 1; jt != a[i].end(); ++jt){
      for(j = 0; j < jt->second.size(); ++j)
        n = mmul(mdiv(n, jt->second[j]-1, MOD), jt->second[j], MOD);
      b[i][jt->first] = n;
    }

  r = 0;
  while(Q--){
    L1 = getn(), L2 = getn(), R1 = getn(), R2 = getn();
    L = madd(mmul(L1, r, N), L2, N), R = madd(mmul(R1, r, N), R2, N);
    if(L > R) n = L, L = R, R = n;
    r = query(L, R);
    for(kt = d.begin(); kt != d.end(); ++kt){
      yt = kt->second.lower_bound(L);
      if(yt == kt->second.end() || yt->first > R) continue;
      zt = kt->second.upper_bound(R);
      if(zt == kt->second.begin()) continue;
      --zt;
      r = mmul(r, f[zt->second - yt->second + 1], MOD);
    }
    r = mdiv(f[R-L+1], r, MOD);
    printf("%d\n", r);
  }
  return 0;
}
