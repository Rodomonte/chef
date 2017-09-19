// LIGHTHSE

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

typedef struct {
  int x,y;
} P ;

P a[100001];
int main(){
  char d;
  int T,N, i,mnx,mny,mxx,mxy,xtl,xtr,xbl,xbr,tl,tr,bl,br;

  T = getn();
  while(T--){
    N = getn();
    mnx = mny = 1000000000;
    mxx = mxy = -1000000000;
    for(i = 1; i <= N; ++i){
      a[i].x = getn(), a[i].y = getn();
      if(a[i].x < mnx)
  mnx = a[i].x;
      if(a[i].x > mxx)
  mxx = a[i].x;
      if(a[i].y < mny)
  mny = a[i].y;
      if(a[i].y > mxy)
  mxy = a[i].y;
    }

    d = 0;
    for(i = 1; i <= N; ++i){
      if(a[i].x == mnx && a[i].y == mxy){
        printf("1\n%d SE\n", i);
  d = 1;
  break;
      }
      if(a[i].x == mxx && a[i].y == mxy){
  printf("1\n%d SW\n", i);
  d = 1;
  break;
      }
      if(a[i].x == mnx && a[i].y == mny){
  printf("1\n%d NE\n", i);
  d = 1;
  break;
      }
      if(a[i].x == mxx && a[i].y == mny){
  printf("1\n%d NW\n", i);
  d = 1;
  break;
      }
    }
    if(d)
      continue;

    xtl = xbl = 1000000001;
    xtr = xbr = -1000000001;
    for(i = 1; i <= N; ++i){
      if(a[i].y == mxy){
  if(a[i].x < xtl)
    xtl = a[i].x, tl = i;
  if(a[i].x > xtr)
    xtr = a[i].x, tr = i;
      }
      if(a[i].y == mny){
  if(a[i].x < xbl)
    xbl = a[i].x, bl = i;
  if(a[i].x > xbr)
    xbr = a[i].x, br = i;
      }
    }

    printf("2\n");
    if(xtl <= xbr)
      printf("%d SE\n%d NW\n", tl, br);
    else
      printf("%d SW\n%d NE\n", tr, bl);
  }
  return 0;
}
