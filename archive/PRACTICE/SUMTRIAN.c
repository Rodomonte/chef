// SUMTRIAN

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9')
    c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
    int N = getn(), R,r, c, p, q;
    while(N--){
        R = getn();
        int a[R][R], m[R][R];
        for(r = 0; r < R; r++)
            for(c = 0; c <= r; c++)
                a[r][c] = getn();
        for(c = 0; c < R; c++) m[R-1][c] = a[R-1][c];
        for(r = R-2; r >= 0; r--){
            for(c = 0; c <= r; c++){
                p = m[r+1][c];
                q = m[r+1][c+1];
                if(p > q) m[r][c] = a[r][c] + p;
                else m[r][c] = a[r][c] + q;
            }
        }
        printf("%d\n",m[0][0]);
    }
    return 0;
}
