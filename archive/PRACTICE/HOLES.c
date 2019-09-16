// HOLES

#include <stdio.h>

int main(){
    int N,i;
    scanf("%d",&N);
    while(N){
        char s[100];
        int h=0;
        scanf("%s",s);
        for(i = 0; s[i]; i++){
            if(s[i] == 'A' || s[i] == 'D' || s[i] == 'O' || s[i] == 'P' || s[i] == 'Q' || s[i] == 'R') h++;
            else if(s[i] == 'B') h += 2;
        }
        printf("%d\n",h);
        N--;
    }
    return 0;
}
