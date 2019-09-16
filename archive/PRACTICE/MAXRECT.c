// MAXRECT

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char r[300]={0}, c[300]={0};
int a[300][300];
ll b[300];
int main(){
  int H,W, i,j,k;
  ll n,t;

  H = getn(), W = getn();
  for(i = 0; i < H; ++i) for(j = 0; j < W; ++j) a[i][j] = getn();

  for(i = 0; i < H; ++i){
    for(j = 0; j < W; ++j) if(a[i][j] > 0) break;
    if(j < W && a[i][j] > 0) break;
  }
  for(j = n = 0; j < W; ++j){
    b[j] = a[i][j];
    if(b[j] > 0) n += b[j], c[j] = 1;
  }

  r[i] = 1;
  for(++i; i < H; ++i){
    for(j = t = 0; j < W; ++j) if(a[i][j] + b[j] > 0) t += a[i][j] + b[j];
    if(t > n){
      for(j = 0; j < W; ++j) b[j] += a[i][j], c[j] = (b[j] > 0) ? 1 : 0;
      n = t, r[i] = 1;
    }
  }
  for(i = 0; i < H; ++i){
    if(!r[i]) continue;
    for(j = n = 0; j < W; ++j) if(c[j]) n += a[i][j];
    if(n < 0) r[i] = 0;
  }
  for(j = 0; j < W; ++j){
    if(!c[j]) continue;
    for(i = n = 0; i < H; ++i) if(r[i]) n += a[i][j];
    if(n < 0) c[j] = 0;
  }

  for(i = j = 0; i < H; ++i) if(r[i]) ++j;
  for(i = k = 0; i < W; ++i) if(c[i]) ++k;
  printf("%d %d\n", j, k);
  for(i = 0; i < H; ++i) if(r[i]) printf("%d ", i);
  printf("\n");
  for(i = 0; i < W; ++i) if(c[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
