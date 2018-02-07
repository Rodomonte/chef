// DISHLIFE

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

int b[100001];
vector<int> a[100000];
int main(){
  int T,N,K,P,I, i,j,f;

  T = getn();
  while(T--){
    N = getn(), K = getn();
    for(i = 1; i <= K; ++i)
      b[i] = 0;
    for(i = 0; i < N; ++i){
      P = getn(), a[i].clear();
      for(j = 0; j < P; ++j)
        I = getn(), a[i].pb(I), ++b[I];
    }

    f = 1;
    for(i = 1; i <= K; ++i)
      if(!b[i]){
        f = 0;
        break;
      }
    if(!f){
      printf("sad\n");
      continue;
    }

    for(i = 0; i < N; ++i){
      f = 1;
      for(j = 0; j < a[i].size(); ++j)
        if(b[a[i][j]] == 1){
          f = 0;
          break;
        }
      if(f)
        break;
    }
    printf(f ? "some\n" : "all\n");
  }
  return 0;
}
