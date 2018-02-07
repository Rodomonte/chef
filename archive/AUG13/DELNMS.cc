// DELNMS

#include <stdio.h>
#include <vector>
using std::vector;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define MAX 100000
struct R {
  int v, t;
  R(int v0, int t0):
    v(v0), t(t0) {}
};
int a[MAX+1];
vector<int> gv[MAX];
vector<int>* gp[MAX];
int main(){
  int N,A, i,j, n,t;
  vector<int>* g;
  vector<R> r;
  N = getn(), n = 0;
  for(i = 1; i <= MAX; i++)
    a[i] = -1;
  for(i = 0; i < N; i++){
    A = getn();
    if(a[A] == -1){
      a[A] = n;
      gv[n++].push_back(i);
    }else
      gv[a[A]].push_back(i);
    gp[i] = gv+a[A];
  }
  for(i = N-1; i >= 0; i--){
    g = gp[i];
    if(g->size() == 0)
      continue;
    if(g->size() == 1 || i - g->at(g->size()-2) > 10000){
      g->pop_back();
      r.push_back(R(i+1,1));
    }else{
      n = g->at(g->size()-2);
      g->pop_back();
      g->pop_back();
      for(j = n+1; j < i; j++){
        t = gp[j]->size();
        while(gp[j]->at(--t) != j);
        gp[j]->at(t)--;
        gp[j-1] = gp[j];
      }
      r.push_back(R(n+1,i-n));
      i--;
    }
  }
  printf("%d\n",r.size());
  for(i = 0; i < r.size(); i++)
    printf("%d %d\n",r.at(i).v,r.at(i).t);
  return 0;
}
