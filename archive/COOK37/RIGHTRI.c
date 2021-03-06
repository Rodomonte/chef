// RIGHTRI

#include <stdio.h>
#include <math.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int N,x1,y1,x2,y2,x3,y3,s1,s2,s3,r;
  N = getn(), r = 0;
  while(N--){
    x1 = getn(), y1 = getn();
    x2 = getn(), y2 = getn();
    x3 = getn(), y3 = getn();
    s1 = (int)(pow(y1-y2,2)+pow(x1-x2,2));
    s2 = (int)(pow(y1-y3,2)+pow(x1-x3,2));
    s3 = (int)(pow(y2-y3,2)+pow(x2-x3,2));
    if(s1 >= s2 && s1 >= s3){
      if(s2 + s3 == s1)
        r++;
    }else if(s2 >= s1 && s2 >= s3){
      if(s1 + s3 == s2)
        r++;
    }else if(s3 >= s1 && s3 >= s2){
      if(s1 + s2 == s3)
        r++;
    }
  }
  printf("%d\n",r);
  return 0;
}
