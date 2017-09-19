// ANUUND

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
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1);
  sort(l, a+n-l);
}

int a[100000], r[100000];
int main(){
  int T,N, i,j,k;
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; i++)
      a[i] = getn();
    sort(a, N);
    j = 0, k = N-1;
    for(i = 0; i < N; i++){
      if(i & 1){
        r[i] = a[k--];
      }else{
        r[i] = a[j++];
      }
      printf("%d ",r[i]);
    }
    printf("\n");
  }
  return 0;
}
