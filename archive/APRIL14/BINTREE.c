// BINTREE

#include <stdio.h>
#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[128][128]={0}, d[16384]={0};
int main(){
  int T,A,B, i,j,k,da,db,n,r;
  for(i = 2, k = 1, n = 2; k < 14;){
    for(j = 0; j < n; j++)
      d[i++] = k;
    k++, n <<= 1;
  }
  T = getn();
  while(T--){
    A = getn(), B = getn(), r = 0;
    if(A < 16384){
      da = d[A];
    }else{
      da = 13, n = 16384;
      while(n <= A)
        da++, n <<= 1;
    }
    if(B < 16384){
      db = d[B];
    }else{
      db = 13, n = 16384;
      while(n <= B)
        db++, n <<= 1;
    }
    while(da > db)
      da--, A >>= 1, r++;
    while(db > da)
      db--, B >>= 1, r++;
    while(A != B)
      da--, db--, A >>= 1, B >>= 1, r += 2;
    printf("%d\n",r);
  }
  return 0;
}
