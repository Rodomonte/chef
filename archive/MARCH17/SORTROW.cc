// SORTROW

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::reverse;
using std::vector;

#define gc getchar_unlocked
#define pb push_back
#define INF 2000000000

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int min(int a, int b){
  return (a < b) ? a : b;
}
int max(int a, int b){
  return (a > b) ? a : b;
}

struct P {
  int n,i,j;
  P(int n0, int i0, int j0): n(n0), i(i0), j(j0) {}
  bool operator<(const P& o){
    return (n < o.n);
  }
};

int main(){
  int N, i,j,k,m,t,u,ii,jj,mi,mj,n,nn;
  vector<P> a;
  vector<int> b[300];

  N = getn(), a.pb(P(0, -1, -1));
  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      a.pb(P(getn(), i, j));
  sort(a.begin(), a.end());

  for(i = 1; i < a.size(); ++i){
    m = INF;
    for(j = 0; j < N; ++j){
      if(b[j].size() == N)
        continue;
      t = (a[i].i-j) * (a[i].i-j);
      if(j&1)
        t += (N-1-b[j].size()-a[i].j) * (N-1-b[j].size()-a[i].j);
      else
        t += (a[i].j-b[j].size()) * (a[i].j-b[j].size());
      if(t < m)
        m = t, k = j;
    }
    b[k].pb(a[i].n);
  }
  for(i = 0; i < N; ++i)
    if(i&1)
      reverse(b[i].begin(), b[i].end());

  // the shuffle for 100 alex
  for(k = 0; k < 2; ++k){
    for(i = 0; i < N; ++i){
      for(j = 0; j < N; ++j){
        m = 0;
        for(ii = max(i-40, 0); ii < min(i+40, N); ++ii){
          if(i == ii)
            continue;
          for(jj = max(j-40, 0); jj < min(j+40, N); ++jj){
            n = b[i][j], nn = b[ii][jj];
            if(((ii&1) && ((jj > 0 && b[ii][jj-1] < n) ||
                           (jj < N-1 && b[ii][jj+1] > n))) ||
               (!(ii&1) && ((jj > 0 && b[ii][jj-1] > n) ||
                            (jj < N-1 && b[ii][jj+1] < n))) ||
               ((i&1) && ((j > 0 && b[i][j-1] < nn) ||
                          (j < N-1 && b[i][j+1] > nn))) ||
               (!(i&1) && ((j > 0 && b[i][j-1] > nn) ||
                           (j < N-1 && b[i][j+1] < nn))))
              continue;

            t = (a[n].i-i)*(a[n].i-i) + (a[n].j-j)*(a[n].j-j) +
                (a[nn].i-ii)*(a[nn].i-ii) + (a[nn].j-jj)*(a[nn].j-jj);
            u = (a[n].i-ii)*(a[n].i-ii) + (a[n].j-jj)*(a[n].j-jj) +
                (a[nn].i-i)*(a[nn].i-i) + (a[nn].j-j)*(a[nn].j-j);
            //printf("b%d,%d=%d b%d,%d=%d t=%d u=%d t-u=%d %d\n",
            //       i,j,n,ii,jj,nn,t,u,t-u,(t-u>0)?888888888:0);
            if(t-u > m)
              m = t-u, mi = ii, mj = jj;
          }
        }
        if(m > 0)
          u = b[i][j], b[i][j] = b[mi][mj], b[mi][mj] = u;
      }
    }
  }

  for(i = 0; i < N; ++i){
    for(j = 0; j < N; ++j)
      printf("%d ", b[i][j]);
    printf("\n");
  }
  return 0;
}
