// CHMKTRPS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

#define ll long long
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back
#define C1 240

inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}
char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  if(n < 0) pc('-'), n = 0-n;
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

struct P {
  int v,i;
  P(int v0, int i0): v(v0), i(i0) {}
};
bool cmp(const P& a, const P& b){
  return (a.v < b.v);
}
struct T {
  int a,b,c;
  T(int a0, int b0, int c0): a(a0), b(b0), c(c0) {}
};

int b[300000];
int rem(int i){
  if(b[i] >= 0) i = b[i];
  ++b[i];
  int r = i-b[i];
  if(!b[i]) b[i] = i;
  return r;
}
bool has(int i, int c){
  if(b[i] >= 0) i = b[i];
  if(b[i] == i) return false;
  return (-b[i] >= c);
}

int main(){
  int N, i,j,k,t,j1;
  ll s;
  vector<P> a;
  vector<T> r;
  unordered_map<int,int> m;
  unordered_map<int,int>::iterator it;

  N = getn() * 3;
  for(i = 1; i <= N; ++i)
    a.pb(P(getn(), i));
  std::sort(a.begin(), a.end(), cmp);
  b[0] = -1, m[a[0].v] = 0;
  for(i = 1; i < N; ++i){
    if(a[i].v != a[i-1].v)
      b[i] = -1, m[a[i].v] = i;
    else if(b[i-1] == -1)
      b[i] = i-1, --b[i-1];
    else
      b[i] = b[i-1], --b[b[i-1]];
  }

  k = (j = (i = (N>>1)-1)+1)+1;
  s = (ll)a[i].v + a[j].v + a[k].v;
  r.pb(T(a[rem(i)].i, a[rem(j)].i, a[rem(k)].i));
  t = N / C1, j1 = 1;
  for(i = 0; i < N; ++i, ++j1){
    if(!has(i,1))
      continue;
    if(j1 == t)
      j1 = 0;
    for(j = j1; j < N; j += t){
      if(!has(j,1) || (a[i].v == a[j].v && !has(j,2)))
  continue;
      it = m.find((int)(s-a[i].v-a[j].v));
      if(it == m.end())
  continue;
      k = it->second;
      if(!has(k,1) || (a[i].v == a[k].v && !has(k,2)) ||
   (a[j].v == a[k].v && !has(k,2)) ||
   (a[i].v == a[k].v && a[j].v == a[k].v && !has(k,3)))
  continue;
      r.pb(T(a[rem(i)].i, a[rem(j)].i, a[rem(k)].i));
      break;
    }
  }

  putn(r.size()), pc('\n');
  for(i = 0; i < r.size(); ++i)
    putn(r[i].a), pc(' '), putn(r[i].b), pc(' '), putn(r[i].c), pc(' ');
  pc('\n');
  return 0;
}
