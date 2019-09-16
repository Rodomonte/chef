// LONGSEQ

#include <stdio.h>
#include <string.h>

char a[100001];
int main(){
  int T,N, i, o,z;

  scanf("%d", &T);
  while(T--){
    scanf("%s", a), N = strlen(a);
    for(i = o = z = 0; i < N; ++i) if(a[i] == '0') ++z; else ++o;
    printf((o == 1 || z == 1) ? "Yes\n" : "No\n");
  }
  return 0;
}
