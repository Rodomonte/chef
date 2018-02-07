// GRGUY

#include <stdio.h>
#include <string.h>

char a[2][200001];
int main(){
  int T, i,s,l,o,r;
  scanf("%d", &T);
  while(T--){
    scanf("%s%s", a[0], a[1]);
    if(a[0][0] == '#' && a[1][0] == '#'){
      printf("No\n");
      continue;
    }
    s = strlen(a[0]);

    l = -1;
    for(i = 0; i < s; ++i){
      if(a[0][i] == '#'){
        l = 1;
  break;
      }
      if(a[1][i] == '#'){
        l = 0;
  break;
      }
    }
    if(l == -1){
      printf("Yes\n0\n");
      continue;
    }

    o = (l ? 0 : 1), r = 0;
    for(i = 1; i < s; ++i){
      if(a[l][i] == '#'){
  if(a[o][i] == '#'){
    r = -1;
    break;
  }
  l = o;
  o = (l ? 0 : 1);
  ++r;
      }
    }

    if(r == -1)
      printf("No\n");
    else
      printf("Yes\n%d\n", r);
  }
  return 0;
}
