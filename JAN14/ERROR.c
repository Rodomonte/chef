// ERROR

#include <stdio.h>
#include <string.h>

char a[100001];
int main(){
  int T, i, l;
  scanf("%d\n",&T);
  while(T--){
    scanf("%s",a);
    l = strlen(a);
    for(i = 0; i < l-2; i++)
      if((a[i]=='0' && a[i+1]=='1' && a[i+2]=='0') ||
          (a[i]=='1' && a[i+1]=='0' && a[i+2]=='1')){
        l = -1;
        break;
      }
    printf((l==-1)?"Good\n":"Bad\n");
  }
  return 0;
}

