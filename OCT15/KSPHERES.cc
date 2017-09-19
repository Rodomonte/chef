// KSPHERES

#include <stdio.h>
#include <vector>

using std::vector;

#define gc getchar_unlocked
#define pb push_back
#define MOD 1000000007

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int madd(int a, int b){
  a += b;
  if(a >= MOD)
    a -= MOD;
  return a;
}
int mmul(int a, int b){
  long long r = a;
  r *= b;
  return (int)(r % MOD);
}

int a[1001]={0}, b[1001]={0};
int main(){
  int N,M,C, i,j,k,n;
  vector<vector<int> > c;

  N = getn(), M = getn(), C = getn();
  for(i = 0; i < N; ++i)
    ++a[getn()];
  for(i = 0; i < M; ++i)
    ++b[getn()];
  for(i = 1; i <= C; ++i){
    if(!a[i] || !b[i])
      continue;
    n = mmul(a[i], b[i]);
    vector<int> cn;
    cn.pb(1);
    cn.pb(n);
    c.pb(cn);
  }

  while(c.size() > 1){
    vector<vector<int> > c2;
    for(i = 0; i < c.size()-1; i += 2){
      vector<int> cn;
      for(j = 0; j < c[i].size()+c[i+1].size()-1; ++j)
  cn.pb(0);
      for(j = 0; j < c[i].size(); ++j)
  for(k = 0; k < c[i+1].size(); ++k)
    cn[j+k] = madd(cn[j+k], mmul(c[i][j], c[i+1][k]));
      c2.pb(cn);
    }
    if(c.size() & 1)
      c2.pb(c.back());
    c = c2;
  }

  for(i = 2; i < c[0].size(); ++i)
    printf("%d ", c[0][i]);
  for(i = 0; i < C-c[0].size()+2; ++i)
    printf("0 ");
  printf("\n");

  return 0;
}
