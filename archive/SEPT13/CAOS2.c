// CAOS2

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
  int n = 0, c = gc(), f = 1;
  while(c != '-' && (c < '0' || c > '9')) c = gc();
  if(c == '-') f = -1, c = gc();
  while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + c - '0', c = gc();
  return n * f;
}

char a[500][500];
int p[53] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,
    89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,
    181,191,193,197,199,211,223,227,229,233,239,241};
int main(){
  int T,R,C, i,j,k, n,r;
  T = getn();
  while(T--){
    R = getn(), C = getn(), r = 0;
    for(i = 0; i < R; i++){
      for(j = 0; j < C; j++)
        a[i][j] = (gc()=='#'?1:0);
      gc();
    }
    if(R < 5 || C < 5){
      printf("0\n");
      continue;
    }
    for(i = 2; i < R-2; i++)
      for(j = 2; j < C-2; j++){
        if(a[i][j])
          continue;
        n = 0;
        for(k = 1; k <= 241; k++){
          if(i-k < 0 || a[i-k][j]  || i+k >= R || a[i+k][j]
              || j-k < 0 || a[i][j-k] || j+k >= C || a[i][j+k])
            break;
          if(k == p[n]){
            r++;
            n++;
          }
        }
      }
    printf("%d\n",r);
  }
  return 0;
}
