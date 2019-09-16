// CHEFMATH

#include <stdio.h>

#define ll long long
#define gc getchar

#define MOD 1000000007
#define CN 43

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int madd(int a, int b){ return (a+b>=MOD) ? a+b-MOD : a+b; }

int c[CN], r;

void eval(int x, int k, int i){
  if(i < 0 || x < 0 || (ll)c[i]*k < x) return;
  if(!k){ if(!x) r = madd(r, 1); return; }
  eval(x-c[i], k-1, i);
  eval(x, k, i-1);
}

int main(){
  int Q,X,K, i;

  for(i = 2, c[0] = 1, c[1] = 2; i < CN; ++i) c[i] = c[i-2] + c[i-1];

  Q = getn();
  while(Q--){
    X = getn(), K = getn(), r = 0;
    eval(X, K, CN-1);
    printf("%d\n", r);
  }
  return 0;
}
