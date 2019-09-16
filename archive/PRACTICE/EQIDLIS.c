// EQIDLIS

#include <stdio.h>

inline int getn(){
  int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9') c = getchar_unlocked();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int main(){
  int T = getn(), N, i,j, a[3001], c,p;
  long r;
  while(T--){
    N = getn();
    for(i = 0; i <= 3000; i++)
      a[i] = 0;
    for(i = 1; i <= N; i++)
      a[getn()]++;
    r = 0, i = 0, j = 3000;
    while(1){
      while(!a[i]) i++;
      while(!a[j]) j--;
      if(i == j){
        printf("%li\n",r);
        break;
      }else if(i + 1 == j){
        printf("-1\n");
        break;
      }
      c = (a[i] > a[j]) ? a[j] : a[i];
      r += c;
      p = (j + 1 - i) / 2;
      a[i+p] += c;
      a[j-p] += c;
      a[i] -= c;
      a[j] -= c;
    }
  }
  return 0;
}
