// EBOLA

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back
#define INF (1<<30)

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

struct P {
  bool z;
  int d,e,w;
  vector<int> n;
};

P a[10000];
int main(){
  int N,M,K,S,X,Y, i,j,k,mi, m,n,t;
  vector<int> q,y,z;

  N = getn(), M = getn(), K = getn(), S = getn();
  for(i = 1; i <= N; ++i) a[i].w = getn(), a[i].d = -1, a[i].z = false;
  for(i = 0; i < M; ++i) X = getn(), Y = getn(), a[X].n.pb(Y), a[Y].n.pb(X);

  q.pb(S), a[S].d = 0;
  for(i = 0; i < q.size(); ++i)
    for(j = 0; j < a[q[i]].n.size(); ++j) if(a[a[q[i]].n[j]].d == -1)
      q.pb(a[q[i]].n[j]), a[a[q[i]].n[j]].d = a[q[i]].d+1;

  a[S].z = true, z.pb(S);
  for(t = 0; K && !z.empty(); ++t){
    y.clear();
    for(i = 0; i < z.size(); ++i) for(j = 0; j < a[z[i]].n.size(); ++j)
      if(!a[a[z[i]].n[j]].z && a[a[z[i]].n[j]].d != INF)
        y.pb(a[z[i]].n[j]), a[a[z[i]].n[j]].z = true;

    for(i = 0, m = mi = -1; i < y.size(); ++i){
      for(j = 1; j <= N; ++j) a[j].e = (a[j].d == INF) ? INF : -1;
      for(j = 0; j < z.size(); ++j) a[z[j]].e = 0;
      q = z, a[y[i]].e = INF;
      for(j = 0; j < q.size(); ++j) if(q[j] != y[i])
        for(k = 0; k < a[q[j]].n.size(); ++k) if(a[a[q[j]].n[k]].e == -1)
          q.pb(a[q[j]].n[k]), a[a[q[j]].n[k]].e = a[q[j]].e+1;

      for(j = 1, n = 0; j <= N; ++j) if(!a[j].z && a[j].d != INF)
        n += a[j].w *
             (((a[j].e == -1 || a[j].e == INF) ? 1000 : a[j].e) - a[j].d);
      if(n > m) m = n, mi = y[i];
    }
    if(mi == -1) break;

    printf("%d ", mi), a[mi].d = INF, z.clear(), --K;
    for(i = 0; i < y.size(); ++i) if(y[i] != mi) z.pb(y[i]);
  }
  while(K--) printf("1 ");
  printf("\n");
  return 0;
}
