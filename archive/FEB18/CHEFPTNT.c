// CHEFPTNT

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }

char s[1000001];
int main(){
  int T,N,M,X,K, i, e,o,t;

  T = getn();
  while(T--){
    N = getn(), M = getn(), X = getn(), K = getn();
    scanf("%s", s);

    for(i = e = o = 0; i < K; ++i) if(s[i] == 'E') ++e; else ++o;
    for(i = 1; i <= M; ++i){
      if(i&1) N -= (t = min(o, X)), o -= t;
      else N -= (t = min(e, X)), e -= t;
    }

    printf((N <= 0) ? "yes\n" : "no\n");
  }
  return 0;
}
