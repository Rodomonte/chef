#include <stdio.h>

char a[100001];
int main(){
  int T,N, i,m,t;
  scanf("%d", &T);
  while(T--){
    scanf("%d%s", &N, a);
    m = 100000;
    for(i = t = 0; i < N; ++i) if(a[i] != 'R') ++t;
    if(t < m) m = t;
    for(i = t = 0; i < N; ++i) if(a[i] != 'G') ++t;
    if(t < m) m = t;
    for(i = t = 0; i < N; ++i) if(a[i] != 'B') ++t;
    if(t < m) m = t;
    printf("%d\n", m);
  }
  return 0;
}