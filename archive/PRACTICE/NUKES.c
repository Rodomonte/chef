// NUKES

#include <stdio.h>
#include <math.h>

int main(){
    int A, N, K,k;
    scanf("%d %d %d",&A,&N,&K);
    int r[100] = {0};
    int p = floor(log(A) / log(N+1));
    while(A > N+1){
        int e = pow(N+1, p);
        while(A >= e){
            r[p]++;
            A -= e;
        }
        p--;
    }
    r[0] = A;
    printf("%d",r[0]);
    for(k = 1; k < K; k++) printf(" %d",r[k]);
    printf("\n");
    return 0;
}
