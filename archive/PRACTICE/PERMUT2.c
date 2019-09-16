// PERMUT2

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
    int N = getn(),n;
    while(N){
        int a[N], b[N];
        for(n = 0; n < N; n++){
            a[n] = getn();
            b[a[n]-1] = n+1;
        }
        int m = 1;
        for(n = 0; n < N; n++){
            if(a[n] != b[n]){
                m = 0;
                break;
            }
        }
        printf(m?"ambiguous\n":"not ambiguous\n");
        N = getn();
    }
    return 0;
}
