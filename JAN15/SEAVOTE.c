// SEAVOTE

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int main(){
  char f;
  int T,N,B, i,mn,mx;
  T = getn();
  while(T--){
    N = getn(), mn = mx = f = 0;
    for(i = 0; i < N; ++i){
      B = getn();
      if(!B)
        continue;
      if(!f)
        f = 1, ++mn;
      mn += B-1;
      mx += B;
    }
    printf((mn <= 100 && mx >= 100) ? "YES\n" : "NO\n");
  }
  return 0;
}
