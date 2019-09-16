// PRPALIN

#include <stdio.h>
#include <math.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
inline int prime(int N){
    int n;
    for(n = 2; n <= sqrt(N); n++)
        if(N % n == 0)
            return 0;
    return 1;
}
inline int palindrome(int N){
    int r=0, n=N;
    while(n){
        r = r*10 + n;
        n /= 10;
    }
    return r==N ? 1 : 0;
}
int main(){
    int N;
    N = getn();
    while(!palindrome(N) || !prime(N)) N++;
    printf("%d\n",N);
    return 0;
}
