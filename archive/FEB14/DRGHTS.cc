// DRGHTS

#include <stdio.h>
#include <vector>
using namespace std;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct R {
  char o,v;
  int d,p;
  vector<int> a;
};
R a[50001];
vector< vector<int> > b;
void dfs(int i, vector<int>* g, int d){
  int j,c;
  a[i].d = d, a[i].v = 1;
  if(a[i].o)
    g->push_back(i);
  for(j = 0; j < a[i].a.size(); j++){
    c = a[i].a.at(j);
    if(a[c].v)
      continue;
    a[c].p = i;
    dfs(c, g, d+1);
  }
}
#define ui unsigned int
int main(){
  int N,M, i,j,k,l, r1,r2;
  vector<int>* v;
  N = getn(), M = getn();
  for(i = 1; i <= N; i++)
    a[i].o = getn(), a[i].v = 0;
  for(k = 0; k < M; k++){
    i = getn(), j = getn();
    a[i].a.push_back(j);
    a[j].a.push_back(i);
  }
  for(i = 1; i <= N; i++){
    if(a[i].v)
      continue;
    a[i].p = 0;
    vector<int> g;
    dfs(i, &g, 1);
    if(g.size() > 1)
      b.push_back(g);
  }
  for(i = 1; i <= N; i++)
    a[i].v = 0;
  for(r1 = r2 = l = 0; l < b.size(); l++){
    v = &b.at(l);
    r1 += ((ui)v->size() * (ui)(v->size()-1)) >> 1;
    a[v->at(0)].v = 1;
    r2++;
    for(k = 1; k < v->size(); k++){
      i = v->at(0), j = v->at(k);
      if(a[j].v)
        continue;
      while(a[i].d > a[j].d){
        i = a[i].p;
        if(!a[i].v)
          r2++;
        a[i].v = 1;
      }
      if(i == j)
        continue;
      while(a[j].d > a[i].d){
        a[j].v = 1;
        r2++;
        j = a[j].p;
        if(a[j].v)
          break;
      }
      if(a[j].v)
        continue;
      a[j].v = 1;
      r2++;
      while(1){
        i = a[i].p, j = a[j].p;
        if(a[i].v && a[j].v)
          break;
        if(i == j){
          a[i].v = 1;
          r2++;
          break;
        }
        if(!a[i].v)
          r2++;
        if(!a[j].v)
          r2++;
        a[i].v = a[j].v = 1;
      }
    }
  }
  printf("%d %d\n",r1,r2);
  return 0;
}
