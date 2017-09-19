// SMARKET

#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[100001], b[100001], c[100001], q[100001][4];
vector<int> d[100001];

void add(map<int,int>& m, int s, int n){
  map<int,int>::iterator it;
  it = m.find(s);
  if(it == m.end())
    m[s] = n;
  else
    it->second += n;
}

void sub(map<int,int>& m, int s, int n){
  map<int,int>::iterator it;
  it = m.find(s);
  it->second -= n;
  if(!it->second)
    m.erase(it);
}

int main(){
  int T,N,Q,L,R,K, i,j,k,n,t,r;
  map<int,int> m;
  map<int,int>::reverse_iterator rit;

  T = getn();
  while(T--){
    N = getn(), Q = getn();
    for(i = 1; i <= N; ++i)
      a[i] = getn(), d[i].clear();

    n = 1, b[1] = 1;
    for(i = 2; i <= N; ++i){
      if(a[i] == a[i-1]){
        ++n;
      }else{
        for(j = i-1, k = 0; k < n; --j, ++k)
          c[j] = n;
        n = 1;
      }
      b[i] = n;
    }
    for(j = i-1, k = 0; k < n; --j, ++k)
      c[j] = n;

    for(i = 1; i <= Q; ++i)
      L = q[i][0] = getn(), R = q[i][1] = getn(), q[i][2] = getn(), q[i][3] = 0,
      d[L-1].pb(-i), d[R].pb(i);

    m.clear();
    m[1] = 1, n = 1;
    for(i = 1; i <= N; ++i){
      if(i > 1){
        if(a[i] == a[i-1])
          sub(m, n, 1), ++n, add(m, n, 1);
        else
          add(m, 1, 1), n = 1;
      }
      if(d[i].empty())
        continue;

      for(rit = m.rbegin(); rit != m.rend(); ++rit){
        for(j = 0; j < d[i].size(); ++j){
          t = (d[i][j] < 0) ? -d[i][j] : d[i][j];
          if(rit->first < q[t][2])
            continue;
          if(d[i][j] < 0)
            q[t][3] -= rit->second;
          else
            q[t][3] += rit->second;
        }
      }

      for(j = 0; j < d[i].size(); ++j){
        if(d[i][j] > 0 || a[i] != a[i+1])
          continue;
        t = -d[i][j], K = q[t][2];
        if(c[i+1] >= K)
          --q[t][3];
        if(b[i] >= K)
          ++q[t][3];
        if(c[i+1]-b[i] >= K)
          ++q[t][3];
      }
    }

    for(i = 1; i <= Q; ++i)
      printf("%d\n", q[i][3]);
  }
  return 0;
}
