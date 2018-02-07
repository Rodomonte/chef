// CHEFAPAR

#include <stdio.h>

#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

char a[100000];
int main(){
  int T,N, i,j,r;
  T = getn();
  while(T--){
    N = getn();
    for(i = 0; i < N; ++i)
      a[i] = getn();
    for(i = j = r = 0; i < N; ++i){
      if(!a[i]){
        r += 1100;
        continue;
      }
      if(i > j){
        a[i] = 0;
        a[j] = 1;
        r += 100;
      }
      while(j < N-1 && a[j])
        ++j;
    }
    printf("%d\n", r);
  }
  return 0;
}
