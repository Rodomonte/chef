// NUMGAME

#include <stdio.h>

int main(){
    int T, N;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&N);
    printf(--N%4?"BOB\n":"ALICE\n");
    }
    return 0;
}
