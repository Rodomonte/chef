// DEVSTR

#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0;
  char c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char s[100001];
int main(){
  char c;
  int T,N,K, i,t,r;
  T = getn();
  while(T--){
    N = getn(), K = getn();
    scanf("%s", s);
    if(N <= K){
      r = 0;
    }else if(K == 1){
      c = '0', r = 0;
      for(i = 0; i < N; ++i){
        if(s[i] != c)
          ++r;
        c = (c == '0') ? '1' : '0';
      }
      c = '1', t = 0;
      for(i = 0; i < N; ++i){
        if(s[i] != c)
          ++t;
        c = (c == '0') ? '1' : '0';
      }
      c = '0';
      if(t < r)
        c = '1', r = t;
      for(i = 0; i < N; ++i){
        s[i] = c;
        c = (c == '0') ? '1' : '0';
      }
    }else{
      r = 0, t = 1;
      for(i = 1; i < N-1; ++i){
        if(s[i] != s[i-1]){
          t = 1;
          continue;
        }
        ++t;
        if(t > K){
          if(s[i+1] == s[i])
            s[i] = (s[i] == '0') ? '1' : '0';
          else
            s[i-1] = (s[i-1] == '0') ? '1' : '0';
          ++r;
        }
      }
      if(s[N-1] == s[N-2] && t+1 > K)
        s[N-1] = (s[N-1] == '0') ? '1' : '0', ++r;
    }
    printf("%d\n%s\n", r, s);
  }
  return 0;
}
