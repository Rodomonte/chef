// DISHOWN

#include <stdio.h>
#include <vector>
using std::vector;

#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

int a[10001];
int b[10001];
int c[10001];
vector<int> d[10001];
int main(){
  int T,N,Q,X,Y, i,g;
  T = getn();
  while(T--){
    N = getn();
    for(i = 1; i <= N; i++){
      a[i] = getn(), b[i] = c[i] = i;
      d[i].clear(), d[i].pb(i);
    }
    Q = getn();
    while(Q--){
      if(getn()){
        X = getn();
        putn(c[b[X]]); pc('\n');
        continue;
      }
      X = getn(), Y = getn();
      if(b[X] == b[Y]){
        printf("Invalid query!\n");
        continue;
      }
      if(a[b[X]] == a[b[Y]])
        continue;
      if(a[b[X]] < a[b[Y]])
        i = X, X = Y, Y = i;
      if(d[b[X]].size() < d[b[Y]].size()){
        g = b[X];
        a[b[Y]] = a[g];
        c[b[Y]] = c[g];
        for(i = 0; i < d[g].size(); i++){
          d[b[Y]].pb(d[g][i]);
          b[d[g][i]] = b[Y];
        }
      }else{
        g = b[Y];
        for(i = 0; i < d[g].size(); i++){
          d[b[X]].pb(d[g][i]);
          b[d[g][i]] = b[X];
        }
      }
    }
  }
  return 0;
}
