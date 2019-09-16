// COOLING

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int I,i, j;
        scanf("%d",&I);
        int p[I], r[I];
        for(i = 0; i < I; i++) scanf("%d",&p[i]);
        for(i = 0; i < I; i++) scanf("%d",&r[i]);
        qsort(p, I, 4, compare);
        qsort(r, I, 4, compare);
        j = I-1;
        for(i = I-1; i >= 0; i--)
            if(p[i] <= r[j])
                j--;
        printf("%d\n",I-j-1);
    }
    return 0;
}
