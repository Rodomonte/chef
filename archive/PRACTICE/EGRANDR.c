// EGRANDR

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int main(){
  int T,N,G, i, f,g,s;

  T = getn();
  while(T--){
    N = getn();
    for(i = s = g = 0, f = 1; i < N; ++i){
      s += (G = getn());
      if(G == 2) f = 0;
      if(G == 5) g = 1;
    }
    printf((f && g && (double)s/N+0.000000001 >= 4.0) ? "Yes\n" : "No\n");
  }
  return 0;
}
