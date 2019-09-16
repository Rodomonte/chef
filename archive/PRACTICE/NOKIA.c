// NOKIA

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char a[32];
int main(){
  int T,N,M, i,j,k, u,v;

  T = getn();
  while(T--){
    N = getn(), M = getn();

    for(i = 1; i <= N; ++i) a[i] = 0;
    a[0] = a[N+1] = 1, u = 0, v = (((N+1)*(N+2))>>1)-1;
    for(k = 0; k < N;){
      for(i = 0; i < N; ++i){
        if(!a[i] || a[i+1]) continue;
        for(j = i+2; j <= N+1; ++j) if(a[j]) break;
        a[i+((j-i)>>1)] = 1, u += j-i, ++k;
      }
    }

    if(M < u) printf("-1\n");
    else if(M > v) printf("%d\n", M-v);
    else printf("0\n");
  }
  return 0;
}
