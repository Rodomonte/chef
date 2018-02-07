// CUBE

#include <stdio.h>

char b[64001];
int a[40][40][40];
int main(){
  int T,N,P, i,j,k, n,s,s3,t;
  scanf("%d\n",&T);
  while(T--){
    scanf("%d %d\n%s",&N,&P,b);
    for(i = n = 0; i < N; i++)
      for(j = 0; j < N; j++)
        for(k = 0; k < N; k++)
          a[i][j][k] = (int)b[n++];
    scanf("%s",b);
    for(i = n = 0; i < N; i++)
      for(j = 0; j < N; j++)
        for(k = 0; k < N; k++)
          a[i][j][k] = (a[i][j][k] == (int)b[n++]) ? 1 : 0;
    for(i = 1; i < N; i++)
      a[i][0][0] += a[i-1][0][0],
      a[0][i][0] += a[0][i-1][0],
      a[0][0][i] += a[0][0][i-1];
    for(i = 1; i < N; i++)
      for(j = 1; j < N; j++)
        a[0][i][j] += a[0][i-1][j] + a[0][i][j-1] - a[0][i-1][j-1],
        a[i][0][j] += a[i-1][0][j] + a[i][0][j-1] - a[i-1][0][j-1],
        a[i][j][0] += a[i-1][j][0] + a[i][j-1][0] - a[i-1][j-1][0];
    for(i = 1; i < N; i++)
      for(j = 1; j < N; j++)
        for(k = 1; k < N; k++)
          a[i][j][k] += a[i-1][j][k] + a[i][j-1][k] + a[i][j][k-1]
              - a[i-1][j-1][k] - a[i-1][j][k-1] - a[i][j-1][k-1]
              + a[i-1][j-1][k-1];
    for(s = N-1; s >= 0; s--){
      s3 = P*(s+1)*(s+1)*(s+1), t = 0;
      if(100*a[s][s][s] >= s3) t++;
      for(i = 1; i < N-s; i++){
        n = a[i+s][s][s] - a[i-1][s][s];
        if(100*n >= s3) t++;
        n = a[s][i+s][s] - a[s][i-1][s];
        if(100*n >= s3) t++;
        n = a[s][s][i+s] - a[s][s][i-1];
        if(100*n >= s3) t++;
      }
      for(i = 1; i < N-s; i++)
        for(j = 1; j < N-s; j++){
          n = a[s][i+s][j+s] - (a[s][i-1][j+s] + a[s][i+s][j-1]
              - a[s][i-1][j-1]);
          if(100*n >= s3) t++;
          n = a[i+s][s][j+s] - (a[i-1][s][j+s] + a[i+s][s][j-1]
              - a[i-1][s][j-1]);
          if(100*n >= s3) t++;
          n = a[i+s][j+s][s] - (a[i-1][j+s][s] + a[i+s][j-1][s]
              - a[i-1][j-1][s]);
          if(100*n >= s3) t++;
        }
      for(i = 1; i < N-s; i++)
        for(j = 1; j < N-s; j++)
          for(k = 1; k < N-s; k++){
            n = a[i+s][j+s][k+s] - (a[i-1][j+s][k+s]
                + a[i+s][j-1][k+s] + a[i+s][j+s][k-1]
                - a[i-1][j-1][k+s] - a[i-1][j+s][k-1]
                - a[i+s][j-1][k-1] + a[i-1][j-1][k-1]);
            if(100*n >= s3) t++;
          }
      if(t) break;
    }
    if(t)
      printf("%d %d\n",s+1,t);
    else
      printf("-1\n");
  }
  return 0;
}
