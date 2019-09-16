// FCTRL2

#include <stdio.h>

int main(){
    int T,t,N,a,i,j;
    unsigned int m,n;
    unsigned int f[160];
    scanf("%d",&T);
    for(t = 0; t < T; t++){
        scanf("%d",&N);
        f[0] = 1;
        a = 1;
        for(i = 2; i <= N; i++){
            n = 0;
            for(j = 0; j < a; j++){
                m = f[j] * i + n;
                f[j] = m % 1000;
                n = m / 1000;
            }
            while(n != 0){
                f[a++] = n % 1000;
                n /= 1000;
            }
        }
        printf("%d",f[a-1]);
        for(i = a - 2; i >= 0; i--)
            printf("%.3d",f[i]);
        printf("\n");
    }
    return 0;
}


