// BEX

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

#define LIM 1000001
char a[LIM][16];
int b[LIM], c[LIM];
int main(){
  int N = getn(), i=1,e;
  c[0] = LIM;
  while(N--){
    e = getn();
    if(e == -1){
      i--;
      printf("%d %s\n",b[i],a[i]);
    }else if(e > 0){
      if(e > c[i-1]){
        b[i-1]++;
      }else{
        c[i] = e;
        scanf("%s",a[i]);
        b[i++] = 0;
      }
    }
  }
  return 0;
}
