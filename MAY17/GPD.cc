// GPD

#include <stdio.h>
#include <vector>
#include <map>
#include <set>

using std::vector;
using std::map;
using std::set;

#define uint unsigned int
#define gc getchar_unlocked
#define pb push_back
#define INF 2147483647
#define SKIP 400

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int min(int a, int b){
  return (a < b) ? a : b;
}
int max(int a, int b){
  return (a > b) ? a : b;
}

struct P {
  int i,p,k,d;
  vector<int> n;
  set<int> s;
};

P a[300000];

void dfs(int i, int p, int d){
  int j;
  a[i].p = p, a[i].d = d;
  if(d % SKIP == 0){
    vector<int> v;
    v.pb(a[i].k);
    if(i){
      j = a[i].p;
      while(a[j].s.empty())
        v.pb(a[j].k), j = a[j].p;
      a[i].s = a[j].s;
    }
    for(j = 0; j < v.size(); ++j)
      a[i].s.insert(v[j]);
  }
  for(j = 0; j < a[i].n.size(); ++j)
    if(a[i].n[j] != a[i].p)
      dfs(a[i].n[j], i, d+1);
}

int len(int k){
  int r = 1;
  if(!k)
    return 0;
  while(k > 1)
    k >>= 1, ++r;
  return r;
}

int main(){
  bool f;
  int N,Q,R,K,U,V,O, i,j,k,u,v,an,rp;
  uint s,t;
  vector<int> vi;
  map<int,int> m;
  map<int,int>::iterator it;
  set<int>::iterator sit;

  N = getn(), Q = getn(), R = getn(), K = getn();
  a[0].i = R, a[0].k = K, m[R] = 0, an = 1;
  for(i = 0; i < N-1; ++i){
    U = getn(), V = getn(), K = getn();

    it = m.find(U);
    if(it == m.end())
      m[U] = u = an++;
    else
      u = it->second;
    it = m.find(V);
    if(it == m.end())
      m[V] = v = an++;
    else
      v = it->second;
    a[u].i = U, a[u].k = K, a[v].i = V;
    a[u].n.pb(v), a[v].n.pb(u);
  }

  dfs(0, -1, 0);

  rp = 0;
  while(Q--){
    O = getn() ^ rp;
    if(O == 0){
      V = getn() ^ rp, U = getn() ^ rp, K = getn() ^ rp;

      it = m.find(U);
      if(it == m.end())
        m[U] = u = an++;
      else
        u = it->second;
      it = m.find(V);
      if(it == m.end())
        m[V] = v = an++;
      else
        v = it->second;
      a[u].i = U, a[u].k = K, a[u].p = v, a[u].d = a[v].d+1;
      a[u].n.pb(v), a[v].n.pb(u);

      if(a[u].d % SKIP == 0){
        vi.clear();
        vi.pb(a[u].k);
        j = a[u].p;
        while(a[j].s.empty())
          vi.pb(a[j].k), j = a[j].p;
        a[u].s = a[j].s;
        for(j = 0; j < vi.size(); ++j)
          a[u].s.insert(vi[j]);
      }

    }else{
      V = getn() ^ rp, K = getn() ^ rp;

      i = m[V], u = INF, v = 0;
      while(a[i].s.empty()){
        u = min(u, K ^ a[i].k);
        v = max(v, K ^ a[i].k);
        i = a[i].p;
      }

      // Maximum

      // Find k w/ larger top bit
      j = len(K), f = false;
      sit = a[i].s.end(), --sit;
      if((uint)*sit >= (1U << j)){
        s = (1 << (len(*sit)-1)), f = true;

      // Else, find k w/ largest top bit matching a 0 in K
      }else if(j > 1){
        for(s = (1 << (j-2)); s > 0; s >>= 1){
          if(K & s)
            continue;
          sit = a[i].s.lower_bound(s);
          if(sit != a[i].s.end() && *sit < (s << 1)){
            f = true;
            break;
          }
        }
      }

      // Else, find k w/ smallest top bit matching a 1 in K
      if(!f && j > 0){
        for(s = 1; s < (1U << j); s <<= 1){
          if(!(K & s))
            continue;
          sit = a[i].s.lower_bound(s);
          if(sit != a[i].s.end() && *sit < (s << 1)){
            f = true;
            break;
          }
        }
      }

      // For each bit down K, find k w/ opposite bits
      if(f){
        for(t = j = k = s; t > 0; t >>= 1){
          if(t != s){
            if(t & K)
              k &= ~t;
            else
              k |= t;
          }
          s |= t;
          sit = a[i].s.lower_bound(k);
          if(sit == a[i].s.end() || *sit >= ((uint)j << 1) ||
             (*sit & s) != (k & s))
            k ^= t;
          else
            v = max(v, K ^ *sit);
        }

      // Else, s must only contain 0
      }else
        v = max(v, K);

      // Minimum

      // Find k w/ largest top bit matching a 1 in K
      j = len(K), f = false;
      if(j > 0){
        for(s = (1 << (j-1)); s > 0; s >>= 1){
          if(!(K & s))
            continue;
          sit = a[i].s.lower_bound(s);
          if(sit != a[i].s.end() && *sit < (s << 1)){
            f = true;
            break;
          }
        }
      }

      // Find k w/ smallest top bit matching a 0 in K
      if(!f){
        sit = a[i].s.end(), --sit, t = *sit;
        for(s = 1; s <= t; s <<= 1){
          if(K & s)
            continue;
          sit = a[i].s.lower_bound(s);
          if(sit != a[i].s.end() && *sit < (s << 1)){
            f = true;
            break;
          }
        }
      }

      // For each bit down K, find k w/ same bits
      if(f){
        for(t = j = k = s; t > 0; t >>= 1){
          if(t != s){
            if(t & K)
              k |= t;
            else
              k &= ~t;
          }
          s |= t;
          sit = a[i].s.lower_bound(k);
          if(sit == a[i].s.end() || *sit >= ((uint)j << 1) ||
             (*sit & s) != (k & s))
            k ^= t;
          else
            u = min(u, K ^ *sit);
        }

      // Else, s must only contain 0
      }else
        u = min(u, K);

      printf("%d %d\n", u, v);
      rp = u ^ v;
    }
  }
  return 0;
}
