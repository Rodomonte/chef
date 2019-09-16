// CHPLGNS

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

#define gc getchar_unlocked
#define pb push_back
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

int d[100000], r[100000];

bool cmp(int i, int j){ return d[i] < d[j]; };

int main(){
  int T,N,M,X,Y, i,j;
  vector<int> b;

  T = getn();
  while(T--){
    N = getn(), b.clear();
    for(i = 0; i < N; ++i){
      M = getn(), b.pb(i), d[i] = -INF;
      for(j = 0; j < M; ++j) X = getn(), Y = getn(), d[i] = max(d[i], X);
    }

    sort(b.begin(), b.end(), cmp);
    for(i = 0; i < N; ++i) r[b[i]] = i;
    for(i = 0; i < N; ++i) printf("%d ", r[i]);
    printf("\n");
  }
  return 0;
}
