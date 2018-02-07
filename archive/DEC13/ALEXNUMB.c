// ALEXNUMB

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
    int n = 0, c = gc();
    while(c < '0' || c > '9') c = gc();
    while(c >= '0' && c <= '9')
        n = (n<<3) + (n<<1) + c - '0', c = gc();
    return n;
}

int main(){
    int T,N, i;
    long long r;
    T = getn();
    while(T--){
        N = getn();
        for(i = 0; i < N; i++)
            getn();
        r = N;
        printf("%lld\n",(r*r-r)>>1);
    }
    return 0;
}
