// CHEFGM

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
  char f;
  int T,K,N, i,j, a[45], e,m,pm;
  long long d,n,p,r;
  T = getn(), d = 1;
  d <<= 44;
  while(T--){
    K = getn(), r = 0;
    for(i = 0; i < K; i++){
      N = getn();
      if(!N)
        continue;
      for(j = 0; j < N; j++)
        a[j] = getn();
      sort(a, N);
      pm = a[0] % 2;
      e = 0, f = 0, p = pm ? -d : d;
      for(j = 1; j < N; j++){
        if(a[j] == a[j-1])
          continue;
        m = a[j] % 2;
        if(f || m != pm)
          e++, f = 1;
        n = m ? -d : d;
        n >>= e;
        p += n;
        pm = m;
      }
      r += p;
    }
    if(r > 0)
      printf("EVEN\n");
    else if(r < 0)
      printf("ODD\n");
    else
      printf("DON'T PLAY\n");
  }
  return 0;
}
