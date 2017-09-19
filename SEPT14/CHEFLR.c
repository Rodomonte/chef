// CHEFLR

#include <stdio.h>

#define gc getchar//_unlocked
#define MOD 1000000007

inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int cmod(int n){
  while(n >= MOD)
    n -= MOD;
  while(n < 0)
    n += MOD;
  return n;
}

char a[100001];
int main(){
  int T, i,n;
  T = getn();
  while(T--){
    scanf("%s", a);
    n = 1;
    for(i = 0; a[i]; i++){
      if(a[i] == 'l'){
        if(i&1)
          n = cmod((n<<1)-1);
        else
          n = cmod(n<<1);
      }else{
        if(i&1)
          n = cmod((n<<1)+1);
        else
          n = cmod((n+1)<<1);
      }
    }
    printf("%d\n", n);
  }
  return 0;
}
