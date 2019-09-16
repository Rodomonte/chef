// CPLAY

#include <stdio.h>

int main(){
  char a[21], r;
  int i, x,y;

  while(scanf("%s", a) != EOF){
    for(i = x = y = 0, r = 'T'; i < 10; ++i){
      if(!(i&1) && a[i] == '1') ++x;
      if((i&1) && a[i] == '1') ++y;
      if(!(i&1) && ((8-i)>>1) + x < y){ r = 'B'; break; }
      if(!(i&1) && ((9-i+1)>>1) + y < x){ r = 'A'; break; }
      if((i&1) && ((9-i)>>1) + y < x){ r = 'A'; break; }
      if((i&1) && ((8-i+1)>>1) + x < y){ r = 'B'; break; }
    }
    if(r != 'T'){ printf("TEAM-%c %d\n", r, i+1); continue; }

    for(i = x = y = 0; i < 10; ++i){
      if(!(i&1) && a[i+10] == '1') ++x;
      if((i&1) && a[i+10] == '1') ++y;
      if((i&1) && x > y){ r = 'A'; break; }
      if((i&1) && x < y){ r = 'B'; break; }
    }
    if(r == 'T') printf("TIE\n");
    else printf("TEAM-%c %d\n", r, i+11);
  }
  return 0;
}
