// MARCHA1

#include <stdio.h>
#include <stdlib.h>

int eval(int* a, int m){
    if(*a == -1) return 0;
    for(; *a != -1; a++){
        if(*a == m) return 1;
        if(*a < m) return (eval(a+1, m-(*a)) || eval(a+1, m));
    }
    return 0;
}
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int B,b, M, e=0;
        scanf("%d %d",&B,&M);
        int a[B+1];
        a[B] = -1;
        for(b = 0; b < B; b++) scanf("%d",&a[b]);
        qsort(a, B, 4, compare);
        if(eval(a, M)) e = 1;
        printf(e==1?"Yes\n":"No\n");
    }
    return 0;
}
