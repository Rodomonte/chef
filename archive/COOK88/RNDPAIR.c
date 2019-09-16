//

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int a[100];
int main(){
  int T,N, i,j, m,c;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i) a[i] = getn();

    for(i = m = 0; i < N-1; ++i){
      for(j = i+1; j < N; ++j){
        if(a[i] + a[j] > m) m = a[i] + a[j], c = 1;
        else if(a[i] + a[j] == m) ++c;
      }
    }

    printf("%lf\n", (double)c / (N*(N-1)/2));
  }
  return 0;
}
