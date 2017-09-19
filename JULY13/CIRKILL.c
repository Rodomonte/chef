// CIRKILL

#include <stdio.h>
#include <math.h>

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
  double x,y;
} P ;
double abs(double d){
  return d < 0 ? -d : d;
}
double clean(double d){
  return d == -0.0 ? 0.0 : d;
}
double llen(double dx, double dy){
  return sqrt((dx * dx) + (dy * dy));
}
int main(){
  int T = getn(),N, i,j,k,l;
  double n,d,ma,mb,cx,cy,r,h;
  P a[30],p1,p2,p3;
  while(T--){
    N = getn(), n = d = 0;
    for(i = 0; i < N; i++)
      a[i].x = getn(), a[i].y = getn();
    for(i = 0; i < N; i++){
      for(j = 0; j < N-2; j++){
        if(j == i)
          continue;
        for(k = j+1; k < N-1; k++){
          if(k == i)
            continue;
          for(l = k+1; l < N; l++){
            if(l == i)
              continue;
            d++;
            if(a[k].x - a[j].x == 0 && a[l].x - a[j].x == 0)
              continue;
            if(a[k].x - a[j].x != 0 && a[l].x - a[j].x != 0){
              ma = clean((a[k].y - a[j].y) / (a[k].x - a[j].x));
              mb = clean((a[l].y - a[j].y) / (a[l].x - a[j].x));
              if(ma == mb)
                continue;
            }
            if(a[j].x == a[k].x){
              p2.x = a[l].x, p2.y = a[l].y;
              if(a[j].y == p2.y){
                p1.x = a[k].x, p1.y = a[k].y;
                p3.x = a[j].x, p3.y = a[j].y;
              }else{
                p1.x = a[j].x, p1.y = a[j].y;
                p3.x = a[k].x, p3.y = a[k].y;
              }
            }else if(a[k].x == a[l].x){
              p2.x = a[j].x, p2.y = a[j].y;
              if(a[k].y == p2.y){
                p1.x = a[l].x, p1.y = a[l].y;
                p3.x = a[k].x, p3.y = a[k].y;
              }else{
                p1.x = a[k].x, p1.y = a[k].y;
                p3.x = a[l].x, p3.y = a[l].y;
              }
            }else{
              p2.x = a[k].x, p2.y = a[k].y;
              if(a[j].y == p2.y){
                p1.x = a[l].x, p1.y = a[l].y;
                p3.x = a[j].x, p3.y = a[j].y;
              }else{
                p1.x = a[j].x, p1.y = a[j].y;
                p3.x = a[l].x, p3.y = a[l].y;
              }
            }
            ma = clean((p2.y - p1.y) / (p2.x - p1.x));
            mb = clean((p3.y - p2.y) / (p3.x - p2.x));
            cx = clean((ma * mb * (p1.y - p3.y) + mb * (p1.x +p2.x)
                - ma * (p2.x + p3.x)) / (2.0 * (mb - ma)));
            cy = clean((p1.y + p2.y) / 2.0 - (cx - (p1.x + p2.x)
                / 2.0) / ma);
            r = llen(cx - p1.x, cy - p1.y);
            h = llen(cx - a[i].x, cy - a[i].y);
            if((h<r?r-h:h-r) < 0.0000001)
              h = r;
            if(h <= r)
              n++;
          }
        }
      }
    }
    printf("%f\n",n/d);
  }
  return 0;
}
