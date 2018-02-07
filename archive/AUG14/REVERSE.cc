// REVERSE

#include <stdio.h>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

#define gc getchar_unlocked
#define pb push_back
#define INF 1000000000

inline int getn(){
  char c = gc(); int n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

struct E {
  int n,w;
  E(int n0, int w0): n(n0), w(w0) {}
};

int d[100001];
vector<E> a[100001];
int main(){
  int N,M,X,Y, i,n,w;
  queue<int> q;
  N = getn(), M = getn(), d[1] = 0;
  for(i = 2; i <= N; i++)
    d[i] = INF;
  for(i = 0; i < M; i++){
    X = getn(), Y = getn();
    a[X].pb(E(Y,0));
    a[Y].pb(E(X,1));
  }
  // BFS Dijkstras
  q.push(1);
  while(!q.empty()){
    n = q.front();
    for(i = 0; i < a[n].size(); i++){
      w = d[n] + a[n][i].w;
      if(w < d[a[n][i].n]){
        d[a[n][i].n] = w;
        q.push(a[n][i].n);
      }
    }
    q.pop();
  }
  if(d[N] == INF)
    printf("-1\n");
  else
    printf("%d\n",d[N]);
  return 0;
}
