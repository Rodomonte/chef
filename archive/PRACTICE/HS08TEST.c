// HS08TEST

#include <stdio.h>

int main(){
    int w;
    float b;
    scanf("%d %f", &w, &b);
    if(w % 5 == 0 && b >= (float)w + .5) printf("%.2f", b - w - .5);
    else printf("%.2f", b);
    return 0;
}
