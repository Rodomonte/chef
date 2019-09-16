// DIVQUERY

#include <stdio.h>
#include <vector>
using std::vector;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define MAX 100001
int c[MAX], d[50];
void fn1(int p, int j, int x, int y){
  if(p == j){
    c[x]++;
    return;
  }
  int z = 1, yy = y / x;
  while(yy % z == 0){
    fn1(p+1, j, x*z, y);
    z *= d[p];
  }
}
int a[MAX],b[MAX],q[3][MAX],r[MAX];
vector<int> e[MAX];
int main(){
  int N,Q, i,j, n;
  r[0] = n = 2, r[1] = 3;
  for(i = 2; i < MAX; i += 2)
    b[i] = 2;
  for(i = 3; i < MAX; i += 3)
    b[i] = 3;
  for(i = 5; i < MAX; i += (i%6==1?4:2))
    if(!b[i]){
      r[n++] = i;
      for(j = i; j < MAX; j += i)
        b[j] = i;
    }
  N = getn(), Q = getn();
  for(i = 0; i < N; i++)
    a[i] = getn();
  for(i = 0; i < Q; i++){
    q[0][i] = getn()-1, q[1][i] = getn()-1, q[2][i] = getn(), r[i] = 0;
    if(q[0][i])
      e[q[0][i]-1].push_back(i);
    e[q[1][i]].push_back(i);
  }
  for(i = 0; i < N; i++){
    j = 0, n = a[i];
    while(n != 1){
      d[j++] = b[n];
      while(b[n] == d[j-1])
        n /= b[n];
    }
    fn1(0, j, 1, a[i]);
    for(j = 0; j < e[i].size(); ++j){
      if(q[0][e[i][j]]-1 == i)
        r[e[i][j]] -= c[q[2][e[i][j]]];
      else
        r[e[i][j]] += c[q[2][e[i][j]]];
    }
  }
  for(i = 0; i < Q; ++i)
    printf("%d\n",r[i]);
  return 0;
}
