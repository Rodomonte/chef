// RECTQUER

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
    int n = 0, c = gc();
    while(c < '0' || c > '9') c = gc();
    while(c >= '0' && c <= '9')
        n = (n<<3) + (n<<1) + c - '0', c = gc();
    return n;
}
#define pc putchar_unlocked
inline void putn(int n){
  if(!n) pc('0');
  char pb[10];
  int pi = 0;
  while(n) pb[pi++] = (n%10) + '0', n /= 10;
  while(pi) pc(pb[--pi]);
}

int main(){
    int N,Q,X1,Y1,X2,Y2, i,j,k, a[300][300][10]={{{0}}},b[10], r;
    N = getn();
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            a[i][j][getn()-1] = 1;
    for(i = 1; i < N; i++)
        for(k = 0; k < 10; k++)
            a[i][0][k] += a[i-1][0][k];
    for(j = 1; j < N; j++)
        for(k = 0; k < 10; k++)
            a[0][j][k] += a[0][j-1][k];
    for(i = 1; i < N; i++)
        for(j = 1; j < N; j++)
            for(k = 0; k < 10; k++){
                a[i][j][k] += a[i-1][j][k] + a[i][j-1][k];
                a[i][j][k] -= a[i-1][j-1][k];
            }
    Q = getn();
    while(Q--){
      X1 = getn()-1, Y1 = getn()-1, X2 = getn()-1, Y2 = getn()-1, r = 0;
        for(k = 0; k < 10; k++)
            b[k] = 0;
        if(X1 > 0)
            for(k = 0; k < 10; k++)
                b[k] += a[X1-1][Y2][k];
        if(Y1 > 0)
            for(k = 0; k < 10; k++)
                b[k] += a[X2][Y1-1][k];
        if(X1 > 0 && Y1 > 0)
            for(k = 0; k < 10; k++)
                b[k] -= a[X1-1][Y1-1][k];
        for(k = 0; k < 10; k++)
            if(a[X2][Y2][k] - b[k] > 0)
                r++;
        putn(r); pc('\n');
    }
    return 0;
}
