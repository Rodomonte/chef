// DAILY

#include <stdio.h>

int comb(int n, int r){
  int f = 1, s = n - r, t;
  if(r < s) t = r, r = s, s = t;
  while(n > r) f *= n--;
  while(s > 1) f /= s--;
  return f;
}
int main(){
  int X, N, i,j, c, t=0;
  char s[55];
  scanf("%d %d\n",&X,&N);
  while(N--){
    gets(s);
    for(i = 0; i < 9; i++){
      c = 0;
      for(j = 0; j < 4; j++)
        if(s[i*4+j] == '0') c++;
      if(s[53-i*2] == '0') c++;
      if(s[52-i*2] == '0') c++;
      if(c >= X) t += comb(c, X);
    }
  }
  printf("%d\n",t);
  return 0;
}
