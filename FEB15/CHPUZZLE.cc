// CHPUZZLE

#include <stdio.h>
#include <algorithm>
#include <vector>
using std::vector;

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
  P(int x0, int y0): x(x0), y(y0) {}
  int x,y;
};

struct C {
  int c,h,w;
  vector<P> p;
};

bool cmp(const C* a, const C* b){
  return a->p.size() > b->p.size();
}

int g[1001][1001]={{0}};
C a[200000];
vector<C*> c;

int main(){
  bool f;
  int H,W,K,N,X,Y, i,j,k,x0,y0,x,y, ITER=0;
  H = getn(), W = getn(), K = getn();
  c.clear();
  for(i = 0; i < K; ++i){
    N = getn();
    a[i].c = i+1, a[i].h = a[i].w = 0;
    for(j = 0; j < N; ++j){
      X = getn(), Y = getn();
      a[i].p.pb(P(X,Y));
      if(X > a[i].h)
        a[i].h = X;
      if(Y > a[i].w)
        a[i].w = Y;
    }
    c.pb(a+i);
  }
  std::sort(c.begin(), c.end(), cmp);

  k = 0;
  for(i = 0; i < K; ++i){
    if(k == 0){
      for(x0 = 1; x0 <= H-c[i]->h+1; ++x0){
        for(y0 = 1; y0 <= W-c[i]->w+1; ++y0){
          f = true;
          for(j = 0; j < c[i]->p.size(); ++j){
            ++ITER;
            P& p = c[i]->p[j];
            if(g[p.x+x0-1][p.y+y0-1]){
              f = false;
              break;
            }
          }
          if(f){
            for(j = 0; j < c[i]->p.size(); ++j){
              ++ITER;
              P& p = c[i]->p[j];
              g[p.x+x0-1][p.y+y0-1] = c[i]->c;
            }
            break;
          }
        }
        if(f) break;
      }

    }else if(k == 1){
      for(x0 = H-c[i]->h+1; x0 >= 1; --x0){
        for(y0 = W-c[i]->w+1; y0 >= 1; --y0){
          f = true;
          for(j = 0; j < c[i]->p.size(); ++j){
            ++ITER;
            P& p = c[i]->p[j];
            if(g[p.x+x0-1][p.y+y0-1]){
              f = false;
              break;
            }
          }
          if(f){
            for(j = 0; j < c[i]->p.size(); ++j){
              ++ITER;
              P& p = c[i]->p[j];
              g[p.x+x0-1][p.y+y0-1] = c[i]->c;
            }
            break;
          }
        }
        if(f) break;
      }

    }else if(k == 2){
      for(y0 = W-c[i]->w+1; y0 >= 1; --y0){
        for(x0 = 1; x0 <= H-c[i]->h+1; ++x0){
          f = true;
          for(j = 0; j < c[i]->p.size(); ++j){
            ++ITER;
            P& p = c[i]->p[j];
            if(g[p.x+x0-1][p.y+y0-1]){
              f = false;
              break;
            }
          }
          if(f){
            for(j = 0; j < c[i]->p.size(); ++j){
              ++ITER;
              P& p = c[i]->p[j];
              g[p.x+x0-1][p.y+y0-1] = c[i]->c;
            }
            break;
          }
        }
        if(f) break;
      }

    }else{
      for(y0 = 1; y0 <= W-c[i]->w+1; ++y0){
        for(x0 = H-c[i]->h+1; x0 >= 1; --x0){
          f = true;
          for(j = 0; j < c[i]->p.size(); ++j){
            ++ITER;
            P& p = c[i]->p[j];
            if(g[p.x+x0-1][p.y+y0-1]){
              f = false;
              break;
            }
          }
          if(f){
            for(j = 0; j < c[i]->p.size(); ++j){
              ++ITER;
              P& p = c[i]->p[j];
              g[p.x+x0-1][p.y+y0-1] = c[i]->c;
            }
            break;
          }
        }
        if(f) break;
      }
    }
    k = (k == 3) ? 0 : k+1;
    if(ITER > 700000000)
      break;
  }

  for(i = 1; i <= H; ++i){
    printf("%d", g[i][1]);
    for(j = 2; j <= W; ++j)
      printf(" %d", g[i][j]);
    printf("\n");
  }
  return 0;
}
