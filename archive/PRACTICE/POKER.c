// POKER

#include <stdio.h>

const char seq[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
int main(){
  int T, i,j;
  scanf("%d",&T);
  while(T--){
    char v,s=0, fl=0,st=0,ro=0, mk=0, fin=0;
    int c[13]={0}, l=-1;
    for(i = 0; i < 5; i++){
      getchar();
      v = getchar(), s = getchar();
      if(!i) fl = s;
      else if(fl && s != fl) fl = 0;
      for(j = 0; j < 13; j++){
        if(v == seq[j]){
          if(++c[j] > mk) mk = c[j];
          break;
        }
      }
    }
    if(mk == 1){
      i = -1;
      while(l == -1) if(c[++i]) l = i;
      if(l <= 8 && c[i+1] && c[i+2] && c[i+3] && c[i+4]){
        st = 1;
        if(l == 8) ro = 1;
      }else if(l == 0 && c[1] && c[2] && c[3] && c[12]) st = 1;
    }
    if(fl && st) puts(ro?"royal flush":"straight flush");
    else if(mk == 4) puts("four of a kind");
    else{
      for(i = 0; i < 13; i++)
        if(mk == 3 && c[i] == 2){
          puts("full house");
          fin = 1;
          break;
        }
      if(!fin){
        if(fl) puts("flush");
        else if(st) puts("straight");
        else if(mk == 3) puts("three of a kind");
        else if(mk == 2){
          int pc = 0;
          for(i = 0; i < 13; i++) if(c[i] == 2) pc++;
          if(pc == 2) puts("two pairs");
          else puts("pair");
        }else puts("high card");
      }
    }
  }
  return 0;
}
