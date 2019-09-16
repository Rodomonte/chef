// PAIRING
 
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
int pi;
inline void putn(int n){
  if(!n) pc('0');
  pi = 0;
  while(n) pb[pi++] = (n) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

int main(){
  int T = getn(), N, M,m, a[10000][2];
  while(T--){
    int b[1000]={0}, c[1000],ci=0;
    N = getn(), M = getn();
    for(m=0; m < M; m++) a[m][0] = getn(), a[m][1] = getn();
    for(m = M-1; m >= 0; m--){
      if(!b[a[m][0]] && !b[a[m][1]]){
        b[a[m][0]] = 1, b[a[m][1]] = 1;
        c[ci++] = m;
      }
    }
    for(ci--; ci >= 0; ci--){
      putn(c[ci]);
      pc(' ');
    }
    pc('\n');
  }
  return 0;
}