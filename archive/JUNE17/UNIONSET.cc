// SUMQ

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char b[2501];
vector<int> a[2500];
int main(){
  char f;
  int T,N,K,L, i,j,k,r;

  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = 0; i < N; ++i){
      L = getn(), a[i].clear();
      for(j = 0; j < L; ++j)
        a[i].pb(getn());
    }

    for(r = i = 0; i < N-1; ++i){
      for(j = i+1; j < N; ++j){
        if(a[i].size() + a[j].size() < K) continue;
        for(k = 1; k <= K; ++k) b[k] = 0;
        for(k = 0; k < a[i].size(); ++k) b[a[i][k]] = 1;
        for(k = 0; k < a[j].size(); ++k) b[a[j][k]] = 1;
        for(k = f = 1; k <= K; ++k)
          if(!b[k]){ f = 0; break; }
        r += f ? 1 : 0;
      }
    }

    printf("%d\n", r);
  }
  return 0;
}
