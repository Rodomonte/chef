// GRAPHCH

#include <stdio.h>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

#define ll long long
#define gc getchar_unlocked
#define pb push_back
#define INF 2000000000
#define INFL 1000000000000000000LL

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int n){ return (n < 0) ? -n : n; }

struct P {
  bool v;
  int w,h,x,y;
  vector<int> n;
};

int N;
P a[50];

bool check(int i, int x, int y){
  int j;
  for(j = 0; j < N; ++j){
    if(i == j || a[j].x == INF) continue;
    if(x < a[j].x+a[j].w && x+a[i].w > a[j].x &&
       y < a[j].y+a[j].h && y+a[i].h > a[j].y) return false;
  }
  return true;
}

ll eval(int i, int x, int y){
  int j,k;
  ll r;
  for(r = j = 0; j < a[i].n.size(); ++j){
    k = a[i].n[j];
    if(a[k].x == INF) continue;
    r += abs(x+a[i].w/2-(a[k].x+a[k].w/2)) + abs(y+a[i].h/2-(a[k].y+a[k].h/2));
  }
  return r;
}

int main(){
  int T,M,U,V, i,j,k, ii,mx,my;
  ll m,t;
  queue<int> q;

  T = getn();
  while(T--){
    N = getn(), M = getn();
    for(i = 0; i < N; ++i)
      a[i].n.clear(), a[i].v = false, a[i].x = a[i].y = INF;
    for(i = 0; i < M; ++i)
      U = getn(), V = getn(), a[U].n.pb(V), a[V].n.pb(U);
    for(i = 0; i < N; ++i)
      a[i].w = getn(), a[i].h = getn();

    for(ii = 0; ii < N; ++ii){
      if(a[ii].x != INF) continue;
      q.push(ii), a[ii].v = true;
      while(!q.empty()){
        i = q.front(), q.pop();
        for(j = 0; j < a[i].n.size(); ++j)
          if(!a[a[i].n[j]].v)
            q.push(a[i].n[j]), a[a[i].n[j]].v = true;
        if(!i){
          a[i].x = -a[i].w/2, a[i].y = -a[i].h/2;
          continue;
        }

        m = INFL;
        for(j = 0; j < N; ++j){
          if(a[j].x == INF) continue;
          int xy[8][2] = {{a[j].x, a[j].y-a[i].h},
                          {a[j].x+(a[j].w-a[i].w), a[j].y-a[i].h},
                          {a[j].x+a[j].w, a[j].y},
                          {a[j].x+a[j].w, a[j].y+(a[j].h-a[i].h)},
                          {a[j].x, a[j].y+a[j].h},
                          {a[j].x+(a[j].w-a[i].w), a[j].y+a[j].h},
                          {a[j].x-a[i].w, a[j].y},
                          {a[j].x-a[i].w, a[j].y+(a[j].h-a[i].h)}};

          for(k = 0; k < 8; ++k){
            if(check(i, xy[k][0], xy[k][1])){
              t = eval(i, xy[k][0], xy[k][1]);
              if(t < m) m = t, mx = xy[k][0], my = xy[k][1];
            }
          }
        }
        a[i].x = mx, a[i].y = my;
      }
    }

    for(i = 0; i < N; ++i)
      printf("%lf %lf\n", (double)a[i].w/2+a[i].x, (double)a[i].h/2+a[i].y);
  }
  return 0;
}
