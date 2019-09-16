// CHEFELEC

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

char a[100001];
int b[100000];
int main(){
  int T,N,P, i, m,s,t;

  T = getn();
  while(T--){
    N = getn(), scanf("%s", a);
    for(i = 0; i < N; ++i) a[i] -= '0', b[i] = getn();

    for(i = s = 0; i < N-1 && !a[i]; ++i) a[i] = 1, s += b[i+1]-b[i];
    for(i = N-1; i > 0 && !a[i]; --i) a[i] = 1, s += b[i]-b[i-1];

    for(i = m = t = 0; i < N-1; ++i){
      if(!a[i] || !a[i+1]) m = max(m, b[i+1]-b[i]), s += b[i+1]-b[i];
      if(a[i+1]) t += m, m = 0;
    }

    printf("%d\n", s-t);
  }
  return 0;
}
