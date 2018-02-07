// CHEFBR

#include <stdio.h>
#include <vector>
#include <set>
using std::vector;
using std::set;

#define ll long long
#define pb push_back
#define MOD 1000000007

struct P {
  int i,j;
  vector<int> c;
  set<int> s;
};

P a[2500];
int an;
bool v[2500]={0};

void dfs(int i, vector<int>& g){
  int j;
  v[i] = true;
  g.pb(i);
  for(j = 0; j < a[i].c.size(); ++j){
    if(v[a[i].c[j]])
      continue;
    dfs(a[i].c[j], g);
  }
}

int rec(vector<int> g){
  if(g.empty())
    return 1;
  int i,j;
  i = g.back();
  g.pop_back();
  vector<int> g2;
  for(j = 0; j < g.size(); ++j)
    if(a[i].s.find(g[j]) == a[i].s.end())
      g2.pb(g[j]);
  j = rec(g) + rec(g2);
  return (j >= MOD) ? j-MOD : j;
}

int main(){
  int N,A[100], i,j,n,r;
  vector<vector<int> > gv;
  scanf("%d", &N);
  for(i = 0; i < N; ++i)
    scanf("%d", A+i);
  // Find bracket pairs
  an = 0;
  for(i = 0; i < N-1; ++i)
    for(j = i+1; j < N; ++j)
      if(A[i] < 0 && A[j] == 0-A[i])
        a[an].i = i, a[an++].j = j;
  // Create conflict graph
  for(i = 0; i < an-1; ++i)
    for(j = i+1; j < an; ++j)
      if(a[i].i == a[j].i || a[i].j == a[j].j ||
          (a[i].i < a[j].i && a[i].j > a[j].i && a[i].j < a[j].j))
        a[i].c.pb(j), a[j].c.pb(i), a[i].s.insert(j), a[j].s.insert(i);
  // Create joint subgraphs
  for(i = 0; i < an; ++i){
    if(v[i])
      continue;
    vector<int> g;
    dfs(i, g);
    gv.pb(g);
  }
  // Recurse each subgraph
  r = 1;
  for(i = 0; i < gv.size(); ++i)
    r = (int)((ll)r * rec(gv[i]) % MOD);
  printf("%d\n", r);
  return 0;
}
