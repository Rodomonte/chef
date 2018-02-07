// AMSGAME1

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int a[1000];
int gcd(int i, int j){
  if(i == j) return a[i];
  int k = gcd(i, (i+j)/2), l = gcd((i+j)/2+1, j), m;
  if(k < 0) k = -k;
  if(l < 0) l = -l;
  while(k != l){
    if(k > l){
      m = k % l;
      if(m) k = m;
      else k = l;
    }else{
      m = l % k;
      if(m) l = m;
      else l = k;
    }
  }
  return k;
}
int main(){
  int T = getn(),N, i;
  while(T--){
    N = getn();
    for(i = 0; i < N; i++)
      a[i] = getn();
    printf("%d\n",gcd(0,N-1));
  }
  return 0;
}
