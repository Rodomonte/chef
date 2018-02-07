// CARLOS

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

unsigned char a[200000], b[201][201], bn[201],bx[201], d[200000],
  en[200000],ex[200000];
int c[200001];

int main(){
  char f,g;
  int T,M,K,N,X,Y, i,j,k,l,m,n;
  T = getn();
  while(T--){
    M = getn(), K = getn(), N = getn();
    for(i = 1; i <= M; ++i){
      bn[i] = bx[i] = i;
      for(j = 1; j <= M; ++j)
        b[i][j] = 0;
    }
    for(i = 0; i < K; ++i){
      X = getn(), Y = getn();
      b[X][Y] = b[Y][X] = 1;
      if(Y < bn[X]) bn[X] = Y;
      if(Y > bx[X]) bx[X] = Y;
      if(X < bn[Y]) bn[Y] = X;
      if(X > bx[Y]) bx[Y] = X;
    }
    for(i = 0; i < N; ++i)
      a[i] = getn(), d[i] = 0;

    // Resolve transitivity
    f = 1;
    while(f){
      f = 0;
      for(i = 1; i <= M; ++i)
        for(j = 1; j <= M; ++j)
          if(i != j && b[i][j])
            for(k = 1; k <= M; ++k)
              if(i != k && j != k && b[j][k] && !b[i][k]){
                b[i][k] = f = 1;
                if(k < bn[i]) bn[i] = k;
                if(k > bx[i]) bx[i] = k;
              }
    }

    // Check if solution exists
    m = 1;
    for(i = 0; i < N; ++i){
      f = 0;
      for(j = m; j <= M; ++j){
        if(b[a[i]][j] || a[i] == j){
          f = 1, m = j;
          break;
        }
      }
      if(!f)
        break;
    }
    if(!f){
      printf("-1\n");
      continue;
    }

    // Find change range for each position
    m = 0;
    for(i = 0; i < N; ++i){
      en[i] = bn[a[i]];
      if(en[i] < m){
        for(j = m; a[i] != j && !b[a[i]][j]; ++j);
        en[i] = j;
      }
      if(en[i] > m)
        m = en[i];
    }
    m = M+1;
    for(i = N-1; i >= 0; --i){
      ex[i] = bx[a[i]];
      if(ex[i] > m){
        for(j = m; a[i] != j && !b[a[i]][j]; --j);
        ex[i] = j;
      }
      if(ex[i] < m)
        m = ex[i];
    }

    // Find positions that must change
    m = 0;
    for(i = 0; i < N; ++i){
      if(a[i] < m)
        d[i] = 1;
      if(en[i] > m)
        m = en[i];
    }
    m = M+1;
    for(i = N-1; i >= 0; --i){
      if(a[i] > m)
        d[i] = 1;
      if(ex[i] < m)
        m = ex[i];
    }

    // Find largest non-decreasing subsequence such that the remaining elements
    // can transform to produce sorted order
    m = 0, c[0] = -1;
    for(i = 0; i < N; ++i){
      if(d[i])
        continue;
      j = 1, k = m;
      while(j <= k){
        n = (j+k)>>1;
        if(a[c[n]] <= a[i])
          j = n+1;
        else
          k = n-1;
      }
      for(--j; j >= 0; --j){
        g = 1, n = (j) ? a[c[j]] : 1;
        for(k = c[j]+1; k < i; ++k){
          f = 0;
          for(l = n; l <= a[i]; ++l){
            if(b[a[k]][l]){
              f = 1, n = l;
              break;
            }
          }
          if(!f){
            g = 0;
            break;
          }
        }
        if(g)
          break;
      }
      if(j == -1)
        continue;
      c[j+1] = i;
      if(j+1 > m)
        m = j+1;
    }

    printf("%d\n", N-m);
  }
  return 0;
}
