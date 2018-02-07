// DCGAME

#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

#define ll long long
#define gc getchar_unlocked
#define SZ 1000000

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[SZ],c[SZ];
int main(){
  char O,P;
  int N,M,K, i,s,e,p;
  ll n;
  vector<char> r;
  vector<int> b;
  vector<ll> l,g,t;
  map<int,ll> d;

  N = getn(), M = getn();
  for(i = 0; i < N; ++i)
    a[i] = getn();

  for(i = 0; i < N; ++i){
    while(b.size() && a[b.back()] < a[i]){
      c[b.back()] = i - b.back();
      b.pop_back();
    }
    b.push_back(i);
  }
  for(i = b.size()-1; i >= 0; --i)
    c[b[i]] = N - b[i];

  b.clear();
  for(i = N-1; i >= 0; --i){
    while(b.size() && a[b.back()] <= a[i]){
      n = (ll)(b.back() - i) * c[b.back()];
      if(d.find(a[b.back()]) == d.end())
        d[a[b.back()]] = n;
      else
        d[a[b.back()]] += n;
      b.pop_back();
    }
    b.push_back(i);
  }
  for(i = b.size()-1; i >= 0; --i){
    n = (ll)(b[i]+1) * c[b[i]];
    if(d.find(a[b[i]]) == d.end())
      d[a[b[i]]] = n;
    else
      d[a[b[i]]] += n;
  }

  n = 0;
  b.clear();
  for(map<int,ll>::iterator it = d.begin(); it != d.end(); ++it){
    b.push_back(it->first);
    n += it->second;
    l.push_back(n);
  }
  n = 0;
  for(i = l.size()-1; i >= 1; --i){
    n += l[i] - l[i-1];
    t.push_back(n);
  }
  t.push_back(n + l[0]);
  for(i = t.size()-1; i >= 0; --i)
    g.push_back(t[i]);

  while(M--){
    O = gc(), K = getn(), P = gc(), gc();

    if(O == '<'){
      if(b[0] >= K){
        n = 0;
      }else if(b.back() < K){
        n = l.back();
      }else{
  s = 0, e = l.size();
  while(s <= e){
    p = s+((e-s)>>1);
    if(b[p] < K){
      if(b[p+1] >= K){
        n = l[p];
        break;
      }else
        s = p+1;
    }else
      e = p-1;
  }
      }

    }else if(O == '>'){
      if(b[0] > K){
        n = g[0];
      }else if(b.back() <= K){
  n = 0;
      }else{
        s = 0, e = g.size();
  while(s <= e){
    p = s+((e-s)>>1);
    if(b[p] > K){
      if(b[p-1] <= K){
        n = g[p];
        break;
      }else
        e = p-1;
    }else
      s = p+1;
  }
      }

    }else if(d.find(K) == d.end()){
      n = 0;
    }else{
      n = d[K];
    }

    if(((n&1)==1 && P=='D') || ((n&1)==0 && P=='C'))
      r.push_back('D');
    else
      r.push_back('C');
  }

  for(i = 0; i < r.size(); ++i)
    printf("%c", r[i]);
  printf("\n");
  return 0;
}
