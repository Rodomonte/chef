// FGFS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct B {
  int s,f;
  B(int s0, int f0): s(s0), f(f0) {}
};
bool cmp(const B &a, const B &b){
  return a.s < b.s;
}
int main(){
  int T,N,K,S,F,P, i, f,r;
  vector<B> *v;
  map<int,vector<B> > a;
  map<int,vector<B> >::iterator ai;
  T = getn();
  while(T--){
    N = getn(), K = getn(), r = 0;
    for(i = 0; i < N; i++){
      S = getn(), F = getn(), P = getn();
      a[P].push_back(B(S,F));
    }
    for(ai = a.begin(); ai != a.end(); ai++){
      P = ai->first, v = &(ai->second);
      sort(v->begin(), v->end(), cmp);
      f = v->at(0).f;
      for(i = 1; i < v->size(); i++){
        if(v->at(i).f <= f)
          f = v->at(i).f;
        else if(v->at(i).s >= f)
          f = v->at(i).f, r++;
      }
      r++;
    }
    printf("%d\n",r);
    a.clear();
  }
  return 0;
}

