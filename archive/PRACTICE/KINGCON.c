// KINGCON

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int N, a[3000][3000], b[3000], l[3000], n,ns;
char s[3000];
void dfs(int v, int x){
  int i, p=0,w;
  b[v] = l[v] = ++n;
  for(i = 1; i <= a[v][0]; i++){
    w = a[v][i];
    if(w == x) continue;
    if(b[w])
      l[v] = l[v] < b[w] ? l[v] : b[w];
    else{
      p++;
      dfs(w, v);
      l[v] = l[v] < l[w] ? l[v] : l[w];
      if(l[w] >= b[v])
        s[v] = 1;
    }
  }
  if(x == -1 && p < 2)
    s[v] = 0;
}
int main(){
  int T=getn(),M,K, i,j;
  while(T--){
    N=getn(), M=getn(), K=getn(), n=0, ns=0;
    for(i = 0; i < N; i++)
      a[i][0] = b[i] = s[i] = 0;
    while(M--){
      i = getn(); j = getn();
      a[i][++(a[i][0])] = j;
      a[j][++(a[j][0])] = i;
    }
    dfs(0, -1);
    for(i = 0; i < N; i++)
      if(s[i])
        ns++;
    printf("%d\n",ns*K);
  }
  return 0;
}
