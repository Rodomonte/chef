// PALIN

#include <stdio.h>

#define gc getchar_unlocked

int main(){
  char c, a[1000002];
  int T, i,j, an;
  scanf("%d",&T);
  while(T--){
    while((c = gc()) == '\n');
    an = 1, a[0] = '0', a[1] = c;
    while((c = gc()) != '\n')
      a[++an] = c;
    if(an == 1){
      if(a[1] == '9')
        printf("11\n");
      else
        printf("%c\n",a[1]+1);
      continue;
    }
    i = an, a[an+1] = 0;
    while(a[i] == '9')
      a[i--] = '0';
    a[i]++;
    if(a[0] == '1'){
      a[an] = '1';
      printf("%s\n",a);
      continue;
    }
    i = an/2, j = i+1;
    if(an % 2)
      j++;
    while(i > 0 && a[i] == a[j])
      i--, j++;
    if(i < 1){
      printf("%s\n",a+1);
      continue;
    }
    if(a[i] < a[j]){
      i = an/2 + (an%2?1:0);
      while(a[i] == '9')
        a[i--] = '0';
      a[i]++;
      for(i = an/2, j = an/2+(an%2?2:1); i > 0; i--, j++)
        a[j] = a[i];
    }else{
      for(; i > 0; i--, j++)
        a[j] = a[i];
    }
    printf("%s\n",a+1);
  }
  return 0;
}
