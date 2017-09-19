// CNG (Frobenius number)

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

#define ll long long
int main(){
  int T,C,D, i;
  T = getn();
  while(T--){
    C = getn(), D = getn();
    printf("%lld\n",(ll)C*D-C-D);
  }
  return 0;
}
