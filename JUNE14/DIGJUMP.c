// DIGJUMP

#include <stdio.h>
#include <string.h>

#define INF 2000000000

char s[100001];
int v[100000];
int main(){
  char a[10]={0};
  int N, i,m;
  scanf("%s",s);
  N = strlen(s), m = v[0] = 0, a[s[0]-'0'] = 1;
  for(i = 1; i < N; i++)
    v[i] = INF;
  while(v[N-1] == INF){
    m++;
    if(a[s[N-1]-'0'] || v[N-2] != INF){
      v[N-1] = m;
      break;
    }
    for(i = 1; i < N-1; i++){
      if(v[i] != INF)
        continue;
      if(v[i-1] == m-1 || v[i+1] == m-1 || a[s[i]-'0'])
        v[i] = m;
    }
    for(i = 1; i < N-1; i++)
      if(v[i] != INF && !a[s[i]-'0'])
        a[s[i]-'0'] = 1;
  }
  printf("%d\n",m);
  return 0;
}
