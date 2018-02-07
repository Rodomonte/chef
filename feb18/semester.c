// SEMESTER

#include <stdio.h>

#define ll long long
#define gc getchar_unlocked

int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

int max(int a, int b){ return (a > b) ? a : b; }

int main(){
  int T,K,A[7], i;
  ll s;

  T = getn();
  while(T--){
    K = getn();
    for(i = s = 0; i < 7; ++i) s += (A[i] = getn());

    if(K > s) K %= s;
    if(!K) for(i = 6; !A[i]; --i);
    else for(i = 0; i < 7; ++i) if(!(K = max(0, K-A[i]))) break;
    if(!i) printf("Monday\n");
    else if(i == 1) printf("Tuesday\n");
    else if(i == 2) printf("Wednesday\n");
    else if(i == 3) printf("Thursday\n");
    else if(i == 4) printf("Friday\n");
    else if(i == 5) printf("Saturday\n");
    else printf("Sunday\n");
  }
  return 0;
}
