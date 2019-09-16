// ARRANGE

#include <stdio.h>
#include <math.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int rev(int v, int b){
  int r=0, c=0, i;
  while(v){
    r<<=1;
    r|=(v&1);
    v>>=1;
    c++;
  }
  for(i = 0; i < b-c; i++) r *= 2;
  return r;
}
int main(){
  int T = getn(), K;
  while(T--){
    K = getn();
    int E = pow(2,K),e;
    char a[E],c;
    for(e = 0; e < E; e++){
      c = getchar();
      a[rev(e,K)] = c;
    }
    for(e = 0; e < E; e++) putchar(a[e]);
    putchar('\n');
  }
  return 0;
}
