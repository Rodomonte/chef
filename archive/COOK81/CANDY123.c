// CANDY123

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,A,B, i,a,b,f;
  T = getn();
  while(T--){
    A = getn(), B = getn(), a = b = 0;
    for(i = 1; ; ++i){
      if(i&1)
        a += i;
      else
        b += i;
      if(a > A){
        f = 0;
        break;
      }
      if(b > B){
        f = 1;
        break;
      }
    }
    printf(f ? "Limak\n" : "Bob\n");
  }
  return 0;
}
