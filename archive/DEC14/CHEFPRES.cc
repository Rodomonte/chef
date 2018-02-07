// CHEFPRES

#include <stdio.h>
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

int min(int a, int b){
  return (a < b) ? a : b;
}

struct C {
  C(){}
  int f,p,d;
  vector<int> n;
};

C a[10001];

void dfs(int i, int p, int d){
  int j;
  a[i].p = p, a[i].d = d;
  for(j = 0; j < a[i].n.size(); ++j)
    if(a[i].n[j] != p)
      dfs(a[i].n[j], i, d+1);
}

int main(){
  int N,K,B,X,Y,Q, i,mx,mi,mn,x,y;
  vector<int> b[101];
  N = getn(), K = getn(), B = getn();
  for(i = 0; i < N-1; ++i){
    X = getn(), Y = getn();
    a[X].n.pb(Y), a[Y].n.pb(X);
  }
  for(i = 1; i <= N; ++i){
    a[i].f = getn();
    b[a[i].f].pb(i);
  }
  dfs(B, 0, 0);
  Q = getn();
  while(Q--){
    X = getn(), Y = getn();
    if(b[Y].empty()){
      printf("-1\n");
      continue;
    }
    mx = -1;
    for(i = 0; i < b[Y].size(); ++i){
      x = X, y = b[Y][i];
      mn = min(a[x].d, a[y].d);
      while(a[x].d > a[y].d){
        x = a[x].p;
        mn = min(mn, a[x].d);
      }
      while(a[y].d > a[x].d){
        y = a[y].p;
        mn = min(mn, a[y].d);
      }
      while(x != y){
        x = a[x].p, y = a[y].p;
        mn = min(mn, min(a[x].d, a[y].d));
      }
      if(mn > mx || (mn == mx && b[Y][i] < mi))
        mx = mn, mi = b[Y][i];
    }
    printf("%d\n", mi);
  }
  return 0;
}
