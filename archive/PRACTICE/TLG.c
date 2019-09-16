// TLG

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
    int N, A=0,a, B=0,b, w, m=0;
    N = getn();
    while(N--){
        a = getn(), b = getn();
        a += A, b += B;
        if(a > b){
            if(a - b > m)
        m = a - b, w = 1;
        }else{
            if(b - a > m)
        m = b - a, w = 2;
        }
        A = a, B = b;
    }
    printf("%d %d\n",w,m);
    return 0;
}
