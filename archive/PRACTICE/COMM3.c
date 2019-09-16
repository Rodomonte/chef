// COMM3

#include <stdio.h>
#include <math.h>

int main(){
  int T, R, x1,y1,x2,y2,x3,y3;
  scanf("%d",&T);
  while(T--){
    scanf("%d\n%d %d\n%d %d\n%d %d",&R,&x1,&y1,&x2,&y2,&x3,&y3);
    double  d12 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)),
        d13 = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)),
        d23 = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    int c=0;
    if(d12 <= R) c++;
    if(d13 <= R) c++;
    if(d23 <= R) c++;
    printf(c>=2?"yes\n":"no\n");
  }
  return 0;
}
