// CHEFUNI

#include <stdio.h>

#define gc getchar_unlocked
#define INF 2000000000

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

int main(){
  int T,X,Y,Z,A,B,C, i,j,k, i0,j0,k0, m,n,x, r,t, d[8][8][8];

  T = getn();
  while(T--){
    X = getn(), Y = getn(), Z = getn(), A = getn(), B = getn(), C = getn();

    if(A*2 <= B && A*3 <= C){ printf("%d\n", A*(X+Y+Z)); continue; }
    n = min(min(X, Y), Z);
    x = max(max(X, Y), Z);
    m = max(min(X, Y), min(max(X, Y), Z));

    i = j = k = r = 0;
    while(x-k > 6){
      if(x-k > m-j+n-i) t = x-k-(m-j+n-i), r += A*t, k += t;
      else if(m-j > n-i) t = m-j-(n-i),
        r += (B < A*2) ? B*t : A*t*2, j += t, k += t;
      else if(x-k > m-j) t = (x-k-(m-j)+1)/2,
        r += (C+A < B*2) ? (C+A)*t : B*t*2, i += t, j += t, k += t*2;
      else{ t = (x-k-5)/2;
        if(C*2 < B*3 && C < A*3) r += C*t*2;
        else r += (B < A*2) ? B*t*3 : A*t*6;
        i += t*2, j += t*2, k += t*2;
      }
    }

    i0 = i-n+7, j0 = j-m+7, k0 = k-x+7;
    for(i = i0; i < 8; ++i) for(j = j0; j < 8; ++j) for(k = k0; k < 8; ++k)
      d[i][j][k] = INF;
    d[i0][j0][k0] = r;
    for(i = i0; i < 8; ++i){ for(j = j0; j < 8; ++j){ for(k = k0; k < 8; ++k){
      if(i > i0) d[i][j][k] = min(d[i][j][k], d[i-1][j][k]+A);
      if(j > j0) d[i][j][k] = min(d[i][j][k], d[i][j-1][k]+A);
      if(k > k0) d[i][j][k] = min(d[i][j][k], d[i][j][k-1]+A);
      if(i > i0 && j > j0) d[i][j][k] = min(d[i][j][k], d[i-1][j-1][k]+B);
      if(i > i0 && k > k0) d[i][j][k] = min(d[i][j][k], d[i-1][j][k-1]+B);
      if(j > j0 && k > k0) d[i][j][k] = min(d[i][j][k], d[i][j-1][k-1]+B);
      if(i > i0 && j > j0 && k > k0)
        d[i][j][k] = min(d[i][j][k], d[i-1][j-1][k-1]+C);
    }}}

    printf("%d\n", d[7][7][7]);
  }
  return 0;
}
