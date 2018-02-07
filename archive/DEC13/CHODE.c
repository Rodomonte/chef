// CHODE

#include <stdio.h>

int main(){
  char a[150001],b[27],c[26];
  int T, i,j, f[26], m,mi,n;
  scanf("%d\n",&T);
  while(T--){
    gets(b); gets(a);
    for(i = 0; i < 26; i++)
      f[i] = 0;
    for(i = 0; a[i]; i++){
      if(a[i] >= 'A' && a[i] <= 'Z')
        f[a[i]-'A']++;
      else if(a[i] >= 'a' && a[i] <= 'z')
        f[a[i]-'a']++;
    }
    for(i = 0, n = 25; i < 26; i++){
      for(m = j = 0; j < 26; j++)
        if(f[j] >= m)
          m = f[j], mi = j;
      if(!m) break;
      c[mi] = b[n--];
      f[mi] = 0;
    }
    for(i = 0; a[i]; i++){
      if(a[i] >= 'A' && a[i] <= 'Z')
        a[i] = c[a[i]-'A'] - ('a'-'A');
      else if(a[i] >= 'a' && a[i] <= 'z')
        a[i] = c[a[i]-'a'];
    }
    printf("%s\n",a);
  }
  return 0;
}
