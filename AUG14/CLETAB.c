// CLETAB

#include <stdio.h>

#define gc getchar_unlocked

inline int getn(){
  char c = gc(); int n = 0;
  while(c < '0' || c > '9') c = gc();
  while(c >= '0' && c <= '9')
    n = (n << 3) + (n << 1) + c - '0', c = gc();
  return n;
}

int main(){
  int T,N,M, i,j,k,m,n,s,r,
       a[400], // Customer order sequence
       b[200], // Customers currently seated
       c[401]; // Orders remaining per customer
  char d[401]; // Is customer seated
  T = getn();
  while(T--){
    N = getn(), M = getn(), r = s = 0;
    for(i = 1; i <= 400; i++)
      c[i] = d[i] = 0;
    for(i = 0; i < M; i++){
      a[i] = getn();
      c[a[i]]++;
    }
    for(i = 0; i < M; i++){
      if(d[a[i]]){
        c[a[i]]--;
        continue;
      }
      if(s < N){
        r++;
        b[s++] = a[i];
        c[a[i]]--;
        d[a[i]] = 1;
        continue;
      }
      n = -1;
      for(j = 0; j < N; j++)
        if(!c[b[j]]){
          n = j;
          break;
        }
      // Replace customer with latest next order
      if(n == -1){
        m = 0;
        for(j = 0; j < N; j++)
          for(k = i+1; k < M; k++)
            if(a[k] == b[j]){
              if(k > m)
                m = k, n = j;
              break;
            }
      }
      d[b[n]] = 0;
      r++;
      b[n] = a[i];
      c[a[i]]--;
      d[a[i]] = 1;
    }
    printf("%d\n",r);
  }
  return 0;
}
