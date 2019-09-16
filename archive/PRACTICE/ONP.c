// ONP

#include <stdio.h>

int main(){
    int N,i,t=0;
    char s[400], b[200];
    scanf("%d",&N);
    while(N){
        scanf("%s",s);
        printf("\n");
        for(i = 0; s[i]; i++){
            if(s[i] == '(') continue;
            else if(s[i] == ')'){
                printf("%c",b[t]);
                t--;
            }else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
                t++;
                b[t] = s[i];
            }else printf("%c",s[i]);
        }
        N--;
    }
    return 0;
}
