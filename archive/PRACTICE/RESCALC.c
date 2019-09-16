// RESCALC

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[101][7];
int main(){
  int T,N,C, i,j,k, m,n,t,u;

  T = getn();
  while(T--){
    N = getn();
    for(i = 1, m = 0; i <= N; ++i){
      C = n = getn();
      for(j = 1; j <= 6; ++j) a[i][j] = 0;
      for(j = 0; j < C; ++j) ++a[i][getn()];

      while(1){
        for(j = 1, u = 0; j <= 6; ++j) if(a[i][j]) ++u;
        if(u < 4) break;
        for(j = 1; j <= 6; ++j) if(a[i][j]) --a[i][j];
        if(u == 4) ++n;
        else if(u == 5) n += 2;
        else n += 4;
      }
      if(n == m) ++t;
      else if(n > m) m = n, k = i, t = 1;
    }

    if(t > 1) printf("tie\n");
    else if(k == 1) printf("chef\n");
    else printf("%d\n", k);
  }
  return 0;
}
