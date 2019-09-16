// GCD2

#include <stdio.h>

int mod(char s[], int i){
  int c, r=0;
  for(c = 0; s[c]; ++c){
    r = 10 * r + (s[c] - 48);
    r = r % i;
  }
  return r;
}
int gcd(int a, int b){
  if(!b) return a;
  else return gcd(b, a % b);
}
int main(){
  int N, i;
  char s[252];
  scanf("%d",&N);
  while(N--){
    scanf("%d %s",&i,s);
    if(!i) printf("%s\n",s);
    else printf("%d\n",gcd(i,mod(s,i)));
  }
  return 0;
}
