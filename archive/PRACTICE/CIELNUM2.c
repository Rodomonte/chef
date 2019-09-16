// CIELNUM2

#include <stdio.h>
#include <string.h>

int main(){
  int N, k=0, l, b, i, n3,n5,n8;
  char s[110];
  scanf("%d\n",&N);
  while(N--){
    gets(s);
    l = strlen(s);
    b = 1;
    n3=n5=n8=0;
    for(i = l - 1; b && i >= 0 && s[i] != ' '; i--){
      if(s[i] == '3') n3++;
      else if(s[i] == '5') n5++;
      else if(s[i] == '8') n8++;
      else if(s[i] >= '0' && s[i] <= '9') b = 0;
    }
    if(b && n8 >= n5 && n5 >= n3) k++;
  }
  printf("%d\n",k);
  return 0;
}
