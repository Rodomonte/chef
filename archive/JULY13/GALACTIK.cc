// GALACTIK

#include <stdio.h>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

vector<int> a[100001];
int b[100001], c[100001];
int main(){
  int N=getn(),M=getn(),A,B,C, i,j,n,n2, g=0,m=10001,mg,r=0;
  queue<int> q;
  vector<int> gm;
  if(N == 1){
    printf("0\n");
    return 0;
  }
  for(i = 0; i < M; i++){
    A = getn(), B = getn();
    a[A].push_back(B);
    a[B].push_back(A);
  }
  for(i = 1; i <= N; i++)
    b[i] = -1, c[i] = getn();
  for(i = 1; i <= N; i++){
    if(b[i] > -1)
      continue;
    b[i] = g;
    q.push(i);
    while(q.size()){
      n = q.front();
      q.pop();
      if(gm.size() <= g){
        if(c[n] < 0)
          gm.push_back(10001);
        else
          gm.push_back(c[n]);
        if(gm.at(g) < m)
          m = gm.at(g), mg = g;
      }else if(c[n] >= 0 && c[n] < gm.at(g)){
        gm.at(g) = c[n];
        if(gm.at(g) < m)
          m = gm.at(g), mg = g;
      }
      for(j = 0; j < a[n].size(); j++){
        n2 = a[n].at(j);
        if(b[n2] == -1){
          b[n2] = g;
          q.push(n2);
        }
      }
    }
    g++;
  }
  if(g == 1){
    printf("0\n");
    return 0;
  }
  for(i = 0; i < g; i++){
    if(gm[i] == 10001){
      printf("-1\n");
      return 0;
    }
    if(i == mg)
      continue;
    r += m + gm[i];
  }
  printf("%d\n",r);
  return 0;
}
