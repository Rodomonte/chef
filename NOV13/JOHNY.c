// JOHNY

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n/2], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int main(){
  int T,N,K, i, a[100], n,r;
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; i++)
      a[i] = getn();
    K = getn();
    n = a[K-1];
    sort(a, N);
    for(i = 0; i < N; i++)
      if(a[i] == n){
        r = i+1;
        break;
      }
    printf("%d\n",r);
  }
  return 0;
}
