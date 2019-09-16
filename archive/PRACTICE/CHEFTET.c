// CHEFTET

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

int N, a[10000], a0[10000], b[10000], b0[10000];

int eval(){
  int i;
  for(i = 1; i < N; ++i){
    if(b[i-1]) a[i] += b[i-1], b[i-1] = 0;
    // None
    if(a[i] == a[0] && i == N-1 && b[i]) return -1;
    if(a[i] == a[0]) continue;
    // First
    if(b[i] && a[i]+b[i] == a[0]) a[i] += b[i], b[i] = 0;
    // Second
    else if(i < N-1 && b[i+1] && a[i]+b[i+1] == a[0])
      a[i] += b[i+1], b[i+1] = 0;
    // Both
    else if(i < N-1 && b[i] && b[i+1] && a[i]+b[i]+b[i+1] == a[0])
      a[i] += b[i] + b[i+1], b[i] = b[i+1] = 0;
    else return -1;
  }
  return a[0];
}

int main(){
  int T, i, r;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i) b[i] = b0[i] = getn();
    for(i = 0; i < N; ++i) a[i] = a0[i] = getn();

    // None
    r = eval();
    // First
    for(i = 0; i < N; ++i) a[i] = a0[i], b[i] = b0[i];
    a[0] += b[0], b[0] = 0;
    r = max(r, eval());
    // Second
    for(i = 0; i < N; ++i) a[i] = a0[i], b[i] = b0[i];
    a[0] += b[1], b[1] = 0;
    r = max(r, eval());
    // Both
    for(i = 0; i < N; ++i) a[i] = a0[i], b[i] = b0[i];
    a[0] += b[0] + b[1], b[0] = b[1] = 0;
    r = max(r, eval());

    printf("%d\n", r);
  }
  return 0;
}
