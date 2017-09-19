// ADTRI

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char ss[5000001]={0};
int main(){
  int T,N, i,j,n,t, s[2237];

  for(i = 1; i <= 2236; ++i)
    s[i] = i * i;
  for(i = 1; i < 2236; ++i){
    for(j = i+1; j <= 2236; ++j){
      n = s[i] + s[j];
      if(n > 5000000)
  break;
      t = n;
      while(t <= 5000000){
  ss[t] = 1;
  t += n;
      }
    }
  }

  T = getn();
  while(T--){
    N = getn();
    printf(ss[N] ? "YES\n" : "NO\n");
  }
  return 0;
}
