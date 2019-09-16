// DRANGE

#include <stdio.h>
#include <algorithm>
using std::sort;

#define gc getchar_unlocked
#define pc putchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
char pb[10];
int pi;
inline int putn(int n){
  if(!n) pc('0');
  pi = 0;
  while(n)
    pb[pi++] = (n) + '0', n /= 10;
  while(pi)
    pc(pb[--pi]);
}

#define IMX 2147483647
int a[1000002], b[20001], c[20000];
int main(){
  int T = getn(),N,M,w,x,y,z, i, l,h,p,n;
  while(T--){
    N = getn(), M = getn(), l = IMX, h = -IMX, p = 1, n = 0;
    a[N+1] = 0, b[M*2] = N+1;
    for(i = 0; i < M*2; i += 2){
      w = getn(), x = getn(), y = getn(), z = getn();
      z = (w==1?z:-z);
      a[x] = 0, b[i] = x, c[i] = z;
      a[y+1] = 0, b[i+1] = y+1, c[i+1] = -z;
    }
    for(i = 0; i < M*2; i++)
      a[b[i]] += c[i];
    sort(b, b+M*2);
    for(i = 0; i <= M*2; i++){
      if(b[i] > p){
        l = p+n<l?p+n:l, h = b[i]+n-1>h?b[i]+n-1:h, p = b[i];
        n += a[b[i]];
      }
    }
    putn(h-l);
    pc('\n');
  }
  return 0;
}

