// GRAPHCH

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[201][201], b[201], c[201];

bool cmp(int i, int j){
  return (double)b[i]/c[i] > (double)b[j]/c[j];
}

int main(){
  int T,N,M, i,j;
  vector<int> d;

  T = getn();
  while(T--){
    N = getn(), M = getn(), d.clear();
    for(i = 1; i <= N; ++i){
      b[i] = getn(), c[i] = 0, d.pb(i);
      for(j = 1; j <= M; ++j){
        a[i][j] = getn();
        if(a[i][j] > c[i]) c[i] = a[i][j];
      }
    }

    sort(d.begin(), d.end(), cmp);
    for(i = 1; i <= M; ++i){
      for(j = 0; j < d.size(); ++j)
        printf("%d ", d[j]);
      printf("\n");
    }
  }
  return 0;
}
