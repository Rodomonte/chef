// ALETHIO

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

int i;
void nm10a(int *s, int n){
  if(s[0] == 1 && s[1] == 0)
    s[1] = n;
  else
    s[++s[0]] = n;
}
void nset(int *d, int *s){
  for(i = 0; i <= s[0]; i++)
    d[i] = s[i];
}
char ngt(int *s, int *s2){
  if(s[0] != s2[0])
    return (s[0]>s2[0]) ? 1 : 0;
  for(i = 1; i <= s[0]; i++){
    if(s[i] != s2[i])
      return (s[i]>s2[i]) ? 1 : 0;
  }
  return 0;
}
int p0[1001], p1[1001], r[1001];
int main(){
  char c = gc();
  p0[0] = p1[0] = r[0] = 1;
  p0[1] = (c>57) ? 0 : c-48;
  p1[1] = r[1] = (c>57) ? 9 : c-48;
  while((c = gc()) != '\n'){
    if(c > 57){
      nm10a(p0, 9);
      nset(p1, p0);
      p0[0] = 1, p0[1] = 0;
    }else{
      nm10a(p1, c-48);
      nm10a(p0, c-48);
    }
    if(ngt(p1, r))
      nset(r, p1);
  }
  i = 1;
  while(i < r[0] && r[i] == 0)
    i++;
  for(i; i <= r[0]; i++)
    printf("%d",r[i]);
  printf("\n");
  return 0;
}
