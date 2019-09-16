// SUMAGCD

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int gcd(int a, int b){
  return b ? gcd(b,a%b) : a;
}

void sort(int* a, int n){
  if(n < 2) return;
  int p = a[n>>1], *l = a, *r = a+n-1, t;
  while(l <= r){
    if(*l < p){ l++; continue; }
    if(*r > p){ r--; continue; }
    t = *l; *l++ = *r; *r-- = t;
  }
  sort(a, r-a+1), sort(l, a+n-l);
}

int a[100000], b[100000], c[100000];
int main(){
  int T,N, i,j, g,h;

  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      b[i] = getn();

    sort(b, N);
    if(b[0] == b[N-1]){
      printf("%d\n", b[0]<<1);
      continue;
    }

    a[0] = b[0];
    for(i = j = 1; i < N; ++i)
      if(b[i] != b[i-1]) a[++j] = b[i];
    N = j+1;

    g = h = 0;
    for(i = N-1; i >= 0; --i){
      if(i < N-1 && a[i] == a[i+1]) continue;
      if(!g) g = a[i];
      else if(!h) h = a[i];
      else if(g - gcd(g, a[i]) < h - gcd(h, a[i])) g = gcd(g, a[i]);
      else h = gcd(h, a[i]);
    }
    g += h;

    b[0] = a[0], c[N-1] = a[N-1];
    for(i = 1; i < N; ++i)
      b[i] = gcd(b[i-1], a[i]);
    for(i = N-2; i >= 0; --i)
      c[i] = gcd(c[i+1], a[i]);
    for(i = 0; i < N; ++i){
      h = a[i];
      if(i > 0 && i < N-1) h += gcd(b[i-1], c[i+1]);
      else if(i > 0) h += b[i-1];
      else if(i < N-1) h += c[i+1];
      if(h > g) g = h;
    }

    printf("%d\n", g);
  }
  return 0;
}
