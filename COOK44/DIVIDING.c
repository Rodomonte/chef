#include <stdio.h>

int main(){
int N,C,i,s,r;
scanf("%d",&N);
s = r = 0;
for(i = 1; i <= N; i++){
scanf("%d",&C);
s += C;
r += i;
}
printf(r==s?"YES\n":"NO\n");
return 0;
}