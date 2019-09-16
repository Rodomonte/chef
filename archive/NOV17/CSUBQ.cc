// CSUBQ

#include <stdio.h>
#include <map>

using std::map;

#define ll long long
#define gc getchar_unlocked
#define mit map<int,int>::iterator

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }
ll np(ll n){ return (n*(n+1))>>1; }

ll getSum(ll a[], int i){
  ll r = 0; ++i;
  while(i > 0) r += a[i], i -= i & (-i);
  return r;
}
void updateBIT(ll a[], int n, int i, ll v){
  ++i; while(i <= n) a[i] += v, i += i & (-i);
}
ll sum(ll x, ll a[], ll b[]){
  return getSum(a, x) * x - getSum(b, x);
}
void updateRange(ll a[], ll b[], int n, ll v, int l, int r){
  updateBIT(a, n, l, v), updateBIT(a, n, r+1, -v);
  updateBIT(b, n, l, v*(l-1)), updateBIT(b, n, r+1, -v*r);
}
ll rangeSum(int l, int r, ll a[], ll b[]){
  if(l < 0 || r < l) return 0;
  return sum(r, a, b) - sum(l-1, a, b);
}

int N,L,R, a[500000]={0};
ll b[2][500001]={{0}}, b2[2][500001]={{0}};
map<int,int> m[2];

void radd(int i, int k){
  int el,er;
  mit it,jt;
  jt = m[k].upper_bound(i), it = jt;
  if((jt == m[k].end() && !m[k].empty()) || jt != m[k].begin()) --it;
  if((it == jt && jt != m[k].end() && jt->first > i+1) || it == m[k].end() ||
     (it->second < i-1 && (jt == m[k].end() || jt->first > i+1)))
    m[k][i] = i, el = er = i;
  else if(it->second == i-1 && jt != m[k].end() && jt->first == i+1)
    it->second = er = jt->second, m[k].erase(jt), el = it->first;
  else if(it->second == i-1)
    ++it->second, el = it->first, er = i;
  else if(jt->first == i+1)
    m[k][i] = er = jt->second, m[k].erase(jt), el = i;
  updateRange(b[k], b2[k], N, -np(i-el), i, er);
  updateRange(b[k], b2[k], N, np(er-el+1) - np(er-i) - np(i-el), er+1, N-1);
}

void rdel(int i, int k){
  int el,er;
  mit it;
  it = m[k].upper_bound(i), --it;
  if(it->first == it->second) m[k].erase(it), el = er = i;
  else if(it->first == i) m[k][i+1] = er = it->second, m[k].erase(it), el = i;
  else if(it->second == i) --it->second, el = it->first, er = i;
  else if(it->first < i && it->second > i)
    m[k][i+1] = er = it->second, it->second = i-1, el = it->first;
  updateRange(b[k], b2[k], N, np(i-el), i, er);
  updateRange(b[k], b2[k], N, np(i-el) + np(er-i) - np(er-el+1), er+1, N-1);
}

void update(int i, int v){
  if(a[i] < L && v >= L) rdel(i, 0);
  else if(a[i] >= L && v < L) radd(i, 0);
  if(a[i] <= R && v > R) rdel(i, 1);
  else if(a[i] > R && v <= R) radd(i, 1);
  a[i] = v;
}

ll query(int l, int r){
  int i,j, cl,cl1,cr,dl;
  ll n;
  mit it,jt,kt;

  jt = m[1].upper_bound(r), it = jt;
  if((jt == m[1].end() && !m[1].empty()) || jt != m[1].begin()) --it;
  cr = (it == jt || it->second < r) ? 0 : r-it->first+1;

  jt = m[1].upper_bound(l), it = jt;
  if((jt == m[1].end() && !m[1].empty()) || jt != m[1].begin()) --it;
  if(it == jt || it->second < l) cl = dl = 0;
  else cl = l-it->first+1, dl = min(r,it->second)-l+1;

  if(it != jt && it->first == l){
    jt = it;
    if(jt != m[1].begin()) --it;
  }
  cl1 = (it == jt || it->second < l-1) ? 0 : min(l-1, it->second)-it->first+1;

  n = rangeSum(r, r, b[1], b2[1]) + np(cr) -
      rangeSum(l-1, l-1, b[1], b2[1]) - np(cl1) -
      (ll)max(0, cl-1) * min(r-l+1, dl);

  jt = m[0].upper_bound(r), it = jt;
  if((jt == m[0].end() && !m[0].empty()) || jt != m[0].begin()) --it;
  cr = (it == jt || it->second < r) ? 0 : r-it->first+1;

  jt = m[0].upper_bound(l), it = jt;
  if((jt == m[0].end() && !m[0].empty()) || jt != m[0].begin()) --it;
  if(it == jt || it->second < l) cl = dl = 0;
  else cl = l-it->first+1, dl = min(r,it->second)-l+1;

  if(it != jt && it->first == l){
    jt = it;
    if(jt != m[0].begin()) --it;
  }
  cl1 = (it == jt || it->second < l-1) ? 0 : min(l-1, it->second)-it->first+1;

  n -= rangeSum(r, r, b[0], b2[0]) + np(cr) -
       rangeSum(l-1, l-1, b[0], b2[0]) - np(cl1) -
       (ll)max(0, cl-1) * min(r-l+1, dl);
  return n;
}

int main(){
  int Q,O,X,Y, i;
  ll r;
  N = getn(), Q = getn(), L = getn(), R = getn();
  m[0][0] = m[1][0] = N-1;
  while(Q--){
    O = getn(), X = getn(), Y = getn();
    if(O == 1) update(X-1, Y);
    else printf("%lld\n", query(X-1, Y-1));
  }
  return 0;
}
