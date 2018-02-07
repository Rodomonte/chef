// LEVY

#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}
inline void putn(int n){
  int t;
  if(n >= 100){
    t = n / 100;
    pc(t + '0');
    n -= t * 100;
    t = n / 10;
    pc(t + '0');
    n -= t * 10;
    pc(n + '0');
  }else if(n >= 10){
    t = n / 10;
    pc(t + '0');
    n -= t * 10;
    pc(n + '0');
  }else{
    pc(n + '0');
  }
}

int main(){
  char p[9997];
  int T = getn(),N, i,j,k, s[669], r[10001],
  a[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  for(i = 2; i <= 9973; i++)
    p[i] = 1;
  for(i = 9974; i <= 9996; i++)
    p[i] = 0;
  for(i = 0; i < 25; i++){
    k = a[i], j = k*2;
    while(j < 9973){
      p[j] = 0;
      j += k;
    }
  }
  j = 0;
  for(i = 2; i <= 4999; i++)
    if(p[i])
      s[j++] = i*2;
  for(i = 1; i <= 5; i++)
    r[i] = 0;
  for(i = 6; i <= 10000; i++)
    r[i] = -1;
  while(T--){
    N = getn();
    if(r[N] == -1){
      i = 0, r[N] = 0;
      while(i < 669 && (j = s[i++]) < N){
        if(p[N-j])
          r[N]++;
      }
    }
    putn(r[N]);
    pc('\n');
  }
  return 0;
}
