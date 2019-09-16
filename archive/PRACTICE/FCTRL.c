// FCTRL

#include <stdio.h>
#include <math.h>

inline int getn(){
  int n=0;
  char c = fgetc(stdin);
  do{
    n = n * 10 + (c - '0');
  }while((c = fgetc(stdin)) != '\n');
  return n;
}
int main(){
    int T, N, p, z, d;
    T = getn();
    while(T--){
        N = getn(), p=1, z=0;
        while(1){
            d = ceil(pow(5, p));
            if(d > N) break;
            z += N / d;
            p++;
        }
        printf("%d\n",z);
    }
    return 0;
}
