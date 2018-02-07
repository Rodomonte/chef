// CHEFZOT

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

int main(){
  int N,A, i,c,r;
  N = getn(), c = r = 0;
  for(i = 0; i < N; i++){
    A = getn();
    if(!A){
      r = (c > r) ? c : r;
      c = 0;
      continue;
    }
    c++;
  }
  r = (c > r) ? c : r;
  printf("%d\n",r);
  return 0;
}