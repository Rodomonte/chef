// CHEFSIGN

#include <stdio.h>
#include <string.h>

int abs(int n){ return (n < 0) ? -n : n; }

char a[100001];
int main(){
  int T, i, m,t, an;

  scanf("%d", &T);
  while(T--){
    scanf("%s", a), an = strlen(a);

    m = t = 0;
    for(i = 0; i < an; ++i){
      if(a[i] == '<'){
        if(t < 0) t = 1;
        else ++t;
      }
      else if(a[i] == '>'){
        if(t > 0) t = -1;
        else --t;
      }
      if(abs(t) > m) m = abs(t);
    }

    printf("%d\n", m+1);
  }
  return 0;
}
