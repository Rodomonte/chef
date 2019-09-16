// TOLLS

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;
using std::sort;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

struct P {
  bool u;
  int i,j,b;
  P(int i0, int j0, int b0): i(i0), j(j0), b(b0) {}
  bool operator<(const P& o) const {
    return b/(j-i+1) > o.b/(o.j-o.i+1);
  }
};

int main(){
  int T,N,M,S,E,B, i,j,k,m,n,t, b[99], mb[99];
  vector<P> a;

  T = getn();
  while(T--){
    N = getn()-1, M = getn(), a.clear();
    for(i = 0; i < M; ++i){
      S = getn(), E = getn(), B = getn();
      if(S == E) continue;
      else if(S > E) t = S, S = E, E = t;
      a.pb(P(S-1,E-2,B));
    }
    M = a.size();

    sort(a.begin(), a.end());
    for(i = 0; i < N; ++i)
      mb[i] = 0;
    for(m = i = 0; i < M; ++i){
      for(j = 0; j < M; ++j)
        a[j].u = true;
      for(j = 0; j < N; ++j)
        b[j] = 0;

      for(j = i; j >= 0; --j){
        for(n = t = 0, k = a[j].i; k <= a[j].j; ++k){
          if(!b[k]) ++n;
          t += b[k];
        }
        if(a[j].b < t) a[j].u = false;
        if(!n || a[j].b < t) continue;
        for(k = a[j].i; k <= a[j].j; ++k)
          if(!b[k]) b[k] = (a[j].b - t) / n;
      }

      for(j = i+1; j < M; ++j){
        for(n = t = 0, k = a[j].i; k <= a[j].j; ++k){
          if(!b[k]) ++n;
          t += b[k];
        }
        if(a[j].b < t) a[j].u = false;
        if(!n || a[j].b < t) continue;
        for(k = a[j].i; k <= a[j].j; ++k)
          if(!b[k]) b[k] = (a[j].b - t) / n;
      }

      for(t = j = 0; j < M; ++j)
        if(a[j].u)
          for(k = a[j].i; k <= a[j].j; ++k)
            t += b[k];
      if(t > m){
        m = t;
        for(j = 0; j < N; ++j)
          mb[j] = b[j];
      }
    }

    for(i = 0; i < N; ++i)
      printf("%d ", mb[i]);
    printf("\n");
  }
  return 0;
}
