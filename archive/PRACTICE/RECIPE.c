// RECIPE

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int I;
int gcd(int a[I]){
    int i, M=0,m, d=1, v=0;
    for(i = 0; i < I; i++) if(a[i] > M) M = a[i];
    while(!v){
        m = M / d;
        v = 1;
        for(i = 0; i < I; i++){
            if(a[i] % m != 0){
                v = 0;
                while(M % ++d);
                break;
            }
        }
    }
    return m;
}
int main(){
    int N = getn(), i, g;
    while(N--){
        I = getn();
        int a[I];
        for(i = 0; i < I; i++) a[i] = getn();
        g = gcd(a);
        printf("%d",a[0]/g);
        for(i = 1; i < I; i++) printf(" %d",a[i]/g);
        printf("\n");
    }
    return 0;
}
