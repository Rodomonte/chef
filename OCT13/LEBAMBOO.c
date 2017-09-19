// LEBAMBOO

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc();
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n;
}

int abs(int n){
  return n < 0 ? -n : n;
}
int main(){
  char f;
  int T,N, i, a[50],b[50], m,n,t,r;
  T = getn();
  while(T--){
    N = getn(), t = r = 0, f = 1;
    for(i = 0; i < N; i++)
      a[i] = getn();
    for(i = 0; i < N; i++){
      b[i] = getn();
      t += b[i] - a[i];
      if(f && b[i] != a[i])
        f = 0;
    }
    if(f){
      r = 0;
    }else if(N == 1){
      r = (a[0] < b[0]) ? -1 : a[0]-b[0];
    }else if(N == 2){
      r = ((b[0]-a[0])+(b[1]-a[1])) ? -1 : abs(b[0]-a[0]);
    }else if(t % (N-2)){
      r = -1;
    }else{
      f = 1;
      while(f){
        m = 1000;
        for(i = 0; i < N; i++)
          if(b[i]-a[i] < m)
            m = b[i]-a[i], n = i;
        a[n] -= 2;
        for(i = 0; i < N; i++)
          a[i]++;
        r++;
        for(i = 0; i < N; i++)
          if(a[i] <= b[i]){
            f = 0;
            break;
          }
        if(f){
          r = -1;
          break;
        }
        f = 0;
        for(i = 0; i < N; i++)
          if(a[i] != b[i]){
            f = 1;
            break;
          }
      }
    }
    printf("%d\n",r);
  }
  return 0;
}
