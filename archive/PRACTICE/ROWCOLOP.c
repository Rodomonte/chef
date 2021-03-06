// ROWCOLOP

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
int main(){
  int N = getn(), Q = getn(), i,rs=0,cs=0,ri,ci;
  int *ra = (int*)calloc(N+1,4), *ca = (int*)calloc(N+1,4);
  while(Q--){
    if(gc() == 'R'){
      i = getn();
      ra[i] += getn();
      if(ra[i] > rs){
        rs = ra[i];
        ri = i;
      }
    }else{
      i = getn();
      ca[i] += getn();
      if(ca[i] > cs){
        cs = ca[i];
        ci = i;
      }
    }
  }
  printf("%d\n",rs+cs);
  return 0;
}
