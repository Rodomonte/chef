// TOURBUS

#include <stdio.h>
#include <vector>

using std::vector;

#define pb push_back

struct E {
  bool u;
  int n;
  E(bool _u, int _n): u(_u), n(_n) {}
};

struct P {
  int x,y;
  vector<E> e;
};

P a[50];

int ori(int i, int j, int k){
  int r = (a[j].y - a[i].y) * (a[k].x - a[j].x) -
          (a[j].x - a[i].x) * (a[k].y - a[j].y);
  if(!r) return 0;
  return (r > 0) ? 1 : 2;
}

bool inter(int i, int j, int k, int l){
  if(i == k || i == l || j == k || j == l) return false;
  return ori(i, j, k) != ori(i, j, l) && ori(k, l, i) != ori(k, l, j);
}

char s[51];
int main(){
  bool f;
  int N, i,j,k, ii,mi;
  vector<vector<int> > r;

  scanf("%d", &N);
  for(i = 0; i < N; ++i)
    scanf("%d %d", &a[i].x, &a[i].y);
  for(i = 0; i < N; ++i){
    scanf("%s", s);
    for(j = 0; j < N; ++j)
      if(s[j] == 'Y') a[i].e.pb(E(false, j));
  }

  for(i = 0; i < N;){
    vector<int> rn;
    k = i;
    while(1){
      rn.pb(k), mi = -1;
      for(j = 0; j < a[k].e.size(); ++j){
        if(a[k].e[j].u) continue;
        if(a[a[k].e[j].n].e.size() == 1) continue;
        for(ii = 0, f = false; ii < rn.size(); ++ii)
          if(rn[ii] == a[k].e[j].n){ f = true; break; }
        if(f) continue;
        for(ii = 1, f = false; ii < rn.size(); ++ii)
          if(inter(k, a[k].e[j].n, rn[ii-1], rn[ii])){ f = true; break; }
        if(f) continue;
        mi = j;
        break;
      }

      if(mi == -1) break;
      a[k].e[mi].u = true, ii = a[k].e[mi].n;
      for(j = 0; j < a[ii].e.size(); ++j)
        if(a[ii].e[j].n == k){ a[ii].e[j].u = true; break; }
      k = ii;
    }
    if(rn.size() > 1) r.pb(rn);
    else ++i;
  }

  printf("%d\n", r.size());
  for(i = 0; i < r.size(); ++i){
    printf("%d", r[i].size()-1);
    for(j = 0; j < r[i].size(); ++j)
      printf(" %d", r[i][j]);
    printf("\n");
  }
  return 0;
}
