// CANDLE

#include <stdio.h>
#include <math.h>

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int c[10],i, m=1, L,l;
        for(i = 0; i < 10; i++){
            scanf("%d",&c[i]);
            if(i > 1 && c[i] < c[m]) m = i;
        }
        if(c[0] < c[m]){
            m = 0;
            L = c[m] + 2;
            printf("1");
        }else{
            L = c[m] + 1;
            printf("%d",m);
        }
        for(l = 1; l < L; l++) printf("%d",m);
        printf("\n");
    }
    return 0;
}
