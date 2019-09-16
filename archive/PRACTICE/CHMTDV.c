// CHMTDV

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[500][500], h[500], v[500];
int main(){
  int N,P, i,j, f,n;
  ll s,t,u;

  N = getn(), P = getn();
  for(s = i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      s += (a[i][j] = getn());

  s /= P, t = s;
  for(u = n = i = 0; i < N-1; ++i){
    for(j = 0; j < N; ++j)
      u += a[i][j];
    if(u >= t)
      h[n++] = i+1, t += s;
  }
  for(; n < P-1; ++n){
    f = 0;
    if(h[0] > 1){
      for(j = n; j > 0; --j) h[j] = h[j-1];
      h[0] = 1, ++n, f = 1;
    }
    for(i = 1; i < n; ++i) if(h[i] - h[i-1] > 1){
      for(j = n; j > i; --j) h[j] = h[j-1];
      --h[i], ++n, f = 1;
    }
    if(!f) h[n] = h[n-1] + 1, ++n;
  }

  t = s;
  for(u = n = j = 0; j < N-1; ++j){
    for(i = 0; i < N; ++i)
      u += a[i][j];
    if(u >= t)
      v[n++] = j+1, t += s;
  }
  for(; n < P-1; ++n){
    f = 0;
    if(v[0] > 1){
      for(i = n; i > 0; --i) v[i] = v[i-1];
      v[0] = 1, ++n, f = 1;
    }
    for(j = 1; j < n; ++j) if(v[j] - v[j-1] > 1){
      for(i = n; i > j; --i) v[i] = v[i-1];
      --v[j], ++n, f = 1;
    }
    if(!f) v[n] = v[n-1] + 1, ++n;
  }

  for(i = 0; i < P-1; ++i)
    printf("%d ", h[i]);
  printf("\n");
  for(i = 0; i < P-1; ++i)
    printf("%d ", v[i]);
  printf("\n");

  return 0;
}
