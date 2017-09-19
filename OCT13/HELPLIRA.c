// HELPLIRA

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

int abs(int n){
  return n >= 0 ? n : -n;
}
int main(){
  int N,X1,Y1,X2,Y2,X3,Y3, i, a2,mn,mx,mni,mxi;
  N = getn(), mn = 4000000, mx = 0;
  for(i = 1; i <= N; i++){
    X1 = getn(), Y1 = getn(),
    X2 = getn(), Y2 = getn(),
    X3 = getn(), Y3 = getn();
    a2 = abs(X1*(Y2-Y3) + X2*(Y3-Y1) + X3*(Y1-Y2));
    if(a2 <= mn)
      mn = a2, mni = i;
    if(a2 >= mx)
      mx = a2, mxi = i;
  }
  printf("%d %d\n",mni,mxi);
  return 0;
}
