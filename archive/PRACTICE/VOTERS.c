// VOTERS

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int A = getn(),B = getn(),C = getn(),n, ai=0,bi=0,ci=0, fi=0, m;
  int a[A+1],b[B+1],c[C+1], f[A+B+C];
  for(n = 0; n < A; n++) a[n] = getn();
  for(n = 0; n < B; n++) b[n] = getn();
  for(n = 0; n < C; n++) c[n] = getn();
  a[A] = 0, b[B] = 0, c[C] = 0;
  while(ai < A || bi < B || ci < C){
    m = a[ai], n = 0;
    if((b[bi] < m && b[bi] > 0) || m == 0) m = b[bi];
    if((c[ci] <= m && c[ci] > 0) || m == 0){
      m = c[ci];
      ci++;
      n++;
    }
    if(a[ai] == m){
      ai++;
      n++;
    }
    if(b[bi] == m){
      bi++;
      n++;
    }
    if(n > 1) f[fi++] = m;
  }
  printf("%d\n",fi);
  for(n = 0; n < fi; n++) printf("%d\n",f[n]);
    return 0;
}
