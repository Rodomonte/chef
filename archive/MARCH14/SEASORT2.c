// SEASORT2

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
  int N, a[10000],r[10000][2],rn, i,j,s,e,m;
  N = getn(), rn = s = 0;
  for(i = 0; i < N; i++)
    a[i] = getn();
  while(s < N){
    m = 5001;
    for(i = s; i < N; i++)
      if(a[i] < m)
        m = a[i], e = i;
    if(s < e){
      r[rn][0] = s+1, r[rn][1] = e+1, rn++;
      for(i = s, j = e; i < s+((e-s+1)>>1); i++, j--)
        m = a[i], a[i] = a[j], a[j] = m;
    }
    s++;
  }
  printf("%d\n",rn);
  for(i = 0; i < rn; i++)
    printf("%d %d\n",r[i][0],r[i][1]);
  return 0;
}
