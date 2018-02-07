// SEASNAKE

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char a[30][30]={{0}}, r[223000], rev,f,f2;
int N,M,A, n,m,gn,gm,l,t,tm, rn;
void fin(){
  int i;
  printf("%d\n",rn);
  for(i = 0; i < rn; i++)
    printf("%d ",r[i]);
  printf("\n");
}
void move(char d){
  if(!A) return;
  if(d == 0) n = (n == 0 ? N-1 : n-1);
  else if(d == 1) n = (n == N-1 ? 0 : n+1);
  else if(d == 2) m = (m == 0 ? M-1 : m-1);
  else m = (m == M-1 ? 0 : m+1);
  if(!n && !m){
    int i,j;
    for(i = 0; i < N; i++)
      for(j = 0; j < N; j++)
        a[i][j] = 0;
  }
  a[n][m] = 1;
  if(n == gn && m == gm){
    l++;
    A--;
    if(A){
      gn = getn(), gm = getn();
      if(rev) tm = gn, gn = gm, gm = tm;
    }
  }
  if(rev){
    if(d == 0) r[rn++] = 2;
    else if(d == 1) r[rn++] = 3;
    else if(d == 2) r[rn++] = 0;
    else r[rn++] = 1;
  }else
    r[rn++] = d;
}
int main(){
  N = getn(), M = getn(), gn = getn(), gm = getn();
  A = N*M-1, n = m = rn = rev = 0, l = a[0][0] = 1;
  if(N == 1){
    while(A) move(3);
    fin();
    return 0;
  }else if(M == 1){
    while(A) move(1);
    fin();
    return 0;
  }
  if(N % 2 && M % 2 == 0){
    rev = 1;
    tm = N, N = M, M = tm;
    tm = gn, gn = gm, gm = tm;
  }
  while(l < (N-3)*M){
    t = 1;
    while(t < l){
      if(n % 2){
        if(m) move(2);
        else move(1);
      }else{
        if(m == M-1) move(1);
        else move(3);
      }
      t++;
    }
    if(n % 2) while(n == gn && m > gm) move(2);
    else while(n == gn && m < gm) move(3);
    move(1);
    while(n <= gn && n < N-2 && gn < N-1){
      if(m < gm){
        if(gm-m <= m+M-gm){
          while(m < gm) move(3);
        }else{
          int i, j = M-(gm-m);
          for(i = 0; i < j; i++) move(2);
        }
      }else if(m > gm){
        if(m-gm <= gm+M-m){
          while(m > gm) move(2);
        }else{
          int i, j = M-(m-gm);
          for(i = 0; i < j; i++) move(3);
        }
      }
      move(1);
      f = 1;
      while(f){
        if(n > gn && n < N-2 && m != gm && !a[gn][gm] && gm != 0 && gm != M-1){
          int i,j;
          if(m < gm && ((gm-m)+(n-gn)*2) < ((M-m)+(N-n)+M+l)){
            for(i = m+1; i <= gm; i++)
              if(a[n][i]) f = 0;
            for(i = n-1; i >= gn; i--)
              if(a[i][gm]) f = 0;
            for(i = gn; i <= n; i++)
              if(a[i][gm+1]) f = 0;
            if(f){
              int n0=n, m0=m, gn0=gn, gm0=gm;
              for(i = m0+1; i <= gm0; i++) move(3);
              for(i = n0-1; i >= gn0; i--) move(0);
              move(3);
              for(i = gn0+1; i <= n0+1; i++){
                if(n < n0 && n == gn && m < gm){
                  f2 = 1;
                  for(j = m+1; j <= gm; j++)
                    if(a[n][j] || a[n+1][j]) f2 = 0;
                  if(f2){
                    int m1=m, gm1=gm;
                    for(j = m1+1; j <= gm1; j++) move(3);
                    move(1);
                    for(j = gm1-1; j >= m1; j--) move(2);
                    move(1);
                    i++;
                  }else move(1);
                }else move(1);
              }
            }else f = 0;
          }else if(m > gm && ((m-gm)+(n-gn)*2) < ((M-m)+(N-n)+M+l)){
            for(i = m-1; i >= gm; i--)
              if(a[n][i]) f = 0;
            for(i = n-1; i >= gn; i--)
              if(a[i][gm]) f = 0;
            for(i = gn; i <= n+1; i++)
              if(a[i][gm-1]) f = 0;
            if(f){
              int n0=n, m0=m, gn0=gn, gm0=gm;
              for(i = m0-1; i >= gm0; i--) move(2);
              for(i = n0-1; i >= gn0; i--) move(0);
              move(2);
              for(i = gn0+1; i <= n0+1; i++){
                if(n == gn && n < n0 && m > gm){
                  f2 = 1;
                  for(j = m-1; j >= gm; j--)
                    if(a[n][j] || a[n+1][j]) f2 = 0;
                  if(f2){
                    int m1=m, gm1=gm;
                    for(j = m1-1; j >= gm1; j--) move(2);
                    move(1);
                    for(j = gm1+1; j <= m1; j++) move(3);
                    move(1);
                    i++;
                  }else move(1);
                }else move(1);
              }
            }else f = 0;
          }else f = 0;
        }else f = 0;
      }
    }
    while(m < M-1) move(3);
    while(n < N-1) move(1);
    while(m > 0) move(2);
    move(1);
  }
  if(N % 2 && M % 2){
    int i,j;
    while(A){
      for(i = 0; i < N-3; i += 2){
        for(j = 1; j < M; j++) move(3);
        move(1);
        for(j = 1; j < M; j++) move(2);
        move(1);
      }
      for(i = 1; i < M; i++) move(3);
      move(1); move(1);
      for(i = 0; i < M-1; i += 2){
        move(2); move(0); move(2); move(1);
      }
      move(1);
    }
  }else{
    int i;
    while(A){
      for(i = 1; i < M; i++) move(3);
      move(1);
      for(i = 1; i < M; i++) move(2);
      move(1);
    }
  }
  fin();
  return 0;
}
