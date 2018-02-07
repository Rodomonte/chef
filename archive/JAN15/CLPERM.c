// CLPERM

#include <stdio.h>

#define gc getchar_unlocked
#define ll long long

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

int a[100000];
int main(){
  char f;
  int T,N,K, i,j;
  ll s,v,ks;
  T = getn();
  while(T--){
    N = getn(), K = getn();
    if(!K){
      printf((((((ll)N*(N+1))>>1)+1) & 1) ? "Chef\n" : "Mom\n");
      continue;
    }
    for(i = 0; i < K; ++i)
      a[i] = getn();
    sort(a, K);
    ks = 0;
    for(i = 0; i < K; ++i){
      s = (((ll)(a[i]-1) * a[i]) >> 1) - ks;
      f = 1, v = a[i]+1;
      for(j = i+1; v <= s+1; ++j, ++v){
        if(v > N)
          break;
        if(j >= K || a[j] != v){
          f = 0;
          break;
        }
      }
      if(f){
        //printf("Sum = %lld: ", s+1);
        printf((++s & 1) ? "Chef\n" : "Mom\n");
        break;
      }
      ks += a[i];
    }
    if(!f){
      //printf("Sum = %lld: ", (((ll)N*(N+1))>>1)-ks+1);
      printf((((((ll)N*(N+1))>>1)-ks+1) & 1) ? "Chef\n" : "Mom\n");
    }
  }
  return 0;
}
