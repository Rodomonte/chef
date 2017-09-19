// RETPO

#include <stdio.h>
#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define pc putchar_unlocked
char pb[10];
inline void putn(int n){
  if(!n) pc('0');
  if(n < 0){ pc('-'); n *= -1; }
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

int main(){
  int T,X,Y, t,r;
  T = getn();
  while(T--){
    X = getn(), Y = getn();
    if(X == Y){
      r = X<<1;
    }else if(X > Y){
      t = X-Y;
      r = (Y<<1)+((t>>1)<<2);
      if(t&1)
        r += 3;
    }else{
      t = Y-X;
      r = (X<<1)+((t>>1)<<2);
      if(t&1)
        r++;
    }
    putn(r); pc(' ');
  }
  return 0;
}
