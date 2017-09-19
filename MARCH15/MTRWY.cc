// MTRWY

#include <stdio.h>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

#define ll long long
#define gc getchar_unlocked
#define pb push_back

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct P {
  bool n,e,s,w,v;
  int x,y,g;
};

int q[1000000][5];
P a[1000][1000];

bool cut(P& p, bool e){
  if(e){
    if(!p.e)
      return false;
    p.e = false;
    a[p.x][p.y+1].w = false;
  }else{
    if(!p.s)
      return false;
    p.s = false;
    a[p.x+1][p.y].n = false;
  }
  return true;
}

int main(){
  int T,N,M,Q,O,X,Y, i,j,k,m,gn;
  ll r;
  bool f;
  P *p;
  queue<P*> b;
  vector<vector<P*> > g;
  vector<P*> *s,*d;
  vector<P*> z;

  T = getn();
  while(T--){
    N = getn(), M = getn(), Q = getn();

    // Build initial graph
    for(i = 0; i < N; ++i){
      for(j = 0; j < M; ++j){
        P& t = a[i][j];
        t.x = i, t.y = j, t.g = 0;
        t.n = t.e = t.s = t.w = t.v = false;
        if(i > 0)
          t.n = true;
        if(j < M-1)
          t.e = true;
        if(i < N-1)
          t.s = true;
        if(j > 0)
          t.w = true;
      }
    }

    // Cut edges, save queries
    for(i = 0; i < Q; ++i){
      O = q[i][0] = getn();
      if(O == 4)
        continue;
      X = q[i][1] = getn()-1, Y = q[i][2] = getn()-1, f = true;
      if(O == 1)
        f = cut(a[X][Y], true);
      else if(O == 2)
        f = cut(a[X][Y], false);
      else if(O == 3)
        q[i][3] = getn()-1, q[i][4] = getn()-1;
      if(!f)
        q[i][1] = -1;
    }

    // BFS to find components
    g.clear();
    gn = 0;
    for(i = 0; i < N; ++i){
      for(j = 0; j < M; ++j){
        if(a[i][j].v)
          continue;
        b.push(a[i]+j);
        a[i][j].v = true;
        vector<P*> gv;
        while(!b.empty()){
          p = b.front();
          b.pop();
          gv.pb(p);
          p->g = gn;
          z.clear();
          if(p->n)
            z.pb(a[p->x-1]+p->y);
          if(p->e)
            z.pb(a[p->x]+p->y+1);
          if(p->s)
            z.pb(a[p->x+1]+p->y);
          if(p->w)
            z.pb(a[p->x]+p->y-1);
          for(k = 0; k < z.size(); ++k){
            if(!z[k]->v){
              b.push(z[k]);
              z[k]->v = true;
            }
          }
        }
        g.pb(gv);
        ++gn;
      }
    }

    // Join back edges, cumulate result
    m = 0;
    for(i = 0; i < g.size(); ++i)
      if(g[i].size() > m)
        m = g[i].size();
    r = 0;
    for(i = Q-1; i >= 0; --i){
      O = q[i][0];
      if(O == 1 || O == 2){
        X = q[i][1], Y = q[i][2];
        if(X == -1)
          continue;
        if(O == 1){
          if(a[X][Y].g == a[X][Y+1].g)
            continue;
          if(g[a[X][Y].g].size() < g[a[X][Y+1].g].size())
            s = &g[a[X][Y].g], d = &g[a[X][Y+1].g];
          else
            s = &g[a[X][Y+1].g], d = &g[a[X][Y].g];
        }else{
          if(a[X][Y].g == a[X+1][Y].g)
            continue;
          if(g[a[X][Y].g].size() < g[a[X+1][Y].g].size())
            s = &g[a[X][Y].g], d = &g[a[X+1][Y].g];
          else
            s = &g[a[X+1][Y].g], d = &g[a[X][Y].g];
        }
        for(j = 0; j < s->size(); ++j){
          d->pb((*s)[j]);
          d->back()->g = (*d)[0]->g;
        }
        s->clear();
        if(d->size() > m)
          m = d->size();
      }else if(O == 3 && a[q[i][1]][q[i][2]].g == a[q[i][3]][q[i][4]].g){
        ++r;
      }else if(O == 4){
        r += m;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
