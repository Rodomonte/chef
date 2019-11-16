// TADELIVE

#include <stdio.h>

#define gc getchar_unlocked
#define MX 100000

int getn(){
  int n = 0; char c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int abs(int a){ return (a < 0) ? -a : a; }

void sort(int* a, int n, char (*lt)()){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(lt(*l, p)){ l++; continue; }
    if(lt(p, *r)){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1, lt), sort(l, a+n-l, lt);
}

int a[MX], b[MX], c[MX];

char clt(int i, int j){
  return abs(a[i] - b[i]) > abs(a[j] - b[j]);
}

int main(){
  int N,X,Y, i, r;

  N = getn(), X = getn(), Y = getn();
  for(i = 0; i < N; ++i)
    a[i] = getn(), c[i] = i;
  for(i = 0; i < N; ++i)
    b[i] = getn();

  sort(c, N, clt);
  for(r = i = 0; i < N; ++i){
    if(!Y || (X && a[c[i]] >= b[c[i]])) --X, r += a[c[i]];
    else --Y, r += b[c[i]];
  }

  printf("%d\n", r);
  return 0;
}
