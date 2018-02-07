// PLZLYKME

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
  int T,L,D,C, i;
  long long S;
  T = getn();
  while(T--){
    L = getn(), D = getn(), S = getn(), C = getn();
    if(D == 1 && S >= L)
      C = -1;
    for(i = 2; i <= D; i++){
      S += S * C;
      if(S >= L){
        C = -1;
        break;
      }
    }
    printf((C==-1)?"ALIVE AND KICKING\n":"DEAD AND ROTTING\n");
  }
  return 0;
}
